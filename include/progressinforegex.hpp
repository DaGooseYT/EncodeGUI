#pragma once

#ifndef PROGRESSINFOREGEX_H
#define PROGRESSINFOREGEX_H

#include <QtCore/QRegularExpression>
#include <QtCore/QElapsedTimer>
#include <QtCore/QTime>
#include <QtCore/QList>

#include "progressinfo.hpp"

class ProgressInfoRegex {
public:
	static bool progressRegex(QString output, QTime totalDuration, int totalFrames, QElapsedTimer timer, QTime pause);
	static bool extractRegex(QString output, QTime totalDuration);

private:
	enum GetInfo {
		Frame = 0,
		Fps = 1,
		Bitrate = 2,
		Time = 3
	};

	static QList<QRegularExpression> _indexer;

	static void setupPatterns();
};

#endif // !PROGRESSINFOREGEX_H