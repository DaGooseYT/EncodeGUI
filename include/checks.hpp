#pragma once

#ifndef CHECKS_H
#define CHECKS_H

#include <QString>
#include <QFile>
#include <QDir>

#define AVC 0
#define HEVC 1
#define PRORES 2
#define THEORA 3
#define VP9 4
#define VC1 5
#define MPEG2 6
#define MPEG4 7
#define HUFFYUV 8

#define AAC 0
#define MP3 1
#define AC3 2
#define FLAC 3
#define VORBIS 4
#define OPUS 5
#define DTS 6
#define TRUEHD 7
#define EAC3 8
#define ALAC 9
#define WMA 10
#define PCM 11
#define MP2 12

class Checks {
public:
	static bool checkFFMpeg(QString path);
	static bool checkFFProbe(QString path);
	static bool checkVsPipe(QString path);
	static bool checkVsScript(QString path);
	static bool checkVapourSynth(QString path);
	static bool checkInputExists(QString path);
	static bool checkInput(QString input);
	static bool checkOutput(QString output);
	static bool checkOutputOverwrite(QString path);
	static bool checkVideoCompatability(int format, QString container);
	static bool checkAudioCompatability(int format, QString container);
	static bool checkSubtitleCompatability(QString format, QString container);
	static bool fileCheck(QString path);
};

#endif // !CHECKS_H