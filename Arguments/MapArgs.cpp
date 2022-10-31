#include "Argument.h"

/// <summary>
/// Maps a stream to a media file.
/// </summary>
/// <param name="type">The stream type.</param>
/// <param name="s1">Stream 1 selection.</param>
/// <param name="s2">Stream 2 selection.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::MapVideo(QString type, QString s1, int s2) {
	return QString(" -map %1:%2:%3").arg(s1).arg(type).arg(s2);
}

/// <summary>
/// Maps a stream to a media file.
/// </summary>
/// <param name="type">The type of stream.</param>
/// <param name="s1">Stream specifier.</param>
/// <returns>String representation of argument.</returns>
QString Argument::MapMux(QString type, int s1) {
	return QString(" -map %1:%2").arg(type).arg(s1);
}

/// <summary>
/// Maps all of a particular stream in a video container. 
/// </summary>
/// <param name="type">The stream type to target.</param>
/// <param name="s1">Stream one identifier.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::MapAll(QString type, QString s1) {
	return QString(" -map %1:%2").arg(s1).arg(type);
}