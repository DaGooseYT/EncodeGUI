#include "../../include/args.hpp"

/// <summary>
/// Adds a timecode to the video for ProRes encoder.
/// </summary>
/// <param name="hour">The number of hour(s).</param>
/// <param name="minute">The number of minute(s).</param>
/// <param name="second">The number of second(s).</param>
/// <param name="millisecond">The number of millisecond(s).</param>
/// <returns>String representation of the argument.</returns>
QString Argument::AddTimecodes(int hour, int minute, int second, int millisecond) {
	return QString(" -timecode %1:%2:%3.%4").arg(hour).arg(minute).arg(second).arg(millisecond);
}