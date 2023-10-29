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

#ifndef VIDEOINFOLIST_H
#define VIDEOINFOLIST_H

#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QTime>

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