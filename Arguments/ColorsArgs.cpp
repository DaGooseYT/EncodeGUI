#include "Argument.h"

/// <summary>
/// ProRes colors video usablility information.
/// </summary>
/// <param name="matrix">The color matrix to use.</param>
/// <param name="transfer">The color transfer to use.</param>
/// <param name="primaries">The color primaries to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Colors(QString matrix, QString transfer, QString primaries) {
	return QString(" -bsf:v prores_metadata=colorspace=%1:color_trc=%2:color_primaries=%3").arg(matrix).arg(transfer).arg(primaries);
}

/// <summary>
/// The pixel format for the video to be processed in.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::PixelFormat(QString format) {
	return QString(" -pix_fmt %1").arg(format);
}