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
/// Maps a stream to a media file.
/// </summary>
/// <param name="type">The stream type.</param>
/// <param name="s1">Stream 1 selection.</param>
/// <param name="s2">Stream 2 selection.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::mapVideo(QString type, int s1, int s2) {
	return(QString("-map %1:%2:%3").arg(s1).arg(type).arg(s2));
}

/// <summary>
/// Maps a stream to a media file.
/// </summary>
/// <param name="type">The type of stream.</param>
/// <param name="s1">Stream specifier.</param>
/// <returns>String representation of argument.</returns>
QString Argument::mapMux(QString type, int s1) {
	return(QString("-map %1:%2").arg(type).arg(s1));
}

/// <summary>
/// Maps a stream type.
/// </summary>
/// <param name="type">The type of stream.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::mapSingle(QString type) {
	return(QString("-map %1").arg(type));
}

/// <summary>
/// Maps all of a particular stream in a video container. 
/// </summary>
/// <param name="type">The stream type to target.</param>
/// <param name="s1">Stream one identifier.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::mapAll(QString type, int s1) {
	return(QString("-map %1:%2?").arg(s1).arg(type));
}