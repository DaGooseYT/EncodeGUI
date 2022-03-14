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
/// Sets the number of channels in the audio stream.
/// </summary>
/// <param name="channels">The number of audio channels</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioChannels(QString channels, QString stream) {
	return QString(" -ac:%1 %2").arg(stream).arg(channels);
}