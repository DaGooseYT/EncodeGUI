#include "VideoInfoRegex.h"

QList<QRegularExpression> VideoInfoRegex::Indexer;
QString VideoInfoRegex::DurationLine;

void VideoInfoRegex::SetupPatterns() {
	Indexer << QRegularExpression("(\\s*?Duration:\\s[0-9]*:[0-9]*:[^\\.]*\\.[^,]*,\\s?start:\\s?[0-9]*\\.[^,]*,\\s?bitrate:\\s?[0-9]*\\s?kb/s)");
	Indexer << QRegularExpression("Stream\\s#0:[0-9]*[^V]*Video:\\s*([^,]*)[^(]*\\(?([^)]*)\\)?,\\s?[^\\s]*[^,]*?,?\\s?[^\\s]*");
	Indexer << QRegularExpression("\\s?([0-9]*)\\s?kb/s");
	Indexer << QRegularExpression("([0-9]*):([0-9]*):([0-9]*)\\.([^,]*)");
	Indexer << QRegularExpression("([^,/]*),?([^,/]*),?/?([^/\\s]*)/?([^/\\s]*),?");
	Indexer << QRegularExpression("(\\d*\\.?\\d*?)\\s?fps");
	Indexer << QRegularExpression("(\\d*\\.?\\d*?)\\s?tbr");
	Indexer << QRegularExpression("\\s(\\d*[0-9]*)x(\\d*)\\s?,?");
	Indexer << QRegularExpression("\\)?,\\s([a-z]*)([0-9])([0-9])([0-9])p([0-9]*)\\w*,?\\(?");
	Indexer << QRegularExpression("(Stream\\s#0:[0-9]*[^V]*Video:\\s*[^,]*)");
	Indexer << QRegularExpression("([^\\s]*)");
	Indexer << QRegularExpression("\\[[0-9]\\s([^\\]]*)\\]\\s*queueC=");
}

void VideoInfoRegex::DurationBitrateRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPatterns();

	QRegularExpressionMatch matchDuration = Indexer.at(GetInfo::DurationBitrate).match(output);

	if (!matchDuration.hasMatch())
		return;
	else
		DurationLine = matchDuration.captured(1);
}

void VideoInfoRegex::VkRegex(QString output) {
	if (Indexer.isEmpty())
		SetupPatterns();

	QRegularExpressionMatch matchVk = Indexer.at(GetInfo::Vk).match(output);

	QString name;

	if (!matchVk.hasMatch())
		return;
	else {
		name = matchVk.captured(1);

		VideoInfoList::SetVk(name);
	}
}

void VideoInfoRegex::VideoInfoerRegex(QString output) {
	if (output.contains("attached pic") || output.contains("mjpeg") || output.contains("png") || output.contains("gif") || output.contains("tiff") || output.contains("bmp") || 
		output.contains("heic") || output.contains("tga") || output.contains("webp") || output.contains("avif"))
		return;

	QRegularExpressionMatch matchVideoInfo = Indexer.at(GetInfo::VideoInfo).match(output);

	QString videoCodec, durationStrng, resolution, bitrate, colors, matrix, transfer, primaries, frameRate;
	QTime duration;
	int width, height;

	if (!matchVideoInfo.hasMatch())
		return;
	else {
		QString remove = Indexer.at(GetInfo::VideoInfoPart).match(output).captured(1);
		videoCodec = Indexer.at(GetInfo::Codec).match(matchVideoInfo.captured(1)).captured(1);
		
		if (!DurationLine.isEmpty()) {
			durationStrng = QString("%1:%2:%3.%4").arg(Indexer.at(GetInfo::Duration).match(DurationLine).captured(1)).arg(Indexer.at(GetInfo::Duration).match(DurationLine).captured(2)).
				arg(Indexer.at(GetInfo::Duration).match(DurationLine).captured(3)).arg(Indexer.at(GetInfo::Duration).match(DurationLine).captured(4));
			duration = QTime(Indexer.at(GetInfo::Duration).match(DurationLine).captured(1).toInt(), Indexer.at(GetInfo::Duration).match(DurationLine).captured(2).toInt(), 
				Indexer.at(GetInfo::Duration).match(DurationLine).captured(3).toInt(), Indexer.at(GetInfo::Duration).match(DurationLine).captured(4).toInt());
		}

		if (!Indexer.at(GetInfo::PixFormat).match(output).captured(2).isEmpty()) {
			colors = Indexer.at(GetInfo::PixFormat).match(output).captured(2) + ':' + Indexer.at(GetInfo::PixFormat).match(output).captured(3) +
				':' + Indexer.at(GetInfo::PixFormat).match(output).captured(4) + '/';

			if (Indexer.at(GetInfo::PixFormat).match(output).captured(5).isEmpty())
				colors += "8-bit";
			else
				colors += Indexer.at(GetInfo::PixFormat).match(output).captured(5) + "-bit";
		}
		else
			colors = "?";

		width = Indexer.at(GetInfo::Resolution).match(output.remove(remove)).captured(1).toInt();
		height = Indexer.at(GetInfo::Resolution).match(output.remove(remove)).captured(2).toInt();

		resolution = QString("%1x%2").arg(width).arg(height);

		if (!DurationLine.isEmpty())
			bitrate = Indexer.at(GetInfo::Bitrate).match(DurationLine).captured(1);
		if (Indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(2).isEmpty())
			matrix = Indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(1);
		else
			matrix = Indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(2);

		transfer = Indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(4);
		primaries = Indexer.at(GetInfo::Colors).match(matchVideoInfo.captured(2)).captured(3);

		if (!Indexer.at(GetInfo::Fps).match(output).hasMatch())
			frameRate = Indexer.at(GetInfo::Tbr).match(output).captured(1);
		else
			frameRate = Indexer.at(GetInfo::Fps).match(output).captured(1);

		if (matrix.contains("progressive") || matrix.contains("interlaced") || matrix.contains("tv") ||
			matrix.contains("top first") || matrix.contains("full") || matrix.isEmpty()) {

			matrix = QString("?");
		}
		if (transfer.isEmpty())
			transfer = "?";
		if (primaries.isEmpty())
			primaries = "?";
		if (videoCodec.isEmpty())
			videoCodec = "?";

		transfer.remove(',');
		videoCodec.remove(',');

		if (videoCodec.contains("h264"))
			videoCodec = "AVC";
		if (videoCodec.contains("theora"))
			videoCodec = "Theora";
		else if (videoCodec.contains("prores"))
			videoCodec = "ProRes";
		else if (videoCodec.contains("video"))
			videoCodec = videoCodec.remove("video").toUpper();
		else if (videoCodec.contains("huffyuv"))
			videoCodec = "HuffYUV";
		else
			videoCodec = videoCodec.toUpper();

		if (frameRate.isEmpty())
			frameRate = "?";
		if (durationStrng.isEmpty())
			durationStrng = "?";
		if (bitrate.isEmpty())
			bitrate = "?";

		if (frameRate.contains("23.98"))
			frameRate = QString("23.976"); //assume
		if (frameRate.contains("47.96"))
			frameRate = QString("47.952"); //assume
		if (frameRate.contains("95.91"))
			frameRate = QString("95.904"); //assume

#ifdef VIDEOINFO_H
		VideoInfo::SetVideoCodec(videoCodec);
		VideoInfo::SetDuration(duration);
		VideoInfo::SetDurationStrng(durationStrng);
		VideoInfo::SetResolution(resolution);
		VideoInfo::SetWidth(width);
		VideoInfo::SetHeight(height);
		VideoInfo::SetBitrate(bitrate);
		VideoInfo::SetColors(colors);
		VideoInfo::SetMatrix(matrix);
		VideoInfo::SetTransfer(transfer);
		VideoInfo::SetPrimaries(primaries);
		VideoInfo::SetFrameRate(frameRate);
#endif // PROGRESSINFO_H
	}
}