#include "../../include/args.hpp"

/// <summary>
/// Set the tune for the video.
/// </summary>
/// <param name="tune">The selected tune.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VideoTune(QString tune) {
	return QString(" -tune %1").arg(tune);
}