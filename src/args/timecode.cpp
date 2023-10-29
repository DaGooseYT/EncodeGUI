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
/// Adds a timecode to the video for ProRes encoder.
/// </summary>
/// <param name="hour">The number of hour(s).</param>
/// <param name="minute">The number of minute(s).</param>
/// <param name="second">The number of second(s).</param>
/// <param name="millisecond">The number of millisecond(s).</param>
/// <returns>String representation of the argument.</returns>
QString Argument::addTimecodes(int hour, int minute, int second, int millisecond) {
	return(QString("-timecode %1:%2:%3.%4").arg(hour).arg(minute).arg(second).arg(millisecond));
}