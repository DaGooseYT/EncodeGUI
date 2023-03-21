#pragma once

#ifndef VIDEOINFOREGEX_H
#define VIDEOINFOREGEX_H

#include "videoinfolist.hpp"
#include "videoinfo.hpp"

#include <QRegularExpression>
#include <QElapsedTimer>
#include <QString>
#include <QList>
#include <QTime>

class VideoInfoRegex {
public:
	static void DurationBitrateRegex(QString);
	static void VkRegex(QString);
	static void VideoInfoerRegex(QString);

	static QString DurationLine;

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

	static QList<QRegularExpression> Indexer;

	static void SetupPatterns();
};

#endif // !VIDEOINFOREGEX_H