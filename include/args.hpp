#pragma once

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QtCore/QString>

class Argument {
protected:
	static QString audioRate(QString rate, QString stream);
	static QString audioChannels(QString channels, QString stream);
	static QString videoCodec(QString codec);
	static QString audioCodec(QString codec);
	static QString subtitleCodec(QString codec);
	static QString mapChapters();
	static QString audioCodecMulti(QString codec, QString stream);
	static QString x265Params();
	static QString setFastPass();
	static QString appleTag();
	static QString threads(int threads);
	static QString colors(QString matrix, QString transfer, QString primaries);
	static QString crop(int x, int y, int width, int height);
	static QString entropyCoding(int coder);
	static QString bFrame(int bFrame);
	static QString referenceFrame(int refFrame);
	static QString masterDisplay(QString display);
	static QString hdr10Opt();
	static QString deinterlace();
	static QString deinterlaceCUDA();
	static QString colors(QString matrix, QString transfer, QString primaries, QString range);
	static QString maxCllFall(int cll, int fall);
	static QString hdrPlus(QString path);
	static QString dbVisionProfile(QString profile);
	static QString dbVisionRPU(QString path);
	static QString mapVideo(QString type, QString s1, int s2);
	static QString mapMux(QString type, int s1);
	static QString mapAll(QString type, QString s1);
	static QString mapSingle(QString type);
	static QString downMix(double channels);
	static QString pixelFormat(QString format);
	static QString pass(int pass);
	static QString videoPreset(QString preset);
	static QString videoProfile(QString profile);
	static QString videoProfileLevel(QString level);
	static QString metaData1();
	static QString metaData2(QString str);
	static QString videoBitrate(int bitrate);
	static QString audioBitrate(int bitrate, QString stream);
	static QString constantRateFactor(int crf);
	static QString constantQuantizer(int strength);
	static QString quantizer(int strength);
	static QString buffer(int bitrate);
	static QString constantVideoQuality(int quality);
	static QString constantAudioQuality(int quality, QString stream);
	static QString videoResolution(int width, int height);
	static QString videoResizeAlgo(QString algo);
	static QString passLogFile();
	static QString transposeVideo(int transpose);
	static QString flipVideo(QString flip);
	static QString noAutoRotate();
	static QString vp9Quality(QString quality);
	static QString audioMetadata(QString stream);
	static QString audioTitle(QString title);
	static QString audioLang(QString lang);
	static QString tier(int tier);
	static QString sharpenVideo(QString radius, QString strength);
	static QString addTimecodes(int hour, int minute, int second, int millisecond);
	static QString videoTune(QString tune);
	static QString override();
	static QString addComma();
	static QString statsFile(QString path);
	static QString allThreads();
	static QString addColin();
	static QString enableFilters();
	static QString input();
	static QString concludeFilters();
	static QString nullPath();
	static QString vsPipe();
	static QString vs();
};

#endif // !ARGUMENT_H