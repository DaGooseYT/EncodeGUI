#include "VapourSynth.h"

/// <summary>
/// Sets the VapourSynth plugins to use.
/// </summary>
QString VapourSynth::Plugin(QString path) {
	return QString("core.std.LoadPlugin(\"%1\")\n").arg(path.replace("\\", "\\\\"));
}

/// <summary>
/// Includes required python nodes.
/// </summary>
QString VapourSynth::Include() {
	return QString("# This file was generated using EncodeGUI\n# This script is available to you under the MIT license: Copyright (C) 2022 DaGoose.\n\nfrom vsrife import RIFE\nimport tempfile\nimport muvsfunc as mf\nimport vapoursynth as vs\nfrom vapoursynth import core\n\n");
}

/// <summary>
/// Configures the source video for piping.
/// </summary>
/// <param name="path">The source video file path.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::Input(QString path, QString id) {
	return QString("\nclip = core.lsmas.LWLibavSource(source=\"%1\", cachefile=tempfile.gettempdir() + \"\\%2.lwi\")\n\n").arg(path).replace("\\", "\\\\").arg(id);
}

/// <summary>
/// Enabled scene change detection for frame interpolation.
/// </summary>
/// <param name="threshold">The sensitivity level for the scene change detection.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::SCDetect(QString threshold) {
	return QString("clip = core.misc.SCDetect(clip, threshold=%1)\n").arg(threshold);
}

/// <summary>
/// Concludes the clip for output pipe.
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::ConcludeClip() {
	return QString("clip.set_output()");
}

/// <summary>
/// Adds a new line to the script.
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::NewLine() {
	return QString("\n");
}

/// <summary>
/// Anti-Aliasing (EIDAA)
/// </summary>
/// <returns>String representation of the script.</returns>
QString VapourSynth::AntiA() {
	return QString("clip = mf.ediaa(clip)\n\n");
}