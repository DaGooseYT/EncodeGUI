#include "EncodeGUI.h"

QString EncodeGUI::BuildScript(int width, int height, QString jobID) {
	ScriptBuilder::ClearScript();

	QString matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out, format;

	switch (ui.VideoEncDD->currentIndex()) {
	case 0:
		if (ui.BitDepth264DD->currentIndex() == 0 && ui.ColorSpace264DD->currentIndex() == 0)
			format = "YUV420P8";
		if (ui.BitDepth264DD->currentIndex() == 1 && ui.ColorSpace264DD->currentIndex() == 0)
			format = "YUV420P10";
		if (ui.BitDepth264DD->currentIndex() == 0 && ui.ColorSpace264DD->currentIndex() == 1)
			format = "YUV422P8";
		if (ui.BitDepth264DD->currentIndex() == 1 && ui.ColorSpace264DD->currentIndex() == 1)
			format = "YUV422P10";
		break;
	case 1:
		if (ui.BitDepth265DD->currentIndex() == 0 && ui.ColorSpace265DD->currentIndex() == 0)
			format = "YUV420P8";
		if (ui.BitDepth265DD->currentIndex() == 1 && ui.ColorSpace265DD->currentIndex() == 0)
			format = "YUV420P10";
		if (ui.BitDepth265DD->currentIndex() == 2 && ui.ColorSpace265DD->currentIndex() == 0)
			format = "YUV420P12";
		if (ui.BitDepth265DD->currentIndex() == 0 && ui.ColorSpace265DD->currentIndex() == 1)
			format = "YUV422P8";
		if (ui.BitDepth265DD->currentIndex() == 1 && ui.ColorSpace265DD->currentIndex() == 1)
			format = "YUV422P10";
		if (ui.BitDepth265DD->currentIndex() == 2 && ui.ColorSpace265DD->currentIndex() == 1)
			format = "YUV422P12";
		if (ui.BitDepth265DD->currentIndex() == 0 && ui.ColorSpace265DD->currentIndex() == 2)
			format = "YUV444P8";
		if (ui.BitDepth265DD->currentIndex() == 1 && ui.ColorSpace265DD->currentIndex() == 2)
			format = "YUV444P10";
		if (ui.BitDepth265DD->currentIndex() == 2 && ui.ColorSpace265DD->currentIndex() == 2)
			format = "YUV444P12";
		break;
	case 2:
		format = "YUV422P10";
		break;
	case 3:
		format = "YUV420P8";
		break;
	case 4:
		if (ui.BitDepthVPXDD->currentIndex() == 0 && ui.SampleVPXDD->currentIndex() == 0)
			format = "YUV422P10";
		if (ui.BitDepthVPXDD->currentIndex() == 1 && ui.SampleVPXDD->currentIndex() == 0)
			format = "YUV422P12";
		if (ui.BitDepthVPXDD->currentIndex() == 2 && ui.SampleVPXDD->currentIndex() == 0)
			format = "YUV422P8";
		if (ui.BitDepthVPXDD->currentIndex() == 0 && ui.SampleVPXDD->currentIndex() == 1)
			format = "YUV444P10";
		if (ui.BitDepthVPXDD->currentIndex() == 1 && ui.SampleVPXDD->currentIndex() == 1)
			format = "YUV444P12";
		if (ui.BitDepthVPXDD->currentIndex() == 2 && ui.SampleVPXDD->currentIndex() == 1)
			format = "YUV444P8";
		if (ui.BitDepthVPXDD->currentIndex() == 0 && ui.SampleVPXDD->currentIndex() == 2)
			format = "YUV420P10";
		if (ui.BitDepthVPXDD->currentIndex() == 1 && ui.SampleVPXDD->currentIndex() == 2)
			format = "YUV420P12";
		if (ui.BitDepthVPXDD->currentIndex() == 2 && ui.SampleVPXDD->currentIndex() == 2)
			format = "YUV420P8";
		break;
	case 5:
		format = "YUV420P8";
		break;
	}

	if (!ui.ColorPropsGB->isChecked()) {
		if (VideoInfo::GetMatrix().contains("bt709"))
			matrix_in = "709";
		else if (VideoInfo::GetMatrix().contains("fcc"))
			matrix_in = "fcc";
		else if (VideoInfo::GetMatrix().contains("bt470bg"))
			matrix_in = "470bg";
		else if (VideoInfo::GetMatrix().contains("smpte170m"))
			matrix_in = "170m";
		else if (VideoInfo::GetMatrix().contains("smpte240m"))
			matrix_in = "240m";
		else if (VideoInfo::GetMatrix().contains("ycgco"))
			matrix_in = "ycgco";
		else if (VideoInfo::GetMatrix().contains("bt2020nc"))
			matrix_in = "2020ncl";
		else if (VideoInfo::GetMatrix().contains("bt2020c"))
			matrix_in = "2020cl";
		else {
			matrix_in = "709";
			WriteLog(QString("Warning: Color matrix for source of job %1 is not specified in media info. Assuming BT709.").arg(jobID), false, false, true);
		}

		if (VideoInfo::GetTransfer().contains("bt709"))
			transfer_in = "709";
		else if (VideoInfo::GetTransfer().contains("bt470m"))
			transfer_in = "470m";
		else if (VideoInfo::GetTransfer().contains("bt470bg"))
			transfer_in = "470bg";
		else if (VideoInfo::GetTransfer().contains("log100"))
			transfer_in = "log100";
		else if (VideoInfo::GetTransfer().contains("log316"))
			transfer_in = "log316";
		else if (VideoInfo::GetTransfer().contains("smpte170m"))
			transfer_in = "170m";
		else if (VideoInfo::GetTransfer().contains("smpte240m"))
			transfer_in = "240m";
		else if (VideoInfo::GetTransfer().contains("smpte2084"))
			transfer_in = "st2084";
		else {
			transfer_in = "709";
			WriteLog(QString("Warning: Color transfer for source of job %1 is not specified in media info. Assuming BT709.").arg(jobID), false, false, true);
		}

		if (VideoInfo::GetPrimaries().contains("bt709"))
			primaries_in = "709";
		else if (VideoInfo::GetPrimaries().contains("bt470m"))
			primaries_in = "470m";
		else if (VideoInfo::GetPrimaries().contains("bt470bg"))
			primaries_in = "470bg";
		else if (VideoInfo::GetPrimaries().contains("smpte170m"))
			primaries_in = "170m";
		else if (VideoInfo::GetPrimaries().contains("smpte240m"))
			primaries_in = "240m";
		else if (VideoInfo::GetPrimaries().contains("bt2020"))
			primaries_in = "2020";
		else {
			primaries_in = "709";
			WriteLog(QString("Warning: Color primaries for source of job %1 is not specified in media info. Assuming BT709.").arg(jobID), false, false, true);
		}
	}
	else {
		matrix_in = ui.InputMatrixDD->currentText().toLower().remove("bt");
		transfer_in = ui.InputTransferDD->currentText().toLower().remove("bt");
		primaries_in = ui.InputPrimsDD->currentText().toLower().remove("bt");
	}

	ScriptBuilder::SetInclude();
	ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\LSMASHSource.dll"));

	if (CHECKED(ui.UseAACB))
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\EEDI2.dll")); 

	if (CHECKED(ui.UpscalingGB)) {
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\waifu2x.dll"));
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\srmd.dll"));
	}
	if (CHECKED(ui.InterpolationCB)) {
		if (ui.BackendDD->currentIndex() == 1)
			ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\rife.dll"));
		
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\svpflow1.dll"));
		ScriptBuilder::SetPlugin(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\plugins\\svpflow2.dll"));
	}

	ScriptBuilder::SetInput(ui.SelectInTxtBox->text(), jobID);

	if (CHECKED(ui.UseAACB))
		ScriptBuilder::SetAntiA();

	if (CHECKED(ui.InterpolationCB)) {
		QString fp, tta, uhd, sc, remv;
		int model, thread, num, den, multi, model2;
		int id = ui.GPUInterpDD->currentIndex();
		double inFPS = VideoInfo::GetFrameRate().toDouble();
		double outFPS = ui.OutputFPSNUD->value();
		double scale = 1.0;

		if (ui.PrecisionDD->currentIndex() == 0)
			fp = "False";
		else
			fp = "True";
		if (CHECKED(ui.TTACB))
			tta = "True";
		else
			tta = "False";
		if (CHECKED(ui.SceneChangeCB))
			sc = "True";
		else
			sc = "False";

		if (height > 1440) {
			scale = 0.5;
			uhd = "True";
		}
		else
			uhd = "False";

		model = ui.RIFEModelVKDD->currentIndex();
		model2 = ui.ModelInterpDD->currentIndex();
		thread = ui.GPUThreadDD->currentIndex() + 1;
		multi = Multi(inFPS, outFPS);

		QString fpsString = QString("%1").arg(outFPS);

		if (fpsString.contains(".")) {
			switch (DecimalCounter(fpsString)) {
			case 1:
				den = 10;
				break;
			case 2:
				den = 100;
				break;
			case 3:
				den = 1000;
				break;
			}
		}
		else
			den = 1;

		remv = fpsString.remove(".");
		num = remv.toInt();

		if (ui.ToolInterpDD->currentIndex() == 0 || ui.ToolInterpDD->currentIndex() == 1) {
			ScriptBuilder::SetRGB(matrix_in, transfer_in, primaries_in);

			if (CHECKED(ui.SceneChangeCB))
				if (CHECKED(ui.SCThresholdCB))
					ScriptBuilder::SetSCDetect(QString("%1").arg(ui.SCThresholdNUD->value()));
				else
					ScriptBuilder::SetSCDetect(QString("0.12"));

			if (CHECKED(ui.UpscalingGB))
				UpscaleMD(width, height);

			switch (ui.BackendDD->currentIndex()) {
			case 0:
				ScriptBuilder::SetRIFECuda("cuda", multi, scale, id, fp);
				break;
			case 1:
				if (ui.ToolInterpDD->currentIndex() == 1)
					ScriptBuilder::SetRIFENcnn(model, id, thread, tta, uhd, sc);
				else
					if (model2 == 0)
						ScriptBuilder::SetRIFENcnn(3, id, thread, tta, uhd, sc);
					else if (model2 == 1)
						ScriptBuilder::SetRIFENcnn(1, id, thread, tta, uhd, sc);
					else if (model2 == 2)
						ScriptBuilder::SetRIFENcnn(0, id, thread, tta, uhd, sc);
				break;
			case 2:
				ScriptBuilder::SetRIFECuda("cpu", multi, scale, id, fp);
				break;
			}

			if (ui.ToolInterpDD->currentIndex() == 0 && inFPS * Multi(inFPS, outFPS) != outFPS) {
				ScriptBuilder::SetColorsOut("YUV420P8", "709", "709", "709");

				if (ui.BackendDD->currentIndex() == 0 || ui.BackendDD->currentIndex() == 2)
					ScriptBuilder::SetSVPFlowNoob("True", id, 13, 150, 0, num, den);
				else
					ScriptBuilder::SetSVPFlowNoob("True", id, 13, 0, 0, num, den);
			}
		}
		else {
			QString useGPU;
			int shader = 0, mask = 0, mode = 0;

			if (CHECKED(ui.UseGPUCB))
				useGPU = "True";
			else
				useGPU = "False";

			switch (ui.ShaderDD->currentIndex()) {
			case 0:
				shader = 1;
				break;
			case 1:
				shader = 2;
				break;
			case 2:
				shader = 11;
				break;
			case 3:
				shader = 13;
				break;
			case 4:
				shader = 21;
				break;
			case 5:
				shader = 23;
				break;
			}

			switch (ui.ArtefactMaskDD->currentIndex()) {
			case 0:
				mask = 150;
				break;
			case 1:
				mask = 100;
				break;
			case 2:
				mask = 50;
				break;
			case 3:
				mask = 0;
				break;
			}

			mode = ui.InterpModeDD->currentIndex();

			if (CHECKED(ui.ParamsCB))
				ScriptBuilder::SetSVPFlow(ui.SuperTxtBox->text(), ui.AnalyseTxtBox->text(), ui.SmoothTxtBox->text(), num, den);
			else
				ScriptBuilder::SetSVPFlowNoob(useGPU, id, shader, mask, mode, num, den);
		}
	}

	if (CHECKED(ui.UpscalingGB) && !CHECKED(ui.InterpolationCB)) {
		ScriptBuilder::SetRGB(matrix_in, transfer_in, primaries_in);
		UpscaleMD(width, height);
	}

	if (CHECKED(ui.ColorPropsGB)) {
		matrix_out = ui.OutputMatrixDD->currentText().toLower().remove("bt");
		transfer_out = ui.OutputTransferDD->currentText().toLower().remove("bt");
		primaries_out = ui.OutputPrimsDD->currentText().toLower().remove("bt");

		if (CHECKED(ui.InterpolationCB) || CHECKED(ui.UpscalingGB)) {
			if (CHECKED(ui.InterpolationCB) && ui.ToolInterpDD->currentIndex() == 2)
				ScriptBuilder::SetColorsInOut(format, matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out);
			else
				ScriptBuilder::SetColorsOut(format, matrix_out, transfer_out, primaries_out);
		}
		else
			ScriptBuilder::SetColorsInOut(format, matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out);
	}
	else if (CHECKED(ui.InterpolationCB) || CHECKED(ui.UpscalingGB))
		if (CHECKED(ui.InterpolationCB) && ui.ToolInterpDD->currentIndex() == 2) {}
		else
			ScriptBuilder::SetColorsOut(format, matrix_in, transfer_in, primaries_in);

	ScriptBuilder::SetConcludeClip();

	return ScriptBuilder::GetScript();
}

void EncodeGUI::UpscaleMD(int width, int height) {

	QString tta;
	int fp, thread, id, noise;
	int scale = 2;

	thread = ui.GPUThreadUpscaleDD->currentIndex() + 1;
	id = ui.GPUInterpDD->currentIndex();
	noise = ui.NoiseReduc2xDD->currentIndex() - 1;

	if ((width * 2 < ui.Width2xNUD->value() && width * 3 >= ui.Width2xNUD->value()) && (height * 2 < ui.Height2xNUD->value() && height * 3 >= ui.Height2xNUD->value()))
		scale = 3;
	else if ((width * 3 < ui.Width2xNUD->value() && width * 4 >= ui.Width2xNUD->value()) && (height * 3 < ui.Height2xNUD->value() && height * 4 >= ui.Height2xNUD->value()))
		scale = 4;

	if (ui.Precision2xDD->currentIndex() == 0)
		fp = 32;
	else
		fp = 16;
	if (CHECKED(ui.TTA2xCB))
		tta = "True";
	else
		tta = "False";

	if (ui.ToolUpscaleDD->currentIndex() == 0)
		if (ui.ModelUpscaleDD->currentIndex() != 3) {
			if (CHECKED(ui.MultiGPUGB))
				ScriptBuilder::SetWaifu2x(noise, 2, ui.ModelUpscaleDD->currentIndex(), id, thread, fp, true, ui.GPU1IDNUD->value(), ui.GPU2IDNUD->value());
			else
				ScriptBuilder::SetWaifu2x(noise, 2, ui.ModelUpscaleDD->currentIndex(), id, thread, fp, false, 0, 0);
		}
		else {
			if (CHECKED(ui.MultiGPUGB))
				ScriptBuilder::SetWaifu2x(noise, 1, 2, id, thread, fp, true, ui.GPU1IDNUD->value(), ui.GPU2IDNUD->value());
			else
				ScriptBuilder::SetWaifu2x(noise, 1, 2, id, thread, fp, false, 0, 0);
		}
	else
		if (CHECKED(ui.MultiGPUGB))
			ScriptBuilder::SetSRMD(scale, ui.NoiseLabelSDDD->currentIndex(), id, thread, tta, true, ui.GPU1IDNUD->value(), ui.GPU2IDNUD->value());
		else
			ScriptBuilder::SetSRMD(scale, ui.NoiseLabelSDDD->currentIndex(), id, thread, tta, false, 0, 0);
}

int EncodeGUI::DecimalCounter(QString value) {
	int index = value.indexOf(".");
	int count = value.remove(".").length();

	return count - index;
}

int EncodeGUI::Multi(double inFPS, double outFPS) {
	int multi = 2;

	for (int i = 2; i == multi; i++)
		if (inFPS * i < outFPS)
			multi++;

	return multi;
}