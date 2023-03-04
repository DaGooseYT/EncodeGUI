#include "EncodeGUI.h"

void EncodeGUI::LoadSysSetting() {
	QSettings* sys = new QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI");

	ui.EnablePreviewCB->setChecked(sys->value("preview", true).toBool());
	ui.AutoDelSourceCB->setChecked(sys->value("delsource", false).toBool());
	ui.ErrorMessageCB->setChecked(sys->value("errormsg", true).toBool());
	ui.UpdateOptCB->setChecked(sys->value("updateopt", true).toBool());
	ui.GenerateOutCB->setChecked(sys->value("genout", false).toBool());
	ui.NextJobCB->setChecked(sys->value("nextjob", true).toBool());

	ui.JobsCB->setChecked(sys->value("jobs", true).toBool());
	ui.FPSCB->setChecked(sys->value("fps", true).toBool());
	ui.BitrateCB->setChecked(sys->value("bitrate", true).toBool());
	ui.TimeLeftCB->setChecked(sys->value("timeleft", true).toBool());
	ui.TimeElapsedCB->setChecked(sys->value("timer", true).toBool());
	ui.PercentageCB->setChecked(sys->value("percent", true).toBool());

	ui.LimitThreadsCB->setChecked(sys->value("threads", false).toBool());
	ui.MultiGPUGB->setChecked(sys->value("dgpu", false).toBool());
	ui.GPU1IDNUD->setValue(sys->value("gpu1", 0).toInt());
	ui.GPU2IDNUD->setValue(sys->value("gpu2", 1).toInt());

	foreach(QVariant arg, sys->value("arguments", QVariantList()).toList())
		arguments << arg.toString();

	foreach(QVariant id, sys->value("jobid", QVariantList()).toList())
		job << id.toString();

	foreach(QVariant vs, sys->value("vs", QVariantList()).toList())
		vapourScript << vs.toString();

	foreach(QVariant in, sys->value("input", QVariantList()).toList())
		inputList << in.toString();

	foreach(QVariant out, sys->value("output", QVariantList()).toList())
		outputList << out.toString();

	foreach(QVariant tmp, sys->value("temp", QVariantList()).toList())
		tempList << tmp.toString();

	foreach(QVariant aArgs, sys->value("audargs", QVariantList()).toList())
		AudioArgs << aArgs.toString();

	foreach(QVariant sta, sys->value("state", QVariantList()).toList())
		state << sta.toString();

	foreach(QVariant dur, sys->value("dur", QVariantList()).toList())
		VideoInfoList::SetDuration(dur.toTime());

	foreach(QVariant fr, sys->value("fr", QVariantList()).toList())
		VideoInfoList::SetFrameRate(fr.toString());

	sys->~QSettings();
}

void EncodeGUI::SaveSettings() {
	Varguments.clear();
	Vjob.clear();
	Vstate.clear();
	VvapourScript.clear();
	VinputList.clear();
	VoutputList.clear();
	VtempList.clear();
	VaudioArgs.clear();
	Vduration.clear();
	VframeRate.clear();

	foreach(QString arg, arguments)
		Varguments << arg;

	foreach(QString id, job)
		Vjob << id;

	foreach(QString sta, state)
		Vstate << sta;

	foreach(QString vs, vapourScript)
		VvapourScript << vs;

	foreach(QString in, inputList)
		VinputList << in;

	foreach(QString out, outputList)
		VoutputList << out;

	foreach(QString temp, tempList)
		VtempList << temp;

	foreach(QString audarg, AudioArgs)
		VaudioArgs << audarg;

	FOR_EACH(arguments.count())
		Vduration << VideoInfoList::GetDuration(i);

	FOR_EACH(arguments.count())
		VframeRate << VideoInfoList::GetFrameRate(i);
}

void EncodeGUI::SetJobSetting() {
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("arguments", Varguments);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("jobid", Vjob);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("vs", VvapourScript);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("input", VinputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("output", VoutputList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("temp", VtempList);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("audargs", VaudioArgs);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("state", Vstate);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("dur", Vduration);
	QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("fr", VframeRate);
}