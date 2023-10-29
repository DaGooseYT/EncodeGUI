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

#ifndef PROCESSERRORREGEX_H
#define PROCESSERRORREGEX_H

#include <QtCore/QRegularExpression>
#include <QtCore/QList>

#include "processerror.hpp"

class ProcessErrorRegex {
public:
	static void errorRegex(QString output);
	static void clearBools();

private:
	enum GetError {
		Pipe = 0,
		Cuda = 1,
		Nvenc = 2,
		Qsv = 3,
		Amf = 4,
		Thread = 5,
		Memory = 6,
		Queue = 7,
		Probe = 8,
		Ncnn = 9,
		NvencBit = 10,
		Page = 11,
		Dolby = 12,
		Alloc = 13,
		GpuInstance = 14,
		IndexFile = 15,
		IndexDevice = 16,
		InvalidGPU = 17,
		Vram = 18
	};

	static QList<bool> _indexerBool;
	static QList<QRegularExpression> _indexerRegex;

	static int _minThreads;
	static int _maxThreads;

	static void setupPatterns();
};

#endif // !PROCESSERRORREGEX_H