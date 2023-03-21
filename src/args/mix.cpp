#include "../../include/args.hpp"

/// <summary>
/// Set the number of audio channels to be processed in.
/// </summary>
/// <param name="channels">The number of channels.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::DownMix(double channels) {
	return QString(" -ac %1").arg(channels);
}