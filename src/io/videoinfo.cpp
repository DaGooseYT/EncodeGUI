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

#include "videoinfo.hpp"

QString VideoInfo::_videoCodec;
QTime VideoInfo::_duration;
QString VideoInfo::_durationStrng;
QString VideoInfo::_resolution;
QString VideoInfo::_bitrate;
QString VideoInfo::_colors;
QString VideoInfo::_matrix;
QString VideoInfo::_transfer;
QString VideoInfo::_primaries;
QString VideoInfo::_frameRate;
int VideoInfo::_width;
int VideoInfo::_height;

/// <summary>
/// Sets the video codec.
/// </summary>
/// <param name="codec">The codec.</param>
void VideoInfo::setVideoCodec(QString videoCodec) {
	_videoCodec = videoCodec;
}

/// <summary>
/// Sets the video duratiom in time.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfo::setDuration(QTime duration) {
	_duration = duration;
}

/// <summary>
/// Sets the video duration in a string.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfo::setDurationStrng(QString duration) {
	_durationStrng = duration;
}

/// <summary>
/// Sets the video resolution.
/// </summary>
/// <param name="resolution">the resolution.</param>
void VideoInfo::setResolution(QString resolution) {
	_resolution = resolution;
}

/// <summary>
/// Sets the video width.
/// </summary>
/// <param name="width">The width.</param>
void VideoInfo::setWidth(int width) {
	_width = width;
}

/// <summary>
/// Sets the video height.
/// </summary>
/// <param name="height">The height.</param>
void VideoInfo::setHeight(int height) {
	_height = height;
}

/// <summary>
/// Sets the total bitrate.
/// </summary>
/// <param name="bitrate">The bitrate.</param>
void VideoInfo::setBitrate(QString bitrate) {
	_bitrate = bitrate;
}

/// <summary>
/// Sets the video colors.
/// </summary>
/// <param name="colors">The colors.</param>
void VideoInfo::setColors(QString colors) {
	_colors = colors;
}

/// <summary>
/// Sets the color matrix.
/// </summary>
/// <param name="matrix">The matrix.</param>
void VideoInfo::setMatrix(QString matrix) {
	_matrix = matrix;
}

/// <summary>
/// Sets the color transfer.
/// </summary>
/// <param name="transfer">The transfer.</param>
void VideoInfo::setTransfer(QString transfer) {
	_transfer = transfer;
}

/// <summary>
/// Sets the color primaries.
/// </summary>
/// <param name="primaries">The primaries.</param>
void VideoInfo::setPrimaries(QString primaries) {
	_primaries = primaries;
}

/// <summary>
/// Sets the video frame rate.
/// </summary>
/// <param name="frameRate">The frame rate.</param>
void VideoInfo::setFrameRate(QString frameRate) {
	_frameRate = frameRate;
}

/// <summary>
/// Gets the video codec.
/// </summary>
/// <returns>The video codec.</returns>
QString VideoInfo::getVideoCodec() {
	return(_videoCodec);
}

/// <summary>
/// Gets the duration time.
/// </summary>
/// <returns>The duration.</returns>
QTime VideoInfo::getDuration() {
	return(_duration);
}

/// <summary>
/// Gets the duration string.
/// </summary>
/// <returns>The duration.</returns>
QString VideoInfo::getDurationStrng() {
	return(_durationStrng);
}

/// <summary>
/// Gets the resolution.
/// </summary>
/// <returns>The resolution.</returns>
QString VideoInfo::getResolution() {
	return(_resolution);
}

/// <summary>
/// Gets the video width.
/// </summary>
/// <returns>The width.</returns>
int VideoInfo::getWidth() {
	return(_width);
}

/// <summary>
/// Gets the video height.
/// </summary>
/// <returns>The height.</returns>
int VideoInfo::getHeight() {
	return(_height);
}

/// <summary>
/// Gets the video bitrate.
/// </summary>
/// <returns>The bitrate.</returns>
QString VideoInfo::getBitrate() {
	return(_bitrate);
}

/// <summary>
/// Gets the video colors.
/// </summary>
/// <returns>The colors.</returns>
QString VideoInfo::getColors() {
	return(_colors);
}

/// <summary>
/// Gets the color matrix.
/// </summary>
/// <returns>The matrix.</returns>
QString VideoInfo::getMatrix() {
	return(_matrix);
}

/// <summary>
/// Gets the color transfer.
/// </summary>
/// <returns>The transfer.</returns>
QString VideoInfo::getTransfer() {
	return(_transfer);
}

/// <summary>
/// Gets the color primaries.
/// </summary>
/// <returns>The primaries.</returns>
QString VideoInfo::getPrimaries() {
	return(_primaries);
}

/// <summary>
/// Gets the video frame rate.
/// </summary>
/// <returns>The frame rate.</returns>
QString VideoInfo::getFrameRate() {
	return(_frameRate);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void VideoInfo::clearAll() {
	_videoCodec = QString("?");
	_durationStrng = QString("?");
	_resolution = QString("?");
	_bitrate = QString("?");
	_colors = QString("?");
	_matrix = QString("?");
	_transfer = QString("?");
	_primaries = QString("?");
	_frameRate = QString("?");
	_duration = QTime(0, 0, 0, 0);
	_width = 0;
	_height = 0;
}