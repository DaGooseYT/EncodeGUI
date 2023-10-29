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

#include "encodegui.hpp"

QString EncodeGUI::checkEnviornment() {
	#ifdef Q_OS_WINDOWS
	// ssl
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libssl-1_1-x64.dll"))).exists()) return(QString("libssl-1_1-x64.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libcrypto-1_1-x64.dll"))).exists()) return(QString("libcrypto-1_1-x64.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\tls\\qopensslbackend.dll"))).exists()) return(QString("qopensslbackend.dll"));

	// lib
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\avcodec-60.dll"))).exists()) return(QString("avcodec-60.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\avdevice-60.dll"))).exists()) return(QString("avdevice-60.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\avfilter-9.dll"))).exists()) return(QString("avfilter-9.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\avformat-60.dll"))).exists()) return(QString("avformat-60.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\avutil-58.dll"))).exists()) return(QString("avutil-58.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\ffmpeg.exe"))).exists()) return(QString("ffmpeg.exe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\ffprobe.exe"))).exists()) return(QString("ffprobe.exe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\postproc-57.dll"))).exists()) return(QString("postproc-57.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\swresample-4.dll"))).exists()) return(QString("swresample-4.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\swscale-7.dll"))).exists()) return(QString("swscale-7.dll"));

	// vs
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\_ctypes.pyd"))).exists()) return(QString("_ctypes.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\_multiprocessing.pyd"))).exists()) return(QString("_multiprocessing.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\_overlapped.pyd"))).exists()) return(QString("_overlapped.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\_socket.pyd"))).exists()) return(QString("_socket.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\libffi-7.dll"))).exists()) return(QString("libffi-7.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\portable.vs"))).exists()) return(QString("portable.vs"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\python310.dll"))).exists()) return(QString("python310.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\python310.zip"))).exists()) return(QString("python310.zip"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\select.pyd"))).exists()) return(QString("select.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\unicodedata.pyd"))).exists()) return(QString("unicodedata.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vapoursynth.cp310-win_amd64.pyd"))).exists()) return(QString("vapoursynth.cp310-win_amd64.pyd"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vapoursynth.dll"))).exists()) return(QString("vapoursynth.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vspipe.exe"))).exists()) return(QString("vspipe.exe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsscript.dll"))).exists()) return(QString("vsscript.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vapoursynth64\\coreplugins\\miscfilters.dll"))).exists()) return(QString("miscfilters.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\liblsmashsource.dll"))).exists()) return(QString("liblsmashsource.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libeedi2.dll"))).exists()) return(QString("libeedi2.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\librife.dll"))).exists()) return(QString("librife.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\librealsrnv.dll"))).exists()) return(QString("librealsrnv.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libwaifu2x.dll"))).exists()) return(QString("libwaifu2x.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libsvpflow.1.dll"))).exists()) return(QString("libsvpflow.1.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\libsvpflow.2.dll"))).exists()) return(QString("libsvpflow.2.dll"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v4.6\\flownet.bin"))).exists()) return(QString("RIFE model v4.6"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v4.6\\flownet.param"))).exists()) return(QString("RIFE model v4.6"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v4\\flownet.bin"))).exists()) return(QString("RIFE model v4.0"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v4\\flownet.param"))).exists()) return(QString("RIFE model v4.0"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v3.1\\flownet.bin"))).exists()) return(QString("RIFE model v3.1"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v3.1\\flownet.param"))).exists()) return(QString("RIFE model v3.1"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v3.1\\contextnet.bin"))).exists()) return(QString("RIFE model v3.1"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v3.1\\contextnet.param"))).exists()) return(QString("RIFE model v3.1"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v3.1\\fusionnet.bin"))).exists()) return(QString("RIFE model v3.1"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v3.1\\fusionnet.param"))).exists()) return(QString("RIFE model v3.1"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.4\\flownet.bin"))).exists()) return(QString("RIFE model v2.4"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.4\\flownet.param"))).exists()) return(QString("RIFE model v2.4"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.4\\contextnet.bin"))).exists()) return(QString("RIFE model v2.4"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.4\\contextnet.param"))).exists()) return(QString("RIFE model v2.4"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.4\\fusionnet.bin"))).exists()) return(QString("RIFE model v2.4"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.4\\fusionnet.param"))).exists()) return(QString("RIFE model v2.4"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.3\\flownet.bin"))).exists()) return(QString("RIFE model v2.3"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.3\\flownet.param"))).exists()) return(QString("RIFE model v2.3"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.3\\contextnet.bin"))).exists()) return(QString("RIFE model v2.3"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.3\\contextnet.param"))).exists()) return(QString("RIFE model v2.3"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.3\\fusionnet.bin"))).exists()) return(QString("RIFE model v2.3"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v2.3\\fusionnet.param"))).exists()) return(QString("RIFE model v2.3"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v1.8\\flownet.bin"))).exists()) return(QString("RIFE model v1.8"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v1.8\\flownet.param"))).exists()) return(QString("RIFE model v1.8"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v1.8\\contextnet.bin"))).exists()) return(QString("RIFE model v1.8"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v1.8\\contextnet.param"))).exists()) return(QString("RIFE model v1.8"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v1.8\\fusionnet.bin"))).exists()) return(QString("RIFE model v1.8"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models\\rife-v1.8\\fusionnet.param"))).exists()) return(QString("RIFE model v1.8"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-realsr\\realsr-x4.bin"))).exists()) return(QString("RealSR models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-realsr\\realsr-x4.param"))).exists()) return(QString("RealSR models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise0_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise0_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise0_scale2.0x_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise0_scale2.0x_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise1_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise1_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise1_scale2.0x_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise1_scale2.0x_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise2_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise2_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise2_scale2.0x_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise2_scale2.0x_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise3_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise3_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise3_scale2.0x_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\noise3_scale2.0x_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\scale2.0x_model.bin"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-cunet\\scale2.0x_model.param"))).exists()) return(QString("CUNET models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise0_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise0_scale2.0x_model.param"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise1_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise1_scale2.0x_model.param"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise2_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise2_scale2.0x_model.param"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise3_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\noise3_scale2.0x_model.param"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\scale2.0x_model.bin"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_anime_style_art_rgb\\scale2.0x_model.param"))).exists()) return(QString("Upconv7 anime models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise0_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise0_scale2.0x_model.param"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise1_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise1_scale2.0x_model.param"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise2_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise2_scale2.0x_model.param"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise3_scale2.0x_model.bin"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\noise3_scale2.0x_model.param"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\scale2.0x_model.bin"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\plugins\\models-upconv_7_photo\\scale2.0x_model.param"))).exists()) return(QString("Upconv7 photo models"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\__init__.py"))).exists()) return(QString("vsutil"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\_metadata.py"))).exists()) return(QString("_metadata.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\clips.py"))).exists()) return(QString("clips.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\func.py"))).exists()) return(QString("func.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\info.py"))).exists()) return(QString("info.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\py.typed"))).exists()) return(QString("py.typed"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsutil\\types.py"))).exists()) return(QString("types.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsrife\\__init__.py"))).exists()) return(QString("vsrife"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsrife\\flownet_v4.6.pkl"))).exists()) return(QString("flownet_v4.6.pkl"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsrife\\flownet_v4.pkl"))).exists()) return(QString("flownet_v4.pkl"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsrife\\IFNet_HDv3_v4_0.py"))).exists()) return(QString("IFNet_HDv3_v4_0.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsrife\\IFNet_HDv3_v4_6.py"))).exists()) return(QString("IFNet_HDv3_v4_6.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vsrife\\warplayer.py"))).exists()) return(QString("warplayer.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\mvsfunc\\__init__.py"))).exists()) return(QString("mvsfunc"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\mvsfunc\\_metadata.py"))).exists()) return(QString("_metadata.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\mvsfunc\\mvsfunc.py"))).exists()) return(QString("mvsfunc.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\mvsfunc\\py.typed"))).exists()) return(QString("py.typed"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\muvs.py"))).exists()) return(QString("muvs.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\__init__.py"))).exists()) return(QString("muvsfunc"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\Collections\\LUM.py"))).exists()) return(QString("LUM.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\Collections\\muvsfunc_misc.py"))).exists()) return(QString("muvsfunc_misc.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\Collections\\muvsfunc_numpy.py"))).exists()) return(QString("muvsfunc_numpy.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\Collections\\net_interp.py"))).exists()) return(QString("net_interp.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\Collections\\resize.py"))).exists()) return(QString("resize.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\muvsfunc\\Collections\\SuperRes.py"))).exists()) return(QString("SuperRes.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\havsfunc\\__init__.py"))).exists()) return(QString("havsfunc"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\Lib\\site-packages\\typing_extensions.py"))).exists()) return(QString("typing_extensions.py"));

	return(QString());
	#endif
	#ifdef Q_OS_DARWIN
	// tls
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/../PlugIns/tls/libqsecuretransportbackend.dylib"))).exists()) return(QString("libqsecuretransportbackend.dylib"));

	// moltenvk
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/moltenvk/libMoltenVK.dylib"))).exists()) return(QString("libMoltenVK.dylib"));

	// lib
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffmpeg"))).exists()) return(QString("ffmpeg"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe"))).exists()) return(QString("ffprobe"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavcodec.dylib"))).exists()) return(QString("libavcodec.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavdevice.dylib"))).exists()) return(QString("libavdevice.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavfilter.dylib"))).exists()) return(QString("libavfilter.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavformat.dylib"))).exists()) return(QString("libavformat.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libavutil.dylib"))).exists()) return(QString("libavutil.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libpostproc.dylib"))).exists()) return(QString("libpostproc.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libswresample.dylib"))).exists()) return(QString("libswresample.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libswscale.dylib"))).exists()) return(QString("libswscale.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/libvapoursynth.dylib"))).exists()) return(QString("libvapoursynth.dylib"));

	// py
	if (!QFile(QDir::toNativeSeparators(QString("/usr/local/lib/libmpdec.3.dylib"))).exists()) return(QString("libmpdec.3.dylib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/Python"))).exists()) return(QString("Python"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/_CodeSignature/CodeResources"))).exists()) return(QString("CodeResources"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/__future__.py"))).exists()) return(QString("__future__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/mimetypes.py"))).exists()) return(QString("mimetypes.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/typing.py"))).exists()) return(QString("typing.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/_weakrefset.py"))).exists()) return(QString("_weakrefset.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/ast.py"))).exists()) return(QString("ast.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/contextlib.py"))).exists()) return(QString("contextlib.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/copyreg.py"))).exists()) return(QString("copyreg.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/decimal.py"))).exists()) return(QString("decimal.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/dis.py"))).exists()) return(QString("dis.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/enum.py"))).exists()) return(QString("enum.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/fractions.py"))).exists()) return(QString("fractions.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/functools.py"))).exists()) return(QString("functools.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/inspect.py"))).exists()) return(QString("inspect.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/keyword.py"))).exists()) return(QString("keyword.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/linecache.py"))).exists()) return(QString("linecache.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/numbers.py"))).exists()) return(QString("numbers.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/opcode.py"))).exists()) return(QString("opcode.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/operator.py"))).exists()) return(QString("operator.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/optparse.py"))).exists()) return(QString("optparse.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/os.py"))).exists()) return(QString("os.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/reprlib.py"))).exists()) return(QString("reprlib.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/string.py"))).exists()) return(QString("string.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/struct.py"))).exists()) return(QString("struct.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/textwrap.py"))).exists()) return(QString("textwrap.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/threading.py"))).exists()) return(QString("threading.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/token.py"))).exists()) return(QString("token.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/tokenize.py"))).exists()) return(QString("tokenize.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/traceback.py"))).exists()) return(QString("traceback.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/types.py"))).exists()) return(QString("types.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/warnings.py"))).exists()) return(QString("warnings.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/collections/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/collections/abc.py"))).exists()) return(QString("abc.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/ctypes/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/ctypes/_endian.py"))).exists()) return(QString("_endian.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/aliases.py"))).exists()) return(QString("aliases.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/ascii.py"))).exists()) return(QString("ascii.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/encodings/utf_8.py"))).exists()) return(QString("utf_8.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/importlib/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/_ctypes.cpython-311-darwin.so"))).exists()) return(QString("_ctypes.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/_decimal.cpython-311-darwin.so"))).exists()) return(QString("_decimal.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/_struct.cpython-311-darwin.so"))).exists()) return(QString("_struct.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/lib-dynload/math.cpython-311-darwin.so"))).exists()) return(QString("math.cpython-311-darwin.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/logging/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/importlib/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_casefix.py"))).exists()) return(QString("_casefix.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_compiler.py"))).exists()) return(QString("_compiler.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_constants.py"))).exists()) return(QString("_constants.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/_parser.py"))).exists()) return(QString("_parser.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/re/__init__.py"))).exists()) return(QString("__init__.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/urllib/__init__.py"))).exists()) return(QString("urllib"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/urllib/error.py"))).exists()) return(QString("error.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/urllib/parse.py"))).exists()) return(QString("parse.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/urllib/request.py"))).exists()) return(QString("request.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/urllib/response.py"))).exists()) return(QString("response.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/urllib/robotparser.py"))).exists()) return(QString("robotparser.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/site-packages/vapoursynth.so"))).exists()) return(QString("vapoursynth.so"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/__init__.py"))).exists()) return(QString("vsutil"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/_metadata.py"))).exists()) return(QString("_metadata.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/clips.py"))).exists()) return(QString("clips.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/func.py"))).exists()) return(QString("func.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/info.py"))).exists()) return(QString("info.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/py.typed"))).exists()) return(QString("py.typed"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/vsutil/types.py"))).exists()) return(QString("types.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/mvsfunc/__init__.py"))).exists()) return(QString("mvsfunc"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/mvsfunc/_metadata.py"))).exists()) return(QString("_metadata.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/mvsfunc/mvsfunc.py"))).exists()) return(QString("mvsfunc.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/mvsfunc/py.typed"))).exists()) return(QString("py.typed"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/muvs.py"))).exists()) return(QString("muvs.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/__init__.py"))).exists()) return(QString("muvsfunc"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/Collections/LUM.py"))).exists()) return(QString("LUM.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/Collections/muvsfunc_misc.py"))).exists()) return(QString("muvsfunc_misc.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/Collections/muvsfunc_numpy.py"))).exists()) return(QString("muvsfunc_numpy.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/Collections/net_interp.py"))).exists()) return(QString("net_interp.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/Collections/resize.py"))).exists()) return(QString("resize.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/muvsfunc/Collections/SuperRes.py"))).exists()) return(QString("SuperRes.py"));
	if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/py/lib/python3.11/havsfunc/__init__.py"))).exists()) return(QString("havsfunc"));

	return(QString());
	#endif
}