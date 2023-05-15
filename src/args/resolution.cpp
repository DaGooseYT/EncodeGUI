#include "args.hpp"

/// <summary>
/// Sets the video resolution to the specified value.
/// </summary>
/// <param name="width">The selected width of the video.</param>
/// <param name="height">The selected height of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoResolution(int width, int height) {
	return(QString("scale=%1x%2").arg(width).arg(height));
}

/// <summary>
/// Sets the specified resizing algo.
/// </summary>
/// <param name="algo">The resize algo.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoResizeAlgo(QString algo) {
	return(QString(":flags=%1").arg(algo));
}

/// <summary>
/// Crops the video at a specified point to a specified resolution.
/// </summary>
/// <param name="x">The x location to crop/</param>
/// <param name="y">The y location to crop.</param>
/// <param name="width">The crop width of the video.</param>
/// <param name="height">The crop height of the video.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::crop(int x, int y, int width, int height) {
	return(QString("crop=%1:%2:%3:%4").arg(width).arg(height).arg(x).arg(y));
}