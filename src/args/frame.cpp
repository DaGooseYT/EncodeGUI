#include "../../include/args.hpp"

/// <summary>
/// Sets the number of B frames.
/// </summary>
/// <param name="bframe">The number of B frames to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::BFrame(int bframe) {
	return QString(" -bf %1").arg(bframe);
}

/// <summary>
/// Sets the number of reference frames.
/// </summary>
/// <param name="refFrame">The number of reference frames to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::ReferenceFrame(int refFrame) {
	return QString(" -refs %1").arg(refFrame);
}