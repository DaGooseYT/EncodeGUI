/****************************************************************************
 * Copyright (C) 2022 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#include "vapoursynth.hpp"

#ifdef Q_OS_WINDOWS
/// <summary>
/// Configures SVPFlow for if you don't know how to write the parameters.
/// </summary>
/// <param name="useGPU">Determines if using the GPU for frame rendering.</param>
/// <param name="id">The GPU id to use for frame rendering, if using the GPU.</param>
/// <param name="shader">The SVP shader to use for interpolation.</param>
/// <param name="mask">Sets the mask for SVPFlow.</param>
/// <param name="mode">The frame interpolation mode to use.</param>
/// <param name="num">The frame rate numerator.</param>
/// <param name="den">The frame rate denominator.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::svpFlowNoob(QString useGPU, int id, int shader, int mask, int mode, int num, int den) {
	QString super, analyse, smooth, complete;

	if (useGPU.contains(QString("True"))) {
		super = QString("{scale:{up:2},gpu:1}");
		analyse = QString("{gpu:1,vectors:3,block:{w:16,h:16,overlap:2},main:{search:{distance:0,coarse:{distance:-10,bad:{sad:2000}}}},refine:[{thsad:250}]}");
		smooth = QString("{rate:{num:%1,den:%2,abs:true},algo:%3,gpuid:%4%4,mask:{area:%5},scene:{mode:%6,blend:false}}").arg(num).arg(den).arg(shader).arg(id).arg(mask).arg(mode);
	}
	else {
		super = QString("{scale:{up:2},gpu:0}");
		analyse = QString("{gpu:0,main:{search:{coarse:{distance:0},type:4}},refine:[{thsad:250}]}");
		smooth = QString("{rate:{num:%1,den:%2,abs:true},algo:%3,mask:{area:%4},scene:{mode:%5,blend:false}}").arg(num).arg(den).arg(shader).arg(mask).arg(mode);
	}

	complete = QString("clip = clip.resize.Bicubic(format=vs.YUV420P8)\n\n") +
		QString("super_params=\"%1\"\n").arg(super) +
		QString("analyse_params=\"%1\"\n").arg(analyse) +
		QString("smoothfps_params=\"%1\"\n\n").arg(smooth) +
		QString("super = core.svp1.Super(clip, super_params)\n") +
		QString("vectors = core.svp1.Analyse(super[\"clip\"], super[\"data\"], clip, analyse_params)\n") +
		QString("clip = core.svp2.SmoothFps(clip, super[\"clip\"], super[\"data\"], vectors[\"clip\"], vectors[\"data\"], smoothfps_params)\n") +
		QString("clip = core.std.AssumeFPS(clip, fpsnum=%1, fpsden=%2)\n\n").arg(num).arg(den);

	return(complete);
}

/// <summary>
/// Configures SVPFlow for use with custom defined parameters.
/// </summary>
/// <param name="super">The super parameters for SVPFlow.</param>
/// <param name="analyse">The analyse parameters for SVPFlow.</param>
/// <param name="smooth">The smooth parameters for SVPFlow.</param>
/// <param name="num">The frame rate numerator.</param>
/// <param name="den">The frame rate denominator.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::svpFlow(QString super, QString analyse, QString smooth, int num, int den) {
	QString complete(QString("clip = clip.resize.Bicubic(format=vs.YUV420P8)\n\n") +
		QString("super_params=\"%1\"\n").arg(super) +
		QString("analyse_params=\"%1\"\n").arg(analyse) +
		QString("smoothfps_params=\"%1\"\n\n").arg(smooth) +
		QString("super = core.svp1.Super(clip, super_params)\n") +
		QString("vectors = core.svp1.Analyse(super[\"clip\"], super[\"data\"], clip, analyse_params)\n") +
		QString("clip = core.svp2.SmoothFps(clip, super[\"clip\"], super[\"data\"], vectors[\"clip\"], vectors[\"data\"], smoothfps_params)\n") +
		QString("clip = core.std.AssumeFPS(clip, fpsnum=%1, fpsden=%2)\n\n").arg(num).arg(den));

	return(complete);
}
#endif