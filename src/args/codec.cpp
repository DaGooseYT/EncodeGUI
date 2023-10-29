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
/// Creates an argument for the video codec.
/// </summary>
/// <param name="codec">The video codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoCodec(QString codec) {
	return(QString("-c:v %1").arg(codec));
}

/// <summary>
/// Creates an argument for the audio codec.
/// </summary>
/// <param name="codec">The audio codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioCodec(QString codec) {
	return(QString("-c:a %1").arg(codec));
}

/// <summary>
/// Creates an argument for the subtitle codec.
/// </summary>
/// <param name="codec">The subtitle codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleCodec(QString codec) {
	return(QString("-c:s %1").arg(codec));
}

/// <summary>
/// Verbatim to audioCodec(), but adds stream specifier.
/// </summary>
/// <param name="codec">The codec to use.</param>
/// <param name="stream">The stream number to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioCodecMulti(QString codec, int stream) {
	return(QString("-c:a:%1 %2").arg(stream).arg(codec));
}

/// <summary>
/// Verbatim to subtitleCodec(), but adds stream specifier.
/// </summary>
/// <param name="codec">The codec to use.</param>
/// <param name="stream">The stream number to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleCodecMulti(QString codec, int stream) {
	return(QString("-c:s:%1 %2").arg(stream).arg(codec));
}

/// <summary>
/// Enables the x265 additional parameters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::x265Params() {
	return(QString("-x265-params"));
}

/// <summary>
/// Limits the threads for an encoding task.
/// </summary>
/// <param name="threads">The number of threads to utilize.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::threads(int threads) {
	return(QString("-threads %1").arg(threads));
}