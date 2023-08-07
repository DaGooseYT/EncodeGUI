#include "args.hpp"

/// <summary>
/// Sets the metadata for subtitle streams.
/// </summary>
/// <param name="stream">Stream number</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleMetadata(int stream) {
	return(QString("-metadata:s:s:%1").arg(stream));
}

/// <summary>
/// Sets the subtitle title for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="title">The contents to be added to the title.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleTitle(QString title) {
	return(QString("title=%2").arg(title));
}

/// <summary>
/// Sets the subtitle language for a specific audio stream.
/// </summary>
/// <param name="stream">The stream file specifier.</param>
/// <param name="lang">The language.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::subtitleLang(QString lang) {
	return(QString("language=%2").arg(lang));
}