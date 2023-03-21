#include "../../include/scriptbuilder.hpp"

QString ScriptBuilder::ScriptList;

void ScriptBuilder::SetRIFECuda(int id, double model, int num, int den, double scale, QString sc) {
	ScriptList.append(VapourSynth::RIFECuda(id, model, num, den, scale, sc));
}

void ScriptBuilder::SetRIFENcnn(int model, int id, int thread, QString tta, QString uhd, QString sc) {
	ScriptList.append(VapourSynth::RIFENcnn(model, id, thread, tta, uhd, sc));
}

void ScriptBuilder::SetRIFENcnnNew(int model, int id, int thread, int num, int den, QString tta, QString uhd, QString sc) {
	ScriptList.append(VapourSynth::RIFENcnnNew(model, id, thread, num, den, tta, uhd, sc));
}

void ScriptBuilder::SetSVPFlowNoob(QString useGPU, int id, int shader, int mask, int mode, int num, int den) {
	ScriptList.append(VapourSynth::SVPFlowNoob(useGPU, id, shader, mask, mode, num, den));
}

void ScriptBuilder::SetSVPFlow(QString super, QString analyse, QString smooth, int num, int den) {
	ScriptList.append(VapourSynth::SVPFlow(super, analyse, smooth, num, den));
}

void ScriptBuilder::SetWaifu2x(int noise, int scale, int model, int id, int thread, int precision, bool dual, int gpu1, int gpu2) {
	ScriptList.append(VapourSynth::Waifu2x(noise, scale, model, id, thread, precision, dual, gpu1, gpu2));
}

void ScriptBuilder::SetSRMD(int scale, int noise, int id, int thread, QString tta, bool dual, int gpu1, int gpu2) {
	ScriptList.append(VapourSynth::SRMD(scale, noise, id, thread, tta, dual, gpu1, gpu2));
}

void ScriptBuilder::SetRGB(QString matrix, QString transfer, QString primaries) {
	ScriptList.append(VapourSynth::RGB(matrix, transfer, primaries));
}

void ScriptBuilder::SetAntiA() {
	ScriptList.append(VapourSynth::AntiA());
}

void ScriptBuilder::SetColorsInOut(QString format, QString matrix_in, QString transfer_in, QString primaries_in, QString matrix, QString transfer, QString primaries) {
	ScriptList.append(VapourSynth::ColorsInOut(format, matrix_in, transfer_in, primaries_in, matrix, transfer, primaries));
}

void ScriptBuilder::SetColorsOut(QString format, QString matrix, QString transfer, QString primaries) {
	ScriptList.append(VapourSynth::ColorsOut(format, matrix, transfer, primaries));
}

void ScriptBuilder::SetSCDetect(QString threshold) {
	ScriptList.append(VapourSynth::SCDetect(threshold));
}

void ScriptBuilder::SetPlugin(QString path) {
	ScriptList.append(VapourSynth::Plugin(path));
}

void ScriptBuilder::SetInput(QString path, QString id) {
	ScriptList.append(VapourSynth::Input(path, id));
}

void ScriptBuilder::SetInclude() {
	ScriptList.append(VapourSynth::Include());
}

void ScriptBuilder::SetConcludeClip() {
	ScriptList.append(VapourSynth::ConcludeClip());
}

void ScriptBuilder::SetNewLine() {
	ScriptList.append(VapourSynth::NewLine());
}

void ScriptBuilder::ClearScript() {
	ScriptList.clear();
}

QString ScriptBuilder::GetScript() {
	return(ScriptList);
}