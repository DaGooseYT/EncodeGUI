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
/// Sets the number of B frames.
/// </summary>
/// <param name="bFrame">The number of B frames to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::bFrame(int bFrame) {
	return(QString("-bf %1").arg(bFrame));
}

/// <summary>
/// Sets the number of reference frames.
/// </summary>
/// <param name="refFrame">The number of reference frames to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::referenceFrame(int refFrame) {
	return(QString("-refs %1").arg(refFrame));
}