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

#include "args.hpp"

/// <summary>
/// Sets the bitrate for the video.
/// </summary>
/// <param name="bitrate">The bitrate value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoBitrate(int bitrate) {
	return(QString("-b:v %1k").arg(bitrate));
}

/// <summary>
/// Sets the bitrate for the audio.
/// </summary>
/// <param name="bitrate">The bitrate value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioBitrate(int bitrate, int stream) {
	return(QString("-b:a:%1 %2k").arg(stream).arg(bitrate));
}

/// <summary>
/// Sets the quality factor for VP9.
/// </summary>
/// <param name="quality"></param>
/// <returns>String representation of the argument.</returns>
QString Argument::vp9Quality(QString quality) {
	return(QString("-quality %1").arg(quality));
}

/// <summary>
/// 
/// </summary>
/// <param name="bitrate"></param>
/// <returns></returns>
QString Argument::buffer(int bitrate) {
	return(QString("vbv-bufsize=%1:vbv-maxrate=%2").arg(bitrate * 2).arg(bitrate + 2000));
}