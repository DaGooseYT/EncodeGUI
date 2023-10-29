/****************************************************************************
 * Copyright (C) 2022 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#pragma once

#ifndef VIDEOINFOREGEX_H
#define VIDEOINFOREGEX_H

#include <QtCore/QRegularExpression>
#include <QtCore/QElapsedTimer>
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QTime>

#include "videoinfolist.hpp"
#include "videoinfo.hpp"

class VideoInfoRegex {
public:
	static void durationBitrateRegex(QString output);
	static void vkRegex(QString output);
	static void videoInfoerRegex(QString output);
	static void batchInfoerRegex(QString output);

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