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

#ifndef AUDIOSUBINFOREGEX_H
#define AUDIOSUBINFOREGEX_H

#include <QtCore/QRegularExpression>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QWidget>
#include <QtCore/QString>
#include <QtCore/QList>

#include "audioinfo.hpp"
#include "subtitleinfo.hpp"

class AudioSubInfoRegex {
public:
	static void audioInfoRegex(QString output);
	static void subInfoRegex(QString output);
	static void chapterInfoRegex(QString output);

private:
	enum GetInfo {
		Audio = 0, 
		Subtitle = 1,
		Chapter = 2
	};

	static QString _audioCodec;
	static QString _audioLanguage;
	static QString _sampleRate;
	static QString _channels;
	static QString _audioStreams;
	static QString _subCodec;
	static QString _subLanguage;
	static QString _subStreams;

	static QList<QRegularExpression> _indexer;
	
	static void setupPattern();
};

#endif // !AUDIOSUBINFOREGEX_H