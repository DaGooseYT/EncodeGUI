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

#include "subtitleinfo.hpp"

QStringList SubtitleInfo::_language;
QStringList SubtitleInfo::_stream;
QStringList SubtitleInfo::_codec;
int SubtitleInfo::_streams;
bool SubtitleInfo::_chapter;

/// <summary>
/// Sets the subtitle language.
/// </summary>
/// <param name="language">The language.</param>
void SubtitleInfo::setLanguage(QString language) {
	_language.append(language);
}

/// <summary>
/// Sets the subtitle codecs.
/// </summary>
/// <param name="codec">The codec.</param>
void SubtitleInfo::setCodec(QString codec) {
	_codec.append(codec);
}

/// <summary>
/// Sets the subtitle stream identifier.
/// </summary>
/// <param name="stream">The stream identifier.</param>
void SubtitleInfo::setStream(QString stream) {
	_stream.append(stream);
}

/// <summary>
/// Sets the chapters.
/// </summary>
/// <param name="chapter">True or false.</param>
void SubtitleInfo::setChapter(bool chapter) {
	_chapter = chapter;
}

/// <summary>
/// Gets the language from subtitle list.
/// </summary>
/// <param name="index">The index from the list.</param>
/// <returns>The language.</returns>
QString SubtitleInfo::getLanguage(int index) {
	return(_language.at(index));
}

/// <summary>
/// Gets the subtitle codec from the the subtitle list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The codec.</returns>
QString SubtitleInfo::getCodec(int index) {
	return(_codec.at(index));
}

/// <summary>
/// Gets the stream identifier from the subtitle list.
/// </summary>
/// <param name="index">The index from the list.</param>
/// <returns></returns>
QString SubtitleInfo::getStream(int index) {
	return(_stream.at(index));
}

/// <summary>
/// Gets the chapters.
/// </summary>
/// <returns>True or false.</returns>
bool SubtitleInfo::getChapter() {
	return(_chapter);
}

/// <summary>
/// Adds a stream to the total.
/// </summary>
void SubtitleInfo::addStreams() {
	_streams++;
}

/// <summary>
/// Gets the total number of streams.
/// </summary>
/// <returns>The total streams.</returns>
int SubtitleInfo::totalStreams() {
	return(_streams);
}

/// <summary>
/// Determines if subtitles exist.
/// </summary>
/// <returns>True or false.</returns>
bool SubtitleInfo::isEmpty() {
	return(_language.isEmpty());
}

/// <summary>
/// Resets all local variables.
/// </summary>
void SubtitleInfo::clearAll() {
	_language.clear();
	_stream.clear();
	_codec.clear();
	_streams = 0;
	_chapter = false;
}