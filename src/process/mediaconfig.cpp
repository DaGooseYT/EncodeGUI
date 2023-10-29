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

#include "mediaconfig.hpp"

QStringList MediaConfig::_argumentList;
QString MediaConfig::_filterList;
QString MediaConfig::_paramsList;

void MediaConfig::setAudioChannels(QString channels, int stream) {
	foreach(QString argument, splitSpace(Argument::audioChannels(channels, stream)))
		_argumentList.append(argument);
}

void MediaConfig::setAudioRate(QString rate, int stream) {
	foreach(QString argument, splitSpace(Argument::audioRate(rate, stream)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoCodec(QString codec) {
	foreach(QString argument, splitSpace(Argument::videoCodec(codec)))
		_argumentList.append(argument);
}

void MediaConfig::setAudioCodec(QString codec) {
	foreach(QString argument, splitSpace(Argument::audioCodec(codec)))
		_argumentList.append(argument);
}

void MediaConfig::setSubtitleCodec(QString codec) {
	foreach(QString argument, splitSpace(Argument::subtitleCodec(codec)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoChapters() {
	foreach(QString argument, splitSpace(Argument::mapChapters()))
		_argumentList.append(argument);
}

void MediaConfig::setAudioCodecMulti(QString codec, int stream) {
	foreach(QString argument, splitSpace(Argument::audioCodecMulti(codec, stream)))
		_argumentList.append(argument);
}

void MediaConfig::setSubtitleCodecMulti(QString codec, int stream) {
	foreach(QString argument, splitSpace(Argument::subtitleCodecMulti(codec, stream)))
		_argumentList.append(argument);
}

void MediaConfig::setThreads(int threads) {
	foreach(QString argument, splitSpace(Argument::threads(threads)))
		_argumentList.append(argument);
}

void MediaConfig::setColorsProRes(QString matrix, QString transfer, QString primaries) {
	foreach(QString argument, splitSpace(Argument::colors(matrix, transfer, primaries)))
		_argumentList.append(argument);
}

void MediaConfig::setCrop(int width, int height, int x, int y) {
	foreach(QString argument, splitSpace(Argument::crop(x, y, width, height)))
		_argumentList.append(argument);
}

void MediaConfig::setEntropyCoding(int coder) {
	foreach(QString argument, splitSpace(Argument::entropyCoding(coder)))
		_argumentList.append(argument);
}

void MediaConfig::setBFrames(int bFrames) {
	foreach(QString argument, splitSpace(Argument::bFrame(bFrames)))
		_argumentList.append(argument);
}

void MediaConfig::setRefFrames(int refFrames) {
	foreach(QString argument, splitSpace(Argument::referenceFrame(refFrames)))
		_argumentList.append(argument);
}

void MediaConfig::setMap(QString type, int s1, int s2) {
	foreach(QString argument, splitSpace(Argument::mapVideo(type, s1, s2)))
		_argumentList.append(argument);
}

void MediaConfig::setMapMux(QString type, int s1) {
	foreach(QString argument, splitSpace(Argument::mapMux(type, s1)))
		_argumentList.append(argument);
}

void MediaConfig::setMapAll(QString type, int s1) {
	foreach(QString argument, splitSpace(Argument::mapAll(type, s1)))
		_argumentList.append(argument);
}

void MediaConfig::setMapSingle(QString type) {
	foreach(QString argument, splitSpace(Argument::mapSingle(type)))
		_argumentList.append(argument);
}

void MediaConfig::setVs() {
	foreach(QString argument, splitSpace(Argument::vs()))
		_argumentList.append(argument);
}

void MediaConfig::setDownMix(double channels) {
	foreach(QString argument, splitSpace(Argument::downMix(channels)))
		_argumentList.append(argument);
}

void MediaConfig::setPixelFormat(QString format) {
	foreach(QString argument, splitSpace(Argument::pixelFormat(format)))
		_argumentList.append(argument);
}

void MediaConfig::setPass(int pass) {
	foreach(QString argument, splitSpace(Argument::pass(pass)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoPreset(QString preset) {
	foreach(QString argument, splitSpace(Argument::videoPreset(preset)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoProfile(QString profile) {
	foreach(QString argument, splitSpace(Argument::videoProfile(profile)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoProfileLevel(QString level) {
	foreach(QString argument, splitSpace(Argument::videoProfileLevel(level)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoBitrate(int bitrate) {
	foreach(QString argument, splitSpace(Argument::videoBitrate(bitrate)))
		_argumentList.append(argument);
}

void MediaConfig::setAudioBitrate(int bitrate, int stream) {
	foreach(QString argument, splitSpace(Argument::audioBitrate(bitrate, stream)))
		_argumentList.append(argument);
}

void MediaConfig::setConstantRateFactor(int crf) {
	foreach(QString argument, splitSpace(Argument::constantRateFactor(crf)))
		_argumentList.append(argument);
}

void MediaConfig::setConstantQuantizer(int strength) {
	foreach(QString argument, splitSpace(Argument::constantQuantizer(strength)))
		_argumentList.append(argument);
}

void MediaConfig::setQuantizer(int strength) {
	foreach(QString argument, splitSpace(Argument::quantizer(strength)))
		_argumentList.append(argument);
}

void MediaConfig::setConstantVideoQuality(int quality) {
	foreach(QString argument, splitSpace(Argument::constantVideoQuality(quality)))
		_argumentList.append(argument);
}

void MediaConfig::setConstantAudioQuality(int quality, int stream) {
	foreach(QString argument, splitSpace(Argument::constantAudioQuality(quality, stream)))
		_argumentList.append(argument);
}

void MediaConfig::setVideoTune(QString tune) {
	foreach(QString argument, splitSpace(Argument::videoTune(tune)))
		_argumentList.append(argument);
}

void MediaConfig::setTimecodes(int hour, int minute, int second, int mSecond) {
	foreach(QString argument, splitSpace(Argument::addTimecodes(hour, minute, second, mSecond)))
		_argumentList.append(argument);
}

void MediaConfig::setVp9Quality(QString quality) {
	foreach(QString argument, splitSpace(Argument::vp9Quality(quality)))
		_argumentList.append(argument);
}

void MediaConfig::setAppleTag() {
	foreach(QString argument, splitSpace(Argument::appleTag()))
		_argumentList.append(argument);
}

void MediaConfig::setNullPath() {
	foreach(QString argument, splitSpace(Argument::nullPath()))
		_argumentList.append(argument);
}

void MediaConfig::setAllThreads() {
	foreach(QString argument, splitSpace(Argument::allThreads()))
		_argumentList.append(argument);
}

void MediaConfig::setVsPipe() {
	foreach(QString argument, splitSpace(Argument::vsPipe()))
		_argumentList.append(argument);
}

void MediaConfig::setPassLogFile(QString path) {
	_argumentList.append(Argument::passLogFile());
	_argumentList.append(path);
}

void MediaConfig::setAudioMetadata(int stream) {
	_argumentList.append(Argument::audioMetadata(stream));
}

void MediaConfig::setAudioTitle(QString title) {
	_argumentList.append(Argument::audioTitle(title));
}

void MediaConfig::setAudioLang(QString lang) {
	_argumentList.append(Argument::audioLang(lang));
}

void MediaConfig::setSubtitleMetadata(int stream) {
	_argumentList.append(Argument::subtitleMetadata(stream));
}

void MediaConfig::setSubtitleTitle(QString title) {
	_argumentList.append(Argument::subtitleTitle(title));
}

void MediaConfig::setSubtitleLang(QString lang) {
	_argumentList.append(Argument::subtitleLang(lang));
}

void MediaConfig::setVideoMetadata() {
	_argumentList.append(Argument::videoMetadata());
}

void MediaConfig::setEncoder(QString str) {
	_argumentList.append(Argument::encoder(str));
}

void MediaConfig::setNoAutoRotate() {
	_argumentList.append(Argument::noAutoRotate());
}

void MediaConfig::setInput(QString path) {
	_argumentList.append(Argument::input());
	_argumentList.append(path);
}

void MediaConfig::setOverride() {
	_argumentList.append(Argument::override());
}

void MediaConfig::setOutput(QString path) {
	_argumentList.append(path);
}

void MediaConfig::setx265Params() {
	_argumentList.append(Argument::x265Params());
}

void MediaConfig::setFilters() {
	_argumentList.append(Argument::enableFilters());
}

void MediaConfig::append(QString string) {
	_argumentList.append(string);
}

void MediaConfig::setVideoResolution(int width, int height) {
	_filterList.append(Argument::videoResolution(width, height));
}

void MediaConfig::setVideoResizeAlgo(QString algo) {
	_filterList.append(Argument::videoResizeAlgo(algo));
}

void MediaConfig::setTransposeVideo(int transpose) {
	_filterList.append(Argument::transposeVideo(transpose));
}

void MediaConfig::setFlipVideo(QString flip) {
	_filterList.append(Argument::flipVideo(flip));
}

void MediaConfig::setSharpenVideo(QString radius, QString strength) {
	_filterList.append(Argument::sharpenVideo(radius, strength));
}

void MediaConfig::setComma() {
	_filterList.append(Argument::addComma());
}

void MediaConfig::setStartFilters() {
	_filterList.append(Argument::concludeFilters());
}

void MediaConfig::setDeinterlace() {
	_filterList.append(Argument::deinterlace());
}

void MediaConfig::setConcludeFilters() {
	_argumentList.append(_filterList);
}

void MediaConfig::setColin() {
	_paramsList.append(Argument::addColin());
}

void MediaConfig::setMasterDisplay(QString display) {
	_paramsList.append(Argument::masterDisplay(display));
}

void MediaConfig::setHDR10Opt() {
	_paramsList.append(Argument::hdr10Opt());
}

void MediaConfig::setBuffer(int bitrate) {
	_paramsList.append(Argument::buffer(bitrate));
}

void MediaConfig::setx265Colors(QString matrix, QString transfer, QString primaries, QString range) {
	_paramsList.append(Argument::colors(matrix, transfer, primaries, range));
}

void MediaConfig::setMaxCllFall(int cll, int fall) {
	_paramsList.append(Argument::maxCllFall(cll, fall));
}

void MediaConfig::setHDRPlus(QString path) {
	_paramsList.append(Argument::hdrPlus(path));
}

void MediaConfig::setTier(int index) {
	_paramsList.append(Argument::tier(index));
}

void MediaConfig::setDBVisionProfile(QString profile) {
	_paramsList.append(Argument::dbVisionProfile(profile));
}

void MediaConfig::setStatsFile(QString path) {
	_paramsList.append(Argument::statsFile(path));
}

void MediaConfig::setFastPass() {
	_paramsList.append(Argument::setFastPass());
}

void MediaConfig::setDBVisionRPU(QString path) {
	_paramsList.append(Argument::dbVisionRPU(path));
}

void MediaConfig::setConcludeParams() {
	_argumentList.append(_paramsList);
}

void MediaConfig::resetArguments() {
	_argumentList.clear();
	_filterList.clear();
	_paramsList.clear();
}

QStringList MediaConfig::splitSpace(QString args) {
	QStringList arg(args.split(QString(" ")));
	return(arg);
}

QStringList MediaConfig::getArguments() {
	return(_argumentList);
}