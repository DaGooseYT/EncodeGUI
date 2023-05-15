#include "audiosubinforegex.hpp"

QList<QRegularExpression> AudioSubInfoRegex::_indexer;

QString AudioSubInfoRegex::_audioCodec;
QString AudioSubInfoRegex::_audioLanguage;
QString AudioSubInfoRegex::_sampleRate;
QString AudioSubInfoRegex::_channels;
QString AudioSubInfoRegex::_audioStreams;
QString AudioSubInfoRegex::_subCodec;
QString AudioSubInfoRegex::_subLanguage;
QString AudioSubInfoRegex::_subStreams;

void AudioSubInfoRegex::setupPattern() {
	_indexer << QRegularExpression(QString("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Audio:\\s?(\\w*)[^,]*,?\\s?([^\\s]*)\\sHz,\\s?([^,]*),?"));
	_indexer << QRegularExpression(QString("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Subtitle:\\s?([^\\s]*)"));
	_indexer << QRegularExpression(QString("\\s*Chapters:"));
}

void AudioSubInfoRegex::audioInfoRegex(QString output) {
	if (_indexer.isEmpty())
		setupPattern();

	QRegularExpressionMatch matchAudioInfo(_indexer.at(GetInfo::Audio).match(output));

	if (!matchAudioInfo.hasMatch())
		return;
	else {
		_audioCodec = matchAudioInfo.captured(3);
		_audioLanguage = matchAudioInfo.captured(2);
		_sampleRate = matchAudioInfo.captured(4);
		_channels = matchAudioInfo.captured(5).remove(QRegularExpression(QString("\\(side\\)")));
		_audioStreams = matchAudioInfo.captured(1);

		if (_channels.contains(QString("stereo")) || _channels.contains(QString("2 channels")))
			_channels = QString("Stereo");
		else if (_channels.contains(QString("mono")) || _channels.contains(QString("1 channels")))
			_channels = QString("Mono");
		else if (_channels.isEmpty())
			_channels = QString("?");

		if (_audioCodec.contains(QString("vorbis")))
			_audioCodec = QString("Vorbis");
		else if (_audioCodec.contains(QString("pcm")))
			_audioCodec = QString("PCM");
		else if (_audioCodec.contains(QString("truehd")))
			_audioCodec = QString("TrueHD");
		else if (_audioCodec.contains(QString("opus")))
			_audioCodec = QString("Opus");
		else if (_audioCodec.isEmpty())
			_audioCodec = QString("?");
		else
			_audioCodec = _audioCodec.toUpper();

		if (!_audioLanguage.contains(QString("und")) && !_audioLanguage.isEmpty())
			_audioLanguage = _audioLanguage.toUpper();
		else if (_audioLanguage.isEmpty() || _audioLanguage.contains(QString("und")))
			_audioLanguage = QString("?");

		if (!_sampleRate.isEmpty())
			_sampleRate = _sampleRate + QString("Hz");
		else
			_sampleRate = QString("?");

		#ifdef AUDIOINFO_H
		AudioInfo::addStream();
		AudioInfo::setCodec(_audioCodec);
		AudioInfo::setLanguage(_audioLanguage);
		AudioInfo::setSampleRate(_sampleRate);
		AudioInfo::setChannels(_channels);
		AudioInfo::setStream(_audioStreams);
		#endif // AUDIOINFO_H
	}
}

void AudioSubInfoRegex::chapterInfoRegex(QString output) {
	if (_indexer.isEmpty())
		setupPattern();

	QRegularExpressionMatch matchChapters(_indexer.at(GetInfo::Chapter).match(output));

	if (!matchChapters.hasMatch())
		return;
	else {
		#ifdef SUBTITLEINFO_H
		SubtitleInfo::setChapter(true);
		#endif // SUBTITLEINFO_H
	}
}

void AudioSubInfoRegex::subInfoRegex(QString output) {
	if (_indexer.isEmpty())
		setupPattern();

	QRegularExpressionMatch matchSubtitleInfo(_indexer.at(GetInfo::Subtitle).match(output));

	if (!matchSubtitleInfo.hasMatch())
		return;
	else {
		_subLanguage = matchSubtitleInfo.captured(2).toUpper();
		_subStreams = matchSubtitleInfo.captured(1);
		_subCodec = matchSubtitleInfo.captured(3);
		
		#ifdef SUBTITLEINFO_H
		SubtitleInfo::addStreams();
		SubtitleInfo::setLanguage(_subLanguage);
		SubtitleInfo::setStream(_subStreams);
		SubtitleInfo::setCodec(_subCodec);
		#endif // SUBTITLEINFO_H
	}
}