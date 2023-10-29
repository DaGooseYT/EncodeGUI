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

#include "scriptbuilder.hpp"

QString ScriptBuilder::_scriptList;

#ifdef Q_OS_WINDOWS
void ScriptBuilder::setRIFECuda(int id, double model, int num, int den, double scale, QString sc, QString trt) {
	_scriptList.append(VapourSynth::rifeCuda(id, model, num, den, scale, sc, trt));
}
#endif

void ScriptBuilder::setRIFENcnn(int model, int id, int thread, QString tta, QString uhd, QString sc) {
	_scriptList.append(VapourSynth::rifeNcnn(model, id, thread, tta, uhd, sc));
}

void ScriptBuilder::setRIFENcnnNew(int model, int id, int thread, int num, int den, QString tta, QString uhd, QString sc) {
	_scriptList.append(VapourSynth::rifeNcnnNew(model, id, thread, num, den, tta, uhd, sc));
}

#ifdef Q_OS_WINDOWS
void ScriptBuilder::setSVPFlowNoob(QString useGPU, int id, int shader, int mask, int mode, int num, int den) {
	_scriptList.append(VapourSynth::svpFlowNoob(useGPU, id, shader, mask, mode, num, den));
}

void ScriptBuilder::setSVPFlow(QString super, QString analyse, QString smooth, int num, int den) {
	_scriptList.append(VapourSynth::svpFlow(super, analyse, smooth, num, den));
}
#endif

void ScriptBuilder::setWaifu2x(int noise, int scale, int model, int id, int thread, int precision, bool dual, int gpu1, int gpu2) {
	_scriptList.append(VapourSynth::waifu2x(noise, scale, model, id, thread, precision, dual, gpu1, gpu2));
}

#ifdef Q_OS_DARWIN
void ScriptBuilder::setSRMD(int scale, int noise, int id, int thread, QString tta) {
	_scriptList.append(VapourSynth::srmd(scale, noise, id, thread, tta));
}
#endif

void ScriptBuilder::setRealSR(int id, int thread, QString tta, bool dual, int gpu1, int gpu2) {
	_scriptList.append(VapourSynth::realSR(id, thread, tta, dual, gpu1, gpu2));
}

void ScriptBuilder::setRGB(QString matrix, QString transfer, QString primaries) {
	_scriptList.append(VapourSynth::rgb(matrix, transfer, primaries));
}

void ScriptBuilder::setAntiA() {
	_scriptList.append(VapourSynth::antiA());
}

void ScriptBuilder::setColorsInOut(QString format, QString matrixIn, QString transferIn, QString primariesIn, QString matrix, QString transfer, QString primaries) {
	_scriptList.append(VapourSynth::colorsInOut(format, matrixIn, transferIn, primariesIn, matrix, transfer, primaries));
}

void ScriptBuilder::setColorsOut(QString format, QString matrix, QString transfer, QString primaries) {
	_scriptList.append(VapourSynth::colorsOut(format, matrix, transfer, primaries));
}

void ScriptBuilder::setSCDetect(QString threshold) {
	_scriptList.append(VapourSynth::scDetect(threshold));
}

void ScriptBuilder::setPlugin(QString path) {
	_scriptList.append(VapourSynth::plugin(path));
}

void ScriptBuilder::setInput(QString path, QString id) {
	_scriptList.append(VapourSynth::input(path, id));
}

void ScriptBuilder::setInclude() {
	_scriptList.append(VapourSynth::include());
}

void ScriptBuilder::setConcludeClip() {
	_scriptList.append(VapourSynth::concludeClip());
}

void ScriptBuilder::setNewLine() {
	_scriptList.append(VapourSynth::newLine());
}

void ScriptBuilder::clearScript() {
	_scriptList.clear();
}

QString ScriptBuilder::getScript() {
	return(_scriptList);
}