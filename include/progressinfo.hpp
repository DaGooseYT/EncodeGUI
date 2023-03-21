#pragma once

#ifndef PROGRESSINFO_H
#define PROGRESSINFO_H

#include <QtCore/QDateTime>
#include <QtCore/QString>

class ProgressInfo {
public:
	static void SetTimeLeft(QTime);
	static void SetTimeElapsed(QTime);
	static void SetProcessedFrames(int);
	static void SetTotalFrames(int);
	static void SetTime(QTime);
	static void SetFps(QString);
	static void SetBitrate(QString);
	static void SetPercentage(double);

	static QTime GetTimeLeft();
	static QTime GetTimeElapsed();
	static int GetProcessedFrames();
	static int GetTotalFrames();
	static QTime GetTime();
	static QString GetFps();
	static QString GetBitrate();
	static double GetPercentage();

	static void ClearAll();

private:
	static QTime TimeLeft;
	static QTime TimeElapsed;
	static int ProcessedFrames;
	static int TotalFrames;
	static QTime Time;
	static QString Fps;
	static QString Bitrate;
	static double Percentage;
};

#endif // !PROGRESSINFO_H