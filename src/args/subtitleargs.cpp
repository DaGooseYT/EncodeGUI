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
/// Sets the metadata for subtitle streams.
/// </summary>
/// <param name="stream">Stream number</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleMetadata(int stream) {
	return(QString("-metadata:s:s:%1").arg(stream));
}

/// <summary>
/// Sets the subtitle title for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="title">The contents to be added to the title.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleTitle(QString title) {
	return(QString("title=%2").arg(title));
}

/// <summary>
/// Sets the subtitle language for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="lang">The language.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleLang(QString lang) {
	return(QString("language=%2").arg(lang));
}