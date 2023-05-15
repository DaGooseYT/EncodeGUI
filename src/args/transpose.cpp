#include "args.hpp"

/// <summary>
/// Rotates the video to a specified degree.
/// </summary>
/// <param name="transpose">The transpose value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::transposeVideo(int transpose) {
	return(QString("transpose=%1").arg(transpose));
}

/// <summary>
/// Flips the video in a specified direction.
/// </summary>
/// <param name="flip">The flip direction.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::flipVideo(QString flip) {
	return(QString("%1flip").arg(flip));
}

/// <summary>
/// Disabled the auto rotate feature in FFMpeg.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::noAutoRotate() {
	return(QString("-noautorotate"));
}