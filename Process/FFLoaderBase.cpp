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

#include "FFLoader.h"

QElapsedTimer Timer;
QTime PauseTime;

int currentJob;

void FFLoader::Encode(QString ffmpeg, QString vsArgs, bool extracti) {
	encode = new QProcess();
	
	if (!extracti) {
		Connector(encode, ProcessType::Encode);
		Connector(encode, ProcessType::EncodeFinish);
		Timer.restart();
	}
	else {
		Connector(encode, ProcessType::ExtractInfo);
		Connector(encode, ProcessType::ExtractFinish);
	}

	if (!vsArgs.isEmpty()) {
		vs = new QProcess();
		Connector(vs, ProcessType::Vs);

		vs->setStandardOutputProcess(encode);
		NewProcess(vs, QStringList(), vsArgs);
	}
	
	NewProcess(encode, QStringList(), ffmpeg);
}

void FFLoader::GPU() {
	vk = new QProcess();

	Connector(vk, ProcessType::VkInfo);
	Connector(vk, ProcessType::VkFinish);

	NewProcess(vk, QStringList() << "/C" << "vapoursynth\\vspipe.exe" << "-c" << "y4m" << "vapoursynth\\dummy.vpy" << "-", "cmd.exe");
}

void FFLoader::Action(bool sd) {
	QProcess* proc = new QProcess();

	if (sd)
		NewProcess(proc, QStringList() << "/C" << "shutdown" << "/s", "cmd.exe");
	else
		NewProcess(proc, QStringList() << "/C" << "shutdown" << "/l", "cmd.exe");
}

void FFLoader::VideoInfo(QString arguments) {
	video = new QProcess();

	Connector(video, ProcessType::VideoInfo);
	Connector(video, ProcessType::VideoFinish);
	NewProcess(video, QStringList(), arguments);
}

void FFLoader::OutputDataVideo() {
	OutputData(video, ProcessType::VideoInfo);
}

void FFLoader::OutputDataInfo() {
	OutputData(encode, ProcessType::Encode);
}

void FFLoader::OutputDataExtract() {
	OutputData(encode, ProcessType::ExtractInfo);
}

void FFLoader::OutputDataVs() {
	OutputData(vs, ProcessType::Vs);
}

void FFLoader::OutputDataVk() {
	OutputData(vk, ProcessType::VkInfo);
}

void FFLoader::VideoFinished() {
	Finisher(video, ProcessType::VideoFinish);
}

void FFLoader::EncodeFinished() {
	Finisher(encode, ProcessType::EncodeFinish);
}

void FFLoader::ExtractFinished() {
	Finisher(encode, ProcessType::ExtractFinish);
}

void FFLoader::VkFinished() {
	Finisher(vk, ProcessType::VkFinish);
}

void FFLoader::OutputData(QProcess* process, ProcessType type) {
	process->setReadChannel(QProcess::StandardError);
	
	QTextStream stream(process);
	QString output;

	while (!stream.atEnd()) {
		output = stream.readLine(0);

		if (type == ProcessType::Encode || type == ProcessType::Vs) {
			ProcessErrorRegex::ErrorRegex(output);

			if (type == ProcessType::Vs && !output.contains("Creating lwi index file"))
				emit Logs(output);
		}

		switch (type) {
		case ProcessType::Encode:
			if (ProgressInfoRegex::ProgressRegex(output, VideoInfoList::GetDuration(currentJob), VideoInfoList::GetFrameRate(currentJob).trimmed().toDouble() 
				* QTime(0, 0, 0, 0).secsTo(VideoInfoList::GetDuration(currentJob)), Timer, PauseTime))
				emit setProgress();
			else
				emit Logs(output);

			break;
		case ProcessType::VideoInfo:
			VideoInfoRegex::DurationBitrateRegex(output);
			VideoInfoRegex::VideoInfoerRegex(output);
			AudioSubInfoRegex::AudioInfoRegex(output);
			AudioSubInfoRegex::SubInfoRegex(output);
			AudioSubInfoRegex::ChapterInfoRegex(output);
			break;
		case ProcessType::ExtractInfo:
			if (ProgressInfoRegex::ExtractRegex(output, VideoInfoList::GetDuration(currentJob)))
				emit ExtractInfo();
			break;
		case ProcessType::VkInfo:
			VideoInfoRegex::VkRegex(output);
			break;
		}
	}
}

void FFLoader::Finisher(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::EncodeFinish:
		Disconnecter(process, ProcessType::EncodeFinish);
		Disconnecter(process, ProcessType::Encode);

		if (vs)
			Disconnecter(vs, ProcessType::Vs);

		emit Completed();
		break;
	case ProcessType::VideoFinish:
		Disconnecter(process, ProcessType::VideoFinish);
		Disconnecter(process, ProcessType::VideoInfo);
		emit setVideoInfo();
		break;
	case ProcessType::ExtractFinish:
		Disconnecter(process, ProcessType::ExtractFinish);
		Disconnecter(process, ProcessType::ExtractInfo);
		emit ExtractComplete();
		break;
	case ProcessType::VkFinish:
		Disconnecter(process, ProcessType::VkFinish);
		Disconnecter(process, ProcessType::VkInfo);
		emit VkComplete();
		break;
	}

	Deconstruct(process);
}

void FFLoader::Connector(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVideo);
		break;
	case ProcessType::Vs:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVs);
		break;
	case ProcessType::ExtractInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataExtract);
		break;
	case ProcessType::VkInfo:
		process->connect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVk);
		break;
	case ProcessType::VideoFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::VideoFinished);
		break;
	case ProcessType::EncodeFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::EncodeFinished);
		break;
	case ProcessType::ExtractFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::ExtractFinished);
		break;
	case ProcessType::VkFinish:
		process->connect(process, &QProcess::finished, this, &FFLoader::VkFinished);
		break;
	}
}

void FFLoader::Disconnecter(QProcess* process, ProcessType type) {
	switch (type) {
	case ProcessType::Encode:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataInfo);
		break;
	case ProcessType::VideoInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVideo);
		break;
	case ProcessType::Vs:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVs);
		break;
	case ProcessType::ExtractInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataExtract);
		break;
	case ProcessType::VkInfo:
		process->disconnect(process, &QProcess::readyReadStandardError, this, &FFLoader::OutputDataVk);
		break;
	case ProcessType::VideoFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::VideoFinished);
		break;
	case ProcessType::EncodeFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::EncodeFinished);
		break;
	case ProcessType::ExtractFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::ExtractFinished);
		break;
	case ProcessType::VkFinish:
		process->disconnect(process, &QProcess::finished, this, &FFLoader::VkFinished);
		break;
	}

	process->closeReadChannel(QProcess::StandardError);
}