#include "Argument.h"

/// <summary>
/// Enables HDR10 for x265.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::HDR10Opt() {
	return QString("hdr-opt=1:repeat-headers=1");
}

/// <summary>
/// Adds the master display info for HDR10.
/// </summary>
/// <param name="display">The master display parameters.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::MasterDisplay(QString display) {
	return QString("master-display=%1").arg(display);
}

/// <summary>
/// Sets the color video usability info for HDR10.
/// </summary>
/// <param name="matrix">The color matrix to use.</param>
/// <param name="transfer">The color transfer to use.</param>
/// <param name="primaries">The color primaries to use.</param>
/// <param name="range">The color range to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Colors(QString matrix, QString transfer, QString primaries, QString range) {
	return QString("colormatrix=%1:transfer=%2:colorprim=%3:range=%4").arg(matrix).arg(transfer).arg(primaries).arg(range);
}

/// <summary>
/// Set the maximum/minimum light content level for HDR10.
/// </summary>
/// <param name="cll">Maximum luminance.</param>
/// <param name="fall">Minimum luminance.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::MaxCllFall(int cll, int fall) {
	return QString("max-cll=%1,%2").arg(cll).arg(fall);
}

/// <summary>
/// Adds HDR10+ dynamic metadata.
/// </summary>
/// <param name="path">The path to the metadata file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::HDRPlus(QString path) {
	return QString("dhdr10-info=\"'%1'\"").arg(path);
}