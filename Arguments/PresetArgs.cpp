#include "Argument.h"

/// <summary>
/// Sets the cpu preset for the encoder.
/// </summary>
/// <param name="preset">The cpu preset to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VideoPreset(QString preset) {
	return QString(" -preset %1").arg(preset);
}