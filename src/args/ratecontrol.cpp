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
/// Sets the quality of the video.
/// </summary>
/// <param name="quality">The quality level of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantVideoQuality(int quality) {
	return(QString("-q:v %1").arg(quality));
}

/// <summary>
/// Sets the quality of the audio.
/// </summary>
/// <param name="quality">The quality level of the audio.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantAudioQuality(int quality, int stream) {
	return(QString("-q:a:%1 %2").arg(stream).arg(quality));
}

/// <summary>
/// Sets the constant rate factor value of the video.
/// </summary>
/// <param name="crf">The constant rate factor value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantRateFactor(int crf) {
	return(QString("-crf %1").arg(crf));
}

/// <summary>
/// Sets the quantization strength of the video.
/// </summary>
/// <param name="strength">The quantizaton strength.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantQuantizer(int strength) {
	return(QString("-cq %1").arg(strength));
}

/// <summary>
/// Sets the constant quantization for GPU encoders.
/// </summary>
/// <param name="strength">The quantizaton strength.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::quantizer(int strength) {
	return(QString("-q %1").arg(strength));
}