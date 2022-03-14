#include "Argument.h"

/// <summary>
/// Configures the pipe for VSPipe.exe.
/// </summary>
/// <param name="vspipe">The path to VSPipe.exe.</param>
/// <param name="vsscript">The path to the VapourSynth script file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::VSPipe(QString vspipe, QString vsscript) {
	return QString("\"%1\" -c y4m \"%2\" -").arg(vspipe).arg(vsscript);
}