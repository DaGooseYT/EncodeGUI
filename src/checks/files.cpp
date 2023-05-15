#include "checks.hpp"

/// <summary>
/// Ensures the path to FFMpeg exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkFFMpeg(QString path) {
	return(fileCheck(path));
}

/// <summary>
/// Ensures the path to FFProbe exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkFFProbe(QString path) {
	return(fileCheck(path));
}

/// <summary>
/// Ensures the path to VsPipe exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkVsPipe(QString path) {
	return(fileCheck(path));
}

/// <summary>
/// Ensures the path to the VapourSynth script exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkVsScript(QString path) {
	return(fileCheck(path));
}

/// <summary>
/// Ensures the path to VapourSynth directory exists.
/// </summary>
/// <param name="path">The directory path.</param>
/// <returns>True or false.</returns>
bool Checks::checkVapourSynth(QString path) {
	if (QDir(path).exists())
		return(true);
	else
		return(false);
}

/// <summary>
/// Ensures the path to the source video exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkInputExists(QString path) {
	return(fileCheck(path));
}

/// <summary>
/// Ensures the source video is defined.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkInput(QString input) {
	if (!input.isEmpty()) 
		return(true);
	else
		return(false);
}

/// <summary>
/// Ensures the output video path is defined.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkOutput(QString output) {
	if (!output.isEmpty())
		return(true);
	else
		return(false);
}

/// <summary>
/// Checks to see if the output path already exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::checkOutputOverwrite(QString path) {
	return(fileCheck(path));
}

/// <summary>
/// Checks a file to see if it exists.
/// </summary>
/// <param name="path">The file path.</param>
/// <returns>True or false.</returns>
bool Checks::fileCheck(QString path) {
	if (QFile::exists(path))
		return(true);
	else
		return(false);
}