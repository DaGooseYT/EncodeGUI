#include "../../include/subtitleinfo.hpp"

QStringList SubtitleInfo::Language;
QStringList SubtitleInfo::Stream;
QStringList SubtitleInfo::Codec;
int SubtitleInfo::Streams;
bool SubtitleInfo::Chapter;

/// <summary>
/// Sets the subtitle language.
/// </summary>
/// <param name="language">The language.</param>
void SubtitleInfo::SetLanguage(QString language) {
	Language << language;
}

/// <summary>
/// Sets the subtitle codecs.
/// </summary>
/// <param name="codec">The codec.</param>
void SubtitleInfo::SetCodec(QString codec) {
	Codec << codec;
}

/// <summary>
/// Sets the subtitle stream identifier.
/// </summary>
/// <param name="stream">The stream identifier.</param>
void SubtitleInfo::SetStream(QString stream) {
	Stream << stream;
}

/// <summary>
/// Sets the chapters.
/// </summary>
/// <param name="chapter">True or false.</param>
void SubtitleInfo::SetChapter(bool chapter) {
	Chapter = chapter;
}

/// <summary>
/// Gets the language from subtitle list.
/// </summary>
/// <param name="index">The index from the list.</param>
/// <returns>The language.</returns>
QString SubtitleInfo::GetLanguage(int index) {
	return(Language.at(index));
}

/// <summary>
/// Gets the subtitle codec from the the subtitle list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The codec.</returns>
QString SubtitleInfo::GetCodec(int index) {
	return(Codec.at(index));
}

/// <summary>
/// Gets the stream identifier from the subtitle list.
/// </summary>
/// <param name="index">The index from the list.</param>
/// <returns></returns>
QString SubtitleInfo::GetStream(int index) {
	return(Stream.at(index));
}

/// <summary>
/// Gets the chapters.
/// </summary>
/// <returns>True or false.</returns>
bool SubtitleInfo::GetChapter() {
	return(Chapter);
}

/// <summary>
/// Adds a stream to the total.
/// </summary>
void SubtitleInfo::AddStreams() {
	Streams++;
}

/// <summary>
/// Gets the total number of streams.
/// </summary>
/// <returns>The total streams.</returns>
int SubtitleInfo::TotalStreams() {
	return(Streams);
}

/// <summary>
/// Determines if subtitles exist.
/// </summary>
/// <returns>True or false.</returns>
bool SubtitleInfo::IsEmpty() {
	return Language.isEmpty();
}

/// <summary>
/// Resets all local variables.
/// </summary>
void SubtitleInfo::ClearAll() {
	Language.clear();
	Stream.clear();
	Codec.clear();
	Streams = 0;
	Chapter = false;
}