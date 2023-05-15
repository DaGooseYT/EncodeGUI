#include "vapoursynth.hpp"

/// <summary>
/// Sets the VapourSynth plugins to use.
/// </summary>
QString VapourSynth::plugin(QString path) {
	return(QString("core.std.LoadPlugin(\"%1\")\n").arg(path.replace(QString("\\"), QString("\\\\"))));
}

/// <summary>
/// Includes required python nodes.
/// </summary>
QString VapourSynth::include() {
	return(QString("# This file was generated using EncodeGUI\n\nfrom vsrife import RIFE\nimport tempfile\nimport muvsfunc as mf\nimport vapoursynth as vs\nfrom vapoursynth import core\n\n"));
}

/// <summary>
/// Configures the source video for piping.
/// </summary>
/// <param name="path">The source video file path.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::input(QString path, QString id) {
	return(QString("\nclip = core.lsmas.LWLibavSource(source=\"%1\", cachefile=tempfile.gettempdir() + \"\\%2.lwi\")\n\n").arg(path).replace(QString("\\"), QString("\\\\")).arg(id));
}

/// <summary>
/// Enabled scene change detection for frame interpolation.
/// </summary>
/// <param name="threshold">The sensitivity level for the scene change detection.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::scDetect(QString threshold) {
	return(QString("clip = core.misc.SCDetect(clip, threshold=%1)\n").arg(threshold));
}

/// <summary>
/// Concludes the clip for output pipe.
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::concludeClip() {
	return(QString("clip.set_output()"));
}

/// <summary>
/// Adds a new line to the script.
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::newLine() {
	return(QString("\n"));
}

/// <summary>
/// Anti-Aliasing (EIDAA)
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::antiA() {
	return(QString("clip = mf.ediaa(clip)\n\n"));
}