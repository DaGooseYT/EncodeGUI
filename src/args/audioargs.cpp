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
/// Sets the sample rate for an audio stream.
/// </summary>
/// <param name="rate">The sample rate of the audio.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioRate(QString rate, int stream) {
	return(QString("-ar:%1 %2").arg(stream).arg(rate));
}

/// <summary>
/// Sets the metadata for audio streams.
/// </summary>
/// <param name="stream">Stream number</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioMetadata(int stream) {
	return(QString("-metadata:s:a:%1").arg(stream));
}

/// <summary>
/// Sets the audio title for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="title">The contents to be added to the title.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioTitle(QString title) {
	return(QString("title=%2").arg(title));
}

/// <summary>
/// Sets the audio language for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="lang">The language.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioLang(QString lang) {
	return(QString("language=%2").arg(lang));
}

/// <summary>
/// Sets the number of channels in the audio stream.
/// </summary>
/// <param name="channels">The number of audio channels</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioChannels(QString channels, int stream) {
	return(QString("-ac:%1 %2").arg(stream).arg(channels));
}

/// <summary>
/// Set the number of audio channels to be processed in.
/// </summary>
/// <param name="channels">The number of channels.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::downMix(double channels) {
	return(QString("-ac %1").arg(channels));
}