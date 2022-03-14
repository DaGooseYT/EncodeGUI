#pragma once

#ifndef PROGRESSINFOREGEX_H
#define PROGRESSINFOREGEX_H

#include "IO\ProgressInfo.h"

#include <QRegularExpression>
#include <QElapsedTimer>
#include <QTime>
#include <QList>

class ProgressInfoRegex {
public:
	static bool ProgressRegex(QString, QTime, int, QElapsedTimer, QTime);
	static bool ExtractRegex(QString, QTime);

private:
	enum GetInfo {
		Frame = 0,
		Fps = 1,
		Bitrate = 2,
		Time = 3
	};

	static QList<QRegularExpression> Indexer;

	static void SetupPatterns();
};

#endif // !PROGRESSINFOREGEX_H