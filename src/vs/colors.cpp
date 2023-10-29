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

#include "vapoursynth.hpp"

/// <summary>
/// Converts the video to the RGB color space.
/// </summary>
/// <param name="matrix">The input color matrix.</param>
/// <param name="transfer">The input color transfer.</param>
/// <param name="primaries">The input color primaries.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::rgb(QString matrix, QString transfer, QString primaries) {
	return(QString("clip = core.resize.Lanczos(clip, format=vs.RGBS, matrix_in_s=\"%1\", transfer_in_s=\"%2\", primaries_in_s=\"%3\")\n\n").arg(matrix).arg(transfer).arg(primaries));
}

/// <summary>
/// Sets both the input and output color spaces.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <param name="matrix_in">The input color matrix.</param>
/// <param name="transfer_in">The input color transfer.</param>
/// <param name="primaries_in">The input color primaries.</param>
/// <param name="matrix">The output color matrix.</param>
/// <param name="transfer">The output color transfer.</param>
/// <param name="primaries">The output color primaries.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::colorsInOut(QString format, QString matrixIn, QString transferIn, QString primariesIn, QString matrix, QString transfer, QString primaries) {
	return(QString("clip = core.resize.Lanczos(clip, format=vs.%1, matrix_s=\"%2\", transfer_s=\"%3\", primaries_s=\"%4\", matrix_in_s=\"%5\", transfer_in_s=\"%6\", primaries_in_s=\"%7\")\n\n")
		.arg(format).arg(matrix).arg(transfer).arg(primaries).arg(matrixIn).arg(transferIn).arg(primariesIn));
}

/// <summary>
/// Sets the output color spaces, assuming the inputs have already been defined.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <param name="matrix">The output color matrix.</param>
/// <param name="transfer">The output color transfer.</param>
/// <param name="primaries">The output color primaries.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::colorsOut(QString format, QString matrix, QString transfer, QString primaries) {
	return(QString("clip = core.resize.Lanczos(clip, format=vs.%1, matrix_s=\"%2\", transfer_s=\"%3\", primaries_s=\"%4\")\n\n")
		.arg(format).arg(matrix).arg(transfer).arg(primaries));
}