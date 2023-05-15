#pragma once

#ifndef SUBTITLEINFO_H
#define SUBTITLEINFO_H

#include <QtCore/QStringList>
#include <QtCore/QString>

class SubtitleInfo {
public:
	static void setLanguage(QString language);
	static void setStream(QString stream);
	static void setCodec(QString codec);
	static void setChapter(bool chapter);

	static QString getLanguage(int index);
	static QString getStream(int index);
	static QString getCodec(int index);
	static bool getChapter();

	static int totalStreams();
	static void addStreams();
	static void clearAll();
	static bool isEmpty();

private:
	static QStringList _language;
	static QStringList _stream;
	static QStringList _codec;
	static int _streams;
	static bool _chapter;
};

#endif // !SUBTITLEINFO_H