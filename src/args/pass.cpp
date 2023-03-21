#include "../../include/args.hpp"

/// <summary>
/// The number of passes for the encoder.
/// </summary>
/// <param name="pass">The pass number.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Pass(int pass) {
	return QString(" -pass %1").arg(pass);
}