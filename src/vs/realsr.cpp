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

/// <summary>
/// Enables real-world super-resolution plugin.
/// </summary>
/// <param name="id">The GPU id index to use.</param>
/// <param name="thread">The number of GPU threads to use.</param>
/// <param name="tta">Enables test time augmentation for better results.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::realSR(int id, int thread, QString tta, bool dual, int gpu1, int gpu2) {
	if (!dual)
		return(QString("clip = core.rsnv.RealSR(clip, gpu_id=%1, gpu_thread=%2, tta=%3)\n\n").arg(id).arg(thread).arg(tta));
	else
		return(QString("even = core.std.SelectEvery(core.rsnv.RealSR(clip, gpu_id=%1, gpu_thread=%2, tta=%3), cycle=2, offsets=0)\nodd = core.std.SelectEvery(core.rsnv.RealSR(clip, gpu_id=%4, gpu_thread=%2, tta=%3), cycle=2, offsets=1)\nclip = core.std.Interleave([even, odd])\n\n").arg(gpu1).arg(thread).arg(tta).arg(gpu2));
}