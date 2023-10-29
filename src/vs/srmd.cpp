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
/// Enables SRMD super-resolution plugin.
/// </summary>
/// <param name="scale">The upscaling rate factor.</param>
/// <param name="noise">The amount of denoise to apply.</param>
/// <param name="id">The GPU id index to use.</param>
/// <param name="thread">The number of GPU threads to use.</param>
/// <param name="tta">Enables test time augmentation for better results.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::srmd(int scale, int noise, int id, int thread, QString tta) {
	return(QString("clip = core.srmdnv.SRMD(clip, scale=%1, noise=%2, gpu_id=%3, gpu_thread=%4, tta=%5)\n\n").arg(scale).arg(noise).arg(id).arg(thread).arg(tta));
}