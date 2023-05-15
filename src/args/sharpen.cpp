#include "args.hpp"

/// <summary>
/// Sharpens the video according to user specifications.
/// </summary>
/// <param name="radius">The sharpening radius value.</param>
/// <param name="strength">The sharpening strength value.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::sharpenVideo(QString radius, QString strength) {
	return(QString("unsharp=%1:%2").arg(radius).arg(strength));
}