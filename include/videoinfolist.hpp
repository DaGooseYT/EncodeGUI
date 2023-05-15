#pragma once

#ifndef VIDEOINFOLIST_H
#define VIDEOINFOLIST_H

#include <QString>
#include <QList>
#include <QTime>

class VideoInfoList {
public:
	static void setDuration(QTime duration);
	static void setFrameRate(QString frameRate);
	static void setVk(QString name);

	static QTime getDuration(int index);
	static QString getFrameRate(int index);
	static QString getVk(int index);

	static void removeDuration(int index);
	static void removeFrameRate(int index);

	static void clearAll();
	static void clearVk();
	static int totalVk();

private:
	static QList<QTime> _duration;
	static QStringList _frameRate;
	static QStringList _vk;
};

#endif // !VIDEOINFOLIST_H