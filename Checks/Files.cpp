#include "Checks.h"

/// <summary>
/// Ensures the path to FFMpeg exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckFFMpeg(QString path) {
	return FileCheck(path);
}

/// <summary>
/// Ensures the path to FFProbe exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckFFProbe(QString path) {
	return FileCheck(path);
}

/// <summary>
/// Ensures the path to VsPipe exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckVsPipe(QString path) {
	return FileCheck(path);
}

/// <summary>
/// Ensures the path to the VapourSynth script exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckVsScript(QString path) {
	return FileCheck(path);
}

/// <summary>
/// Ensures the path to VapourSynth directory exists.
/// </summary>
/// <param name="path">The directory path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckVapourSynth(QString path) {
	QDir dir(path);
	
	if (dir.exists()) {
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// Ensures the path to the source video exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckInputExists(QString path) {
	return FileCheck(path);
}

/// <summary>
/// Ensures the source video is defined.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckInput(QString input) {
	if (!input.isEmpty()) {
		return true;
	}
	else {
		return false;
	}
}

/// <summary>
/// Ensures the output video path is defined.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckOutput(QString output) {
	if (!output.isEmpty())
		return true;
	else
		return false;
}

/// <summary>
/// Checks to see if the output path already exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::CheckOutputOverwrite(QString path) {
	return FileCheck(path);
}

/// <summary>
/// Checks a file to see if it exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::FileCheck(QString path) {
	if (QFile::exists(path))
		return true;
	else
		return false;
}