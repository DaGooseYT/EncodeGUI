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

#include "processerrorregex.hpp"

QList<bool> ProcessErrorRegex::_indexerBool;
QList<QRegularExpression> ProcessErrorRegex::_indexerRegex;

int ProcessErrorRegex::_minThreads;
int ProcessErrorRegex::_maxThreads;

void ProcessErrorRegex::setupPatterns() {
	_indexerRegex.append(QRegularExpression(QString("pipe::\\sInvalid\\sdata\\sfound\\swhen\\sprocessing\\sinput")));
	_indexerRegex.append(QRegularExpression(QString("RuntimeError:\\sCUDA\\serror:\\sinvalid\\sdevice\\sordinal")));
	_indexerRegex.append(QRegularExpression(QString("Cannot\\sload\\snvEncodeAPI64\\.dll")));
	_indexerRegex.append(QRegularExpression(QString("Error\\squerying\\sencoder\\sparams:\\sunsupported")));
	_indexerRegex.append(QRegularExpression(QString("DLL\\samfrt64\\.dll\\sfailed\\sto\\sopen")));
	_indexerRegex.append(QRegularExpression(QString("gpu_thread\\smust\\sbe\\sbetween\\s([0-9]*)\\sand\\s([0-9]*)")));
	_indexerRegex.append(QRegularExpression(QString("vkAllocateMemory\\sfailed")));
	_indexerRegex.append(QRegularExpression(QString("vkQueueSubmit\\sfailed")));
	_indexerRegex.append(QRegularExpression(QString("not\\senough\\sframes\\sto\\sestimate\\srate;\\sconsider\\sincreasing\\sprobesize")));
	_indexerRegex.append(QRegularExpression(QString("librife.dll.\\sGetLastError()\\sreturned\\s126.\\sThe\\sfile\\syou\\stried\\sto\\sload\\sor\\sone\\sof\\sits\\sdependencies\\sis\\sprobably\\smissing\\.")));
	_indexerRegex.append(QRegularExpression(QString("\\[h264_nvenc\\s@\\s\\w*\\]\\s[0-9]*\\sbit\\sencode\\snot\\ssupported")));
	_indexerRegex.append(QRegularExpression(QString("The\\spaging\\sfile\\sis\\stoo\\ssmall\\sfor\\sthis\\soperation\\sto\\scomplete")));
	_indexerRegex.append(QRegularExpression(QString("\\)\\sis\\snot\\ssupported\\sby\\sthe\\sbitstream\\sfilter\\s'hevc_mp4toannexb'.")));
	_indexerRegex.append(QRegularExpression(QString("Failed\\sto\\sallocate\\smemory\\sfor\\splane.\\sOut\\sof\\smemory.")));
	_indexerRegex.append(QRegularExpression(QString("failed\\sto\\screate\\sGPU\\sinstance")));
	_indexerRegex.append(QRegularExpression(QString("lsmas:\\sfailed\\sto\\sconstruct\\sindex.")));
	_indexerRegex.append(QRegularExpression(QString("CUDA\\serror:\\sinvalid\\sdevice\\sordinal")));
	_indexerRegex.append(QRegularExpression(QString("invalid\\s'gpu_id'")));
	_indexerRegex.append(QRegularExpression(QString("torch.cuda.OutOfMemoryError:\\sCUDA\\sout\\sof\\smemory.\\sTried\\sto\\sallocate")));
}

void ProcessErrorRegex::clearBools() {
	_indexerBool.clear();
}

void ProcessErrorRegex::errorRegex(QString output) {
	if (_indexerRegex.isEmpty())
		setupPatterns();

	if (_indexerBool.isEmpty())
		for (int i = 0; i < _indexerRegex.count(); i++)
			_indexerBool << false;

	QRegularExpressionMatch matchPipeError(_indexerRegex.at(GetError::Pipe).match(output));
	QRegularExpressionMatch matchCudaError(_indexerRegex.at(GetError::Cuda).match(output));
	QRegularExpressionMatch matchNvencError(_indexerRegex.at(GetError::Nvenc).match(output));
	QRegularExpressionMatch matchQuickSyncError(_indexerRegex.at(GetError::Qsv).match(output));
	QRegularExpressionMatch matchAmfError(_indexerRegex.at(GetError::Amf).match(output));
	QRegularExpressionMatch matchGpuThreadError(_indexerRegex.at(GetError::Thread).match(output));
	QRegularExpressionMatch matchVkMemoryError(_indexerRegex.at(GetError::Memory).match(output));
	QRegularExpressionMatch matchVkQueueError(_indexerRegex.at(GetError::Queue).match(output));
	QRegularExpressionMatch matchProbeWarning(_indexerRegex.at(GetError::Probe).match(output));
	QRegularExpressionMatch matchNcnnError(_indexerRegex.at(GetError::Ncnn).match(output));
	QRegularExpressionMatch matchNvencBitError(_indexerRegex.at(GetError::NvencBit).match(output));
	QRegularExpressionMatch matchPageError(_indexerRegex.at(GetError::Page).match(output));
	QRegularExpressionMatch matchDolbyError(_indexerRegex.at(GetError::Dolby).match(output));
	QRegularExpressionMatch matchAllocateMem(_indexerRegex.at(GetError::Alloc).match(output));
	QRegularExpressionMatch matchGpuInstance(_indexerRegex.at(GetError::GpuInstance).match(output));
	QRegularExpressionMatch matchIndexError(_indexerRegex.at(GetError::IndexFile).match(output));
	QRegularExpressionMatch matchIndexDeviceError(_indexerRegex.at(GetError::IndexDevice).match(output));
	QRegularExpressionMatch matchInvalidGpuError(_indexerRegex.at(GetError::InvalidGPU).match(output));
	QRegularExpressionMatch matchVramError(_indexerRegex.at(GetError::Vram).match(output));

	if (matchPipeError.hasMatch())
		_indexerBool.replace(GetError::Pipe, true);
	if (matchCudaError.hasMatch())
		_indexerBool.replace(GetError::Cuda, true);
	if (matchNvencError.hasMatch())
		_indexerBool.replace(GetError::Nvenc, true);
	if (matchQuickSyncError.hasMatch())
		_indexerBool.replace(GetError::Qsv, true);
	if (matchAmfError.hasMatch())
		_indexerBool.replace(GetError::Amf, true);
	if (matchGpuThreadError.hasMatch()) {
		_indexerBool.replace(GetError::Thread, true);

		_minThreads = matchGpuThreadError.captured(1).toInt();
		_maxThreads = matchGpuThreadError.captured(2).toInt();
	}
	if (matchVkMemoryError.hasMatch())
		_indexerBool.replace(GetError::Memory, true);
	if (matchVkQueueError.hasMatch())
		_indexerBool.replace(GetError::Queue, true);
	if (matchProbeWarning.hasMatch())
		_indexerBool.replace(GetError::Probe, true);
	if (matchNcnnError.hasMatch())
		_indexerBool.replace(GetError::Ncnn, true);
	if (matchNvencBitError.hasMatch())
		_indexerBool.replace(GetError::NvencBit, true);
	if (matchPageError.hasMatch())
		_indexerBool.replace(GetError::Page, true);
	if (matchDolbyError.hasMatch())
		_indexerBool.replace(GetError::Dolby, true);
	if (matchAllocateMem.hasMatch())
		_indexerBool.replace(GetError::Alloc, true);
	if (matchGpuInstance.hasMatch())
		_indexerBool.replace(GetError::GpuInstance, true);
	if (matchIndexError.hasMatch())
		_indexerBool.replace(GetError::IndexFile, true);
	if (matchIndexDeviceError.hasMatch())
		_indexerBool.replace(GetError::IndexDevice, true);
	if (matchInvalidGpuError.hasMatch())
		_indexerBool.replace(GetError::InvalidGPU, true);
	if (matchVramError.hasMatch())
		_indexerBool.replace(GetError::Vram, true);

	if (matchCudaError.hasMatch() || matchNvencError.hasMatch() || matchQuickSyncError.hasMatch() || matchAmfError.hasMatch() ||
		matchGpuThreadError.hasMatch() || matchVkMemoryError.hasMatch() || matchVkQueueError.hasMatch() || matchNcnnError.hasMatch() || matchNvencBitError.hasMatch() || 
		matchPageError.hasMatch() || matchAllocateMem.hasMatch() || matchGpuInstance.hasMatch() || matchIndexError.hasMatch() || matchIndexDeviceError.hasMatch() || matchInvalidGpuError.hasMatch() ||
		matchVramError.hasMatch()) {

		#ifdef PROCESSERROR_H
		ProcessError::setCudaError(_indexerBool.at(GetError::Cuda));
		ProcessError::setNvencError(_indexerBool.at(GetError::Nvenc));
		ProcessError::setQuickSyncError(_indexerBool.at(GetError::Qsv));
		ProcessError::setAmfError(_indexerBool.at(GetError::Amf));
		ProcessError::setGpuThreadError(_indexerBool.at(GetError::Thread));
		ProcessError::setMinThreads(_minThreads);
		ProcessError::setMaxThreads(_maxThreads);
		ProcessError::setVkMemoryError(_indexerBool.at(GetError::Memory));
		ProcessError::setVkQueueError(_indexerBool.at(GetError::Queue));
		ProcessError::setNcnnError(_indexerBool.at(GetError::Ncnn));
		ProcessError::setNvencBitError(_indexerBool.at(GetError::NvencBit));
		ProcessError::setAllocateMemory(_indexerBool.at(GetError::Alloc));
		ProcessError::setGpuInstance(_indexerBool.at(GetError::GpuInstance));
		ProcessError::setIndexError(_indexerBool.at(GetError::IndexFile));
		ProcessError::setIndexDeviceError(_indexerBool.at(GetError::IndexDevice));
		ProcessError::setInvalidGpuError(_indexerBool.at(GetError::InvalidGPU));
		ProcessError::setVramError(_indexerBool.at(GetError::Vram));
		
		ProcessError::setError(true);
		#endif // PROCESSERROR_H
	}
	else if (matchPipeError.hasMatch()) {
		#ifdef PROCESSERROR_H
		ProcessError::setPipeError(_indexerBool.at(GetError::Pipe));
		#endif // PROCESSERROR_H
	}

	#ifdef PROCESSERROR_H
	if (matchProbeWarning.hasMatch())
		ProcessError::setProbeError(_indexerBool.at(GetError::Probe));
		
	if (matchDolbyError.hasMatch())
		ProcessError::setDolbyError(_indexerBool.at(GetError::Dolby));
	#endif // PROCESSERROR_H
}