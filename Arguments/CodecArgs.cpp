#include "Argument.h"

/// <summary>
/// Creates an argument for the video codec.
/// </summary>
/// <param name="codec">The video codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VideoCodec(QString codec) {
	return QString(" -c:v %1").arg(codec);
}

/// <summary>
/// Creates an argument for the audio codec.
/// </summary>
/// <param name="codec">The audio codec to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioCodec(QString codec) {
	return QString(" -c:a %1").arg(codec);
}

/// <summary>
/// Verbatim to AudioCodec, but adds stream specifier.
/// </summary>
/// <param name="codec">The codec to use.</param>
/// <param name="stream">The stream number to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AudioCodecMulti(QString codec, QString stream) {
	return QString(" -c:a:%1 %2").arg(stream).arg(codec);
}

/// <summary>
/// Enables the x265 additional parameters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::x265Params() {
	return QString(" -x265-params ");
}

/// <summary>
/// Limits the threads for an encoding task.
/// </summary>
/// <param name="threads">The number of threads to utilize.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Threads(int threads) {
	return QString(" -threads %1").arg(threads);
}