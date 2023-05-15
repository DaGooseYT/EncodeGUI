#pragma once

#ifndef PROGRESSINFO_H
#define PROGRESSINFO_H

#include <QtCore/QDateTime>
#include <QtCore/QString>

class ProgressInfo {
public:
	static void setTimeLeft(QTime timeLeft);
	static void setTimeElapsed(QTime timeElapsed);
	static void setProcessedFrames(int processedFrames);
	static void setTotalFrames(int totalFrames);
	static void setTime(QTime time);
	static void setFps(QString fps);
	static void setBitrate(QString bitrate);
	static void setPercentage(double percentage);

	static QTime getTimeLeft();
	static QTime getTimeElapsed();
	static int getProcessedFrames();
	static int getTotalFrames();
	static QTime getTime();
	static QString getFps();
	static QString getBitrate();
	static double getPercentage();

	static void clearAll();

private:
	static QTime _timeLeft;
	static QTime _timeElapsed;
	static int _processedFrames;
	static int _totalFrames;
	static QTime _time;
	static QString _fps;
	static QString _bitrate;
	static double _percentage;
};

#endif // !PROGRESSINFO_H