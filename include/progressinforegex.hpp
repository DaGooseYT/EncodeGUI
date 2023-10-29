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

#ifndef PROGRESSINFOREGEX_H
#define PROGRESSINFOREGEX_H

#include <QtCore/QRegularExpression>
#include <QtCore/QElapsedTimer>
#include <QtCore/QTime>
#include <QtCore/QList>

#include "progressinfo.hpp"

class ProgressInfoRegex {
public:
	static bool progressRegex(QString output, QTime totalDuration, int totalFrames, QElapsedTimer timer, QTime pause);
	static bool extractRegex(QString output, QTime totalDuration);

private:
	enum GetInfo {
		Frame = 0,
		Fps = 1,
		Bitrate = 2,
		Time = 3
	};

	static QList<QRegularExpression> _indexer;

	static void setupPatterns();
};

#endif // !PROGRESSINFOREGEX_H