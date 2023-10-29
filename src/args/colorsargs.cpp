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
/// ProRes colors video usablility information.
/// </summary>
/// <param name="matrix">The color matrix to use.</param>
/// <param name="transfer">The color transfer to use.</param>
/// <param name="primaries">The color primaries to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::colors(QString matrix, QString transfer, QString primaries) {
	return(QString("-bsf:v prores_metadata=colorspace=%1:color_trc=%2:color_primaries=%3").arg(matrix).arg(transfer).arg(primaries));
}

/// <summary>
/// The pixel format for the video to be processed in.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::pixelFormat(QString format) {
	return(QString("-pix_fmt %1").arg(format));
}