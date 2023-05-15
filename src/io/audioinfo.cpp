#include "audioinfo.hpp"

QStringList AudioInfo::_codec;
QStringList AudioInfo::_language;
QStringList AudioInfo::_sampleRate;
QStringList AudioInfo::_channels;
QStringList AudioInfo::_stream;
int AudioInfo::_streams;

/// <summary>
/// Adds the audio codec to the audio info list.
/// </summary>
/// <param name="codec">The audio codec.</param>
void AudioInfo::setCodec(QString codec) {
	_codec.append(codec);
}

/// <summary>
/// Adds the audio language to the audio info list.
/// </summary>
/// <param name="language">The audio language.</param>
void AudioInfo::setLanguage(QString language) {
	_language.append(language);
}

/// <summary>
/// Adds the audio sample rate to the audio info list.
/// </summary>
/// <param name="sampleRate">The audio sample rate.</param>
void AudioInfo::setSampleRate(QString sampleRate) {
	_sampleRate.append(sampleRate);
}

/// <summary>
/// Adds the audio channels to the audio info list.
/// </summary>
/// <param name="channels">The number of audio channels.</param>
void AudioInfo::setChannels(QString channels) {
	_channels.append(channels);
}

/// <summary>
/// Adds the audio strream number to the audio info list.
/// </summary>
/// <param name="stream">The audio stream number.</param>
void AudioInfo::setStream(QString stream) {
	_stream.append(stream);
}

/// <summary>
/// Gets the audio codec from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns>The audio codec.</returns>
QString AudioInfo::getCodec(int index) {
	return(_codec.at(index));
}

/// <summary>
/// Gets the audio language from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns></returns>
QString AudioInfo::getLanguage(int index) {
	return(_language.at(index));
}

/// <summary>
/// Gets the audio sample rate from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns></returns>
QString AudioInfo::getSampleRate(int index) {
	return(_sampleRate.at(index));
}

/// <summary>
/// Gets the audio channels from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns></returns>
QString AudioInfo::getChannels(int index) {
	return(_channels.at(index));
}

/// <summary>
/// Gets the audio stream identifier from the audio info list.
/// </summary>
/// <param name="index">The index to get from the list.</param>
/// <returns></returns>
QString AudioInfo::getStream(int index) {
	return(_stream.at(index));
}

/// <summary>
/// Gets the total number of audio streams counted.
/// </summary>
/// <returns>The total number of streams.</returns>
int AudioInfo::totalStreams() {
	return(_streams);
}

/// <summary>
/// Adds an audio stream to info.
/// </summary>
void AudioInfo::addStream() {
	_streams++;
}

/// <summary>
/// Resets all private variables.
/// </summary>
void AudioInfo::clearAll() {
	_codec.clear();
	_language.clear();
	_sampleRate.clear();
	_channels.clear();
	_stream.clear();
	_streams = 0;
}