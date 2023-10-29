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

#include "videoinfolist.hpp"

QStringList VideoInfoList::_codec;
QStringList VideoInfoList::_matrix;
QStringList VideoInfoList::_transfer;
QStringList VideoInfoList::_primaries;
QList<int> VideoInfoList::_width;
QList<int> VideoInfoList::_height;
QList<QTime> VideoInfoList::_jobDuration;
QList<QTime> VideoInfoList::_duration;
QStringList VideoInfoList::_jobFrameRate;
QStringList VideoInfoList::_frameRate;
QStringList VideoInfoList::_vk;

/// <summary>
/// Sets the video codec.
/// </summary>
/// <param name="codec">The video codec.</param>
void VideoInfoList::setCodec(QString codec) {
	_codec.append(codec);
}

/// <summary>
/// Sets the color matrix.
/// </summary>
/// <param name="matrix">The color matrix.</param>
void VideoInfoList::setMatrix(QString matrix) {
	_matrix.append(matrix);
}

/// <summary>
/// Sets the color transfer.
/// </summary>
/// <param name="transfer">The color transfer.</param>
void VideoInfoList::setTransfer(QString transfer) {
	_transfer.append(transfer);
}

/// <summary>
/// Sets the color primaries.
/// </summary>
/// <param name="primaries">The color primaries.</param>
void VideoInfoList::setPrimaries(QString primaries) {
	_primaries.append(primaries);
}

/// <summary>
/// Sets the video width.
/// </summary>
/// <param name="width">The video width.</param>
void VideoInfoList::setWidth(int width) {
	_width.append(width);
}

/// <summary>
/// Sets the video height.
/// </summary>
/// <param name="height">The video height.</param>
void VideoInfoList::setHeight(int height) {
	_height.append(height);
}

/// <summary>
/// Sets the total duration.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfoList::setJobDuration(QTime duration) {
	_jobDuration.append(duration);
}

/// <summary>
/// Sets the total duration.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfoList::setDuration(QTime duration) {
	_duration.append(duration);
}

/// <summary>
/// Sets the frame rate.
/// </summary>
/// <param name="frameRate">The frame rate.</param>
void VideoInfoList::setJobFrameRate(QString frameRate) {
	_jobFrameRate.append(frameRate);
}

/// <summary>
/// Sets the frame rate.
/// </summary>
/// <param name="frameRate">The frame rate.</param>
void VideoInfoList::setFrameRate(QString frameRate) {
	_frameRate.append(frameRate);
}

/// <summary>
/// Sets the GPU device name.
/// </summary>
/// <param name="name">The GPU device name.</param>
void VideoInfoList::setVk(QString name) {
	_vk.append(name);
}

/// <summary>
/// Gets the codec from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The video codec.</returns>
QString VideoInfoList::getCodec(int index) {
	return(_codec.at(index));
}

/// <summary>
/// Gets the color matrix from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The video matrix.</returns>
QString VideoInfoList::getMatrix(int index) {
	return(_matrix.at(index));
}

/// <summary>
/// Gets the color transfer from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The video transfer.</returns>
QString VideoInfoList::getTransfer(int index) {
	return(_transfer.at(index));
}

/// <summary>
/// Gets the color primaries from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The video primaries.</returns>
QString VideoInfoList::getPrimaries(int index) {
	return(_primaries.at(index));
}

/// <summary>
/// Gets the width from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The video width.</returns>
int VideoInfoList::getWidth(int index) {
	return(_width.at(index));
}

/// <summary>
/// Gets the height from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The video height.</returns>
int VideoInfoList::getHeight(int index) {
	return(_height.at(index));
}

/// <summary>
/// Gets the duration from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The duration.</returns>
QTime VideoInfoList::getJobDuration(int index) {
	return(_jobDuration.at(index));
}

/// <summary>
/// Gets the duration from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The duration.</returns>
QTime VideoInfoList::getDuration(int index) {
	return(_duration.at(index));
}

/// <summary>
/// Gets the frame rate from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The frame rate.</returns>
QString VideoInfoList::getJobFrameRate(int index) {
	return(_jobFrameRate.at(index));
}

/// <summary>
/// Gets the frame rate from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The frame rate.</returns>
QString VideoInfoList::getFrameRate(int index) {
	return(_frameRate.at(index));
}

/// <summary>
/// Gets the selected GPU device name.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The GPU device name.</returns>
QString VideoInfoList::getVk(int index) {
	return(_vk.at(index));
}

/// <summary>
/// Removes a codec from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeCodec(int index) {
	_codec.removeAt(index);
}

/// <summary>
/// Removes a matrix from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeMatrix(int index) {
	_matrix.removeAt(index);
}

/// <summary>
/// Removes a transfer from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeTransfer(int index) {
	_transfer.removeAt(index);
}

/// <summary>
/// Removes a primaries from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removePrimaries(int index) {
	_primaries.removeAt(index);
}

/// <summary>
/// Removes a width from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeWidth(int index) {
	_width.removeAt(index);
}

/// <summary>
/// Removes a height from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeHeight(int index) {
	_height.removeAt(index);
}

/// <summary>
/// Removes a duration from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeJobDuration(int index) {
	_jobDuration.removeAt(index);
}

/// <summary>
/// Removes a duration from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeDuration(int index) {
	_duration.removeAt(index);
}

/// <summary>
/// The frame rate to remove at an index in the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeJobFrameRate(int index) {
	_jobFrameRate.removeAt(index);
}

/// <summary>
/// The frame rate to remove at an index in the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::removeFrameRate(int index) {
	_frameRate.removeAt(index);
}

/// <summary>
/// Gets the total count of elements in the codec video list.
/// </summary>
/// <returns>The codec video list count.</returns>
int VideoInfoList::totalCodec() {
	return(_codec.count());
}

/// <summary>
/// Resets GPU device list. 
/// </summary>
void VideoInfoList::clearVk() {
	_vk.clear();
}

/// <summary>
/// Resets all private variables.
/// </summary>
void VideoInfoList::clearJobAll() {
	_jobDuration.clear();
	_jobFrameRate.clear();
}

/// <summary>
/// Resets all private variables.
/// </summary>
void VideoInfoList::clearAll() {
	_codec.clear();
	_matrix.clear();
	_transfer.clear();
	_primaries.clear();
	_width.clear();
	_height.clear();
	_duration.clear();
	_frameRate.clear();
}

/// <summary>
/// The total count of GPU devices.
/// </summary>
/// <returns>The total.</returns>
int VideoInfoList::totalVk() {
	return(_vk.count());
}