#include "VapourSynth.h"

/// <summary>
/// Configures RIFE in it's CUDA implementation.
/// </summary>
/// <param name="device">The type of device to use for frame rendering.</param>
/// <param name="multi">Sets the interpolation multiplication factor.</param>
/// <param name="scale">Sets the interpolation mode on the basis of the video's resolution.</param>
/// <param name="id">Sets the GPU id index.</param>
/// <param name="fp">Sets the color precision.</param>
/// <returns>String representation of the argument.</returns>
QString VapourSynth::RIFECuda(QString device, int multi, double scale, int id, QString fp) {
	return QString("clip = RIFE(clip, multi=%1, scale=%2, device_type='%3', device_index=%4, fp16=%5)\n\n").arg(multi).arg(scale).arg(device).arg(id).arg(fp);
}

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
QString VapourSynth::RIFENcnn(int model, int id, int thread, QString tta, QString uhd, QString sc) {
	return QString("clip = core.rife.RIFE(clip, model=%1, multiplier=2, gpu_id=%2, gpu_thread=%3, tta=%4, uhd=%5, sc=%6)\n\n").arg(model).arg(id).arg(thread).arg(tta).arg(uhd).arg(sc);
}