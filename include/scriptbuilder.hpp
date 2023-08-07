#pragma once

#ifndef SCRIPTBUILDER_H
#define SCRIPTBUILDER_H

#include <QtCore/QString>

#include "vapoursynth.hpp"

class ScriptBuilder : protected VapourSynth {
public:
	static QString getScript();
	static void setRIFENcnn(int model, int id, int thread, QString tta, QString uhd, QString sc);
	static void setRIFENcnnNew(int model, int id, int thread, int num, int den, QString tta, QString uhd, QString sc);
	static void setWaifu2x(int noise, int scale, int model, int id, int thread, int precision, bool dual, int gpu1, int gpu2);
	static void setSRMD(int scale, int noise, int id, int thread, QString tta, bool dual, int gpu1, int gpu2);
	static void setRGB(QString matrix, QString transfer, QString primaries);
	static void setColorsInOut(QString format, QString matrixIn, QString transferIn, QString primariesIn, QString matrix, QString transfer, QString primaries);
	static void setColorsOut(QString format, QString matrix, QString transfer, QString primaries);
	static void setSCDetect(QString threshold);
	static void setPlugin(QString path);
	static void setInput(QString path, QString id);
	static void setAntiA();
	static void setInclude();
	static void setConcludeClip();
	static void setNewLine();
	static void clearScript();

	#ifdef Q_OS_WINDOWS
	static void setRIFECuda(int id, double model, int num, int den, double scale, QString sc, QString trt);
	static void setSVPFlowNoob(QString useGPU, int id, int shader, int mask, int mode, int num, int den);
	static void setSVPFlow(QString super, QString analyse, QString smooth, int num, int den);
	#endif

private:
	static QString _scriptList;
};

#endif // !SCRIPTBUILDER_H