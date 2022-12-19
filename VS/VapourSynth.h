#pragma once

#ifndef VAPOURSYNTH_H
#define VAPOURSYNTH_H

#include <QString>

class VapourSynth {
protected:
	static QString RIFECuda(QString, int, double, int, QString);
	static QString RIFENcnn(int, int, int, QString, QString, QString);
	static QString SVPFlowNoob(QString, int, int, int, int, int, int);
	static QString SVPFlow(QString, QString, QString, int, int);
	static QString Waifu2x(int, int, int, int, int, int, bool, int, int);
	static QString SRMD(int, int, int, int, QString, bool, int, int);
	static QString RGB(QString, QString, QString);
	static QString ColorsInOut(QString, QString, QString, QString, QString, QString, QString);
	static QString ColorsOut(QString, QString, QString, QString);
	static QString SCDetect(QString);
	static QString Plugin(QString);
	static QString Input(QString, QString);
	static QString Include();
	static QString AntiA();
	static QString ConcludeClip();
	static QString NewLine();
};

#endif // !VAPOURSYNTH_H