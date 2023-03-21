#include "../../include/args.hpp"

/// <summary>
/// Sets the path to ffmpeg.
/// </summary>
/// <param name="path">The file path to ffmpeg.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::FFMpeg(QString path) {
	return QString("\"%1\"").arg(path);
}

/// <summary>
/// Overrides the output file.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::Override() {
	return QString(" -y");
}

/// <summary>
/// Sets the source video to encode.
/// </summary>
/// <param name="path">The path to the input file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Input(QString path) {
	return QString(" -i \"%1\"").arg(path);
}

/// <summary>
/// Saves the output to a specified destination.
/// </summary>
/// <param name="path">The path to the output file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::Output(QString path) {
	return QString(" \"%1\"").arg(path);
}