#include "../../include/processerrorregex.hpp"

QList<bool> ProcessErrorRegex::IndexerBool;
QList<QRegularExpression> ProcessErrorRegex::IndexerRegex;

int ProcessErrorRegex::MinThreads;
int ProcessErrorRegex::MaxThreads;

void ProcessErrorRegex::SetupPatterns() {
	IndexerRegex << QRegularExpression("pipe::\\sInvalid\\sdata\\sfound\\swhen\\sprocessing\\sinput");
	IndexerRegex << QRegularExpression("RuntimeError:\\sCUDA\\serror:\\sinvalid\\sdevice\\sordinal");
	IndexerRegex << QRegularExpression("Cannot\\sload\\snvEncodeAPI64\\.dll");
	IndexerRegex << QRegularExpression("Error\\squerying\\sencoder\\sparams:\\sunsupported");
	IndexerRegex << QRegularExpression("DLL\\samfrt64\\.dll\\sfailed\\sto\\sopen");
	IndexerRegex << QRegularExpression("gpu_thread\\smust\\sbe\\sbetween\\s([0-9]*)\\sand\\s([0-9]*)");
	IndexerRegex << QRegularExpression("vkAllocateMemory\\sfailed");
	IndexerRegex << QRegularExpression("vkQueueSubmit\\sfailed");
	IndexerRegex << QRegularExpression("not\\senough\\sframes\\sto\\sestimate\\srate;\\sconsider\\sincreasing\\sprobesize");
	IndexerRegex << QRegularExpression("The\\sfile\\syou\\stried\\sto\\sload\\sor\\sone\\sof\\sits\\sdependencies\\sis\\sprobably\\smissing\\.");
	IndexerRegex << QRegularExpression("\\[h264_nvenc\\s@\\s\\w*\\]\\s[0-9]*\\sbit\\sencode\\snot\\ssupported");
	IndexerRegex << QRegularExpression("The\\spaging\\sfile\\sis\\stoo\\ssmall\\sfor\\sthis\\soperation\\sto\\scomplete");
}

void ProcessErrorRegex::ClearBools() {
	IndexerBool.clear();
}

void ProcessErrorRegex::ErrorRegex(QString output) {
	if (IndexerRegex.isEmpty())
		SetupPatterns();

	if (IndexerBool.isEmpty())
		for (int i = 0; i < IndexerRegex.count(); i++)
			IndexerBool << false;

	QRegularExpressionMatch matchPipeError = IndexerRegex.at(GetError::Pipe).match(output);
	QRegularExpressionMatch matchCudaError = IndexerRegex.at(GetError::Cuda).match(output);
	QRegularExpressionMatch matchNvencError = IndexerRegex.at(GetError::Nvenc).match(output);
	QRegularExpressionMatch matchQuickSyncError = IndexerRegex.at(GetError::Qsv).match(output);
	QRegularExpressionMatch matchAmfError = IndexerRegex.at(GetError::Amf).match(output);
	QRegularExpressionMatch matchGpuThreadError = IndexerRegex.at(GetError::Thread).match(output);
	QRegularExpressionMatch matchVkMemoryError = IndexerRegex.at(GetError::Memory).match(output);
	QRegularExpressionMatch matchVkQueueError = IndexerRegex.at(GetError::Queue).match(output);
	QRegularExpressionMatch matchProbeWarning = IndexerRegex.at(GetError::Probe).match(output);
	QRegularExpressionMatch matchNcnnError = IndexerRegex.at(GetError::Ncnn).match(output);
	QRegularExpressionMatch matchNvencBitError = IndexerRegex.at(GetError::NvencBit).match(output);
	QRegularExpressionMatch matchPageError = IndexerRegex.at(GetError::Page).match(output);

	if (matchPipeError.hasMatch())
		IndexerBool.replace(GetError::Pipe, true);
	if (matchCudaError.hasMatch())
		IndexerBool.replace(GetError::Cuda, true);
	if (matchNvencError.hasMatch())
		IndexerBool.replace(GetError::Nvenc, true);
	if (matchQuickSyncError.hasMatch())
		IndexerBool.replace(GetError::Qsv, true);
	if (matchAmfError.hasMatch())
		IndexerBool.replace(GetError::Amf, true);
	if (matchGpuThreadError.hasMatch()) {
		IndexerBool.replace(GetError::Thread, true);

		MinThreads = matchGpuThreadError.captured(1).toInt();
		MaxThreads = matchGpuThreadError.captured(2).toInt();
	}
	if (matchVkMemoryError.hasMatch())
		IndexerBool.replace(GetError::Memory, true);
	if (matchVkQueueError.hasMatch())
		IndexerBool.replace(GetError::Queue, true);
	if (matchProbeWarning.hasMatch())
		IndexerBool.replace(GetError::Probe, true);
	if (matchNcnnError.hasMatch())
		IndexerBool.replace(GetError::Ncnn, true);
	if (matchNvencBitError.hasMatch())
		IndexerBool.replace(GetError::NvencBit, true);
	if (matchPageError.hasMatch())
		IndexerBool.replace(GetError::Page, true);

	if (matchCudaError.hasMatch() || matchNvencError.hasMatch() || matchQuickSyncError.hasMatch() || matchAmfError.hasMatch() ||
		matchGpuThreadError.hasMatch() || matchVkMemoryError.hasMatch() || matchVkQueueError.hasMatch() || matchNcnnError.hasMatch() || matchNvencBitError.hasMatch() || matchPageError.hasMatch()) {

#ifdef PROCESSERROR_H
		ProcessError::SetCudaError(IndexerBool.at(GetError::Cuda));
		ProcessError::SetNvencError(IndexerBool.at(GetError::Nvenc));
		ProcessError::SetQuickSyncError(IndexerBool.at(GetError::Qsv));
		ProcessError::SetAmfError(IndexerBool.at(GetError::Amf));
		ProcessError::SetGpuThreadError(IndexerBool.at(GetError::Thread));
		ProcessError::SetMinThreads(MinThreads);
		ProcessError::SetMaxThreads(MaxThreads);
		ProcessError::SetVkMemoryError(IndexerBool.at(GetError::Memory));
		ProcessError::SetVkQueueError(IndexerBool.at(GetError::Queue));
		ProcessError::SetNcnnError(IndexerBool.at(GetError::Ncnn));
		ProcessError::SetNvencBitError(IndexerBool.at(GetError::NvencBit));
		
		ProcessError::SetError(true);
#endif // PROCESSERROR_H
	}
	else if (matchPipeError.hasMatch()) {
#ifdef PROCESSERROR_H
		ProcessError::SetPipeError(IndexerBool.at(GetError::Pipe));
#endif // PROCESSERROR_H
	}

#ifdef PROCESSERROR_H
	if (matchProbeWarning.hasMatch())
		ProcessError::SetProbeError(IndexerBool.at(GetError::Probe));
#endif // PROCESSERROR_H
}