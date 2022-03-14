#pragma once

#ifndef SUBTITLEINFO_H
#define SUBTITLEINFO_H

#include <QStringList>
#include <QString>

class SubtitleInfo {
public:
	static void SetLanguage(QString);
	static void SetStream(QString);
	static void SetCodec(QString);
	static void SetChapter(bool);

	static QString GetLanguage(int);
	static QString GetStream(int);
	static QString GetCodec(int);
	static bool GetChapter();

	static int TotalStreams();
	static void AddStreams();
	static void ClearAll();
	static bool IsEmpty();

private:
	static QStringList Language;
	static QStringList Stream;
	static QStringList Codec;
	static int Streams;
	static bool Chapter;
};

#endif // !SUBTITLEINFO_H