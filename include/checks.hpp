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

#ifndef CHECKS_H
#define CHECKS_H

#include <QtCore/QString>
#include <QtCore/QFile>
#include <QtCore/QDir>

#define AVC 0
#define HEVC 1
#define PRORES 2
#define THEORA 3
#define VP9 4
#define VC1 5
#define MPEG2 6
#define MPEG4 7
#define HUFFYUV 8

#define AAC 0
#define MP3 1
#define AC3 2
#define FLAC 3
#define VORBIS 4
#define OPUS 5
#define DTS 6
#define TRUEHD 7
#define EAC3 8
#define ALAC 9
#define WMA 10
#define PCM 11
#define MP2 12

class Checks {
public:
	static bool checkFFMpeg(QString path);
	static bool checkFFProbe(QString path);
	static bool checkVsPipe(QString path);
	static bool checkVsScript(QString path);
	static bool checkVapourSynth(QString path);
	static bool checkInputExists(QString path);
	static bool checkInput(QString input);
	static bool checkOutput(QString output);
	static bool checkOutputOverwrite(QString path);
	static bool checkVideoCompatability(int format, QString container);
	static bool checkAudioCompatability(int format, QString container);
	static bool checkSubtitleCompatability(QString format, QString container);
	static bool fileCheck(QString path);
};

#endif // !CHECKS_H