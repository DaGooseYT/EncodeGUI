/****************************************************************************
 * Copyright (C) 2022 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "ffloader.hpp"

void FFLoader::encode(QStringList args, QStringList vsArgs, QString ffmpeg, QString vsPipe, bool extracti) {
	_encode = new QProcess();
	_pauseTime = new QTime(0, 0, 0);
	_timer = new QElapsedTimer();
	
	if (!extracti) {
		connector(_encode, ProcessType::Encode);
		connector(_encode, ProcessType::EncodeFinish);
		_timer->restart();
	}
	else {
		connector(_encode, ProcessType::ExtractInfo);
		connector(_encode, ProcessType::ExtractFinish);
	}

	if (!vsArgs.isEmpty()) {
		_vs = new QProcess();
		connector(_vs, ProcessType::Vs);

		_vs->setStandardOutputProcess(_encode);
		newProcess(_vs, vsArgs, vsPipe);
	}
	
	newProcess(_encode, args, ffmpeg);
}

#ifdef Q_OS_WINDOWS
void FFLoader::gpu() {
	_vk = new QProcess();

	connector(_vk, ProcessType::VkInfo);
	connector(_vk, ProcessType::VkFinish);

	newProcess(_vk, QStringList() << QString("/C") << QString("vs\\vspipe.exe") << QString("-c") << QString("y4m") << QString("vs\\dummy.vpy") << QString("-"), QString("cmd.exe"));
}
#endif

void FFLoader::extractRPU(QStringList args, QStringList doviArgs, QString doviTool, QString ffmpeg) {
	_extract = new QProcess();
	_dovi = new QProcess();

	connector(_extract, ProcessType::ExtractRPU);
	connector(_extract, ProcessType::ExtractRPUFinish);
	_extract->setStandardOutputProcess(_dovi);

	newProcess(_extract, args, ffmpeg);
	newProcess(_dovi, doviArgs, doviTool);
}

void FFLoader::action(bool sd) {
	QProcess *proc(new QProcess());

	#ifdef Q_OS_WINDOWS
	if (sd)
		newProcess(proc, QStringList() << QString("/C") << QString("shutdown") << QString("/s"), QString("cmd.exe"));
	else
		newProcess(proc, QStringList() << QString("/C") << QString("shutdown") << QString("/l"), QString("cmd.exe"));
	#endif
	#ifdef Q_OS_DARWIN
	if (sd)
		newProcess(proc, QStringList() << QString("sudo") << QString("shutdown") << QString("-h") << QString("now"), QString("cmd.exe"));
	else
		newProcess(proc, QStringList() << QString("sudo") << QString("shutdown") << QString("-s") << QString("now"), QString("cmd.exe"));
	#endif
}

void FFLoader::batchInfo(QStringList args, QString ffprobe) {
	_video = new QProcess();

	connector(_video, ProcessType::BatchInfo);
	connector(_video, ProcessType::BatchFinish);
	newProcess(_video, args, ffprobe);
}

void FFLoader::videoInfo(QStringList args, QString ffprobe) {
	_video = new QProcess();

	connector(_video, ProcessType::VideoInfo);
	connector(_video, ProcessType::VideoFinish);
	newProcess(_video, args, ffprobe);
}

void FFLoader::audioInfo(QStringList args, QString ffprobe) {
	_video = new QProcess();

	connector(_video, ProcessType::AudioInfo);
	connector(_video, ProcessType::AudioFinish);
	newProcess(_video, args, ffprobe);
}

void FFLoader::subtitleInfo(QStringList args, QString ffprobe) {
	_video = new QProcess();

	connector(_video, ProcessType::SubtitleInfo);
	connector(_video, ProcessType::SubtitleFinish);
	newProcess(_video, args, ffprobe);
}

void FFLoader::outputDataVideo() {
	outputData(_video, ProcessType::VideoInfo);
}

void FFLoader::outputDataBatch() {
	outputData(_video, ProcessType::BatchInfo);
}

void FFLoader::outputDataInfo() {
	outputData(_encode, ProcessType::Encode);
}

void FFLoader::outputDataAudio() {
	outputData(_video, ProcessType::AudioInfo);
}

void FFLoader::outputDataSubtitle() {
	outputData(_video, ProcessType::SubtitleInfo);
}

void FFLoader::outputDataExtract() {
	outputData(_encode, ProcessType::ExtractInfo);
}

void FFLoader::outputDataVs() {
	outputData(_vs, ProcessType::Vs);
}

#ifdef Q_OS_WINDOWS
void FFLoader::outputDataVk() {
	outputData(_vk, ProcessType::VkInfo);
}
#endif

void FFLoader::outputDataRPU() {
	outputData(_extract, ProcessType::ExtractRPU);
}

void FFLoader::videoFinished() {
	finisher(_video, ProcessType::VideoFinish);
}

void FFLoader::batchFinished() {
	finisher(_video, ProcessType::BatchFinish);
}

void FFLoader::audioFinished() {
	finisher(_video, ProcessType::AudioFinish);
}

void FFLoader::subtitleFinished() {
	finisher(_video, ProcessType::SubtitleFinish);
}

void FFLoader::encodeFinished() {
	finisher(_encode, ProcessType::EncodeFinish);
}

void FFLoader::extractFinished() {
	finisher(_encode, ProcessType::ExtractFinish);
}

#ifdef Q_OS_WINDOWS
void FFLoader::vkFinished() {
	finisher(_vk, ProcessType::VkFinish);
}
#endif

void FFLoader::extractRPUFinished() {
	finisher(_extract, ProcessType::ExtractRPUFinish);
}

void FFLoader::outputData(QProcess *process, ProcessType type) {
	process->setReadChannel(QProcess::StandardError);
	
	QTextStream stream(process);
	QString output;

	while (!stream.atEnd()) {
		output = stream.readLine(0);

		if (type == ProcessType::Encode || type == ProcessType::Vs || type == ProcessType::ExtractRPU) {
			ProcessErrorRegex::errorRegex(output);

			if (type == ProcessType::Vs && !output.contains(QString("Creating lwi index file")))
				emit logs(output);
		}

		switch (type) {
		case ProcessType::Encode:
			if (ProgressInfoRegex::progressRegex(output, VideoInfoList::getJobDuration(_currentJob), VideoInfoList::getJobFrameRate(_currentJob).trimmed().toDouble() 
				* QTime(0, 0, 0, 0).secsTo(VideoInfoList::getJobDuration(_currentJob)), *_timer, *_pauseTime))
				emit setProgress();
			else
				emit logs(output);

			break;
		case ProcessType::VideoInfo:
			VideoInfoRegex::durationBitrateRegex(output);
			VideoInfoRegex::videoInfoerRegex(output);
			AudioSubInfoRegex::audioInfoRegex(output);
			AudioSubInfoRegex::subInfoRegex(output);
			AudioSubInfoRegex::chapterInfoRegex(output);
			break;
		case ProcessType::BatchInfo:
			VideoInfoRegex::durationBitrateRegex(output);
			VideoInfoRegex::batchInfoerRegex(output);
			break;
		case ProcessType::AudioInfo:
			AudioSubInfoRegex::audioInfoRegex(output);
			break;
		case ProcessType::SubtitleInfo:
			AudioSubInfoRegex::subInfoRegex(output);
			break;
		case ProcessType::ExtractInfo:
			if (ProgressInfoRegex::extractRegex(output, VideoInfoList::getJobDuration(_currentJob)))
				emit extractInfo();
			break;
		#ifdef Q_OS_WINDOWS
		case ProcessType::VkInfo:
			VideoInfoRegex::vkRegex(output);
			break;
		#endif
		}
	}
}

void FFLoader::finisher(QProcess *process, ProcessType type) {
	switch (type) {
	case ProcessType::EncodeFinish:
		disconnecter(process, ProcessType::EncodeFinish);
		disconnecter(process, ProcessType::Encode);

		if (_vs) {
			disconnecter(_vs, ProcessType::Vs);
			killProcess(_vs);
		}
		
		killProcess(_encode);

		emit completed();
		break;
	case ProcessType::VideoFinish:
		disconnecter(process, ProcessType::VideoFinish);
		disconnecter(process, ProcessType::VideoInfo);
		emit setVideoInfo();
		break;
	case ProcessType::BatchFinish:
		disconnecter(process, ProcessType::BatchFinish);
		disconnecter(process, ProcessType::BatchInfo);
		emit setBatchInfo();
		break;
	case ProcessType::AudioFinish:
		disconnecter(process, ProcessType::AudioFinish);
		disconnecter(process, ProcessType::AudioInfo);
		emit setAudioInfo();
		break;
	case ProcessType::SubtitleFinish:
		disconnecter(process, ProcessType::SubtitleFinish);
		disconnecter(process, ProcessType::SubtitleInfo);
		emit setSubtitleInfo();
		break;
	case ProcessType::ExtractFinish:
		disconnecter(process, ProcessType::ExtractFinish);
		disconnecter(process, ProcessType::ExtractInfo);
		emit extractComplete();
		break;
	#ifdef Q_OS_WINDOWS
	case ProcessType::VkFinish:
		disconnecter(process, ProcessType::VkFinish);
		disconnecter(process, ProcessType::VkInfo);
		emit vkComplete();
		break;
	#endif
	case ProcessType::ExtractRPUFinish:
		disconnecter(process, ProcessType::ExtractRPUFinish);
		disconnecter(process, ProcessType::ExtractRPU);
		emit rpuFinished();
		break;
	}

	if ((type == ProcessType::EncodeFinish || type == ProcessType::Vs || type == ProcessType::ExtractFinish) && !process->errorString().isEmpty()) {
		QString change;

		if (process->errorString().contains(QString("Unknown error")))
			change = QString("Unknown/No error");
		if (process->errorString().contains(QString("Crashed")))
			change = QString("Crashed/Canceled");

		emit errorLogs(QString("\n#================================================#"));
		emit errorLogs(QString("General process logs: ") + change);
		emit errorLogs(QString("#================================================#\n"));
	}

	deconstruct(process);
}

void FFLoader::connector(QProcess *process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVideo);
		break;
	case ProcessType::BatchInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataBatch);
		break;
	case ProcessType::AudioInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataAudio);
		break;
	case ProcessType::SubtitleInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataSubtitle);
		break;
	case ProcessType::Vs:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVs);
		break;
	case ProcessType::ExtractInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataExtract);
		break;
	#ifdef Q_OS_WINDOWS
	case ProcessType::VkInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVk);
		break;
	#endif
	case ProcessType::ExtractRPU:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataRPU);
		break;
	case ProcessType::VideoFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::videoFinished);
		break;
	case ProcessType::BatchFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::batchFinished);
		break;
	case ProcessType::AudioFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::audioFinished);
		break;
	case ProcessType::SubtitleFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::subtitleFinished);
		break;
	case ProcessType::EncodeFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::encodeFinished);
		break;
	case ProcessType::ExtractFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::extractFinished);
		break;
	#ifdef Q_OS_WINDOWS
	case ProcessType::VkFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::vkFinished);
		break;
	#endif
	case ProcessType::ExtractRPUFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::extractRPUFinished);
		break;
	}
}

void FFLoader::disconnecter(QProcess *process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVideo);
		break;
	case ProcessType::BatchInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataBatch);
		break;
	case ProcessType::AudioInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataAudio);
		break;
	case ProcessType::SubtitleInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataSubtitle);
		break;
	case ProcessType::Vs:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVs);
		break;
	case ProcessType::ExtractInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataExtract);
		break;
	#ifdef Q_OS_WINDOWS
	case ProcessType::VkInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataVk);
		break;
	#endif
	case ProcessType::ExtractRPU:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::outputDataRPU);
		break;
	case ProcessType::VideoFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::videoFinished);
		break;
	case ProcessType::BatchFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::batchFinished);
		break;
	case ProcessType::AudioFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::audioFinished);
		break;
	case ProcessType::SubtitleFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::subtitleFinished);
		break;
	case ProcessType::EncodeFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::encodeFinished);
		break;
	case ProcessType::ExtractFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::extractFinished);
		break;
	#ifdef Q_OS_WINDOWS
	case ProcessType::VkFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::vkFinished);
		break;
	#endif
	case ProcessType::ExtractRPUFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::extractRPUFinished);
		break;
	}

	process->closeReadChannel(QProcess::StandardError);
}