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
/// Sharpens the video according to user specifications.
/// </summary>
/// <param name="radius">The sharpening radius value.</param>
/// <param name="strength">The sharpening strength value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::sharpenVideo(QString radius, QString strength) {
	return(QString("unsharp=%1:%2").arg(radius).arg(strength));
}