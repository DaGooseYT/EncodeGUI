#include "args.hpp"

/// <summary>
/// Sets the number of B frames.
/// </summary>
/// <param name="bFrame">The number of B frames to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::bFrame(int bFrame) {
	return(QString("-bf %1").arg(bFrame));
}

/// <summary>
/// Sets the number of reference frames.
/// </summary>
/// <param name="refFrame">The number of reference frames to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::referenceFrame(int refFrame) {
	return(QString("-refs %1").arg(refFrame));
}