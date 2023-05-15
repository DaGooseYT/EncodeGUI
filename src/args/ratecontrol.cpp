#include "args.hpp"

/// <summary>
/// Sets the quality of the video.
/// </summary>
/// <param name="quality">The quality level of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantVideoQuality(int quality) {
	return(QString("-q:v %1").arg(quality));
}

/// <summary>
/// Sets the quality of the audio.
/// </summary>
/// <param name="quality">The quality level of the audio.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantAudioQuality(int quality, QString stream) {
	return(QString("-q:a:%1 %2").arg(stream).arg(quality));
}

/// <summary>
/// Sets the constant rate factor value of the video.
/// </summary>
/// <param name="crf">The constant rate factor value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantRateFactor(int crf) {
	return(QString("-crf %1").arg(crf));
}

/// <summary>
/// Sets the quantization strength of the video.
/// </summary>
/// <param name="strength">The quantizaton strength.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::constantQuantizer(int strength) {
	return(QString("-cq %1").arg(strength));
}

/// <summary>
/// Sets the constant quantization for GPU encoders.
/// </summary>
/// <param name="strength">The quantizaton strength.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::quantizer(int strength) {
	return(QString("-q %1").arg(strength));
}