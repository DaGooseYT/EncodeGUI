#pragma once

#ifndef SCRIPTBUILDER_H
#define SCRIPTBUILDER_H

#include "..\VS\VapourSynth.h"

#include <QtCore/QString>

class ScriptBuilder : protected VapourSynth {
public:
	static QString GetScript();
	static void SetRIFECuda(int, double, int, int, double, QString);
	static void SetRIFENcnn(int, int, int, QString, QString, QString);
	static void SetRIFENcnnNew(int, int, int, int, int, QString, QString, QString);
	static void SetSVPFlowNoob(QString, int, int, int, int, int, int);
	static void SetSVPFlow(QString, QString, QString, int, int);
	static void SetWaifu2x(int, int, int, int, int, int, bool, int, int);
	static void SetSRMD(int, int, int, int, QString, bool, int, int);
	static void SetRGB(QString, QString, QString);
	static void SetColorsInOut(QString, QString, QString, QString, QString, QString, QString);
	static void SetColorsOut(QString, QString, QString, QString);
	static void SetSCDetect(QString);
	static void SetPlugin(QString);
	static void SetInput(QString, QString);
	static void SetAntiA();
	static void SetInclude();
	static void SetConcludeClip();
	static void SetNewLine();
	static void ClearScript();

private:
	static QString ScriptList;
};

#endif // !SCRIPTBUILDER_H