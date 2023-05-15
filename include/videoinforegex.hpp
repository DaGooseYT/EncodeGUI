#pragma once

#ifndef VIDEOINFOREGEX_H
#define VIDEOINFOREGEX_H

#include <QRegularExpression>
#include <QElapsedTimer>
#include <QString>
#include <QList>
#include <QTime>

#include "videoinfolist.hpp"
#include "videoinfo.hpp"

class VideoInfoRegex {
public:
	static void durationBitrateRegex(QString output);
	static void vkRegex(QString output);
	static void videoInfoerRegex(QString output);

	static QString _durationLine;

private:
	enum GetInfo {
		DurationBitrate = 0,
		VideoInfo = 1,
		Bitrate = 2,
		Duration = 3,
		Colors = 4,
		Fps = 5,
		Tbr = 6,
		Resolution = 7,
		PixFormat = 8,
		VideoInfoPart = 9,
		Codec = 10,
		Vk = 11
	};

	static QList<QRegularExpression> _indexer;

	static void setupPatterns();
};

#endif // !VIDEOINFOREGEX_H