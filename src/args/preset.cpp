#include "args.hpp"

/// <summary>
/// Sets the cpu preset for the encoder.
/// </summary>
/// <param name="preset">The cpu preset to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::videoPreset(QString preset) {
	return(QString("-preset %1").arg(preset));
}