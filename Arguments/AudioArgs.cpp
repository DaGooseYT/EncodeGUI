#include "Argument.h"

/// <summary>
/// Sets the sample rate for an audio stream.
/// </summary>
/// <param name="rate">The sample rate of the audio.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioRate(QString rate, QString stream) {
	return QString(" -ar:%1 %2").arg(stream).arg(rate);
}

/// <summary>
/// Sets the audio title for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="title">The contents to be added to the title.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioTitle(QString stream, QString title) {
	return QString(" -metadata:s:a:%1 title=\"%2\"").arg(stream).arg(title);
}

/// <summary>
/// Sets the audio language for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="lang">The language.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioLang(QString stream, QString lang) {
	return QString(" -metadata:s:a:%1 language=%2").arg(stream).arg(lang);
}

/// <summary>
/// Sets the number of channels in the audio stream.
/// </summary>
/// <param name="channels">The number of audio channels</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioChannels(QString channels, QString stream) {
	return QString(" -ac:%1 %2").arg(stream).arg(channels);
}