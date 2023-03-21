#include "../../include/mediaconfig.hpp"

QString MediaConfig::ArgumentList;

void MediaConfig::Append(QString string) {
	ArgumentList.append(string);
}

void MediaConfig::SetAudioChannels(QString channels, QString stream) {
	ArgumentList.append(Argument::AudioChannels(channels, stream));
}

void MediaConfig::SetAudioRate(QString rate, QString stream) {
	ArgumentList.append(Argument::AudioRate(rate, stream));
}

void MediaConfig::SetVideoCodec(QString codec) {
	ArgumentList.append(Argument::VideoCodec(codec));
}

void MediaConfig::SetAudioCodec(QString codec) {
	ArgumentList.append(Argument::AudioCodec(codec));
}

void MediaConfig::SetAudioCodecMulti(QString codec, QString stream) {
	ArgumentList.append(Argument::AudioCodecMulti(codec, stream));
}

void MediaConfig::Setx265Params() {
	ArgumentList.append(Argument::x265Params());
}

void MediaConfig::SetThreads(int threads) {
	ArgumentList.append(Argument::Threads(threads));
}

void MediaConfig::SetColorsProRes(QString matrix, QString transfer, QString primaries) {
	ArgumentList.append(Argument::Colors(matrix, transfer, primaries));
}

void MediaConfig::SetCrop(int width, int height, int x, int y) {
	ArgumentList.append(Argument::Crop(x, y, width, height));
}

void MediaConfig::SetEntropyCoding(int coder) {
	ArgumentList.append(Argument::EntropyCoding(coder));
}

void MediaConfig::SetBFrames(int bframes) {
	ArgumentList.append(Argument::BFrame(bframes));
}

void MediaConfig::SetRefFrames(int refFrames) {
	ArgumentList.append(Argument::ReferenceFrame(refFrames));
}

void MediaConfig::SetMasterDisplay(QString display) {
	ArgumentList.append(Argument::MasterDisplay(display));
}

void MediaConfig::SetHDR10Opt() {
	ArgumentList.append(Argument::HDR10Opt());
}

void MediaConfig::Setx265Colors(QString matrix, QString transfer, QString primaries, QString range) {
	ArgumentList.append(Argument::Colors(matrix, transfer, primaries, range));
}

void MediaConfig::SetDeinterlace() {
	ArgumentList.append(Argument::Deinterlace());
}

void MediaConfig::SetPassLogFile(QString path) {
	ArgumentList.append(Argument::PassLogFile(path));
}

void MediaConfig::SetMaxCllFall(int cll, int fall) {
	ArgumentList.append(Argument::MaxCllFall(cll, fall));
}

void MediaConfig::SetHDRPlus(QString path) {
	ArgumentList.append(Argument::HDRPlus(path));
}

void MediaConfig::SetDBVisionProfile(QString profile) {
	ArgumentList.append(Argument::DBVisionProfile(profile));
}

void MediaConfig::SetDBVisionRPU(QString path) {
	ArgumentList.append(Argument::DBVisionRPU(path));
}

void MediaConfig::SetMap(QString type, QString s1, int s2) {
	ArgumentList.append(Argument::MapVideo(type, s1, s2));
}

void MediaConfig::SetMapMux(QString type, int s1) {
	ArgumentList.append(Argument::MapMux(type, s1));
}

void MediaConfig::SetMapAll(QString type, QString s1) {
	ArgumentList.append(Argument::MapAll(type, s1));
}

void MediaConfig::SetDownMix(double channels) {
	ArgumentList.append(Argument::DownMix(channels));
}

void MediaConfig::SetPixelFormat(QString format) {
	ArgumentList.append(Argument::PixelFormat(format));
}

void MediaConfig::SetPass(int pass) {
	ArgumentList.append(Argument::Pass(pass));
}

void MediaConfig::SetTier(int index) {
	ArgumentList.append(Argument::Tier(index));
}

void MediaConfig::SetVideoPreset(QString preset) {
	ArgumentList.append(Argument::VideoPreset(preset));
}

void MediaConfig::SetVideoProfile(QString profile) {
	ArgumentList.append(Argument::VideoProfile(profile));
}

void MediaConfig::SetVideoProfileLevel(QString level) {
	ArgumentList.append(Argument::VideoProfileLevel(level));
}

void MediaConfig::SetVideoBitrate(int bitrate) {
	ArgumentList.append(Argument::VideoBitrate(bitrate));
}

void MediaConfig::SetAudioBitrate(int bitrate, QString stream) {
	ArgumentList.append(Argument::AudioBitrate(bitrate, stream));
}

void MediaConfig::SetConstantRateFactor(int crf) {
	ArgumentList.append(Argument::ConstantRateFactor(crf));
}

void MediaConfig::SetConstantQuantizer(int strength) {
	ArgumentList.append(Argument::ConstantQuantizer(strength));
}

void MediaConfig::SetQuantizer(int strength) {
	ArgumentList.append(Argument::Quantizer(strength));
}

void MediaConfig::SetConstantVideoQuality(int quality) {
	ArgumentList.append(Argument::ConstantVideoQuality(quality));
}

void MediaConfig::SetAudioTitle(QString stream, QString text) {
	ArgumentList.append(Argument::AudioTitle(stream, text));
}

void MediaConfig::SetAudioLang(QString stream, QString lang) {
	ArgumentList.append(Argument::AudioLang(stream, lang));
}

void MediaConfig::SetConstantAudioQuality(int quality, QString stream) {
	ArgumentList.append(Argument::ConstantAudioQuality(quality, stream));
}

void MediaConfig::SetVideoResolution(int width, int height) {
	ArgumentList.append(Argument::VideoResolution(width, height));
}

void MediaConfig::SetVideoResizeAlgo(QString algo) {
	ArgumentList.append(Argument::VideoResizeAlgo(algo));
}

void MediaConfig::SetTransposeVideo(int transpose) {
	ArgumentList.append(Argument::TransposeVideo(transpose));
}

void MediaConfig::SetFlipVideo(QString flip) {
	ArgumentList.append(Argument::FlipVideo(flip));
}

void MediaConfig::SetNoAutoRotate() {
	ArgumentList.append(Argument::NoAutoRotate());
}

void MediaConfig::SetSharpenVideo(QString radius, QString strength) {
	ArgumentList.append(Argument::SharpenVideo(radius, strength));
}

void MediaConfig::SetTimecodes(int hour, int minute, int second, int mSecond) {
	ArgumentList.append(Argument::AddTimecodes(hour, minute, second, mSecond));
}

void MediaConfig::SetVideoTune(QString tune) {
	ArgumentList.append(Argument::VideoTune(tune));
}

void MediaConfig::SetVSPipe(QString vspipe, QString vsscript) {
	ArgumentList.append(Argument::VSPipe(vspipe, vsscript));
}

void MediaConfig::SetFFMpeg(QString path) {
	ArgumentList.append(Argument::FFMpeg(path));
}

void MediaConfig::SetInput(QString path) {
	ArgumentList.append(Argument::Input(path));
}

void MediaConfig::SetOverride() {
	ArgumentList.append(Argument::Override());
}

void MediaConfig::SetOutput(QString path) {
	ArgumentList.append(Argument::Output(path));
}

void MediaConfig::SetComma() {
	ArgumentList.append(Argument::AddComma());
}

void MediaConfig::SetColin() {
	ArgumentList.append(Argument::AddColin());
}

void MediaConfig::SetFilters() {
	ArgumentList.append(Argument::EnableFilters());
}

void MediaConfig::SetConcludeFilters() {
	ArgumentList.append(Argument::ConcludeFilters());
}

void MediaConfig::ResetArguments() {
	ArgumentList.clear();
}

QString MediaConfig::GetArguments() {
	return(ArgumentList);
}