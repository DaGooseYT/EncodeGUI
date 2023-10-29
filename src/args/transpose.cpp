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
/// Rotates the video to a specified degree.
/// </summary>
/// <param name="transpose">The transpose value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::transposeVideo(int transpose) {
	return(QString("transpose=%1").arg(transpose));
}

/// <summary>
/// Flips the video in a specified direction.
/// </summary>
/// <param name="flip">The flip direction.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::flipVideo(QString flip) {
	return(QString("%1flip").arg(flip));
}

/// <summary>
/// Disabled the auto rotate feature in FFMpeg.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::noAutoRotate() {
	return(QString("-noautorotate"));
}