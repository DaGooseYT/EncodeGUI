#include "args.hpp"

/// <summary>
/// Sets the bitrate for the video.
/// </summary>
/// <param name="bitrate">The bitrate value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoBitrate(int bitrate) {
	return(QString("-b:v %1k").arg(bitrate));
}

/// <summary>
/// Sets the bitrate for the audio.
/// </summary>
/// <param name="bitrate">The bitrate value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::audioBitrate(int bitrate, QString stream) {
	return(QString("-b:a:%1 %2k").arg(stream).arg(bitrate));
}

/// <summary>
/// Sets the quality factor for VP9.
/// </summary>
/// <param name="quality"></param>
/// <returns>String representation of the argument.</returns>
QString Argument::vp9Quality(QString quality) {
	return(QString("-quality %1").arg(quality));
}

/// <summary>
/// 
/// </summary>
/// <param name="bitrate"></param>
/// <returns></returns>
QString Argument::buffer(int bitrate) {
	return(QString("vbv-bufsize=%1:vbv-maxrate=%2").arg(bitrate * 2).arg(bitrate + 2000));
}