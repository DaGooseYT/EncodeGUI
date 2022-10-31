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
	static bool CheckFFMpeg(QString);
	static bool CheckFFProbe(QString);
	static bool CheckVsPipe(QString);
	static bool CheckVsScript(QString);
	static bool CheckVapourSynth(QString);
	static bool CheckInputExists(QString);
	static bool CheckInput(QString);
	static bool CheckOutput(QString);
	static bool CheckOutputOverwrite(QString);
	static bool CheckVideoCompatability(int, QString);
	static bool CheckAudioCompatability(int, QString);
	static bool CheckSubtitleCompatability(QString, QString);
	static bool FileCheck(QString);
};

#endif // !CHECKS_H