#include "VapourSynth.h"

/// <summary>
/// Converts the video to the RGB color space.
/// </summary>
/// <param name="matrix">The input color matrix.</param>
/// <param name="transfer">The input color transfer.</param>
/// <param name="primaries">The input color primaries.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::RGB(QString matrix, QString transfer, QString primaries) {
	return QString("clip = core.resize.Lanczos(clip, format=vs.RGBS, matrix_in_s=\"%1\", transfer_in_s=\"%2\", primaries_in_s=\"%3\")\n\n").arg(matrix).arg(transfer).arg(primaries);
}

/// <summary>
/// Sets both the input and output color spaces.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <param name="matrix_in">The input color matrix.</param>
/// <param name="transfer_in">The input color transfer.</param>
/// <param name="primaries_in">The input color primaries.</param>
/// <param name="matrix">The output color matrix.</param>
/// <param name="transfer">The output color transfer.</param>
/// <param name="primaries">The output color primaries.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::ColorsInOut(QString format, QString matrix_in, QString transfer_in, QString primaries_in, QString matrix, QString transfer, QString primaries) {
	return QString("clip = core.resize.Lanczos(clip, format=vs.%1, matrix_s=\"%2\", transfer_s=\"%3\", primaries_s=\"%4\", matrix_in_s=\"%5\", transfer_in_s=\"%6\", primaries_in_s=\"%7\")\n\n")
		.arg(format).arg(matrix).arg(transfer).arg(primaries).arg(matrix_in).arg(transfer_in).arg(primaries_in);
}

/// <summary>
/// Sets the output color spaces, assuming the inputs have already been defined.
/// </summary>
/// <param name="format">The pixel format to use.</param>
/// <param name="matrix">The output color matrix.</param>
/// <param name="transfer">The output color transfer.</param>
/// <param name="primaries">The output color primaries.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::ColorsOut(QString format, QString matrix, QString transfer, QString primaries) {
	return QString("clip = core.resize.Lanczos(clip, format=vs.%1, matrix_s=\"%2\", transfer_s=\"%3\", primaries_s=\"%4\")\n\n")
		.arg(format).arg(matrix).arg(transfer).arg(primaries);
}