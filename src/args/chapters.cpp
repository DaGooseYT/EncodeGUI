#include "args.hpp"

/// <summary>
/// Disables video chapters.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::mapChapters() {
	return(QString("-map_chapters -1"));
}