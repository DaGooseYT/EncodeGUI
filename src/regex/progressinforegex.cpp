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

#include "progressinforegex.hpp"

QList<QRegularExpression> ProgressInfoRegex::_indexer;

void ProgressInfoRegex::setupPatterns() {
	_indexer.append(QRegularExpression(QString("frame=\\s*([0-9]*)")));
	_indexer.append(QRegularExpression(QString("fps=\\s*([0-9]*\\.?[0-9]?)")));
	_indexer.append(QRegularExpression(QString("bitrate=\\s*([0-9]*\\.?[0-9]?)kbits/s")));
	_indexer.append(QRegularExpression(QString("time=\\s*([0-9]*):([0-9]*):([0-9]*)\\.([0-9]*)")));
}

bool ProgressInfoRegex::extractRegex(QString output, QTime totalDuration) {
	if (_indexer.isEmpty())
		setupPatterns();

	QRegularExpressionMatch matchTimeProcessed(_indexer.at(GetInfo::Time).match(output));
	QTime timeProcessed;

	if (!matchTimeProcessed.hasMatch())
		return false;
	else {
		timeProcessed = QTime(matchTimeProcessed.captured(1).toInt(), matchTimeProcessed.captured(2).toInt(), matchTimeProcessed.captured(3).toInt(),
			QString(matchTimeProcessed.captured(4) + QString("0")).toInt());
		
		int mSecondsProcessed = QTime(0, 0, 0, 0).msecsTo(timeProcessed);
		int mSecondsTotal = QTime(0, 0, 0, 0).msecsTo(totalDuration);

		double percentage = ceil(static_cast<double>(mSecondsProcessed) / mSecondsTotal * 10000.0) / 100.0;

		if (percentage > 100)
			percentage = 100;

		#ifdef PROGRESSINFO_H
		ProgressInfo::setPercentage(percentage);
		#endif // PROGRESSINFO_H

		return(true);
	}
}

bool ProgressInfoRegex::progressRegex(QString output, QTime totalDuration, int totalFrames, QElapsedTimer timer, QTime pause) {
	if (_indexer.isEmpty())
		setupPatterns();
	
	QRegularExpressionMatch matchFrames(_indexer.at(GetInfo::Frame).match(output));
	QRegularExpressionMatch matchFps(_indexer.at(GetInfo::Fps).match(output));
	QRegularExpressionMatch matchBitrate(_indexer.at(GetInfo::Bitrate).match(output));
	QRegularExpressionMatch matchTimeProcessed(_indexer.at(GetInfo::Time).match(output));

	int frames;
	QString fps, bitrate;
	QTime timeProcessed;

	if (!matchFrames.hasMatch() && !matchFps.hasMatch() && !matchBitrate.hasMatch() && !matchTimeProcessed.hasMatch())
		return(false);
	else {
		frames = matchFrames.captured(1).toInt();
		fps = matchFps.captured(1);
		bitrate = matchBitrate.captured(1);
		timeProcessed = QTime(matchTimeProcessed.captured(1).toInt(), matchTimeProcessed.captured(2).toInt(), matchTimeProcessed.captured(3).toInt(),
			QString(matchTimeProcessed.captured(4) + QString("0")).toInt());

		int mSecondsProcessed = QTime(0, 0, 0, 0).msecsTo(timeProcessed);
		int mSecondsTotal = QTime(0, 0, 0, 0).msecsTo(totalDuration);

		double percentage = ceil(static_cast<double>(mSecondsProcessed) / mSecondsTotal * 10000.0) / 100.0;

		int elapsed = (timer.elapsed() + QTime(0, 0, 0, 0).msecsTo(pause)) / 1000;

		int framesLeft = totalFrames - frames;
		double timeLeft = framesLeft * (static_cast<double>(elapsed) / frames);

		int seconds = ((int)timeLeft % 60);
		timeLeft /= 60;
		int minutes = ((int)timeLeft % 60);
		timeLeft /= 60;
		int hours = ((int)timeLeft);

		if (seconds < 0)
			seconds = 0;
		if (minutes < 0)
			minutes = 0;
		if (hours < 0)
			hours = 0;

		if (percentage > 100)
			percentage = 100;

		QTime qTimeLeft(QTime(hours, minutes, seconds));

		int sec = (int)(elapsed % 60);
		elapsed /= 60;
		int min = (int)(elapsed % 60);
		elapsed /= 60;
		int hr = (int)(elapsed);

		QTime timeElapsed(QTime(hr, min, sec));

		if (bitrate.isEmpty())
			bitrate = QString("0.0");
		if (fps.isEmpty())
			fps = QString("0.0");

		#ifdef PROGRESSINFO_H
		ProgressInfo::setTimeLeft(qTimeLeft);
		ProgressInfo::setTimeElapsed(timeElapsed);
		ProgressInfo::setProcessedFrames(frames);
		ProgressInfo::setTotalFrames(totalFrames);
		ProgressInfo::setTime(timeProcessed);
		ProgressInfo::setFps(fps);
		ProgressInfo::setBitrate(bitrate);
		ProgressInfo::setPercentage(percentage);
		#endif // PROGRESSINFO_H

		return(true);
	}
}