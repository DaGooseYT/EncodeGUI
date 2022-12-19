#include "Argument.h"

/// <summary>
/// Enables FFMpeg filters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::EnableFilters() {
	return QString(" -filter:v \"");
}

/// <summary>
/// Adds a comma to seperate video filters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::AddComma() {
	return QString(", ");
}

/// <summary>
/// Redirects the log file for 2 pass encoding.
/// </summary>
/// <param name="path">The path to save the logs.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::PassLogFile(QString path) {
	return QString(" -passlogfile \"%1\"").arg(path);
}

/// <summary>
/// Adds a colin to an argument.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::AddColin() {
	return QString(":");
}

/// <summary>
/// Concludes the filters list by adding a quotation mark.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::ConcludeFilters() {
	return QString("\"");
}

/// <summary>
/// Applies the YADIF deinterlacing filter.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::Deinterlace() {
	return QString("yadif");
}

/// <summary>
/// Applies the YADIF (CUDA) deinterlacing filter.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::DeinterlaceCUDA() {
	return QString("yadif_cuda");
}