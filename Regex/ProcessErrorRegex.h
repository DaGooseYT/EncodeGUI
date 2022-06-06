#pragma once

#ifndef PROCESSERRORREGEX_H
#define PROCESSERRORREGEX_H

#include "..\IO\ProcessError.h"

#include <QRegularExpression>
#include <QList>

class ProcessErrorRegex {
public:
	static void ErrorRegex(QString);
	static void ClearBools();

private:
	enum GetError {
		Pipe = 0,
		Cuda = 1,
		Nvenc = 2,
		Qsv = 3,
		Amf = 4,
		Thread = 5,
		Memory = 6,
		Queue = 7,
		Probe = 8,
		Ncnn = 9,
		NvencBit = 10,
		Page = 11
	};

	static QList<bool> IndexerBool;
	static QList<QRegularExpression> IndexerRegex;

	static int MinThreads;
	static int MaxThreads;

	static void SetupPatterns();
};

#endif // !PROCESSERRORREGEX_H