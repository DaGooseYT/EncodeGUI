#pragma once

#ifndef VIDEOINFOLIST_H
#define VIDEOINFOLIST_H

#include <QString>
#include <QList>
#include <QTime>

class VideoInfoList {
public:
	static void setCodec(QString codec);
	static void setMatrix(QString matrix);
	static void setTransfer(QString transfer);
	static void setPrimaries(QString primaries);
	static void setWidth(int width);
	static void setHeight(int height);
	static void setJobDuration(QTime duration);
	static void setDuration(QTime duration);
	static void setJobFrameRate(QString frameRate);
	static void setFrameRate(QString frameRate);
	static void setVk(QString name);

	static QString getCodec(int index);
	static QString getMatrix(int index);
	static QString getTransfer(int index);
	static QString getPrimaries(int index);
	static int getWidth(int index);
	static int getHeight(int index);
	static QTime getJobDuration(int index);
	static QTime getDuration(int index);
	static QString getJobFrameRate(int index);
	static QString getFrameRate(int index);
	static QString getVk(int index);

	static void removeCodec(int index);
	static void removeMatrix(int index);
	static void removeTransfer(int index);
	static void removePrimaries(int index);
	static void removeWidth(int index);
	static void removeHeight(int index);
	static void removeJobDuration(int index);
	static void removeDuration(int index);
	static void removeJobFrameRate(int index);
	static void removeFrameRate(int index);

	static int totalCodec();
	static int totalVk();

	static void clearAll();
	static void clearJobAll();
	static void clearVk();

private:
	static QStringList _codec;
	static QStringList _matrix;
	static QStringList _transfer;
	static QStringList _primaries;
	static QList<int> _width;
	static QList<int> _height;
	static QList<QTime> _jobDuration;
	static QList<QTime> _duration;
	static QStringList _jobFrameRate;
	static QStringList _frameRate;
	static QStringList _vk;
};

#endif // !VIDEOINFOLIST_H