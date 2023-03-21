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

#pragma once

#ifndef MEDIACONFIG_H
#define MEDIACONFIG_H

#include "args.hpp"

#include <QStringList>

class MediaConfig : protected Argument {
public:
	static QString GetArguments();
	static void Append(QString);
	static void SetAudioChannels(QString, QString);
	static void SetAudioRate(QString, QString);
	static void SetVideoCodec(QString);
	static void SetAudioCodec(QString);
	static void SetAudioCodecMulti(QString, QString);
	static void Setx265Params();
	static void SetThreads(int);
	static void SetColorsProRes(QString, QString, QString);
	static void SetCrop(int, int, int, int);
	static void SetEntropyCoding(int);
	static void SetBFrames(int);
	static void SetRefFrames(int);
	static void SetMasterDisplay(QString);
	static void SetHDR10Opt();
	static void Setx265Colors(QString, QString, QString, QString);
	static void SetMaxCllFall(int, int);
	static void SetHDRPlus(QString);
	static void SetDBVisionProfile(QString);
	static void SetDBVisionRPU(QString);
	static void SetMap(QString, QString, int);
	static void SetMapMux(QString, int);
	static void SetMapAll(QString, QString);
	static void SetDownMix(double);
	static void SetPixelFormat(QString);
	static void SetPass(int);
	static void SetTier(int);
	static void SetVideoPreset(QString);
	static void SetVideoProfile(QString);
	static void SetVideoProfileLevel(QString);
	static void SetVideoBitrate(int);
	static void SetAudioTitle(QString, QString);
	static void SetAudioLang(QString, QString);
	static void SetAudioBitrate(int, QString);
	static void SetConstantRateFactor(int);
	static void SetConstantQuantizer(int);
	static void SetQuantizer(int);
	static void SetConstantVideoQuality(int);
	static void SetConstantAudioQuality(int, QString);
	static void SetVideoResolution(int, int);
	static void SetVideoResizeAlgo(QString);
	static void SetTransposeVideo(int);
	static void SetFlipVideo(QString);
	static void SetPassLogFile(QString);
	static void SetNoAutoRotate();
	static void SetSharpenVideo(QString, QString);
	static void SetTimecodes(int, int, int, int);
	static void SetVideoTune(QString);
	static void SetVSPipe(QString, QString);
	static void SetFFMpeg(QString);
	static void SetOverride();
	static void SetInput(QString);
	static void SetOutput(QString);
	static void SetDeinterlace();
	static void SetComma();
	static void SetColin();
	static void SetFilters();
	static void SetConcludeFilters();
	static void ResetArguments();

private:
	static QString ArgumentList;
};

#endif // !MEDIACONFIG_H