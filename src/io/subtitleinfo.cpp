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