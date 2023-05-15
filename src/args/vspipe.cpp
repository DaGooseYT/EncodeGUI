#include "args.hpp"

/// <summary>
/// Enables vapoursynth script input.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::vs() {
	return(QString("-f vapoursynth"));
}

/// <summary>
/// Configures the pipe for vspipe.exe.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::vsPipe() {
	return(QString("-c y4m"));
}