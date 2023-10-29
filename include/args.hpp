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

#ifndef ARGUMENT_H
#define ARGUMENT_H

#include <QtCore/QString>

class Argument {
protected:
	static QString audioRate(QString rate, int stream);
	static QString audioChannels(QString channels, int stream);
	static QString videoCodec(QString codec);
	static QString audioCodec(QString codec);
	static QString subtitleCodec(QString codec);
	static QString mapChapters();
	static QString audioCodecMulti(QString codec, int stream);
	static QString subtitleCodecMulti(QString codec, int stream);
	static QString x265Params();
	static QString setFastPass();
	static QString appleTag();
	static QString threads(int threads);
	static QString colors(QString matrix, QString transfer, QString primaries);
	static QString crop(int x, int y, int width, int height);
	static QString entropyCoding(int coder);
	static QString bFrame(int bFrame);
	static QString referenceFrame(int refFrame);
	static QString masterDisplay(QString display);
	static QString hdr10Opt();
	static QString deinterlace();
	static QString deinterlaceCUDA();
	static QString colors(QString matrix, QString transfer, QString primaries, QString range);
	static QString maxCllFall(int cll, int fall);
	static QString hdrPlus(QString path);
	static QString dbVisionProfile(QString profile);
	static QString dbVisionRPU(QString path);
	static QString mapVideo(QString type, int s1, int s2);
	static QString mapMux(QString type, int s1);
	static QString mapAll(QString type, int s1);
	static QString mapSingle(QString type);
	static QString downMix(double channels);
	static QString pixelFormat(QString format);
	static QString pass(int pass);
	static QString videoPreset(QString preset);
	static QString videoProfile(QString profile);
	static QString videoProfileLevel(QString level);
	static QString videoMetadata();
	static QString encoder(QString str);
	static QString videoBitrate(int bitrate);
	static QString audioBitrate(int bitrate, int stream);
	static QString constantRateFactor(int crf);
	static QString constantQuantizer(int strength);
	static QString quantizer(int strength);
	static QString buffer(int bitrate);
	static QString constantVideoQuality(int quality);
	static QString constantAudioQuality(int quality, int stream);
	static QString videoResolution(int width, int height);
	static QString videoResizeAlgo(QString algo);
	static QString passLogFile();
	static QString transposeVideo(int transpose);
	static QString flipVideo(QString flip);
	static QString noAutoRotate();
	static QString vp9Quality(QString quality);
	static QString audioMetadata(int stream);
	static QString audioTitle(QString title);
	static QString audioLang(QString lang);
	static QString subtitleMetadata(int stream);
	static QString subtitleTitle(QString title);
	static QString subtitleLang(QString lang);
	static QString tier(int tier);
	static QString sharpenVideo(QString radius, QString strength);
	static QString addTimecodes(int hour, int minute, int second, int millisecond);
	static QString videoTune(QString tune);
	static QString override();
	static QString addComma();
	static QString statsFile(QString path);
	static QString allThreads();
	static QString addColin();
	static QString enableFilters();
	static QString input();
	static QString concludeFilters();
	static QString nullPath();
	static QString vsPipe();
	static QString vs();
};

#endif // !ARGUMENT_H