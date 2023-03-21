#pragma once

#ifndef AUDIOINFO_H
#define AUDIOINFO_H

#include <QtCore/QStringList>

class AudioInfo {
public:
	static void SetCodec(QString);
	static void SetLanguage(QString);
	static void SetSampleRate(QString);
	static void SetChannels(QString);
	static void SetStream(QString);

	static QString GetCodec(int);
	static QString GetLanguage(int);
	static QString GetSampleRate(int);
	static QString GetChannels(int);
	static QString GetStream(int);

	static int TotalStreams();
	static void AddStream();

	static void ClearAll();

private:
	static QStringList Codec;
	static QStringList Language;
	static QStringList SampleRate;
	static QStringList Channels;
	static QStringList Stream;
	static int Streams;
};

#endif // !AUDIOINFO_H