#pragma once

#ifndef MEDIACONFIG_H
#define MEDIACONFIG_H

#include "Arguments\Argument.h"

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
	static void SetMap(QString, QString, int);
	static void SetMapAll(QString, QString);
	static void SetDownMix(double);
	static void SetPixelFormat(QString);
	static void SetPass(int);
	static void SetTier(int);
	static void SetVideoPreset(QString);
	static void SetVideoProfile(QString);
	static void SetVideoProfileLevel(QString);
	static void SetVideoBitrate(int);
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
	static void SetComma();
	static void SetColin();
	static void SetFilters();
	static void SetConcludeFilters();
	static void ResetArguments();

private:
	static QString ArgumentList;
};

#endif // !MEDIACONFIG_H