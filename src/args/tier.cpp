#include "../../include/args.hpp"

/// <summary>
/// Sets the tier for x265 encoding.
/// </summary>
/// <param name="tier">The tier index.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Tier(int tier) {
	return QString("no-high-tier=%1").arg(tier);
}