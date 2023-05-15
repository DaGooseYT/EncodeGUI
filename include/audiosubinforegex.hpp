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