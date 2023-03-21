#include "../../include/audiosubinforegex.hpp"

QList<QRegularExpression> AudioSubInfoRegex::Indexer;

QString AudioSubInfoRegex::AudioCodec;
QString AudioSubInfoRegex::AudioLanguage;
QString AudioSubInfoRegex::SampleRate;
QString AudioSubInfoRegex::Channels;
QString AudioSubInfoRegex::AudioStreams;

QString AudioSubInfoRegex::SubCodec;
QString AudioSubInfoRegex::SubLanguage;
QString AudioSubInfoRegex::SubStreams;

void AudioSubInfoRegex::SetupPattern() {
	Indexer << QRegularExpression("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Audio:\\s?(\\w*)[^,]*,?\\s?([^\\s]*)\\sHz,\\s?([^,]*),?");
	Indexer << QRegularExpression("Stream\\s?#0:([0-9]?[0-9]?)\\[?[^\\]]*?\\]?\\(?(\\w*)\\)?:?\\[?[^\\]]*\\]?:\\s?Subtitle:\\s?([^\\s]*)");
	Indexer << QRegularExpression("\\s*Chapters:");
}

void AudioSubInfoRegex::AudioInfoRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPattern();

	QRegularExpressionMatch matchAudioInfo = Indexer.at(GetInfo::Audio).match(output);

	if (!matchAudioInfo.hasMatch())
		return;
	else {
		AudioCodec = matchAudioInfo.captured(3);
		AudioLanguage = matchAudioInfo.captured(2);
		SampleRate = matchAudioInfo.captured(4);
		Channels = matchAudioInfo.captured(5).remove(QRegularExpression("\\(side\\)"));
		AudioStreams = matchAudioInfo.captured(1);

		if (Channels.contains("stereo") || Channels.contains("2 channels"))
			Channels = "Stereo";
		else if (Channels.contains("mono") || Channels.contains("1 channels"))
			Channels = "Mono";
		else if (Channels.isEmpty())
			Channels = "?";

		if (AudioCodec.contains("vorbis"))
			AudioCodec = "Vorbis";
		else if (AudioCodec.contains("pcm"))
			AudioCodec = "PCM";
		else if (AudioCodec.contains("truehd"))
			AudioCodec = "TrueHD";
		else if (AudioCodec.contains("opus"))
			AudioCodec = "Opus";
		else if (AudioCodec.isEmpty())
			AudioCodec = "?";
		else
			AudioCodec = AudioCodec.toUpper();

		if (!AudioLanguage.contains("und") && !AudioLanguage.isEmpty())
			AudioLanguage = AudioLanguage.toUpper();
		else if (AudioLanguage.isEmpty() || AudioLanguage.contains("und"))
			AudioLanguage = "?";

		if (!SampleRate.isEmpty())
			SampleRate = SampleRate + "Hz";
		else
			SampleRate = "?";

#ifdef AUDIOINFO_H
		AudioInfo::AddStream();
		AudioInfo::SetCodec(AudioCodec);
		AudioInfo::SetLanguage(AudioLanguage);
		AudioInfo::SetSampleRate(SampleRate);
		AudioInfo::SetChannels(Channels);
		AudioInfo::SetStream(AudioStreams);
#endif // AUDIOINFO_H
	}
}

void AudioSubInfoRegex::ChapterInfoRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPattern();

	QRegularExpressionMatch matchChapters = Indexer.at(GetInfo::Chapter).match(output);

	if (!matchChapters.hasMatch())
		return;
	else {
#ifdef SUBTITLEINFO_H
		SubtitleInfo::SetChapter(true);
#endif // SUBTITLEINFO_H
	}
}

void AudioSubInfoRegex::SubInfoRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPattern();

	QRegularExpressionMatch matchSubtitleInfo = Indexer.at(GetInfo::Subtitle).match(output);

	if (!matchSubtitleInfo.hasMatch())
		return;
	else {
		SubLanguage = matchSubtitleInfo.captured(2).toUpper();
		SubStreams = matchSubtitleInfo.captured(1);
		SubCodec = matchSubtitleInfo.captured(3);
		
#ifdef SUBTITLEINFO_H
		SubtitleInfo::AddStreams();
		SubtitleInfo::SetLanguage(SubLanguage);
		SubtitleInfo::SetStream(SubStreams);
		SubtitleInfo::SetCodec(SubCodec);
#endif // SUBTITLEINFO_H
	}
}