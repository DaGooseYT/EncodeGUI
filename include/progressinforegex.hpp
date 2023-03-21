#pragma once

#ifndef PROGRESSINFOREGEX_H
#define PROGRESSINFOREGEX_H

#include "progressinfo.hpp"

#include <QtCore/QRegularExpression>
#include <QtCore/QElapsedTimer>
#include <QtCore/QTime>
#include <QtCore/QList>

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