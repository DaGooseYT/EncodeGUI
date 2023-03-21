#include "../../include/vapoursynth.hpp"

/// <summary>
/// Enables the use of Waifu2x super resolution plugin.
/// </summary>
/// <param name="noise">The noise level.</param>
/// <param name="scale">The scaling factor.</param>
/// <param name="model">The model index to use.</param>
/// <param name="id">The GPU id index.</param>
/// <param name="thread">The number of GPU threads.</param>
/// <param name="precision">The color precision.</param>
/// <returns>String representation of the script.</returns>
QString VapourSynth::Waifu2x(int noise, int scale, int model, int id, int thread, int precision, bool dual, int gpu1, int gpu2) {
	if (!dual)
		return QString("clip = core.w2xnvk.Waifu2x(clip, noise=%1, scale=%2, model=%3, tile_size=0, gpu_id=%4, gpu_thread=%5, precision=%6)\n\n").arg(noise).arg(scale).arg(model).arg(id).arg(thread).arg(precision);
	else
		return QString("even = core.std.SelectEvery(core.w2xnvk.Waifu2x(clip, noise=%1, scale=%2, model=%3, tile_size=0, gpu_id=%4, gpu_thread=%5, precision=%6), cycle=2, offsets=0)\nodd = core.std.SelectEvery(core.w2xnvk.Waifu2x(clip, noise=%1, scale=%2, model=%3, tile_size=0, gpu_id=%7, gpu_thread=%5, precision=%6), cycle=2, offsets=1)\nclip = core.std.Interleave([even, odd])\n\n").arg(noise).arg(scale).arg(model).arg(gpu1).arg(thread).arg(precision).arg(gpu2);
}