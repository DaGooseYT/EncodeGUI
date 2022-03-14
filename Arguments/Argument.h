#pragma once

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QString>

class Argument {
protected:
	static QString AudioRate(QString, QString);
	static QString AudioChannels(QString, QString);
	static QString VideoCodec(QString);
	static QString AudioCodec(QString);
	static QString AudioCodecMulti(QString, QString);
	static QString x265Params();
	static QString Threads(int);
	static QString Colors(QString, QString, QString);
	static QString Crop(int, int, int, int);
	static QString EntropyCoding(int);
	static QString BFrame(int);
	static QString ReferenceFrame(int);
	static QString MasterDisplay(QString);
	static QString HDR10Opt();
	static QString Colors(QString, QString, QString, QString);
	static QString MaxCllFall(int, int);
	static QString HDRPlus(QString);
	static QString MapVideo(QString, QString, int);
	static QString MapAll(QString, QString);
	static QString DownMix(double);
	static QString PixelFormat(QString);
	static QString Pass(int);
	static QString VideoPreset(QString);
	static QString VideoProfile(QString);
	static QString VideoProfileLevel(QString);
	static QString VideoBitrate(int);
	static QString AudioBitrate(int, QString);
	static QString ConstantRateFactor(int);
	static QString ConstantQuantizer(int);
	static QString ConstantVideoQuality(int);
	static QString ConstantAudioQuality(int, QString);
	static QString VideoResolution(int, int);
	static QString VideoResizeAlgo(QString);
	static QString PassLogFile(QString);
	static QString TransposeVideo(int);
	static QString FlipVideo(QString);
	static QString NoAutoRotate();
	static QString Tier(int);
	static QString SharpenVideo(QString, QString);
	static QString AddTimecodes(int, int, int, int);
	static QString VideoTune(QString);
	static QString VSPipe(QString, QString);
	static QString FFMpeg(QString);
	static QString Override();
	static QString Input(QString);
	static QString Output(QString);
	static QString AddComma();
	static QString AddColin();
	static QString EnableFilters();
	static QString ConcludeFilters();
};

#endif // !ARGUMENT_H