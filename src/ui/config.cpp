#include "encodegui.hpp"

QStringList EncodeGUI::configureAudioM(int stream, int stream2, QString stream3, QString id, QString container) {
	MediaConfig::resetArguments();

	if (stream == 1 && stream3.toInt() == 0) {
		if (_ui->VideoEncDD->currentIndex() != 6) {
			MediaConfig::setOverride();
			MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1").arg(id)));
			MediaConfig::setInput(_ui->SelectInTxtBox->text());
			MediaConfig::setMapAll(QString("v"), QString("0"));
			MediaConfig::setVideoCodec(QString("copy"));
		}

		configureSubtitle(stream, container, id);

		if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter())
			MediaConfig::setVideoChapters();
	}

	if (stream == 1)
		if (_ui->VideoEncDD->currentIndex() != 6)
			MediaConfig::setMap(QString("a"), QString("%1").arg(stream), stream2);
		else
			MediaConfig::setMapMux(QString("a"), stream2);

	if (_isTitle->at(stream3.toInt())) {
		MediaConfig::setAudioMetadata(stream3);
		MediaConfig::setAudioTitle(_title->at(stream3.toInt()));

		if (_isLang->at(stream3.toInt())) {
			MediaConfig::setAudioMetadata(stream3);
			MediaConfig::setAudioLang(_audioLangs->at(stream3.toInt()));
		}
	}
	else if (_isLang->at(stream3.toInt())) {
		MediaConfig::setAudioMetadata(stream3);
		MediaConfig::setAudioLang(_audioLangs->at(stream3.toInt()));
	}

	if (_isEncoding->at(stream3.toInt())) {
		MediaConfig::setAudioCodecMulti(_audioCodec->at(stream3.toInt()), stream3);
			
		if (!_audioCodec->at(stream3.toInt()).contains(QString("libvorbis")))
			MediaConfig::setAudioBitrate(_bitrate->at(stream3.toInt()), stream3);
		else
			MediaConfig::setConstantAudioQuality(_quality->at(stream3.toInt()), stream3);

		if (!_channels->at(stream3.toInt()).contains(QString("0")))
			MediaConfig::setAudioChannels(_channels->at(stream3.toInt()), stream3);
	}
	else
		MediaConfig::setAudioCodecMulti(QString("copy"), stream3);

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6 && stream3.toInt() == _ui->AudioQueue->rowCount() - 1) {
		MediaConfig::setMetaData1();
		MediaConfig::setMetaData2(QString("\"EncodeGUI v%1\"").arg(VERSION));
		MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
	}

	return(MediaConfig::getArguments());
}

QStringList EncodeGUI::configureAudioP(int stream, QString id, QString container) {
	MediaConfig::resetArguments();

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6) {
		MediaConfig::setOverride();
		MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1").arg(id)));
		MediaConfig::setInput(_ui->SelectInTxtBox->text());
		MediaConfig::setMapAll(QString("v"), QString("0"));
		MediaConfig::setVideoCodec(QString("copy"));
	}

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6)
		MediaConfig::setMapAll(QString("a"), QString("%1").arg(stream));
	else if (_ui->VideoEncDD->currentIndex() == 6)
		MediaConfig::setMapSingle(QString("a"));
	
	MediaConfig::setAudioCodec(QString("copy"));

	configureSubtitle(stream, container, id);

	if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter())
		MediaConfig::setVideoChapters();

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6) {
		MediaConfig::setMetaData1();
		MediaConfig::setMetaData2(QString("\"EncodeGUI v%1\"").arg(VERSION));
		MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
	}

	return(MediaConfig::getArguments());
}

QStringList EncodeGUI::configureSubtitle(int stream, QString container, QString id) {
	if (!CHECKED(_ui->AudioCB)) {
		MediaConfig::resetArguments();

		if (_ui->VideoEncDD->currentIndex() != 6) {
			MediaConfig::setOverride();
			MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1%2").arg(id).arg(container)));
			MediaConfig::setInput(_ui->SelectInTxtBox->text());
			MediaConfig::setMapAll(QString("v"), QString("0"));
			MediaConfig::setVideoCodec(QString("copy"));
		}
	}

	if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 0) {
		if (_ui->VideoEncDD->currentIndex() != 6)
			MediaConfig::setMapAll(QString("s"), QString("%1").arg(stream));
		else
			MediaConfig::setMapSingle(QString("s"));

		MediaConfig::setSubtitleCodec(QString("copy"));
	}
	else if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 1) {
		if (_ui->VideoEncDD->currentIndex() != 6)
			MediaConfig::setMapAll(QString("s"), QString("%1").arg(stream));
		else
			MediaConfig::setMapSingle(QString("s"));

		if (container.contains(QString(".mkv")) || container.contains(QString(".webm")))
			MediaConfig::setSubtitleCodec(QString("webvtt"));
		else if (container.contains(QString(".mov")) || container.contains(QString(".mp4")) || container.contains(QString(".3gp")))
			MediaConfig::setSubtitleCodec(QString("mov_text"));
	}

	if (!CHECKED(_ui->AudioCB)) {
		if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter())
			MediaConfig::setVideoChapters();

		if (_ui->VideoEncDD->currentIndex() != 6) {
			MediaConfig::setMetaData1();
			MediaConfig::setMetaData2(QString("\"EncodeGUI v%1\"").arg(VERSION));
			MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
		}

		return(MediaConfig::getArguments());
	}
	else
		return(QStringList());
}

QStringList EncodeGUI::configureVS(QString id) {
	MediaConfig::resetArguments();

	MediaConfig::setVsPipe();
	MediaConfig::append(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1\\%1.vpy").arg(id)));
	MediaConfig::setOutput("-");

	return(MediaConfig::getArguments());
}

QStringList EncodeGUI::configureMux(QString container, QStringList audio, QStringList subtitles) {
	MediaConfig::resetArguments();

	MediaConfig::setOverride();
	MediaConfig::setInput(_ui->SelectInTxtBox->text());

	MediaConfig::setMapMux(QString("V"), 0);
	MediaConfig::setVideoCodec(QString("copy"));

	foreach(QString aud, audio)
		MediaConfig::append(aud);
	foreach(QString sub, subtitles)
		MediaConfig::append(sub);

	MediaConfig::setMetaData1();
	MediaConfig::setMetaData2(QString("\"EncodeGUI v%1\"").arg(VERSION));
	MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);

	return(MediaConfig::getArguments());
}

QStringList EncodeGUI::configureArgs(QString container, QString id, bool twoPass, int pass) {
	MediaConfig::resetArguments();
	MediaConfig::setOverride();

	if (CHECKED(_ui->RotateGB) && CHECKED(_ui->NoAutoRotateCB))
		MediaConfig::setNoAutoRotate();

	MediaConfig::setInput("-");

	switch (_ui->VideoEncDD->currentIndex()) {
	case 0:
		if (!CHECKED(_ui->Hardware264CB)) {
			MediaConfig::setVideoCodec(QString("libx264"));

			if (_ui->EncodeMode264DD->currentIndex() == 0)
				MediaConfig::setConstantRateFactor(_ui->CRFValue264NUD->value());
			else if (_ui->EncodeMode264DD->currentIndex() == 1 || _ui->EncodeMode264DD->currentIndex() == 2) {
				MediaConfig::setVideoBitrate(_ui->Bitrate264NUD->value());
				if (_ui->EncodeMode264DD->currentIndex() == 2)
					MediaConfig::setPass(pass);
			}
			else
				MediaConfig::setConstantQuantizer(_ui->Quantizer264NUD->value());

			if (CHECKED(_ui->Tune264CB))
				MediaConfig::setVideoTune(_ui->Tune264DD->currentText().remove(QString(" ")).toLower());
			
			if (CHECKED(_ui->Preset264CB))
				MediaConfig::setVideoPreset(_ui->Preset264DD->currentText().toLower().remove(QString(" ")));
			
			if (CHECKED(_ui->Profile264GB)) {
				MediaConfig::setVideoProfile(_ui->Profile264DD->currentText().toLower().remove(QString(" ")).remove(QString(":")));

				if (_ui->EntropyCode264DD->currentIndex() == 0)
					MediaConfig::setEntropyCoding(1);
				else
					MediaConfig::setEntropyCoding(0);
				
				if (!_ui->Level264DD->currentText().contains(QString("Unlimited")))
					MediaConfig::setVideoProfileLevel(_ui->Level264DD->currentText());

				if (_ui->BitDepth264DD->currentIndex() == 0 && _ui->ColorSpace264DD->currentIndex() == 0)
					MediaConfig::setPixelFormat(QString("yuv420p"));
				if (_ui->BitDepth264DD->currentIndex() == 1 && _ui->ColorSpace264DD->currentIndex() == 0)
					MediaConfig::setPixelFormat(QString("yuv420p10le"));
				if (_ui->BitDepth264DD->currentIndex() == 0 && _ui->ColorSpace264DD->currentIndex() == 1)
					MediaConfig::setPixelFormat(QString("yuv422p"));
				if (_ui->BitDepth264DD->currentIndex() == 1 && _ui->ColorSpace264DD->currentIndex() == 1)
					MediaConfig::setPixelFormat(QString("yuv422p10le"));
			}

			if (CHECKED(_ui->RefFrames264GB))
				MediaConfig::setRefFrames(_ui->Reference264Sldr->value());
			if (CHECKED(_ui->BFrames264GB))
				MediaConfig::setBFrames(_ui->BFrame264Sldr->value());
		}
		else {
			if (_ui->Hardware264DD->currentText().contains(QString("QuickSync")))
				MediaConfig::setVideoCodec(QString("h264_qsv"));
			else if (_ui->Hardware264DD->currentText().contains(QString("AMF")))
				MediaConfig::setVideoCodec(QString("h264_amf"));
			else if (_ui->Hardware264DD->currentText().contains(QString("NVENC")))
				MediaConfig::setVideoCodec(QString("h264_nvenc"));

			switch (_ui->EncodeMode264HWDD->currentIndex()) {
			case 0:
				if (_ui->Hardware264DD->currentText().contains(QString("NVENC")))
					MediaConfig::setConstantQuantizer(_ui->Quantizer264NUD->value());
				else
					MediaConfig::setQuantizer(_ui->Quantizer264NUD->value());
				break;
			case 1:
				MediaConfig::setVideoBitrate(_ui->Bitrate264NUD->value());
				break;
			case 2:
				MediaConfig::setVideoBitrate(_ui->Bitrate264NUD->value());
				MediaConfig::setPass(pass);
				break;
			}
		}
		break;
	case 1:
		if (!CHECKED(_ui->Hardware265CB)) {
			MediaConfig::setVideoCodec(QString("libx265"));

			if (_ui->EncodeMode265DD->currentIndex() == 0)
				MediaConfig::setConstantRateFactor(_ui->CRFValue265NUD->value());
			else if (_ui->EncodeMode265DD->currentIndex() == 1 || _ui->EncodeMode265DD->currentIndex() == 2)
				MediaConfig::setVideoBitrate(_ui->Bitrate265NUD->value());
			else
				MediaConfig::setConstantQuantizer(_ui->Quantizer265NUD->value());

			if (CHECKED(_ui->Tune265CB))
				MediaConfig::setVideoTune(_ui->Tune265DD->currentText().toLower().remove(QString(" ")));

			if (CHECKED(_ui->Preset265CB))
				MediaConfig::setVideoPreset(_ui->Preset265DD->currentText().toLower().remove(QString(" ")));

			QString profile;

			if (CHECKED(_ui->Profile265GB)) {
				profile = _ui->Profile265DD->currentText().toLower().remove(QString(" ")).remove(QString(":"));

				if (_ui->BitDepth265DD->currentIndex() == 0 && _ui->ColorSpace265DD->currentIndex() == 0)
					MediaConfig::setPixelFormat(QString("yuv420p"));
				if (_ui->BitDepth265DD->currentIndex() == 1 && _ui->ColorSpace265DD->currentIndex() == 0)
					MediaConfig::setPixelFormat(QString("yuv420p10le"));
				if (_ui->BitDepth265DD->currentIndex() == 2 && _ui->ColorSpace265DD->currentIndex() == 0)
					MediaConfig::setPixelFormat(QString("yuv420p12le"));
				if (_ui->BitDepth265DD->currentIndex() == 0 && _ui->ColorSpace265DD->currentIndex() == 1) {
					MediaConfig::setPixelFormat(QString("yuv422p"));
					profile += QString("-8");
				}
				if (_ui->BitDepth265DD->currentIndex() == 1 && _ui->ColorSpace265DD->currentIndex() == 1) {
					MediaConfig::setPixelFormat(QString("yuv422p10le"));
					profile += QString("-10");
				}
				if (_ui->BitDepth265DD->currentIndex() == 2 && _ui->ColorSpace265DD->currentIndex() == 1) {
					MediaConfig::setPixelFormat("yuv422p12le");
					profile += QString("-12");
				}
				if (_ui->BitDepth265DD->currentIndex() == 0 && _ui->ColorSpace265DD->currentIndex() == 2) {
					MediaConfig::setPixelFormat(QString("yuv444p"));
					profile += QString("-8");
				}
				if (_ui->BitDepth265DD->currentIndex() == 1 && _ui->ColorSpace265DD->currentIndex() == 2) {
					MediaConfig::setPixelFormat(QString("yuv444p10le"));
					profile += QString("-10");
				}
				if (_ui->BitDepth265DD->currentIndex() == 2 && _ui->ColorSpace265DD->currentIndex() == 2) {
					MediaConfig::setPixelFormat(QString("yuv444p12le"));
					profile += QString("-12");
				}

				MediaConfig::setVideoProfile(profile);

				if (!_ui->Level265DD->currentText().contains(QString("Unlimited")))
					MediaConfig::setVideoProfileLevel(_ui->Level265DD->currentText());
			}

			if (CHECKED(_ui->RefFrames265GB))
				MediaConfig::setRefFrames(_ui->Reference265Sldr->value());
			if (CHECKED(_ui->BFrames265GB))
				MediaConfig::setBFrames(_ui->BFrame265Sldr->value());

			if ((CHECKED(_ui->FastPass265CB) && _ui->EncodeMode265DD->currentIndex() == 2) || _ui->EncodeMode265DD->currentIndex() == 2 || 
				CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->Profile265GB) || CHECKED(_ui->DBVisionGB))
				MediaConfig::setx265Params();

			if (CHECKED(_ui->FastPass265CB) && _ui->EncodeMode265DD->currentIndex() == 2) {
				MediaConfig::setFastPass();

				if (CHECKED(_ui->Profile265GB) && _ui->Tier265DD->currentIndex() == 0 && (_ui->EncodeMode265DD->currentIndex() == 2 || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->HDRMetadataGB)))
					MediaConfig::setColin();
			}
			if (CHECKED(_ui->Profile265GB) && _ui->Tier265DD->currentIndex() == 0) {
				MediaConfig::setTier(0);

				if (_ui->EncodeMode265DD->currentIndex() == 2 || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->HDRMetadataGB))
					MediaConfig::setColin();
			}
			if (_ui->EncodeMode265DD->currentIndex() == 2) {
				MediaConfig::setStatsFile(TEMPPATH_WIN);
				
				if (CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->DBVisionGB))
					MediaConfig::setColin();
			}
			if (CHECKED(_ui->HDRMetadataGB)) {
				MediaConfig::setHDR10Opt();
				MediaConfig::setColin();
				MediaConfig::setMasterDisplay(_ui->MasterDisplayTxtBox->text());
				MediaConfig::setColin();
				MediaConfig::setMaxCllFall(_ui->MaxCllNUD->value(), _ui->MaxFallNUD->value());
				
				if (CHECKED(_ui->ColorsHDRGB))
					MediaConfig::setColin();

				if (!_ui->DynamicHDRTxtBox->text().isEmpty()) {
					MediaConfig::setColin();
					MediaConfig::setHDRPlus(_ui->DynamicHDRTxtBox->text());
					
					if (CHECKED(_ui->ColorsHDRGB))
						MediaConfig::setColin();
				}
			}

			if (CHECKED(_ui->ColorsHDRGB)) {
				QString mat(_ui->ColorMatrixDD->currentText().toLower());
				QString tra(_ui->ColorTransferDD->currentText().toLower());
				QString prim(_ui->ColorPrimariesDD->currentText().toLower());
				QString range(_ui->ColorRangeDD->currentText().toLower());

				MediaConfig::setx265Colors(mat, tra, prim, range);
			}

			if (CHECKED(_ui->DBVisionGB)) {
				MediaConfig::setColin();
				MediaConfig::setDBVisionRPU(_ui->RpuTxtBox->text());
				MediaConfig::setColin();
				MediaConfig::setDBVisionProfile(_ui->DBProfileDD->currentText());
				MediaConfig::setColin();
				MediaConfig::setBuffer((int)_ui->Bitrate265NUD->value());
			}

			if ((CHECKED(_ui->FastPass265CB) && _ui->EncodeMode265DD->currentIndex() == 2) || _ui->EncodeMode265DD->currentIndex() == 2 ||
				CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->Profile265GB) || CHECKED(_ui->DBVisionGB))
				MediaConfig::setConcludeParams();

			MediaConfig::setAppleTag();
		}
		else {
		    if (_ui->Hardware265DD->currentText().contains(QString("QuickSync")))
				MediaConfig::setVideoCodec(QString("hevc_qsv"));
			else if (_ui->Hardware265DD->currentText().contains(QString("AMF")))
				MediaConfig::setVideoCodec(QString("hevc_amf"));
			else if (_ui->Hardware265DD->currentText().contains(QString("NVENC")))
				MediaConfig::setVideoCodec(QString("hevc_nvenc"));

			switch (_ui->EncodeMode265HWDD->currentIndex()) {
			case 0:
				if (_ui->Hardware265DD->currentText().contains(QString("NVENC")))
					MediaConfig::setConstantQuantizer(_ui->Quantizer265NUD->value());
				else
					MediaConfig::setQuantizer(_ui->Quantizer265NUD->value());
				break;
			case 1:
				MediaConfig::setVideoBitrate(_ui->Bitrate265NUD->value());
				break;
			case 2:
				MediaConfig::setVideoBitrate(_ui->Bitrate265NUD->value());
				MediaConfig::setPass(pass);
				break;
			}
		}

		break;
	case 2:
		MediaConfig::setVideoCodec(QString("prores_ks"));
		MediaConfig::setVideoProfile(QString("%1").arg(_ui->ProfileDD->currentIndex()));
		
		if (CHECKED(_ui->ColorsGB)) {
			QString mtrx(_ui->MatrixProResDD->currentText().toLower());
			QString trans(_ui->TransferProResDD->currentText().toLower());
			QString prims(_ui->TransferProResDD->currentText().toLower());

			MediaConfig::setColorsProRes(mtrx, trans, prims);
		}

		if (_ui->ProfileDD->currentIndex() >= 0 && _ui->ProfileDD->currentIndex() < 4)
			MediaConfig::setPixelFormat(QString("yuv422p10le"));
		else
			MediaConfig::setPixelFormat(QString("yuv444p12le"));

		break;
	case 3:
		MediaConfig::setVideoCodec(QString("libtheora"));

		switch (_ui->EncodeModeTDD->currentIndex()) {
		case 0:
			MediaConfig::setVideoBitrate(_ui->BitrateThNUD->value());
			break;
		case 1:
			MediaConfig::setConstantVideoQuality(_ui->QualityNUD->value());
			break;
		}
		break;
	case 4:
		MediaConfig::setVideoCodec(QString("libvpx-vp9"));
		MediaConfig::setAllThreads();
		MediaConfig::setVp9Quality(_ui->SpeedDD->currentText().toLower());

		switch (_ui->EncodeModeVPXDD->currentIndex()) {
		case 0:
			MediaConfig::setConstantRateFactor(_ui->crfVPXNUD->value());
			break;
		case 1:
			MediaConfig::setVideoBitrate(_ui->BitrateVPXNUD->value());
			break;
		case 2:
			MediaConfig::setVideoBitrate(_ui->BitrateVPXNUD->value());
			MediaConfig::setPass(pass);
			break;
		}

		MediaConfig::setVideoProfile(QString("%1").arg(_ui->ProfileVPXDD->currentIndex()));

		if (_ui->BitDepthVPXDD->currentIndex() == 0 && _ui->SampleVPXDD->currentIndex() == 0)
			MediaConfig::setPixelFormat(QString("yuv422p10le"));
		if (_ui->BitDepthVPXDD->currentIndex() == 1 && _ui->SampleVPXDD->currentIndex() == 0)
			MediaConfig::setPixelFormat(QString("yuv422p12le"));
		if (_ui->BitDepthVPXDD->currentIndex() == 2 && _ui->SampleVPXDD->currentIndex() == 0)
			MediaConfig::setPixelFormat(QString("yuv422p"));
		if (_ui->BitDepthVPXDD->currentIndex() == 0 && _ui->SampleVPXDD->currentIndex() == 1)
			MediaConfig::setPixelFormat(QString("yuv444p10le"));
		if (_ui->BitDepthVPXDD->currentIndex() == 1 && _ui->SampleVPXDD->currentIndex() == 1)
			MediaConfig::setPixelFormat(QString("yuv444p12le"));
		if (_ui->BitDepthVPXDD->currentIndex() == 2 && _ui->SampleVPXDD->currentIndex() == 1)
			MediaConfig::setPixelFormat(QString("yuv444p"));
		if (_ui->BitDepthVPXDD->currentIndex() == 0 && _ui->SampleVPXDD->currentIndex() == 2)
			MediaConfig::setPixelFormat(QString("yuv420p10le"));
		if (_ui->BitDepthVPXDD->currentIndex() == 1 && _ui->SampleVPXDD->currentIndex() == 2)
			MediaConfig::setPixelFormat(QString("yuv420p12le"));
		if (_ui->BitDepthVPXDD->currentIndex() == 2 && _ui->SampleVPXDD->currentIndex() == 2)
			MediaConfig::setPixelFormat(QString("yuv420p"));

		break;
	case 5:
		MediaConfig::setVideoCodec(QString("libsvtav1"));

		switch (_ui->EncodeModeAV1DD->currentIndex()) {
		case 0:
			MediaConfig::setConstantRateFactor(_ui->crfAV1NUD->value());
			break;
		case 1:
			MediaConfig::setVideoBitrate(_ui->BitrateAV1NUD->value());
			break;
		}

		if (_ui->BitDepthAV1DD->currentIndex() == 1)
			MediaConfig::setPixelFormat(QString("yuv420p10le"));
		else
			MediaConfig::setPixelFormat(QString("yuv420p"));
		break;
	}

	if (_ui->VideoEncDD->currentIndex() != 6) {
		if (CHECKED(_ui->UpscalingGB) || CHECKED(_ui->ResizeGB) || CHECKED(_ui->CropGB) || CHECKED(_ui->RotateGB) || CHECKED(_ui->SharpenGB) || CHECKED(_ui->UseDeintCB))
			if (!((CHECKED(_ui->RotateGB) && !CHECKED(_ui->FlipCB) && _ui->AngleDD->currentIndex() == 0) && !CHECKED(_ui->UpscalingGB) && !CHECKED(_ui->ResizeGB) && !CHECKED(_ui->CropGB) && !CHECKED(_ui->SharpenGB)))
				MediaConfig::setFilters();

		if (CHECKED(_ui->UseDeintCB)) {
			MediaConfig::setDeinterlace();

			if (CHECKED(_ui->ResizeGB) || CHECKED(_ui->UpscalingGB) || CHECKED(_ui->CropGB) || CHECKED(_ui->RotateGB) || CHECKED(_ui->SharpenGB))
				MediaConfig::setComma();
		}

		if (CHECKED(_ui->UpscalingGB)) {
			MediaConfig::setVideoResolution(_ui->Width2xNUD->value(), _ui->Height2xNUD->value());

			if (CHECKED(_ui->CropGB) || CHECKED(_ui->RotateGB) || CHECKED(_ui->SharpenGB))
				MediaConfig::setComma();
		}
		else if (CHECKED(_ui->ResizeGB)) {
			MediaConfig::setVideoResolution(_ui->WidthNUD->value(), _ui->HeightNUD->value());

			if (CHECKED(_ui->ResizeAlgoCB))
				MediaConfig::setVideoResizeAlgo(_ui->ResizeAlgoDD->currentText().toLower());

			if (CHECKED(_ui->CropGB) || CHECKED(_ui->RotateGB) || CHECKED(_ui->SharpenGB))
				MediaConfig::setComma();
		}

		if (CHECKED(_ui->CropGB)) {
			MediaConfig::setCrop(_ui->OutWidthNUD->value(), _ui->OutHeightNUD->value(), _ui->EksNUD->value(), _ui->WhyNUD->value());
			
			if (CHECKED(_ui->RotateGB) || CHECKED(_ui->SharpenGB))
				MediaConfig::setComma();
		}
		
		if (CHECKED(_ui->RotateGB)) {
			switch (_ui->AngleDD->currentIndex()) {
			case 1:
				MediaConfig::setTransposeVideo(1);
				break;
			case 2:
				MediaConfig::setTransposeVideo(1);
				MediaConfig::setComma();
				MediaConfig::setTransposeVideo(1);
				break;
			case 3:
				MediaConfig::setTransposeVideo(3);
				break;
			}
			if (_ui->AngleDD->currentIndex() != 0 && CHECKED(_ui->FlipCB) || CHECKED(_ui->SharpenGB))
				MediaConfig::setComma();
			
			if (CHECKED(_ui->FlipCB)) {

				switch (_ui->FlipDD->currentIndex()) {
				case 0:
					MediaConfig::setFlipVideo(QString("h"));
					break;
				case 1:
					MediaConfig::setFlipVideo(QString("v"));
					break;
				}

				if (CHECKED(_ui->SharpenGB))
					MediaConfig::setComma();
			}
		}

		if (CHECKED(_ui->SharpenGB)) {
			QString radius, strength;

			switch (_ui->RadiusDD->currentIndex()) {
			case 0:
				radius = QString("3:3");
				break;
			case 1:
				radius = QString("5:5");
				break;
			case 2:
				radius = QString("7:7");
				break;
			}

			switch (_ui->StrengthDD->currentIndex()) {
			case 0:
				strength = QString("0.5");
				break;
			case 1:
				strength = QString("1.0");
				break;
			case 2:
				strength = QString("2.0");
				break;
			case 3:
				strength = QString("3.5");
				break;
			case 4:
				strength = QString("5.0");
				break;
			}

			MediaConfig::setSharpenVideo(radius, strength);
		}

		if (CHECKED(_ui->UseDeintCB) || CHECKED(_ui->UpscalingGB) || CHECKED(_ui->ResizeGB) || CHECKED(_ui->CropGB) || CHECKED(_ui->RotateGB) || CHECKED(_ui->SharpenGB))
			if (!((CHECKED(_ui->RotateGB) && !CHECKED(_ui->FlipCB) && _ui->AngleDD->currentIndex() == 0) && !CHECKED(_ui->UpscalingGB) && !CHECKED(_ui->ResizeGB) && !CHECKED(_ui->CropGB) && !CHECKED(_ui->SharpenGB)))
				MediaConfig::setConcludeFilters();
	}

	if (twoPass) {
		if (_ui->VideoEncDD->currentIndex() != 1)
			MediaConfig::setPassLogFile(TEMPPATH_WIN);
		
		MediaConfig::setNullPath();
	}
	else
		if (CHECKED(_ui->AudioCB) || CHECKED(_ui->SubtitlesCB))
			MediaConfig::setOutput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1.mkv").arg(id)));
		else if (!CHECKED(_ui->AudioCB) && !CHECKED(_ui->SubtitlesCB)) {
			if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter())
				MediaConfig::setVideoChapters();

			MediaConfig::setMetaData1();
			MediaConfig::setMetaData2(QString("\"EncodeGUI v%1\"").arg(VERSION));
			MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
		}

	return(MediaConfig::getArguments());
}