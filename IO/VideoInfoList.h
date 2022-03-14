#pragma once

#ifndef VIDEOINFOLIST_H
#define VIDEOINFOLIST_H

#include <QString>
#include <QList>
#include <QTime>

class VideoInfoList {
public:
	static void SetDuration(QTime);
	static void SetFrameRate(QString);
	static void SetInFrameRate(QString);

	static QTime GetDuration(int);
	static QString GetFrameRate(int);
	static QString GetInFrameRate(int);

	static void RemoveDuration(int);
	static void RemoveFrameRate(int);
	static void RemoveInFrameRate(int);

	static void ClearAll();

private:
	static QList<QTime> Duration;
	static QStringList FrameRate;
	static QStringList InFrameRate;
};

#endif // !VIDEOINFOLIST_H