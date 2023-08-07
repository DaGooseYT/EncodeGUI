#pragma once

#ifndef VAPOURSYNTH_H
#define VAPOURSYNTH_H

#include <QString>

class VapourSynth {
protected:
	
	static QString rifeNcnn(int model, int id, int thread, QString tta, QString uhd, QString sc);
	static QString rifeNcnnNew(int model, int id, int thread, int num, int den, QString tta, QString uhd, QString sc);
	static QString waifu2x(int noise, int scale, int model, int id, int thread, int precision, bool dual, int gpu1, int gpu2);
	static QString srmd(int scale, int noise, int id, int thread, QString tta, bool dual, int gpu1, int gpu2);
	static QString rgb(QString matrix, QString transfer, QString primaries);
	static QString colorsInOut(QString format, QString matrixIn, QString transferIn, QString primariesIn, QString matrix, QString transfer, QString primaries);
	static QString colorsOut(QString format, QString matrix, QString transfer, QString primaries);
	static QString scDetect(QString threshold);
	static QString plugin(QString path);
	static QString input(QString path, QString id);
	static QString include();
	static QString antiA();
	static QString concludeClip();
	static QString newLine();

	#ifdef Q_OS_WINDOWS
	static QString rifeCuda(int id, double model, int num, int den, double scale, QString sc, QString trt);
	static QString svpFlowNoob(QString useGPU, int id, int shader, int mask, int mode, int num, int den);
	static QString svpFlow(QString super, QString analyse, QString smooth, int num, int den);
	#endif
};

#endif // !VAPOURSYNTH_H