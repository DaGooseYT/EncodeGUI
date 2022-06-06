#include "EncodeGUI.h"

QString EncodeGUI::ConfigureAudioM(int stream, int stream2, QString stream3, QString id, QString container) {
	MediaConfig::ResetArguments();

	if (stream == 1 && stream3.toInt() == 0) {
		MediaConfig::SetFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe");
		MediaConfig::SetOverride();
		MediaConfig::SetInput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(id)));
		MediaConfig::SetInput(ui.SelectInTxtBox->text());
		MediaConfig::SetMapAll("v", "0");
		MediaConfig::SetVideoCodec("copy");

		ConfigureSubtitle(stream, container);

		if (!CHECKED(ui.ChaptersCB) && SubtitleInfo::GetChapter())
			MediaConfig::Append(" -map_chapters -1");
	}

	if (stream == 1)
		MediaConfig::SetMap("a", QString("%1").arg(stream), stream2);

	if (IsTitle.at(stream3.toInt()))
		MediaConfig::SetAudioTitle(QString("%1").arg(stream3), Title.at(stream3.toInt()));

	if (IsEncoding.at(stream3.toInt())) {
		MediaConfig::SetAudioCodecMulti(AudioCodec.at(stream3.toInt()), stream3);
			
		if (!AudioCodec.at(stream3.toInt()).contains("libvorbis"))
			MediaConfig::SetAudioBitrate(Bitrate.at(stream3.toInt()), stream3);
		else
			MediaConfig::SetConstantAudioQuality(Quality.at(stream3.toInt()), stream3);

		if (!Channels.at(stream3.toInt()).contains("0"))
			MediaConfig::SetAudioChannels(Channels.at(stream3.toInt()), stream3);
	}
	else
		MediaConfig::SetAudioCodecMulti("copy", stream3);

	if (stream == 1 && stream3.toInt() == ui.AudioQueue->rowCount() - 1) {
		MediaConfig::Append(QString(" -metadata:g encoding_tool=\"EncodeGUI v%1\"").arg(VERSION));
		MediaConfig::SetOutput(ui.SaveOutTxtBox->text());
	}

	return MediaConfig::GetArguments();
}

QString EncodeGUI::ConfigureAudioP(int stream, QString id, QString container) {
	MediaConfig::ResetArguments();

	if (stream == 1) {
		MediaConfig::SetFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe");
		MediaConfig::SetOverride();
		MediaConfig::SetInput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(id)));
		MediaConfig::SetInput(ui.SelectInTxtBox->text());
		MediaConfig::SetMapAll("v", "0");
		MediaConfig::SetVideoCodec("copy");
	}

	if (stream == 1)
		MediaConfig::SetMapAll("a", QString("%1").arg(stream));
	
	MediaConfig::SetAudioCodec("copy");

	ConfigureSubtitle(stream, container);

	if (stream == 1) {
		MediaConfig::Append(QString(" -metadata:g encoding_tool=\"EncodeGUI v%1\"").arg(VERSION));
		MediaConfig::SetOutput(ui.SaveOutTxtBox->text());
	}

	return MediaConfig::GetArguments();
}

void EncodeGUI::ConfigureSubtitle(int stream, QString container) {
	if (CHECKED(ui.SubtitlesCB) && ui.SubtitlesDD->currentIndex() == 0) {
		MediaConfig::SetMapAll("s", QString("%1").arg(stream));
		MediaConfig::Append(" -c:s copy");
	}
	else if (CHECKED(ui.SubtitlesCB) && ui.SubtitlesDD->currentIndex() == 1) {
		MediaConfig::SetMapAll("s", QString("%1").arg(stream));

		if (container.contains(".mkv") || container.contains(".webm"))
			MediaConfig::Append(" -c:s webvtt");
		else if (container.contains(".mov") || container.contains(".mp4") || container.contains(".3gp"))
			MediaConfig::Append(" -c:s mov_text");
	}
}

QString EncodeGUI::ConfigureVS(QString id) {
	MediaConfig::ResetArguments();

	MediaConfig::SetVSPipe(QDir::toNativeSeparators(QDir::currentPath()) + "\\vapoursynth\\vspipe.exe",
		QDir::toNativeSeparators(QDir::tempPath()).replace("Temp", QString("EncodeGUI\\job-%1\\%1.vpy").arg(id)));

	return MediaConfig::GetArguments();
}

QString EncodeGUI::ConfigureArgs(QString id, QString audio, QString subtitles, bool twoPass, int pass) {
	MediaConfig::ResetArguments();

	MediaConfig::SetFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe");
	MediaConfig::SetOverride();

	if (CHECKED(ui.RotateGB) && CHECKED(ui.NoAutoRotateCB))
		MediaConfig::SetNoAutoRotate();

	MediaConfig::Append(" -i -");

	switch (ui.VideoEncDD->currentIndex()) {
	case 0:
		if (!CHECKED(ui.Hardware264CB)) {
			MediaConfig::SetVideoCodec("libx264");

			if (ui.EncodeMode264DD->currentIndex() == 0)
				MediaConfig::SetConstantRateFactor(ui.CRFValue264NUD->value());
			else if (ui.EncodeMode264DD->currentIndex() == 1 || ui.EncodeMode264DD->currentIndex() == 2) {
				MediaConfig::SetVideoBitrate(ui.Bitrate264NUD->value());
				if (ui.EncodeMode264DD->currentIndex() == 2)
					MediaConfig::SetPass(pass);
			}
			else {
				MediaConfig::SetConstantQuantizer(ui.Quantizer264NUD->value());
			}

			if (CHECKED(ui.Tune264CB))
				MediaConfig::SetVideoTune(ui.Tune264DD->currentText().remove(" ").toLower());
			
			if (CHECKED(ui.Preset264CB))
				MediaConfig::SetVideoPreset(ui.Preset264DD->currentText().toLower().remove(" "));
			
			if (CHECKED(ui.Profile264GB)) {
				MediaConfig::SetVideoProfile(ui.Profile264DD->currentText().toLower().remove(" ").remove(":"));

				if (ui.EntropyCode264DD->currentIndex() == 0)
					MediaConfig::SetEntropyCoding(1);
				else
					MediaConfig::SetEntropyCoding(0);
				
				if (!ui.Level264DD->currentText().contains("Unlimited"))
					MediaConfig::SetVideoProfileLevel(ui.Level264DD->currentText());

				if (ui.BitDepth264DD->currentIndex() == 0 && ui.ColorSpace264DD->currentIndex() == 0)
					MediaConfig::SetPixelFormat("yuv420p");
				if (ui.BitDepth264DD->currentIndex() == 1 && ui.ColorSpace264DD->currentIndex() == 0)
					MediaConfig::SetPixelFormat("yuv420p10le");
				if (ui.BitDepth264DD->currentIndex() == 0 && ui.ColorSpace264DD->currentIndex() == 1)
					MediaConfig::SetPixelFormat("yuv422p");
				if (ui.BitDepth264DD->currentIndex() == 1 && ui.ColorSpace264DD->currentIndex() == 1)
					MediaConfig::SetPixelFormat("yuv422p10le");
			}

			if (CHECKED(ui.RefFrames264GB))
				MediaConfig::SetRefFrames(ui.Reference264Sldr->value());
			if (CHECKED(ui.BFrames264GB))
				MediaConfig::SetBFrames(ui.BFrame264Sldr->value());
		}
		else {
			if (ui.Hardware264DD->currentText().contains("QuickSync"))
				MediaConfig::SetVideoCodec("h264_qsv");
			else if (ui.Hardware264DD->currentText().contains("AMF"))
				MediaConfig::SetVideoCodec("h264_amf");
			else if (ui.Hardware264DD->currentText().contains("NVENC"))
				MediaConfig::SetVideoCodec("h264_nvenc");

			switch (ui.EncodeMode264HWDD->currentIndex()) {
			case 0:
				if (ui.Hardware264DD->currentText().contains("NVENC"))
					MediaConfig::SetConstantQuantizer(ui.Quantizer264NUD->value());
				else
					MediaConfig::SetQuantizer(ui.Quantizer264NUD->value());
				break;
			case 1:
				MediaConfig::SetVideoBitrate(ui.Bitrate264NUD->value());
				break;
			case 2:
				MediaConfig::SetVideoBitrate(ui.Bitrate264NUD->value());
				MediaConfig::SetPass(pass);
				break;
			}
		}
		break;
	case 1:
		if (!CHECKED(ui.Hardware265CB)) {
			MediaConfig::SetVideoCodec("libx265");

			if (ui.EncodeMode265DD->currentIndex() == 0)
				MediaConfig::SetConstantRateFactor(ui.CRFValue265NUD->value());
			else if (ui.EncodeMode265DD->currentIndex() == 1 || ui.EncodeMode265DD->currentIndex() == 2) {
				MediaConfig::SetVideoBitrate(ui.Bitrate265NUD->value());
			}
			else
				MediaConfig::SetConstantQuantizer(ui.Quantizer265NUD->value());

			if (CHECKED(ui.Tune265CB))
				MediaConfig::SetVideoTune(ui.Tune265DD->currentText().toLower().remove(" "));

			if (CHECKED(ui.Preset265CB))
				MediaConfig::SetVideoPreset(ui.Preset264DD->currentText().toLower().remove(" "));

			QString profile;

			if (CHECKED(ui.Profile265GB)) {
				profile = ui.Profile265DD->currentText().toLower().remove(" ").remove(":");

				if (ui.BitDepth265DD->currentIndex() == 0 && ui.ColorSpace265DD->currentIndex() == 0)
					MediaConfig::SetPixelFormat("yuv420p");
				if (ui.BitDepth265DD->currentIndex() == 1 && ui.ColorSpace265DD->currentIndex() == 0)
					MediaConfig::SetPixelFormat("yuv420p10le");
				if (ui.BitDepth265DD->currentIndex() == 2 && ui.ColorSpace265DD->currentIndex() == 0)
					MediaConfig::SetPixelFormat("yuv420p12le");
				if (ui.BitDepth265DD->currentIndex() == 0 && ui.ColorSpace265DD->currentIndex() == 1) {
					MediaConfig::SetPixelFormat("yuv422p");
					profile += "-8";
				}
				if (ui.BitDepth265DD->currentIndex() == 1 && ui.ColorSpace265DD->currentIndex() == 1) {
					MediaConfig::SetPixelFormat("yuv422p10le");
					profile += "-10";
				}
				if (ui.BitDepth265DD->currentIndex() == 2 && ui.ColorSpace265DD->currentIndex() == 1) {
					MediaConfig::SetPixelFormat("yuv422p12le");
					profile += "-12";
				}
				if (ui.BitDepth265DD->currentIndex() == 0 && ui.ColorSpace265DD->currentIndex() == 2) {
					MediaConfig::SetPixelFormat("yuv444p");
					profile += "-8";
				}
				if (ui.BitDepth265DD->currentIndex() == 1 && ui.ColorSpace265DD->currentIndex() == 2) {
					MediaConfig::SetPixelFormat("yuv444p10le");
					profile += "-10";
				}
				if (ui.BitDepth265DD->currentIndex() == 2 && ui.ColorSpace265DD->currentIndex() == 2) {
					MediaConfig::SetPixelFormat("yuv444p12le");
					profile += "-12";
				}

				MediaConfig::SetVideoProfile(profile);

				if (!ui.Level265DD->currentText().contains("Unlimited"))
					MediaConfig::SetVideoProfileLevel(ui.Level265DD->currentText());
			}

			if (CHECKED(ui.RefFrames265GB))
				MediaConfig::SetRefFrames(ui.Reference265Sldr->value());
			if (CHECKED(ui.BFrames265GB))
				MediaConfig::SetBFrames(ui.BFrame265Sldr->value());

			if ((CHECKED(ui.FastPass265CB) && ui.EncodeMode265DD->currentIndex() == 2) || ui.EncodeMode265DD->currentIndex() == 2 || 
				CHECKED(ui.HDRMetadataGB) || CHECKED(ui.ColorsHDRGB) || CHECKED(ui.Profile265GB))
				MediaConfig::Setx265Params();

			if (CHECKED(ui.FastPass265CB) && ui.EncodeMode265DD->currentIndex() == 2) {
				MediaConfig::Append("no-slow-firstpass=1");

				if (CHECKED(ui.Profile265GB) && ui.Tier265DD->currentIndex() == 0 && (ui.EncodeMode265DD->currentIndex() == 2 || CHECKED(ui.ColorsHDRGB) || CHECKED(ui.HDRMetadataGB)))
					MediaConfig::SetColin();
			}
			if (CHECKED(ui.Profile265GB) && ui.Tier265DD->currentIndex() == 0) {
				MediaConfig::SetTier(0);

				if (ui.EncodeMode265DD->currentIndex() == 2 || CHECKED(ui.ColorsHDRGB) || CHECKED(ui.HDRMetadataGB))
					MediaConfig::SetColin();
			}
			if (ui.EncodeMode265DD->currentIndex() == 2) {
				MediaConfig::Append(QString("pass=%1:stats=\"'%2\\x265.log'\"").arg(pass).arg(QDir::toNativeSeparators(QDir::tempPath())));
				
				if (CHECKED(ui.ColorsHDRGB) || CHECKED(ui.HDRMetadataGB))
					MediaConfig::SetColin();
			}
			if (CHECKED(ui.HDRMetadataGB)) {
				MediaConfig::SetHDR10Opt();
				MediaConfig::SetColin();
				MediaConfig::SetMasterDisplay(ui.MasterDisplayTxtBox->text());
				MediaConfig::SetColin();
				MediaConfig::SetMaxCllFall(ui.MaxCllNUD->value(), ui.MaxFallNUD->value());
				
				if (CHECKED(ui.ColorsHDRGB))
					MediaConfig::SetColin();

				if (!ui.DynamicHDRTxtBox->text().isEmpty()) {
					MediaConfig::SetHDRPlus(ui.DynamicHDRTxtBox->text());
					
					if (CHECKED(ui.ColorsHDRGB))
						MediaConfig::SetColin();
				}
			}
			if (CHECKED(ui.ColorsHDRGB)) {
				QString mat = ui.ColorMatrixDD->currentText().toLower();
				QString tra = ui.ColorTransferDD->currentText().toLower();
				QString prim = ui.ColorPrimariesDD->currentText().toLower();
				QString range = ui.ColorRangeDD->currentText().toLower();

				MediaConfig::Setx265Colors(mat, tra, prim, range);
			}
		}
		else {
		    if (ui.Hardware265DD->currentText().contains("QuickSync"))
				MediaConfig::SetVideoCodec("hevc_qsv");
			else if (ui.Hardware265DD->currentText().contains("AMF"))
				MediaConfig::SetVideoCodec("hevc_amf");
			else if (ui.Hardware265DD->currentText().contains("NVENC"))
				MediaConfig::SetVideoCodec("hevc_nvenc");

			switch (ui.EncodeMode265HWDD->currentIndex()) {
			case 0:
				if (ui.Hardware265DD->currentText().contains("NVENC"))
					MediaConfig::SetConstantQuantizer(ui.Quantizer265NUD->value());
				else
					MediaConfig::SetQuantizer(ui.Quantizer265NUD->value());
				break;
			case 1:
				MediaConfig::SetVideoBitrate(ui.Bitrate265NUD->value());
				break;
			case 2:
				MediaConfig::SetVideoBitrate(ui.Bitrate265NUD->value());
				MediaConfig::SetPass(pass);
				break;
			}
		}

		MediaConfig::Append(" -tag:v hvc1"); //Apple compat

		break;
	case 2:
		MediaConfig::SetVideoCodec("prores_ks");
		MediaConfig::SetVideoProfile(QString("%1").arg(ui.ProfileDD->currentIndex()));
		
		if (CHECKED(ui.ColorsGB)) {
			QString mtrx, prims, trans;

			mtrx = ui.MatrixProResDD->currentText().toLower();
			trans = ui.TransferProResDD->currentText().toLower();
			prims = ui.TransferProResDD->currentText().toLower();

			MediaConfig::SetColorsProRes(mtrx, trans, prims);
		}

		if (ui.ProfileDD->currentIndex() >= 0 && ui.ProfileDD->currentIndex() < 4)
			MediaConfig::SetPixelFormat("yuv422p10le");
		else
			MediaConfig::SetPixelFormat("yuv444p12le");

		break;
	case 3:
		MediaConfig::SetVideoCodec("libtheora");

		switch (ui.EncodeModeTDD->currentIndex()) {
		case 0:
			MediaConfig::SetVideoBitrate(ui.BitrateThNUD->value());
			break;
		case 1:
			MediaConfig::SetConstantVideoQuality(ui.QualityNUD->value());
			break;
		}
		break;
	case 4:
		MediaConfig::SetVideoCodec("libvpx-vp9");
		MediaConfig::Append(" -row-mt 1");
		MediaConfig::Append(QString(" -quality %1").arg(ui.SpeedDD->currentText().toLower()));

		switch (ui.EncodeModeVPXDD->currentIndex()) {
		case 0:
			MediaConfig::SetConstantRateFactor(ui.crfVPXNUD->value());
			break;
		case 1:
			MediaConfig::SetVideoBitrate(ui.BitrateVPXNUD->value());
			break;
		case 2:
			MediaConfig::SetVideoBitrate(ui.BitrateVPXNUD->value());
			MediaConfig::SetPass(pass);
			break;
		}

		MediaConfig::SetVideoProfile(QString("%1").arg(ui.ProfileVPXDD->currentIndex()));

		if (ui.BitDepthVPXDD->currentIndex() == 0 && ui.SampleVPXDD->currentIndex() == 0)
			MediaConfig::SetPixelFormat("yuv422p10le");
		if (ui.BitDepthVPXDD->currentIndex() == 1 && ui.SampleVPXDD->currentIndex() == 0)
			MediaConfig::SetPixelFormat("yuv422p12le");
		if (ui.BitDepthVPXDD->currentIndex() == 2 && ui.SampleVPXDD->currentIndex() == 0)
			MediaConfig::SetPixelFormat("yuv422p");
		if (ui.BitDepthVPXDD->currentIndex() == 0 && ui.SampleVPXDD->currentIndex() == 1)
			MediaConfig::SetPixelFormat("yuv444p10le");
		if (ui.BitDepthVPXDD->currentIndex() == 1 && ui.SampleVPXDD->currentIndex() == 1)
			MediaConfig::SetPixelFormat("yuv444p12le");
		if (ui.BitDepthVPXDD->currentIndex() == 2 && ui.SampleVPXDD->currentIndex() == 1)
			MediaConfig::SetPixelFormat("yuv444p");
		if (ui.BitDepthVPXDD->currentIndex() == 0 && ui.SampleVPXDD->currentIndex() == 2)
			MediaConfig::SetPixelFormat("yuv420p10le");
		if (ui.BitDepthVPXDD->currentIndex() == 1 && ui.SampleVPXDD->currentIndex() == 2)
			MediaConfig::SetPixelFormat("yuv420p12le");
		if (ui.BitDepthVPXDD->currentIndex() == 2 && ui.SampleVPXDD->currentIndex() == 2)
			MediaConfig::SetPixelFormat("yuv420p");

		break;
	case 5:
		MediaConfig::SetVideoCodec("copy");
		break;
	}

	if (ui.VideoEncDD->currentIndex() != 5) {
		if (CHECKED(ui.UpscalingGB) || CHECKED(ui.ResizeGB) || CHECKED(ui.CropGB) || CHECKED(ui.RotateGB) || CHECKED(ui.SharpenGB))
			if (!((CHECKED(ui.RotateGB) && !CHECKED(ui.FlipCB) && ui.AngleDD->currentIndex() == 0) && !CHECKED(ui.UpscalingGB) && !CHECKED(ui.ResizeGB) && !CHECKED(ui.CropGB) && !CHECKED(ui.SharpenGB)))
				MediaConfig::SetFilters();

		if (CHECKED(ui.UpscalingGB)) {
			MediaConfig::SetVideoResolution(ui.Width2xNUD->value(), ui.Height2xNUD->value());

			if (CHECKED(ui.CropGB) || CHECKED(ui.RotateGB) || CHECKED(ui.SharpenGB))
				MediaConfig::SetComma();
		}
		else if (CHECKED(ui.ResizeGB)) {
			MediaConfig::SetVideoResolution(ui.WidthNUD->value(), ui.HeightNUD->value());

			if (CHECKED(ui.ResizeAlgoCB))
				MediaConfig::SetVideoResizeAlgo(ui.ResizeAlgoDD->currentText().toLower());

			if (CHECKED(ui.CropGB) || CHECKED(ui.RotateGB) || CHECKED(ui.SharpenGB))
				MediaConfig::SetComma();
		}

		if (CHECKED(ui.CropGB)) {
			MediaConfig::SetCrop(ui.OutWidthNUD->value(), ui.OutHeightNUD->value(), ui.EksNUD->value(), ui.WhyNUD->value());
			
			if (CHECKED(ui.RotateGB) || CHECKED(ui.SharpenGB))
				MediaConfig::SetComma();
		}
		
		if (CHECKED(ui.RotateGB)) {
			switch (ui.AngleDD->currentIndex()) {
			case 1:
				MediaConfig::SetTransposeVideo(1);
				break;
			case 2:
				MediaConfig::SetTransposeVideo(1);
				MediaConfig::SetComma();
				MediaConfig::SetTransposeVideo(1);
				break;
			case 3:
				MediaConfig::SetTransposeVideo(3);
				break;
			}
			if (ui.AngleDD->currentIndex() != 0 && CHECKED(ui.FlipCB) || CHECKED(ui.SharpenGB))
				MediaConfig::SetComma();
			
			if (CHECKED(ui.FlipCB)) {

				switch (ui.FlipDD->currentIndex()) {
				case 0:
					MediaConfig::SetFlipVideo("h");
					break;
				case 1:
					MediaConfig::SetFlipVideo("v");
					break;
				}

				if (CHECKED(ui.SharpenGB))
					MediaConfig::SetComma();
			}
		}

		if (CHECKED(ui.SharpenGB)) {
			QString radius, strength;

			switch (ui.RadiusDD->currentIndex()) {
			case 0:
				radius = "3:3";
				break;
			case 1:
				radius = "5:5";
				break;
			case 2:
				radius = "7:7";
				break;
			}

			switch (ui.StrengthDD->currentIndex()) {
			case 0:
				strength = "0.5";
				break;
			case 1:
				strength = "1.0";
				break;
			case 2:
				strength = "2.0";
				break;
			case 3:
				strength = "3.5";
				break;
			case 4:
				strength = "5.0";
				break;
			}

			MediaConfig::SetSharpenVideo(radius, strength);
		}

		if (CHECKED(ui.UpscalingGB) || CHECKED(ui.ResizeGB) || CHECKED(ui.CropGB) || CHECKED(ui.RotateGB) || CHECKED(ui.SharpenGB))
			if (!((CHECKED(ui.RotateGB) && !CHECKED(ui.FlipCB) && ui.AngleDD->currentIndex() == 0) && !CHECKED(ui.UpscalingGB) && !CHECKED(ui.ResizeGB) && !CHECKED(ui.CropGB) && !CHECKED(ui.SharpenGB)))
				MediaConfig::SetConcludeFilters();
	}

	if (twoPass) {
		if (ui.VideoEncDD->currentIndex() != 1)
			MediaConfig::SetPassLogFile(QDir::toNativeSeparators(QDir::tempPath()));
		
		MediaConfig::Append(" -f NULL nul");
	}
	else
		if (CHECKED(ui.AudioCB))
			MediaConfig::SetOutput(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(id)));
		else {
			MediaConfig::Append(QString(" -metadata:g encoding_tool=\"EncodeGUI v%1\"").arg(VERSION));
			MediaConfig::SetOutput(ui.SaveOutTxtBox->text());
		}

	return MediaConfig::GetArguments();
}