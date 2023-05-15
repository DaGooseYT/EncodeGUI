#include "encodegui.hpp"

QString EncodeGUI::buildScript(int width, int height, QString jobID) {
	ScriptBuilder::clearScript();

	QString matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out, format;

	switch (_ui->VideoEncDD->currentIndex()) {
	case 0:
		if (_ui->BitDepth264DD->currentIndex() == 0 && _ui->ColorSpace264DD->currentIndex() == 0)
			format = QString("YUV420P8");
		if (_ui->BitDepth264DD->currentIndex() == 1 && _ui->ColorSpace264DD->currentIndex() == 0)
			format = QString("YUV420P10");
		if (_ui->BitDepth264DD->currentIndex() == 0 && _ui->ColorSpace264DD->currentIndex() == 1)
			format = QString("YUV422P8");
		if (_ui->BitDepth264DD->currentIndex() == 1 && _ui->ColorSpace264DD->currentIndex() == 1)
			format = QString("YUV422P10");
		break;
	case 1:
		if (_ui->BitDepth265DD->currentIndex() == 0 && _ui->ColorSpace265DD->currentIndex() == 0)
			format = QString("YUV420P8");
		if (_ui->BitDepth265DD->currentIndex() == 1 && _ui->ColorSpace265DD->currentIndex() == 0)
			format = QString("YUV420P10");
		if (_ui->BitDepth265DD->currentIndex() == 2 && _ui->ColorSpace265DD->currentIndex() == 0)
			format = QString("YUV420P12");
		if (_ui->BitDepth265DD->currentIndex() == 0 && _ui->ColorSpace265DD->currentIndex() == 1)
			format = QString("YUV422P8");
		if (_ui->BitDepth265DD->currentIndex() == 1 && _ui->ColorSpace265DD->currentIndex() == 1)
			format = QString("YUV422P10");
		if (_ui->BitDepth265DD->currentIndex() == 2 && _ui->ColorSpace265DD->currentIndex() == 1)
			format = QString("YUV422P12");
		if (_ui->BitDepth265DD->currentIndex() == 0 && _ui->ColorSpace265DD->currentIndex() == 2)
			format = QString("YUV444P8");
		if (_ui->BitDepth265DD->currentIndex() == 1 && _ui->ColorSpace265DD->currentIndex() == 2)
			format = QString("YUV444P10");
		if (_ui->BitDepth265DD->currentIndex() == 2 && _ui->ColorSpace265DD->currentIndex() == 2)
			format = QString("YUV444P12");
		break;
	case 2:
		format = QString("YUV422P10");
		break;
	case 3:
		format = QString("YUV420P8");
		break;
	case 4:
		if (_ui->BitDepthVPXDD->currentIndex() == 0 && _ui->SampleVPXDD->currentIndex() == 0)
			format = QString("YUV422P10");
		if (_ui->BitDepthVPXDD->currentIndex() == 1 && _ui->SampleVPXDD->currentIndex() == 0)
			format = QString("YUV422P12");
		if (_ui->BitDepthVPXDD->currentIndex() == 2 && _ui->SampleVPXDD->currentIndex() == 0)
			format = QString("YUV422P8");
		if (_ui->BitDepthVPXDD->currentIndex() == 0 && _ui->SampleVPXDD->currentIndex() == 1)
			format = QString("YUV444P10");
		if (_ui->BitDepthVPXDD->currentIndex() == 1 && _ui->SampleVPXDD->currentIndex() == 1)
			format = QString("YUV444P12");
		if (_ui->BitDepthVPXDD->currentIndex() == 2 && _ui->SampleVPXDD->currentIndex() == 1)
			format = QString("YUV444P8");
		if (_ui->BitDepthVPXDD->currentIndex() == 0 && _ui->SampleVPXDD->currentIndex() == 2)
			format = QString("YUV420P10");
		if (_ui->BitDepthVPXDD->currentIndex() == 1 && _ui->SampleVPXDD->currentIndex() == 2)
			format = QString("YUV420P12");
		if (_ui->BitDepthVPXDD->currentIndex() == 2 && _ui->SampleVPXDD->currentIndex() == 2)
			format = QString("YUV420P8");
		break;
	case 5:
		format = QString("YUV420P8");
		break;
	}

	if (!_ui->ColorPropsGB->isChecked()) {
		if (VideoInfo::getMatrix().contains(QString("bt709")))
			matrix_in = QString("709");
		else if (VideoInfo::getMatrix().contains(QString("fcc")))
			matrix_in = QString("fcc");
		else if (VideoInfo::getMatrix().contains(QString("bt470bg")))
			matrix_in = QString("470bg");
		else if (VideoInfo::getMatrix().contains(QString("smpte170m")))
			matrix_in = QString("170m");
		else if (VideoInfo::getMatrix().contains(QString("smpte240m")))
			matrix_in = QString("240m");
		else if (VideoInfo::getMatrix().contains(QString("ycgco")))
			matrix_in = QString("ycgco");
		else if (VideoInfo::getMatrix().contains(QString("bt2020nc")))
			matrix_in = QString("2020ncl");
		else if (VideoInfo::getMatrix().contains(QString("bt2020c")))
			matrix_in = QString("2020cl");
		else {
			matrix_in = QString("709");
			writeLog(QString("Warning: Color matrix for source of job %1 is not specified in media info. Assuming BT709.").arg(jobID), false, false, true);
		}

		if (VideoInfo::getTransfer().contains(QString("bt709")))
			transfer_in = QString("709");
		else if (VideoInfo::getTransfer().contains(QString("bt470m")))
			transfer_in = QString("470m");
		else if (VideoInfo::getTransfer().contains(QString("bt470bg")))
			transfer_in = QString("470bg");
		else if (VideoInfo::getTransfer().contains(QString("log100")))
			transfer_in = QString("log100");
		else if (VideoInfo::getTransfer().contains(QString("log316")))
			transfer_in = QString("log316");
		else if (VideoInfo::getTransfer().contains(QString("smpte170m")))
			transfer_in = QString("170m");
		else if (VideoInfo::getTransfer().contains(QString("smpte240m")))
			transfer_in = QString("240m");
		else if (VideoInfo::getTransfer().contains(QString("smpte2084")))
			transfer_in = QString("st2084");
		else {
			transfer_in = QString("709");
			writeLog(QString("Warning: Color transfer for source of job %1 is not specified in media info. Assuming BT709.").arg(jobID), false, false, true);
		}

		if (VideoInfo::getPrimaries().contains(QString("bt709")))
			primaries_in = QString("709");
		else if (VideoInfo::getPrimaries().contains(QString("bt470m")))
			primaries_in = QString("470m");
		else if (VideoInfo::getPrimaries().contains(QString("bt470bg")))
			primaries_in = QString("470bg");
		else if (VideoInfo::getPrimaries().contains(QString("smpte170m")))
			primaries_in = QString("170m");
		else if (VideoInfo::getPrimaries().contains(QString("smpte240m")))
			primaries_in = QString("240m");
		else if (VideoInfo::getPrimaries().contains(QString("bt2020")))
			primaries_in = QString("2020");
		else {
			primaries_in = QString("709");
			writeLog(QString("Warning: Color primaries for source of job %1 is not specified in media info. Assuming BT709.").arg(jobID), false, false, true);
		}
	}
	else {
		matrix_in = _ui->InputMatrixDD->currentText().toLower().remove(QString("bt"));
		transfer_in = _ui->InputTransferDD->currentText().toLower().remove(QString("bt"));
		primaries_in = _ui->InputPrimsDD->currentText().toLower().remove(QString("bt"));
	}

	ScriptBuilder::setInclude();
	ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\liblsmashsource.dll")));

	if (CHECKED(_ui->UseAACB))
		ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\libeedi2.dll")));

	if (CHECKED(_ui->UpscalingGB)) {
		ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\libwaifu2x.dll")));
		ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\libsrmdnv.dll")));
	}
	if (CHECKED(_ui->InterpolationCB)) {
		if (_ui->BackendDD->currentIndex() == 1)
			ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\librife.dll")));
		
		ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\libsvpflow.1.dll")));
		ScriptBuilder::setPlugin(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\vs\\plugins\\libsvpflow.2.dll")));
	}

	ScriptBuilder::setInput(_ui->SelectInTxtBox->text(), jobID);

	if (CHECKED(_ui->UseAACB))
		ScriptBuilder::setAntiA();

	if (CHECKED(_ui->InterpolationCB)) {
		QString fp, tta, uhd, sc, remv;
		int model, thread, num, den, multI, multi2, model2;
		int id = _ui->GPUInterpDD->currentIndex();
		double model3;
		double inFPS = VideoInfo::getFrameRate().toDouble();
		double outFPS = _ui->OutputFPSNUD->value();
		double scale = 1.0;

		if (CHECKED(_ui->SceneChangeCB))
			sc = QString("True");
		else
			sc = QString("False");

		if (height > 1440) {
			scale = 0.5;
			uhd = QString("True");
		}
		else
			uhd = QString("False");

		tta = QString("False");

		model = _ui->RIFEModelVKDD->currentIndex();
		model2 = _ui->ModelInterpDD->currentIndex();
		model3 = _ui->RIFEModelCADD->currentText().remove(QString("v")).toDouble();
		thread = _ui->GPUThreadDD->currentIndex() + 1;
		multI = multi(inFPS, outFPS);

		QString fpsString = QString("%1").arg(outFPS);

		if (fpsString.contains(QString("."))) {
			switch (decimalCounter(fpsString)) {
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

		remv = fpsString.remove(QString("."));
		num = remv.toInt();

		if (_ui->ToolInterpDD->currentIndex() == 0 || _ui->ToolInterpDD->currentIndex() == 1) {
			ScriptBuilder::setRGB(matrix_in, transfer_in, primaries_in);

			if (CHECKED(_ui->SceneChangeCB))
				ScriptBuilder::setSCDetect(QString("%1").arg(_ui->SCThresholdNUD->value()));

			if (CHECKED(_ui->UpscalingGB))
				upscaleMD(width, height);

			switch (_ui->BackendDD->currentIndex()) {
			case 0:
				if (_ui->ToolInterpDD->currentIndex() == 1) {
					if (model3 == 4.0)
						ScriptBuilder::setRIFECuda(id, model3, num, den, scale, sc, QString("False"));
					else
						ScriptBuilder::setRIFECuda(id, model3, num, den, scale, sc, QString("True"));
				}
				else
					if (model2 == 0)
						ScriptBuilder::setRIFECuda(id, 4.6, QString("%1").arg(multI * inFPS).remove(QString(".")).toInt(), den, scale, sc, QString("False"));
					else if (model2 == 1)
						ScriptBuilder::setRIFECuda(id, 4.0, QString("%1").arg(multI* inFPS).remove(QString(".")).toInt(), den, scale, sc, QString("True"));
				break;
			case 1:
				if (_ui->ToolInterpDD->currentIndex() == 1) {
					if (_ui->RIFEModelVKDD->currentIndex() < 4)
						ScriptBuilder::setRIFENcnn(model, id, thread, tta, uhd, sc);
					else
						ScriptBuilder::setRIFENcnnNew(model, id, thread, num, den, tta, uhd, sc);
				}
				else
					if (model2 == 0)
						ScriptBuilder::setRIFENcnnNew(5, id, thread, QString("%1").arg(multI * inFPS).remove(QString(".")).toInt(), den, tta, uhd, sc);
					else if (model2 == 1)
						ScriptBuilder::setRIFENcnn(1, id, thread, tta, uhd, sc);
					else if (model2 == 2)
						ScriptBuilder::setRIFENcnn(0, id, thread, tta, uhd, sc);
				break;
			}

			if (_ui->ToolInterpDD->currentIndex() == 0 && inFPS * multI != outFPS) {
				ScriptBuilder::setColorsOut(QString("YUV420P8"), QString("709"), QString("709"), QString("709"));

				if (_ui->BackendDD->currentIndex() == 0 || _ui->BackendDD->currentIndex() == 2)
					ScriptBuilder::setSVPFlowNoob(QString("True"), id, 13, 150, 0, num, den);
				else
					ScriptBuilder::setSVPFlowNoob(QString("True"), id, 13, 0, 0, num, den);
			}
		}
		else {
			QString useGPU;
			int shader = 0, mask = 0, mode = 0;

			if (CHECKED(_ui->UseGPUCB))
				useGPU = QString("True");
			else
				useGPU = QString("False");

			switch (_ui->ShaderDD->currentIndex()) {
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

			switch (_ui->ArtefactMaskDD->currentIndex()) {
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

			mode = _ui->InterpModeDD->currentIndex();

			if (CHECKED(_ui->ParamsCB))
				ScriptBuilder::setSVPFlow(_ui->SuperTxtBox->text(), _ui->AnalyseTxtBox->text(), _ui->SmoothTxtBox->text(), num, den);
			else
				ScriptBuilder::setSVPFlowNoob(useGPU, id, shader, mask, mode, num, den);
		}
	}

	if (CHECKED(_ui->UpscalingGB) && !CHECKED(_ui->InterpolationCB)) {
		ScriptBuilder::setRGB(matrix_in, transfer_in, primaries_in);
		upscaleMD(width, height);
	}

	if (CHECKED(_ui->ColorPropsGB)) {
		matrix_out = _ui->OutputMatrixDD->currentText().toLower().remove(QString("bt"));
		transfer_out = _ui->OutputTransferDD->currentText().toLower().remove(QString("bt"));
		primaries_out = _ui->OutputPrimsDD->currentText().toLower().remove(QString("bt"));

		if (CHECKED(_ui->InterpolationCB) || CHECKED(_ui->UpscalingGB)) {
			if (CHECKED(_ui->InterpolationCB) && _ui->ToolInterpDD->currentIndex() == 2)
				ScriptBuilder::setColorsInOut(format, matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out);
			else
				ScriptBuilder::setColorsOut(format, matrix_out, transfer_out, primaries_out);
		}
		else
			ScriptBuilder::setColorsInOut(format, matrix_in, transfer_in, primaries_in, matrix_out, transfer_out, primaries_out);
	}
	else if (CHECKED(_ui->InterpolationCB) || CHECKED(_ui->UpscalingGB))
		if (CHECKED(_ui->InterpolationCB) && _ui->ToolInterpDD->currentIndex() == 2) {}
		else
			ScriptBuilder::setColorsOut(format, matrix_in, transfer_in, primaries_in);

	ScriptBuilder::setConcludeClip();

	return(ScriptBuilder::getScript());
}

void EncodeGUI::upscaleMD(int width, int height) {
	QString tta;
	int fp, thread, id, noise;
	int scale = 2;

	thread = _ui->GPUThreadUpscaleDD->currentIndex() + 1;
	id = _ui->GPUInterpDD->currentIndex();
	noise = _ui->NoiseReduc2xDD->currentIndex() - 1;

	if ((width * 2 < _ui->Width2xNUD->value() && width * 3 >= _ui->Width2xNUD->value()) && (height * 2 < _ui->Height2xNUD->value() && height * 3 >= _ui->Height2xNUD->value()))
		scale = 3;
	else if ((width * 3 < _ui->Width2xNUD->value() && width * 4 >= _ui->Width2xNUD->value()) && (height * 3 < _ui->Height2xNUD->value() && height * 4 >= _ui->Height2xNUD->value()))
		scale = 4;

	if (_ui->Precision2xDD->currentIndex() == 0)
		fp = 32;
	else
		fp = 16;
	if (CHECKED(_ui->TTA2xCB))
		tta = QString("True");
	else
		tta = QString("False");

	if (_ui->ToolUpscaleDD->currentIndex() == 0)
		if (_ui->ModelUpscaleDD->currentIndex() != 3) {
			if (CHECKED(_ui->MultiGPUGB))
				ScriptBuilder::setWaifu2x(noise, 2, _ui->ModelUpscaleDD->currentIndex(), id, thread, fp, true, _ui->GPU1IDNUD->value(), _ui->GPU2IDNUD->value());
			else
				ScriptBuilder::setWaifu2x(noise, 2, _ui->ModelUpscaleDD->currentIndex(), id, thread, fp, false, 0, 0);
		}
		else {
			if (CHECKED(_ui->MultiGPUGB))
				ScriptBuilder::setWaifu2x(noise, 1, 2, id, thread, fp, true, _ui->GPU1IDNUD->value(), _ui->GPU2IDNUD->value());
			else
				ScriptBuilder::setWaifu2x(noise, 1, 2, id, thread, fp, false, 0, 0);
		}
	else
		if (CHECKED(_ui->MultiGPUGB))
			ScriptBuilder::setSRMD(scale, _ui->NoiseLabelSDDD->currentIndex(), id, thread, tta, true, _ui->GPU1IDNUD->value(), _ui->GPU2IDNUD->value());
		else
			ScriptBuilder::setSRMD(scale, _ui->NoiseLabelSDDD->currentIndex(), id, thread, tta, false, 0, 0);
}

int EncodeGUI::decimalCounter(QString value) {
	int index = value.indexOf(QString("."));
	int count = value.remove(QString(".")).length();

	return(count - index);
}

int EncodeGUI::multi(double inFPS, double outFPS) {
	int multi = 1;

	for (int i = 1; i == multi; i++)
		if (inFPS * i < outFPS) {
			if (inFPS * (i + 1) > outFPS)
				break;
			else
				multi++;
		}

	return(multi);
}