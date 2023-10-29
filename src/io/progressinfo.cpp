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

#include "progressinfo.hpp"

QTime ProgressInfo::_timeLeft;
QTime ProgressInfo::_timeElapsed;
int ProgressInfo::_processedFrames;
int ProgressInfo::_totalFrames;
QTime ProgressInfo::_time;
QString ProgressInfo::_fps;
QString ProgressInfo::_bitrate;
double ProgressInfo::_percentage;

/// <summary>
/// Sets the time left.
/// </summary>
/// <param name="timeLeft">The amount of time left.</param>
void ProgressInfo::setTimeLeft(QTime timeLeft) {
	_timeLeft = timeLeft;
}

/// <summary>
/// Sets the time elapsed.
/// </summary>
/// <param name="timeElapsed">The amount of time elapsed.</param>
void ProgressInfo::setTimeElapsed(QTime timeElapsed) {
	_timeElapsed = timeElapsed;
}

/// <summary>
/// Sets the processed frames.
/// </summary>
/// <param name="processedFrames">The amount of frames processed.</param>
void ProgressInfo::setProcessedFrames(int processedFrames) {
	_processedFrames = processedFrames;
}

/// <summary>
/// Sets the total number of frames.
/// </summary>
/// <param name="totalFrames">The total number of frames.</param>
void ProgressInfo::setTotalFrames(int totalFrames) {
	_totalFrames = totalFrames;
}

/// <summary>
/// Sets the time processed.
/// </summary>
/// <param name="time">The time processed.</param>
void ProgressInfo::setTime(QTime time) {
	_time = time;
}

/// <summary>
/// Sets the fps.
/// </summary>
/// <param name="fps">The fps.</param>
void ProgressInfo::setFps(QString fps) {
	_fps = fps;
}

/// <summary>
/// Sets the bitrate.
/// </summary>
/// <param name="bitrate">The bitrate.</param>
void ProgressInfo::setBitrate(QString bitrate) {
	_bitrate = bitrate;
}

/// <summary>
/// Sets the encoding percentage.
/// </summary>
/// <param name="percentage">The percentage.</param>
void ProgressInfo::setPercentage(double percentage) {
	_percentage = percentage;
}

/// <summary>
/// Gets the time left.
/// </summary>
/// <returns>The time left.</returns>
QTime ProgressInfo::getTimeLeft() {
	return(_timeLeft);
}

/// <summary>
/// Gets the time elapsed.
/// </summary>
/// <returns>The time elapsed.</returns>
QTime ProgressInfo::getTimeElapsed() {
	return(_timeElapsed);
}

/// <summary>
/// Gets the processed frames.
/// </summary>
/// <returns>The number of processed frames.</returns>
int ProgressInfo::getProcessedFrames() {
	return(_processedFrames);
}

/// <summary>
/// Gets the total number of frames.
/// </summary>
/// <returns>The total number of frames.</returns>
int ProgressInfo::getTotalFrames() {
	return(_totalFrames);
}

/// <summary>
/// Gets the time processed.
/// </summary>
/// <returns>The time processed.</returns>
QTime ProgressInfo::getTime() {
	return(_time);
}

/// <summary>
/// Gets the fps.
/// </summary>
/// <returns>The fps.</returns>
QString ProgressInfo::getFps() {
	return(_fps);
}

/// <summary>
/// Gets the bitrate.
/// </summary>
/// <returns>The bitrate.</returns>
QString ProgressInfo::getBitrate() {
	return(_bitrate);
}

/// <summary>
/// Gets the percentage.
/// </summary>
/// <returns>The percentage.</returns>
double ProgressInfo::getPercentage() {
	return(_percentage);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void ProgressInfo::clearAll() {
	_timeLeft = QTime();
	_timeElapsed = QTime();
	_processedFrames = 0;
	_totalFrames = 0;
	_time = QTime();
	_fps.clear();
	_bitrate.clear();
	_percentage = 0.0;
}