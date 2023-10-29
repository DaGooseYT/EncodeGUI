/****************************************************************************
 * Copyright (C) 2022 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "args.hpp"

/// <summary>
/// Enables FFMpeg filters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::enableFilters() {
	return(QString("-filter:v"));
}

/// <summary>
/// Sets source video parameter.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::input() {
	return(QString("-i"));
}

/// <summary>
/// Overrides the output file.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::override() {
	return(QString("-y"));
}

/// <summary>
/// Adds a comma to seperate video filters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::addComma() {
	return(QString(","));
}

/// <summary>
/// Redirects the log file for 2 pass encoding.
/// </summary>
/// <param name="path">The path to save the logs.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::passLogFile() {
	return(QString("-passlogfile"));
}

/// <summary>
/// Sets VP9 encoder to use all CPU threads.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::allThreads() {
	return(QString("-row-mt 1"));
}

/// <summary>
/// Adds a colin to an argument.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::addColin() {
	return(QString(":"));
}

/// <summary>
/// Concludes the filters list by adding a quotation mark.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::concludeFilters() {
	return(QString("\""));
}

/// <summary>
/// Applies the YADIF deinterlacing filter.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::deinterlace() {
	return(QString("yadif"));
}

/// <summary>
/// Sets the destination for the x265 stats file in 2 pass encoding.
/// </summary>
/// <param name="path">Tempfile path.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::statsFile(QString path) {
	#ifdef Q_OS_WINDOWS
	return(QString("pass=1:stats='%2\\x265.log'").arg(path));
	#endif
	#ifdef Q_OS_DARWIN
	return(QString("pass=1:stats='%2/x265.log'").arg(path));
	#endif
}

/// <summary>
/// Applies the YADIF (CUDA) deinterlacing filter.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::deinterlaceCUDA() {
	return(QString("yadif_cuda"));
}

/// <summary>
/// Sets fast first pass for x265.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::setFastPass() {
	return(QString("no-slow-firstpass=1"));
}

/// <summary>
/// Adds tag for Apple "industry standard" HEVC videos.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::appleTag() {
	return(QString("-tag:v hvc1"));
}

/// <summary>
/// Sets empty output path for 2 pass encoding.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::nullPath() {
	return(QString("-f NULL nul"));
}

/// <summary>
/// Writes string metadata to the video file.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::videoMetadata() {
	return(QString("-metadata:g"));
}

/// <summary>
/// Writes string metadata to the video file.
/// </summary>
/// <param name="str">The string to write.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::encoder(QString str) {
	return(QString("encoding_tool=%1").arg(str));
}