#pragma once

#ifndef CHECKS_H
#define CHECKS_H

#include <QString>
#include <QFile>
#include <QDir>

#define AAC 0
#define MP3 1
#define AC3 2
#define FLAC 3
#define VORBIS 4
#define OPUS 5
#define EAC3 6
#define ALAC 7
#define WMA 8
#define PCM 9
#define MP2 10
#define DTS 11
#define TRUEHD 12

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
	static bool CheckAudioCompatability(int, QString);
	static bool CheckSubtitleCompatability(QString, QString);
	static bool FileCheck(QString);
};

#endif // !CHECKS_H