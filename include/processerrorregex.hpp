#pragma once

#ifndef PROCESSERRORREGEX_H
#define PROCESSERRORREGEX_H

#include <QtCore/QRegularExpression>
#include <QtCore/QList>

#include "processerror.hpp"

class ProcessErrorRegex {
public:
	static void errorRegex(QString output);
	static void clearBools();

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
		Page = 11,
		Dolby = 12,
		Alloc = 13,
		GpuInstance = 14,
		IndexFile = 15,
		IndexDevice = 16,
		InvalidGPU = 17,
		Vram = 18
	};

	static QList<bool> _indexerBool;
	static QList<QRegularExpression> _indexerRegex;

	static int _minThreads;
	static int _maxThreads;

	static void setupPatterns();
};

#endif // !PROCESSERRORREGEX_H