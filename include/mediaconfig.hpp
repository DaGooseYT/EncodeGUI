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

#ifndef MEDIACONFIG_H
#define MEDIACONFIG_H

#include <QtCore/QStringList>

#include "args.hpp"

class MediaConfig : protected Argument {
public:
	static QStringList getArguments();
	static void append(QString string);
	static void setAudioChannels(QString channels, int stream);
	static void setAudioRate(QString rate, int stream);
	static void setVideoCodec(QString codec);
	static void setAudioCodec(QString codec);
	static void setSubtitleCodec(QString codec);
	static void setVp9Quality(QString quality);
	static void setFastPass();
	static void setVideoChapters();
	static void setAppleTag();
	static void setAudioCodecMulti(QString codec, int stream);
	static void setSubtitleCodecMulti(QString codec, int stream);
	static void setx265Params();
	static void setThreads(int threads);
	static void setColorsProRes(QString matrix, QString transfer, QString primaries);
	static void setCrop(int width, int height, int x, int y);
	static void setEntropyCoding(int coder);
	static void setBFrames(int bFrames);
	static void setRefFrames(int refFrames);
	static void setMasterDisplay(QString display);
	static void setHDR10Opt();
	static void setx265Colors(QString matrix, QString transfer, QString primaries, QString range);
	static void setMaxCllFall(int cll, int fall);
	static void setHDRPlus(QString path);
	static void setDBVisionProfile(QString profile);
	static void setDBVisionRPU(QString path);
	static void setMap(QString type, int s1, int s2);
	static void setMapMux(QString type, int s1);
	static void setMapAll(QString type, int s1);
	static void setMapSingle(QString type);
	static void setDownMix(double channels);
	static void setBuffer(int bitrate);
	static void setPixelFormat(QString format);
	static void setPass(int pass);
	static void setTier(int index);
	static void setVideoPreset(QString preset);
	static void setVideoProfile(QString profile);
	static void setVideoProfileLevel(QString level);
	static void setVideoBitrate(int bitrate);
	static void setAudioMetadata(int stream);
	static void setAudioTitle(QString title);
	static void setAudioLang(QString lang);
	static void setSubtitleMetadata(int stream);
	static void setSubtitleTitle(QString title);
	static void setSubtitleLang(QString lang);
	static void setAudioBitrate(int bitrate, int stream);
	static void setConstantRateFactor(int crf);
	static void setConstantQuantizer(int strength);
	static void setQuantizer(int strength);
	static void setConstantVideoQuality(int quality);
	static void setConstantAudioQuality(int quality, int stream);
	static void setVideoResolution(int width, int height);
	static void setVideoResizeAlgo(QString algo);
	static void setTransposeVideo(int transpose);
	static void setFlipVideo(QString flip);
	static void setPassLogFile(QString path);
	static void setNoAutoRotate();
	static void setSharpenVideo(QString radius, QString strength);
	static void setTimecodes(int hour, int minute, int second, int mSecond);
	static void setVideoTune(QString tune);
	static void setOverride();
	static void setInput(QString path);
	static void setOutput(QString path);
	static void setVideoMetadata();
	static void setEncoder(QString str);
	static void setDeinterlace();
	static void setComma();
	static void setStatsFile(QString path);
	static void setAllThreads();
	static void setColin();
	static void setFilters();
	static void setConcludeFilters();
	static void setStartFilters();
	static void setConcludeParams();
	static void resetArguments();
	static void setNullPath();
	static void setVsPipe();
	static void setVs();

private:
	static QStringList _argumentList;
	static QString _filterList;
	static QString _paramsList;

	static QStringList splitSpace(QString args);
};

#endif // !MEDIACONFIG_H