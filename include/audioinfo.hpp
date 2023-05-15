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