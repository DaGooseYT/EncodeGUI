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
/// Sets the video resolution to the specified value.
/// </summary>
/// <param name="width">The selected width of the video.</param>
/// <param name="height">The selected height of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoResolution(int width, int height) {
	return(QString("scale=%1x%2").arg(width).arg(height));
}

/// <summary>
/// Sets the specified resizing algo.
/// </summary>
/// <param name="algo">The resize algo.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoResizeAlgo(QString algo) {
	return(QString(":flags=%1").arg(algo));
}

/// <summary>
/// Crops the video at a specified point to a specified resolution.
/// </summary>
/// <param name="x">The x location to crop/</param>
/// <param name="y">The y location to crop.</param>
/// <param name="width">The crop width of the video.</param>
/// <param name="height">The crop height of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::crop(int x, int y, int width, int height) {
	return(QString("crop=%1:%2:%3:%4").arg(width).arg(height).arg(x).arg(y));
}