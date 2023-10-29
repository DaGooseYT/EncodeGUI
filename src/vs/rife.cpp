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
/// Configures RIFE in it's CUDA implementation.
/// </summary>
/// <param name="device">The type of device to use for frame rendering.</param>
/// <param name="multi">Sets the interpolation multiplication factor.</param>
/// <param name="scale">Sets the interpolation mode on the basis of the video's resolution.</param>
/// <param name="id">Sets the GPU id index.</param>
/// <param name="fp">Sets the color precision.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::rifeCuda(int id, double model, int num, int den, double scale, QString sc, QString trt) {
	if (model == 4.0)
		return(QString("clip = RIFE(clip, device_index=%1, model=%2, fps_num=%3, fps_den=%4, scale=%5, ensemble=True, sc=%6)\n\n").arg(id).arg(model).arg(num).arg(den).arg(scale).arg(sc));
	else
		return(QString("clip = RIFE(clip, device_index=%1, cuda_graphs=True, model=%2, fps_num=%3, fps_den=%4, scale=%5, ensemble=True, sc=%6)\n\n").arg(id).arg(model).arg(num).arg(den).arg(scale).arg(sc));
}
#endif

/// <summary>
/// Configures RIFE in it's NCNN implementation.
/// </summary>
/// <param name="model">Sets the model index to use.</param>
/// <param name="id">Sets the GPU id index to use.</param>
/// <param name="thread">Sets the number of GPU threads to use.</param>
/// <param name="tta">Enables test time augmentation for better interpolation quality.</param>
/// <param name="uhd">Enables or disabled UHD mode for better frame rendering.</param>
/// <param name="sc">Enables or disables scene change detection.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::rifeNcnn(int model, int id, int thread, QString tta, QString uhd, QString sc) {
	return(QString("clip = core.rife.RIFE(clip, model=%1, gpu_id=%2, gpu_thread=%3, tta=%4, uhd=%5, sc=%6)\n\n").arg(model).arg(id).arg(thread).arg(tta).arg(uhd).arg(sc));
}

/// <summary>
/// 
/// </summary>
/// <param name="model">Sets the model index to use.</param>
/// <param name="id">Sets the GPU id index to use.</param>
/// <param name="thread">Sets the number of GPU threads to use.</param>
/// <param name="num"></param>
/// <param name="den"></param>
/// <param name="tta">Enables test time augmentation for better interpolation quality.</param>
/// <param name="uhd">Enables or disabled UHD mode for better frame rendering.</param>
/// <param name="sc">Enables or disables scene change detection.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::rifeNcnnNew(int model, int id, int thread, int num, int den, QString tta, QString uhd, QString sc) {
	return(QString("clip = core.rife.RIFE(clip, model=%1, gpu_id=%2, gpu_thread=%3, fps_num=%4, fps_den=%5, tta=%6, uhd=%7, sc=%8)\n\n").arg(model).arg(id).arg(thread).arg(num).arg(den).arg(tta).arg(uhd).arg(sc));
}