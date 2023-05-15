#include "encodegui.hpp"

void EncodeGUI::loadSysSetting() {
	QSettings sys(QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")));

	_ui->EnablePreviewCB->setChecked(sys.value(QString("preview"), true).toBool());
	_ui->AutoDelSourceCB->setChecked(sys.value(QString("delsource"), false).toBool());
	_ui->ErrorMessageCB->setChecked(sys.value(QString("errormsg"), true).toBool());
	_ui->UpdateOptCB->setChecked(sys.value(QString("updateopt"), true).toBool());
	_ui->GenerateOutCB->setChecked(sys.value(QString("genout"), false).toBool());
	_ui->NextJobCB->setChecked(sys.value(QString("nextjob"), true).toBool());
	_ui->JobsCB->setChecked(sys.value(QString("jobs"), true).toBool());
	_ui->FPSCB->setChecked(sys.value(QString("fps"), true).toBool());
	_ui->BitrateCB->setChecked(sys.value(QString("bitrate"), true).toBool());
	_ui->TimeLeftCB->setChecked(sys.value(QString("timeleft"), true).toBool());
	_ui->TimeElapsedCB->setChecked(sys.value(QString("timer"), true).toBool());
	_ui->PercentageCB->setChecked(sys.value(QString("percent"), true).toBool());
	_ui->LimitThreadsCB->setChecked(sys.value(QString("threads"), false).toBool());
	_ui->MultiGPUGB->setChecked(sys.value(QString("dgpu"), false).toBool());
	_ui->GPU1IDNUD->setValue(sys.value(QString("gpu1"), 0).toInt());
	_ui->GPU2IDNUD->setValue(sys.value(QString("gpu2"), 1).toInt());

	_arguments = sys.value(QString("arguments"), QVariantList()).toList();
	_audioArgs = sys.value(QString("audargs"), QVariantList()).toList();
	_vapourScript = sys.value(QString("vs"), QVariantList()).toList();

	foreach(QVariant id, sys.value(QString("jobid"), QVariantList()).toList())
		_job->append(id.toString());

	foreach(QVariant in, sys.value(QString("input"), QVariantList()).toList())
		_inputList->append(in.toString());

	foreach(QVariant out, sys.value(QString("output"), QVariantList()).toList())
		_outputList->append(out.toString());

	foreach(QVariant tmp, sys.value(QString("temp"), QVariantList()).toList())
		_tempList->append(tmp.toString());

	foreach(QVariant sta, sys.value(QString("state"), QVariantList()).toList())
		_state->append(sta.toString());

	foreach(QVariant dur, sys.value(QString("dur"), QVariantList()).toList())
		VideoInfoList::setDuration(dur.toTime());

	foreach(QVariant fr, sys.value(QString("fr"), QVariantList()).toList())
		VideoInfoList::setFrameRate(fr.toString());
}

void EncodeGUI::saveSettings() {
	_sArguments.clear();
	_sJob.clear();
	_sState.clear();
	_sVapourScript.clear();
	_sInputList.clear();
	_sOutputList.clear();
	_sTempList.clear();
	_sAudioArgs.clear();
	_sDuration.clear();
	_sFrameRate.clear();

	_sArguments = _arguments;
	_sAudioArgs = _audioArgs;
	_sVapourScript = _vapourScript;

	foreach(QString id, *_job)
		_sJob.append(id);

	foreach(QString sta, *_state)
		_sState.append(sta);

	foreach(QString in, *_inputList)
		_sInputList.append(in);

	foreach(QString out, *_outputList)
		_sOutputList.append(out);

	foreach(QString temp, *_tempList)
		_sTempList.append(temp);

	FOR_EACH(_arguments.count())
		_sDuration << VideoInfoList::getDuration(i);

	FOR_EACH(_arguments.count())
		_sFrameRate << VideoInfoList::getFrameRate(i);
}

void EncodeGUI::setJobSetting() {
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("arguments"), _sArguments);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("jobid"), _sJob);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("vs"), _sVapourScript);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("input"), _sInputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("output"), _sOutputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("temp"), _sTempList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("audargs"), _sAudioArgs);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("state"), _sState);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("dur"), _sDuration);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("fr"), _sFrameRate);
}