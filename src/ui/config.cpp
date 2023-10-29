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

#include "encodegui.hpp"

QStringList EncodeGUI::configureAudioM(int stream, int index, QVariantList stream2, QString id, QString container) {
	if (stream == 1) {
		MediaConfig::resetArguments();
		
		if (_ui->VideoEncDD->currentIndex() != 6) {
			MediaConfig::setOverride();

			#ifdef Q_OS_WINDOWS
			MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1").arg(id)));
			#endif
			#ifdef Q_OS_DARWIN
			MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1").arg(id)));
			#endif

			if (_ui->AudioDD->currentIndex() != 1)
				MediaConfig::setInput(_ui->SelectInTxtBox->text());
			else
				foreach(QString path, *_streamInputs)
					MediaConfig::setInput(path);

			MediaConfig::setMapAll(QString("v"), 0);
			MediaConfig::setVideoCodec(QString("copy"));
		}

		if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter())
			MediaConfig::setVideoChapters();
	}

	for (int i = _streamNum; i < stream2.count() + _streamNum; i++) {
		if (stream > 0) {
			if (_ui->VideoEncDD->currentIndex() != 6)
				MediaConfig::setMap(QString("a"), _audioStream->at(i).toInt(), stream2.at(index).toInt());
			else {
				if (_streamInputs->count() > 1)
					MediaConfig::setMap(QString("a"), _audioStream->at(i).toInt(), stream2.at(index).toInt());
				else if (_streamInputs->count() == 1)
					MediaConfig::setMapMux(QString("a"), stream2.at(index).toInt());
			}
		}

		if (_isTitle->at(i)) {
			MediaConfig::setAudioMetadata(i);
			MediaConfig::setAudioTitle(_title->at(i));

			if (_isLang->at(i)) {
				MediaConfig::setAudioMetadata(i);
				MediaConfig::setAudioLang(_audioLangs->at(i));
			}
		}
		else if (_isLang->at(i)) {
			MediaConfig::setAudioMetadata(i);
			MediaConfig::setAudioLang(_audioLangs->at(i));
		}

		if (_isEncoding->at(i)) {
			MediaConfig::setAudioCodecMulti(_audioCodec->at(i), i);

			if (!_audioCodec->at(i).contains(QString("libvorbis")))
				MediaConfig::setAudioBitrate(_bitrate->at(i), i);
			else
				MediaConfig::setConstantAudioQuality(_quality->at(i), i);

			if (!_channels->at(i).contains(QString("0")))
				MediaConfig::setAudioChannels(_channels->at(i), i);
		}
		else
			MediaConfig::setAudioCodecMulti(QString("copy"), i);

		index++;
	}

	_streamNum = stream2.count() + _streamNum;

	if (CHECKED(_ui->SubtitlesCB) && stream == _stream.count())
		configureSubtitle(stream, 0, container, id);

	if (stream == _stream.count() && _ui->VideoEncDD->currentIndex() != 6) {
		MediaConfig::setVideoMetadata();
		MediaConfig::setEncoder(QString("EncodeGUI v%1").arg(VERSION));
		MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
	}

	if (_streamNum == _ui->AudioQueue->rowCount())
		return(MediaConfig::getArguments());
	else
		return(QStringList());
}

QStringList EncodeGUI::configureAudioP(int stream, int stream2, int index, QString id, QString container) {
	MediaConfig::resetArguments();

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6) {
		MediaConfig::setOverride();
		
		#ifdef Q_OS_WINDOWS
		MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1").arg(id)));
		#endif
		#ifdef Q_OS_DARWIN
		MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1").arg(id)));
		#endif

		if (!CHECKED(_ui->BatchCB))
			MediaConfig::setInput(_ui->SelectInTxtBox->text());
		else
			MediaConfig::setInput(_batchFiles->at(index));

		MediaConfig::setMapAll(QString("v"), 0);
		MediaConfig::setVideoCodec(QString("copy"));
	}

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6)
		MediaConfig::setMapAll(QString("a"), stream);
	else if (_ui->VideoEncDD->currentIndex() == 6)
		MediaConfig::setMapSingle(QString("a"));
	
	MediaConfig::setAudioCodec(QString("copy"));

	if (CHECKED(_ui->SubtitlesCB))
		configureSubtitle(stream, 0, container, id);

	if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter())
		MediaConfig::setVideoChapters();

	if (stream == 1 && _ui->VideoEncDD->currentIndex() != 6) {
		MediaConfig::setVideoMetadata();
		MediaConfig::setEncoder(QString("EncodeGUI v%1").arg(VERSION));
		
		if (CHECKED(_ui->BatchCB)) {
			QFileInfo fn(_batchFiles->at(index));

			#ifdef Q_OS_WINDOWS
			MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + QString("\\batch_") + fn.fileName() + container);
			#endif
			#ifdef Q_OS_DARWIN
			MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + QString("/batch_") + fn.fileName() + container);
			#endif
		}
		else
			MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
	}

	return(MediaConfig::getArguments());
}

QStringList EncodeGUI::configureSubtitle(int stream, int index, QString container, QString id) {
	if (!CHECKED(_ui->AudioCB)) {
		MediaConfig::resetArguments();

		if (_ui->VideoEncDD->currentIndex() != 6) {
			MediaConfig::setOverride();
			#ifdef Q_OS_WINDOWS
			MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1%2").arg(id).arg(container)));
			#endif
			#ifdef Q_OS_DARWIN
			MediaConfig::setInput(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1%2").arg(id).arg(container)));
			#endif

			if (_ui->SubtitlesDD->currentIndex() != 2) {
				if (!CHECKED(_ui->BatchCB))
					MediaConfig::setInput(_ui->SelectInTxtBox->text());
				else
					MediaConfig::setInput(_batchFiles->at(index));
			}
			else
				foreach(QString path, *_streamInputs)
					MediaConfig::setInput(path);

			MediaConfig::setMapAll(QString("v"), 0);
			MediaConfig::setVideoCodec(QString("copy"));
		}
	}

	if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 0) {
		if (_ui->VideoEncDD->currentIndex() != 6)
			MediaConfig::setMapAll(QString("s"), stream);
		else
			MediaConfig::setMapSingle(QString("s"));

		MediaConfig::setSubtitleCodec(QString("copy"));
	}
	else if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 1) {
		if (_ui->VideoEncDD->currentIndex() != 6)
			MediaConfig::setMapAll(QString("s"), stream);
		else
			MediaConfig::setMapSingle(QString("s"));

		if (container.contains(QString(".mkv")) || container.contains(QString(".webm")))
			MediaConfig::setSubtitleCodec(QString("webvtt"));
		else if (container.contains(QString(".mov")) || container.contains(QString(".mp4")) || container.contains(QString(".3gp")))
			MediaConfig::setSubtitleCodec(QString("mov_text"));
	}
	else if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 2) {
		int indexr = 0;

		for (int i = 0; i < _streamSub.count(); i++) {
			QVariantList stream2(_streamSub.at(i).toList());

			for (int j = _subStreamNum; j < stream2.count() + _subStreamNum; j++) {
				if (_ui->VideoEncDD->currentIndex() != 6)
					MediaConfig::setMap(QString("s"), _subtitleStream->at(j).toInt(), stream2.at(indexr).toInt());
				else {
					if (_streamInputs->count() > 1)
						MediaConfig::setMap(QString("s"), _subtitleStream->at(i).toInt(), stream2.at(indexr).toInt());
					else if (_streamInputs->count() == 1)
						MediaConfig::setMapMux(QString("s"), stream2.at(indexr).toInt());
				}

				if (_isTitleSub->at(j)) {
					MediaConfig::setSubtitleMetadata(j);
					MediaConfig::setSubtitleTitle(_titleSub->at(j));

					if (_isLangSub->at(j)) {
						MediaConfig::setSubtitleMetadata(j);
						MediaConfig::setSubtitleLang(_subtitleLangs->at(j));
					}
				}
				else if (_isLangSub->at(j)) {
					MediaConfig::setSubtitleMetadata(j);
					MediaConfig::setSubtitleLang(_subtitleLangs->at(j));
				}

				if (_isEncodingSub->at(j))
					MediaConfig::setSubtitleCodecMulti(_subtitleCodec->at(j), j);
				else
					MediaConfig::setSubtitleCodecMulti(QString("copy"), j);

				indexr++;
			}

			indexr = 0;
			_subStreamNum = stream2.count() + _subStreamNum;
		}
	}

	if (!CHECKED(_ui->AudioCB)) {
		if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter() && !CHECKED(_ui->BatchCB))
			MediaConfig::setVideoChapters();

		if (_ui->VideoEncDD->currentIndex() != 6) {
			MediaConfig::setVideoMetadata();
			MediaConfig::setEncoder(QString("EncodeGUI v%1").arg(VERSION));
			
			if (CHECKED(_ui->BatchCB)) {
				QFileInfo fn(_batchFiles->at(index));

				#ifdef Q_OS_WINDOWS
				MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + QString("\\batch_") + fn.fileName() + container);
				#endif
				#ifdef Q_OS_DARWIN
				MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + QString("/batch_") + fn.fileName() + container);
				#endif
			}
			else
				MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
		}

		return(MediaConfig::getArguments());
	}
	else
		return(QStringList());
}

#ifdef Q_OS_WINDOWS
QStringList EncodeGUI::configureVS(QString id) {
	MediaConfig::resetArguments();

	MediaConfig::setVsPipe();
	MediaConfig::append(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1\\%1.vpy").arg(id)));
	MediaConfig::setOutput("-");

	return(MediaConfig::getArguments());
}
#endif

QStringList EncodeGUI::configureMux(QString container, QStringList audio, QStringList subtitles) {
	MediaConfig::resetArguments();

	MediaConfig::setOverride();

	if ((CHECKED(_ui->AudioCB) && _ui->AudioDD->currentIndex() == 1) || (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 2))
		foreach(QString input, *_streamInputs)
			MediaConfig::setInput(input);
	else if (_streamInputs->count() == 0)
		MediaConfig::setInput(_ui->SelectInTxtBox->text());

	MediaConfig::setMapMux(QString("v"), 0);
	MediaConfig::setVideoCodec(QString("copy"));

	foreach(QString aud, audio)
		MediaConfig::append(aud);
	foreach(QString sub, subtitles)
		MediaConfig::append(sub);

	MediaConfig::setVideoMetadata();
	MediaConfig::setEncoder(QString("EncodeGUI v%1").arg(VERSION));
	MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);

	return(MediaConfig::getArguments());
}

QStringList EncodeGUI::configureArgs(QString input, int index, QString container, QString id, bool twoPass, int pass) {
	MediaConfig::resetArguments();
	MediaConfig::setOverride();

	if (CHECKED(_ui->RotateGB) && CHECKED(_ui->NoAutoRotateCB))
		MediaConfig::setNoAutoRotate();

	#ifdef Q_OS_WINDOWS
	MediaConfig::setInput(QString("-"));
	#endif
	#ifdef Q_OS_DARWIN
	MediaConfig::setVs();
	MediaConfig::setInput(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1/%1.vpy").arg(id)));
	#endif

	QString profile;

	switch (_ui->VideoEncDD->currentIndex()) {
	case 0:
		#ifdef Q_OS_WINDOWS
		if (!CHECKED(_ui->Hardware264CB)) {
		#endif
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
		#ifdef Q_OS_WINDOWS
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
		#endif
		break;
	case 1:
		#ifdef Q_OS_WINDOWS
		if (!CHECKED(_ui->Hardware265CB)) {
		#endif
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

			#ifdef Q_OS_WINDOWS
			if ((CHECKED(_ui->FastPass265CB) && _ui->EncodeMode265DD->currentIndex() == 2) || _ui->EncodeMode265DD->currentIndex() == 2 || 
				CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->Profile265GB) || CHECKED(_ui->DBVisionGB))
				MediaConfig::setx265Params();
			#endif
			#ifdef Q_OS_DARWIN
			if (_ui->EncodeMode265DD->currentIndex() == 2 || CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->Profile265GB) || CHECKED(_ui->DBVisionGB))
				MediaConfig::setx265Params();
			#endif

			#ifdef Q_OS_WINDOWS
			if (CHECKED(_ui->FastPass265CB) && _ui->EncodeMode265DD->currentIndex() == 2) {
				MediaConfig::setFastPass();

				if (CHECKED(_ui->Profile265GB) && _ui->Tier265DD->currentIndex() == 0 && (_ui->EncodeMode265DD->currentIndex() == 2 || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->HDRMetadataGB)))
					MediaConfig::setColin();
			}
			#endif
			if (CHECKED(_ui->Profile265GB) && _ui->Tier265DD->currentIndex() == 0) {
				MediaConfig::setTier(0);

				if (_ui->EncodeMode265DD->currentIndex() == 2 || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->HDRMetadataGB))
					MediaConfig::setColin();
			}
			if (_ui->EncodeMode265DD->currentIndex() == 2) {
				#ifdef Q_OS_WINDOWS
				MediaConfig::setStatsFile(TEMPPATH_WIN);
				#endif
				#ifdef Q_OS_DARWIN
				MediaConfig::setStatsFile(TEMPPATH_DAR);
				#endif
				
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

			#ifdef Q_OS_WINDOWS
			if ((CHECKED(_ui->FastPass265CB) && _ui->EncodeMode265DD->currentIndex() == 2) || _ui->EncodeMode265DD->currentIndex() == 2 ||
				CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->Profile265GB) || CHECKED(_ui->DBVisionGB))
				MediaConfig::setConcludeParams();
			#endif
			#ifdef Q_OS_DARWIN
			if (_ui->EncodeMode265DD->currentIndex() == 2 || CHECKED(_ui->HDRMetadataGB) || CHECKED(_ui->ColorsHDRGB) || CHECKED(_ui->Profile265GB) || CHECKED(_ui->DBVisionGB))
				MediaConfig::setConcludeParams();
			#endif

			MediaConfig::setAppleTag();
		#ifdef Q_OS_WINDOWS
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
		#endif
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
		#ifdef Q_OS_WINDOWS
		MediaConfig::setVideoCodec(QString("libsvtav1"));
		#endif
		#ifdef Q_OS_DARWIN
		MediaConfig::setVideoCodec(QString("libaom-av1"));
		#endif

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
		if (_ui->VideoEncDD->currentIndex() != 1) {
			#ifdef Q_OS_WINDOWS
			MediaConfig::setPassLogFile(TEMPPATH_WIN);
			#endif
			#ifdef Q_OS_DARWIN
			MediaConfig::setPassLogFile(TEMPPATH_DAR);
			#endif
		}
		
		MediaConfig::setNullPath();
	}
	else
		if (CHECKED(_ui->AudioCB) || CHECKED(_ui->SubtitlesCB)) {
			#ifdef Q_OS_WINDOWS
			MediaConfig::setOutput(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1.mkv").arg(id)));
			#endif
			#ifdef Q_OS_DARWIN
			MediaConfig::setOutput(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1.mkv").arg(id)));
			#endif
		}
		else if (!CHECKED(_ui->AudioCB) && !CHECKED(_ui->SubtitlesCB)) {
			if (!CHECKED(_ui->ChaptersCB) && SubtitleInfo::getChapter() && !CHECKED(_ui->BatchCB))
				MediaConfig::setVideoChapters();

			MediaConfig::setVideoMetadata();
			MediaConfig::setEncoder(QString("EncodeGUI v%1").arg(VERSION));

			if (CHECKED(_ui->BatchCB)) {
				QFileInfo fn(_batchFiles->at(index));

				#ifdef Q_OS_WINDOWS
				MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + QString("\\batch_") + fn.fileName() + container);
				#endif
				#ifdef Q_OS_DARWIN
				MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + QString("/batch_") + fn.fileName() + container);
				#endif
			}
			else
				MediaConfig::setOutput(_ui->SaveOutTxtBox->text() + container);
		}

	return(MediaConfig::getArguments());
}