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

#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <QtCore/QStringList>

class AudioInfo {
public:
	static void setCodec(QString codec);
	static void setLanguage(QString language);
	static void setSampleRate(QString sampleRate);
	static void setChannels(QString channels);
	static void setStream(QString stream);

	static QString getCodec(int index);
	static QString getLanguage(int index);
	static QString getSampleRate(int index);
	static QString getChannels(int index);
	static QString getStream(int index);

	static int totalStreams();
	static void addStream();
	static void clearAll();

private:
	static QStringList _codec;
	static QStringList _language;
	static QStringList _sampleRate;
	static QStringList _channels;
	static QStringList _stream;
	static int _streams;
};

#endif // !AUDIOINFO_H