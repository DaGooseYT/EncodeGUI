#include "EncodeGUI.h"

void EncodeGUI::LoadSysSetting() {
	QSettings* sys = new QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI");

	ui.EnablePreviewCB->setChecked(sys->value("preview", true).toBool());
	ui.AutoDelSourceCB->setChecked(sys->value("delsource", false).toBool());
	ui.CompleteMessageCB->setChecked(sys->value("complete", true).toBool());
	ui.ErrorMessageCB->setChecked(sys->value("errormsg", true).toBool());
	ui.UpdateOptCB->setChecked(sys->value("updateopt", true).toBool());

	ui.JobsCB->setChecked(sys->value("jobs", true).toBool());
	ui.FPSCB->setChecked(sys->value("fps", true).toBool());
	ui.BitrateCB->setChecked(sys->value("bitrate", true).toBool());
	ui.TimeLeftCB->setChecked(sys->value("timeleft", true).toBool());
	ui.TimeElapsedCB->setChecked(sys->value("timer", true).toBool());
	ui.PercentageCB->setChecked(sys->value("percent", true).toBool());

	ui.LimitThreadsCB->setChecked(sys->value("threads", false).toBool());
	ui.SCThresholdCB->setChecked(sys->value("sc", false).toBool());
	ui.SCThresholdNUD->setValue(sys->value("scvalue", 0.12).toDouble());
}