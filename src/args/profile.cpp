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
/// Sets the profile for the encoder.
/// </summary>
/// <param name="profile">The encoder profile.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoProfile(QString profile) {
	return(QString("-profile:v %1").arg(profile));
}

/// <summary>
/// Sets the profile level for the encoder.
/// </summary>
/// <param name="level">The encoder profile level.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoProfileLevel(QString level) {
	return(QString("-level:v %1").arg(level));
}