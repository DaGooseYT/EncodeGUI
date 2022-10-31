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
	static void SetVk(QString);

	static QTime GetDuration(int);
	static QString GetFrameRate(int);
	static QString GetVk(int);

	static void RemoveDuration(int);
	static void RemoveFrameRate(int);

	static void ClearAll();
	static void ClearVk();
	static int TotalVk();

private:
	static QList<QTime> Duration;
	static QStringList FrameRate;
	static QStringList Vk;
};

#endif // !VIDEOINFOLIST_H