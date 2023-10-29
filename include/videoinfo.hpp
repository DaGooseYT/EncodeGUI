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

#ifndef VIDEOINFO_H
#define VIDEOINFO_H

#include <QtCore/QTime>
#include <QtCore/QString>

class VideoInfo {
public:
	static void setVideoCodec(QString videoCodec);
	static void setDuration(QTime duration);
	static void setDurationStrng(QString duration);
	static void setResolution(QString resolution);
	static void setWidth(int width);
	static void setHeight(int height);
	static void setBitrate(QString bitrate);
	static void setColors(QString colors);
	static void setMatrix(QString matrix);
	static void setTransfer(QString transfer);
	static void setPrimaries(QString primaries);
	static void setFrameRate(QString frameRate);

	static QString getVideoCodec();
	static QTime getDuration();
	static QString getDurationStrng();
	static QString getResolution();
	static int getWidth();
	static int getHeight();
	static QString getBitrate();
	static QString getColors();
	static QString getMatrix();
	static QString getTransfer();
	static QString getPrimaries();
	static QString getFrameRate();

	static void clearAll();

private:
	static QString _videoCodec;
	static QTime _duration;
	static QString _durationStrng;
	static QString _resolution;
	static int _width;
	static int _height;
	static QString _bitrate;
	static QString _colors;
	static QString _matrix;
	static QString _transfer;
	static QString _primaries;
	static QString _frameRate;
};

#endif // !VIDEOINFO_H