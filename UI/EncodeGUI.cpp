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

#include "EncodeGUI.h"

FFLoader* ffloader;

QFile LogFile;

int selectedJob;
int selectedAudio;

bool EncodingAudio;

QString winDir;
QString vers;
QStringList gpuNames;
QStringList FileStream;

Preview* preview;
Update* up;

EncodeGUI::EncodeGUI(QWidget *parent) : QMainWindow(parent)
{
    ui.setupUi(this);
    setup_queue();
    preview = new Preview(this);

    connect(ui.VideoEncDD, SIGNAL(currentIndexChanged(int)), this, SLOT(HideEnc()));
    connect(ui.UseGPUCB, SIGNAL(stateChanged(int)), this, SLOT(hide_interpgpu()));
    connect(ui.BackendDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hide_interpgpucb()));
    connect(ui.ToolInterpDD, SIGNAL(currentIndexChanged(int)), this, SLOT(tool_interp()));
    connect(ui.ParamsCB, SIGNAL(stateChanged(int)), this, SLOT(hide_params()));
    connect(ui.ToolUpscaleDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hide_upscale()));
    connect(ui.AudioCB, SIGNAL(stateChanged(int)), this, SLOT(hide_aud()));
    connect(ui.SubtitlesCB, SIGNAL(stateChanged(int)), this, SLOT(hide_sub()));
    connect(ui.AudioDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hide_audtab()));
    connect(ui.Hardware264CB, SIGNAL(stateChanged(int)), this, SLOT(hdwr_264()));
    connect(ui.EncodeMode264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode_264()));
    connect(ui.EncodeMode264HWDD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode_264()));
    connect(ui.Preset264CB, SIGNAL(stateChanged(int)), this, SLOT(hide_pre264()));
    connect(ui.Tune264CB, SIGNAL(stateChanged(int)), this, SLOT(hide_tun264()));
    connect(ui.Profile264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(profile_264()));
    connect(ui.Profile264GB, SIGNAL(toggled(bool)), this, SLOT(profile_gb264()));
    connect(ui.Reference264Sldr, SIGNAL(valueChanged(int)), this, SLOT(refsldr_264()));
    connect(ui.BFrame264Sldr, SIGNAL(valueChanged(int)), this, SLOT(bsldr_264()));
    connect(ui.SCThresholdCB, SIGNAL(stateChanged(int)), this, SLOT(ThresholdNUD()));
    connect(ui.LimitThreadsCB, SIGNAL(stateChanged(int)), this, SLOT(cpu_thread()));
    connect(ui.Hardware265CB, SIGNAL(stateChanged(int)), this, SLOT(hdwr_265()));
    connect(ui.EncodeMode265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode_265()));
    connect(ui.EncodeMode265HWDD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode_265()));
    connect(ui.Preset265CB, SIGNAL(stateChanged(int)), this, SLOT(hide_pre265()));
    connect(ui.Tune265CB, SIGNAL(stateChanged(int)), this, SLOT(hide_tun265()));
    connect(ui.Profile265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(profile_265()));
    connect(ui.Profile265GB, SIGNAL(toggled(bool)), this, SLOT(profile_gb265()));
    connect(ui.Reference265Sldr, SIGNAL(valueChanged(int)), this, SLOT(refsldr_265()));
    connect(ui.BFrame265Sldr, SIGNAL(valueChanged(int)), this, SLOT(bsldr_265()));
    connect(ui.EncodeModeTDD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode_theora()));
    connect(ui.AudioEncoderDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audio_dd()));
    connect(ui.DownmixCB, SIGNAL(stateChanged(int)), this, SLOT(downmix_cb()));
    connect(ui.EncodeModeVPXDD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode_vpx()));
    connect(ui.ProfileVPXDD, SIGNAL(currentIndexChanged(int)), this, SLOT(profile_vpx()));
    connect(ui.SelectInBttn, SIGNAL(clicked(bool)), this, SLOT(input_bttn()));
    connect(ui.SampleVidCB, SIGNAL(stateChanged(int)), this, SLOT(SampleVid()));
    connect(ui.SaveOutBttn, SIGNAL(clicked(bool)), this, SLOT(OutBttn()));
    connect(ui.OutContainerx264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(container_ch()));
    connect(ui.OutContainerx265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(container_ch()));
    connect(ui.OutContainerProResDD, SIGNAL(currentIndexChanged(int)), this, SLOT(container_ch()));
    connect(ui.OutContainerTheoraDD, SIGNAL(currentIndexChanged(int)), this, SLOT(container_ch()));
    connect(ui.OutContainerVPXDD, SIGNAL(currentIndexChanged(int)), this, SLOT(container_ch()));
    connect(ui.AddJobBttn, SIGNAL(clicked(bool)), this, SLOT(CreateJob()));
    connect(ui.StartBttn, SIGNAL(clicked(bool)), this, SLOT(Start()));
    connect(ui.CancelBttn, SIGNAL(clicked(bool)), this, SLOT(CancelMain()));
    connect(ui.PauseBttn, SIGNAL(clicked(bool)), this, SLOT(PauseClick()));
    connect(ui.CancelQueueBttn, SIGNAL(clicked(bool)), this, SLOT(CancelAllClick()));
    connect(ui.ClearJobsBttn, SIGNAL(clicked(bool)), this, SLOT(ClearFinished()));
    connect(ui.AddAudioJob, SIGNAL(clicked(bool)), this, SLOT(AddAudioJob()));
    connect(ui.LogsDirBttn, SIGNAL(clicked(bool)), this, SLOT(OpenLogs()));
    connect(ui.PreviewBttn, SIGNAL(clicked(bool)), this, SLOT(OpenPreview()));
    connect(ui.AutoAdjCB, SIGNAL(stateChanged(int)), this, SLOT(AutoAjustU()));
    connect(ui.AutoAdjDD, SIGNAL(currentIndexChanged(int)), this, SLOT(AutoAdjustUD()));
    connect(ui.AutoAdjResCB, SIGNAL(stateChanged(int)), this, SLOT(AutoAdjust()));
    connect(ui.AutoAdjResDD, SIGNAL(currentIndexChanged(int)), this, SLOT(AutoAdjustDD()));
    connect(ui.ResizeAlgoCB, SIGNAL(stateChanged(int)), this, SLOT(AlgoDD()));
    connect(ui.FlipCB, SIGNAL(stateChanged(int)), this, SLOT(FlipDD()));
    connect(ui.ModelUpscaleDD, SIGNAL(currentIndexChanged(int)), this, SLOT(ModelUpScaleGB()));
    connect(ui.UpscalingGB, SIGNAL(toggled(bool)), this, SLOT(UpscaleGB()));
    connect(ui.ResizeGB, SIGNAL(toggled(bool)), this, SLOT(ResizeGB()));
    connect(ui.ToolUpscaleDD, SIGNAL(currentIndexChanged(int)), this, SLOT(ModelUpscale()));
    connect(ui.JobsCB, SIGNAL(stateChanged(int)), this, SLOT(JobsCB()));
    connect(ui.FPSCB, SIGNAL(stateChanged(int)), this, SLOT(FpsCB()));
    connect(ui.BitrateCB, SIGNAL(stateChanged(int)), this, SLOT(BitrateCB()));
    connect(ui.TimeLeftCB, SIGNAL(stateChanged(int)), this, SLOT(TimeLeftCB()));
    connect(ui.TimeElapsedCB, SIGNAL(stateChanged(int)), this, SLOT(TimerCB()));
    connect(ui.PercentageCB, SIGNAL(stateChanged(int)), this, SLOT(PercentCB()));
    connect(ui.DonateToDaGooseBttn, SIGNAL(clicked(bool)), this, SLOT(DonateDaGoose()));
    connect(ui.DonateToGlitchBttn, SIGNAL(clicked(bool)), this, SLOT(DonateGlitch()));
    connect(ui.InterpFactorNUD, SIGNAL(valueChanged(int)), this, SLOT(InterpFactor()));
    connect(ui.PatreonBttn, SIGNAL(clicked(bool)), this, SLOT(PatreonClick()));
    connect(ui.YoutubeBttn, SIGNAL(clicked(bool)), this, SLOT(YouClick()));
    connect(ui.DiscordBttn, SIGNAL(clicked(bool)), this, SLOT(DisClick()));
    connect(ui.InstaBttn, SIGNAL(clicked(bool)), this, SLOT(IgClick()));
    connect(ui.EnablePreviewCB, SIGNAL(stateChanged(int)), this, SLOT(EnablePreview()));
    connect(ui.CompleteMessageCB, SIGNAL(stateChanged(int)), this, SLOT(JobsComplete()));
    connect(ui.ErrorMessageCB, SIGNAL(stateChanged(int)), this, SLOT(ErrorMsg()));
    connect(ui.DynamicMetadataBttn, SIGNAL(clicked(bool)), this, SLOT(HDRMeta()));

    ffloader = new FFLoader();

    connect(ffloader, SIGNAL(ExtractInfo()), this, SLOT(ExtracterInfo()));
    connect(ffloader, SIGNAL(ExtractComplete()), this, SLOT(ExtracterComplete()));
    connect(ffloader, SIGNAL(setVideoInfo()), this, SLOT(RegexFinished()));
    connect(ffloader, SIGNAL(setProgress()), this, SLOT(UpdateProgress()));
    connect(ffloader, SIGNAL(Completed()), this, SLOT(EncodeFinished()));
    connect(ffloader, SIGNAL(Logs(QString)), this, SLOT(WriteFile(QString)));

    HideEnc();
    hide_aud();
    hide_sub();
    hdwr_264();
    hdwr_264d();
    mode_264();
    hide_pre264();
    hide_tun264();
    audio_dd();
    profile_264();
    profile_vpx();
    refsldr_264();
    bsldr_264();
    profile_gb264();
    hdwr_265();
    hdwr_265d();
    SampleVid();
    mode_265();
    mode_vpx();
    downmix_cb();
    mode_theora();
    hide_pre265();
    hide_tun265();
    profile_265();
    profile_gb265();
    refsldr_265();
    bsldr_265();
    hide_interpgpucb();
    tool_interp();
    hide_params();
    hide_upscale();
    AutoAjustU();
    AutoAdjustUD();
    AutoAdjust();
    AutoAdjustDD();
    InterpFactor();
    FlipDD();
    AlgoDD();

    //fix disabled bug
    ui.InterpolationCB->setChecked(true);
    ui.InterpolationCB->setChecked(false);
    ui.UpscalingGB->setChecked(true);
    ui.UpscalingGB->setChecked(false);
    ui.Preset264DD->setCurrentIndex(6);
    ui.Preset265DD->setCurrentIndex(6);
    ui.ResizeGB->setChecked(true);
    ui.ResizeGB->setChecked(false);

    if (!QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI"))).exists())
        QDir().mkpath(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI")));
    else {
        if (QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI"))).removeRecursively());
            QDir().mkpath(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI")));
    }

    WriteLog(QString("Welcome to EncodeGUI! You are using the v%1 (free, stable) build.").arg(VERSION), false, false, false);
    WriteLog("This is a user information log and will not be accepted in an issue/bug report.", true, false, false);
    WriteLog("Visit https://encodegui.com/support.html for directions on how to submit a proper issue/bug report.", false, false, false);

    GPUFinished();
    CheckEncoders();
    GetProcessor();
    LoadSysSetting();

    Updater();

    connect(ui.AutoDelSourceCB, SIGNAL(stateChanged(int)), this, SLOT(DelSource()));
    connect(ui.SCThresholdNUD, SIGNAL(valueChanged(int)), this, SLOT(ScNUD()));
}

void EncodeGUI::CheckEncoders() {
    ui.Hardware264DD->clear();
    ui.Hardware265DD->clear();

    QString dir = QDir::tempPath().at(0);
    winDir = QString("%1:\\Windows").arg(dir);

    if (QFile().exists(QString("%1\\System32\\nvEncodeAPI64.dll").arg(winDir))) {
        ui.Hardware264DD->addItem("NVENC");
        ui.Hardware265DD->addItem("NVENC");
    }
    else
        WriteLog("Warning: No NVENC drivers found. Removing NVENC support in AVC and HEVC.", false, false, true);

    if (QFile().exists(QString("%1\\System32\\amfrt64.dll").arg(winDir))) {
        ui.Hardware264DD->addItem("AMF");
        ui.Hardware265DD->addItem("AMF");
    }
    else {
        WriteLog("Warning: No AMF drivers found. Removing AMF support in AVC and HEVC.", false, false, true);

        ui.Hardware264DD->addItem("QuickSync");
        ui.Hardware265DD->addItem("QuickSync");
    }

    if (ui.Hardware264DD->count() == 0) {
        SET_DISABLED(ui.Hardware264CB);
        SET_DISABLED(ui.Hardware265CB);
        ui.Hardware264CB->setChecked(false);
        ui.Hardware265CB->setChecked(false);
    }
    else {
        connect(ui.Hardware265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(hdwr_265d()));
        connect(ui.Hardware264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(hdwr_264d()));
    }
}

void EncodeGUI::Updater() {
    QNetworkRequest req;
    req.setUrl(QUrl("http://encodegui.com/update.txt"));
    req.setHeader(QNetworkRequest::UserAgentHeader, "EncodeGUI Updater");

    QNetworkAccessManager* nam = new QNetworkAccessManager();
    QNetworkReply* reply = nam->get(req);

    connect(reply, SIGNAL(finished()), this, SLOT(UpdateFinished()));
}

void EncodeGUI::UpdateFinished() {
    QNetworkReply* rply = qobject_cast<QNetworkReply*>(sender());

    if (rply->error() == QNetworkReply::NoError) {
        QString output;

        QStringList lst;
        QTextStream stream(rply);

        bool newUp = false;

        while (!stream.atEnd()) {
            output = stream.readLine(0);

            if (!output.contains("Version="))
                lst << output;
            else
                vers = output.remove("Version=");

            if (output.contains("Version="))
                if (!output.contains(VERSION) && !output.contains(QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").value("update", VERSION).toString()))
                    newUp = true;
                else
                    break;
        }

        if (newUp) {
            up = new Update(this);

            up->SetText(lst.join("\n"));

            up->show();
            up->activateWindow();

            connect(up->GetSkip(), SIGNAL(clicked(bool)), this, SLOT(Skip()));
            connect(up->GetNow(), SIGNAL(clicked(bool)), this, SLOT(GoToUpdate()));
            connect(up->GetLater(), SIGNAL(clicked(bool)), this, SLOT(Later()));
        }
        else
            WriteLog(QString("Checked for updates, either no new updates were found or the user had selected to skip the latest update (latest version: v%1).").arg(vers), false, false, false);
    }
    else
        WriteLog(QString("Error: Unable to check for updates due to a network error: %1").arg(rply->errorString()), false, true, false);
}

void EncodeGUI::Skip() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("update", vers);
    up->close();
}

void EncodeGUI::GoToUpdate() {
    QDesktopServices::openUrl(QUrl("https://encodegui.com/downloads.html"));
    up->close();
}

void EncodeGUI::Later() {
    up->close();
}

void EncodeGUI::Paletter(QLabel* label) {
    QPalette palette = label->palette();
    palette.setColor(label->foregroundRole(), Qt::darkGreen);
    label->setPalette(palette);
}

void EncodeGUI::SetVideoInfo() {
    Paletter(ui.VidformatValueLabel);
    ui.VidformatValueLabel->setText(VideoInfo::GetVideoCodec());

    Paletter(ui.DurationValueLabel);
    ui.DurationValueLabel->setText(VideoInfo::GetDurationStrng());

    Paletter(ui.ResolutionValueLabel);
    ui.ResolutionValueLabel->setText(VideoInfo::GetResolution());

    Paletter(ui.BitrateValueLabel);
    if (!VideoInfo::GetBitrate().contains("?"))
        ui.BitrateValueLabel->setText(VideoInfo::GetBitrate() + "kb/s");
    else
        ui.BitrateValueLabel->setText(VideoInfo::GetBitrate());

    Paletter(ui.ColorsValueLabel);
    ui.ColorsValueLabel->setText(VideoInfo::GetColors());

    Paletter(ui.MatrixValueLabel);
    ui.MatrixValueLabel->setText(VideoInfo::GetMatrix());

    Paletter(ui.TransferValueLabel);
    ui.TransferValueLabel->setText(VideoInfo::GetTransfer());

    Paletter(ui.PrimariesValueLabel);
    ui.PrimariesValueLabel->setText(VideoInfo::GetPrimaries());

    Paletter(ui.FPSValueLabel);
    if (!VideoInfo::GetFrameRate().contains("?"))
        ui.FPSValueLabel->setText(VideoInfo::GetFrameRate() + "fps");
    else
        ui.FPSValueLabel->setText(VideoInfo::GetFrameRate());
}

void EncodeGUI::input_bttn() {
    VideoInfo::ClearAll();
    AudioInfo::ClearAll();
    SubtitleInfo::ClearAll();

    VideoInfoRegex::DurationLine.clear();
    
    QString input;
    QString ffprobe;

#if DEBUG
    ffprobe = QDir::toNativeSeparators(QDir::currentPath()) + QString("\\x64\\Release\\ffmpeg\\ffprobe.exe");
#else
    ffprobe = QDir::toNativeSeparators(QDir::currentPath()) + QString("\\ffmpeg\\ffprobe.exe");
#endif // DEBUG


    if (!CHECKED(ui.SampleVidCB))
        input = QFileDialog::getOpenFileName(this, tr("Select Input"), ui.SelectInTxtBox->text(), tr("All files (*.*)"));
    else
        input = ui.SelectInTxtBox->text();

    if (input.isEmpty() && !ui.SelectInTxtBox->text().isEmpty())
        input = ui.SelectInTxtBox->text();

    if (Checks::CheckFFProbe(ffprobe)) {
        input = QDir::toNativeSeparators(input);
        ui.SelectInTxtBox->setText(input);

        if (!ui.SelectInTxtBox->text().isEmpty()) {
            disconnect(ui.AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audio_track()));

            ui.AudioTrackDD->clear();
            ui.SelectedAudioDD->clear();
            RemoveAudio();

            ffloader->VideoInfo(QString("\"%1\"").arg(ffprobe) + QString(" -hide_banner -i \"%1\"").arg(input));
        }
    }
    else {
        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Required dependency \"ffprobe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::OpenPreview() {
    preview->show();
    preview->activateWindow();
}

void EncodeGUI::HDRMeta() {
    QString input = QFileDialog::getOpenFileName(this, tr("Select dynamic metadata file"), QDir::toNativeSeparators(QDir::currentPath()), tr("DHDR10 file (*.json)"));

    if (!input.isEmpty())
        ui.DynamicHDRTxtBox->setText(QDir::toNativeSeparators(input));
}

void EncodeGUI::ScNUD() {
    QSettings set(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI");
    set.setValue("scvalue", ui.SCThresholdNUD->value());
}

void EncodeGUI::ErrorMsg() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("errormsg", CHECKED(ui.ErrorMessageCB));
}

void EncodeGUI::JobsComplete() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("complete", CHECKED(ui.CompleteMessageCB));
}

void EncodeGUI::EnablePreview() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("preview", CHECKED(ui.EnablePreviewCB));
}

void EncodeGUI::DelSource() {
    if (CHECKED(ui.AutoDelSourceCB)) {
        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Warning, "Warning", "This option is destructive as it deletes the source video after a successful encode. It will stay enabled until you disable it, even if you close and reopen EncodeGUI. Would you still like to enable this option anyway?\n\nRemember: the EncodeGUI developers are never held reponsible for the loss of information due to distructive behaviors in EncodeGUI.",
            QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

        if (msg == QMessageBox::No)
            ui.AutoDelSourceCB->setChecked(false);
    }

    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("delsource", CHECKED(ui.AutoDelSourceCB));
}

void EncodeGUI::DonateDaGoose() {
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/donate/?hosted_button_id=CLBETTY9GBM28"));
}

void EncodeGUI::DonateGlitch() {
    QDesktopServices::openUrl(QUrl("https://www.paypal.com/donate/?hosted_button_id=4KSB88LADE3WU"));
}

void EncodeGUI::PatreonClick() {
    QDesktopServices::openUrl(QUrl("https://www.patreon.com/dagoose"));
}

void EncodeGUI::YouClick() {
    QDesktopServices::openUrl(QUrl("https://youtube.com/c/DaGoose"));
}

void EncodeGUI::DisClick() {
    QDesktopServices::openUrl(QUrl("https://discord.gg/PmcbXJVBNu"));
}

void EncodeGUI::IgClick() {
    QDesktopServices::openUrl(QUrl("https://www.instagram.com/dagooseyt/"));
}

void EncodeGUI::ExtracterInfo() {
    QString progress;

    if (VideoInfoList::GetDuration(ffloader->currentJob).isValid())
        ui.progressBar->setValue((int)ProgressInfo::GetPercentage());

    progress.append("Extracting");
    
    if (CHECKED(ui.PercentageCB) && VideoInfoList::GetDuration(ffloader->currentJob).isValid())
        progress.append(QString(" - %1%").arg(ProgressInfo::GetPercentage()));

    ui.JobQueue->item(ffloader->currentJob, 2)->setText(QString("%1%").arg(ProgressInfo::GetPercentage()));
    ui.ProgressBarLabel->setText(progress);
}

void EncodeGUI::RegexFinished() {
    if (VideoInfo::GetVideoCodec().contains("?")) {
        QMessageBox::critical(this, tr("Import file error"), tr("The selected input file is not a video. Only choose video files as the input.\n"));
        ui.SelectInTxtBox->setText(QString());
    }
    else if (VideoInfo::GetDurationStrng().contains("?") && !VideoInfo::GetVideoCodec().contains("?")) {
        WriteLog(QString("Warning: the source file (%1) duration could not be found. Some encoding progress info will be unavailible for the associated job.").arg(ui.SelectInTxtBox->text()), false, false, true);
        QMessageBox::warning(this, tr("Input Error"), tr("EncodeGUI was unable to find the duration of the selected file. As a result, encoding progress info for this source won't be displayed."));
    }
    else {
        tool_interp();
        ui.InterpolationCB->setChecked(true);
        ui.InterpolationCB->setChecked(false);

        if (AudioInfo::TotalStreams() != 0) {
            SET_ENABLED(ui.AudioTrackDD);
            SET_ENABLED(ui.AudioCB);
            ui.AudioCB->setChecked(true);

            if (CHECKED(ui.ColorSpaceCB)) {
                if (VideoInfo::GetMatrix().contains("?") || VideoInfo::GetMatrix().contains("unknown")) {
                    VideoInfo::SetMatrix("bt709");
                    WriteLog("Color matrix for the selected source is unknown, assuming BT709.", false, false, false);
                }
                if (VideoInfo::GetTransfer().contains("?") || VideoInfo::GetTransfer().contains("unknown")) {
                    VideoInfo::SetTransfer("bt709");
                    WriteLog("Color transfer for the selected source is unknown, assuming BT709.", false, false, false);
                }
                if (VideoInfo::GetPrimaries().contains("?") || VideoInfo::GetPrimaries().contains("unknown")) {
                    VideoInfo::SetPrimaries("bt709");
                    WriteLog("Color primaries for the selected source is unknown, assuming BT709.", false, false, false);
                }
            }
        }
        if (SubtitleInfo::TotalStreams() != 0) {
            SET_ENABLED(ui.SubtitlesDD);
            SET_ENABLED(ui.SubtitlesCB);
            ui.SubtitlesCB->setChecked(true);
        }
        else {
            SET_DISABLED(ui.SubtitlesDD);
            SET_DISABLED(ui.SubtitlesCB);
            ui.SubtitlesCB->setChecked(false);
        }
        if (!SubtitleInfo::GetChapter()) {
            SET_DISABLED(ui.ChaptersCB);
            SET_DISABLED(ui.ChaptersLabel);
            ui.ChaptersCB->setChecked(false);
        }
        else {
            SET_ENABLED(ui.ChaptersCB);
            SET_ENABLED(ui.ChaptersLabel);
            ui.ChaptersCB->setChecked(true);
        }

        disconnect(ui.Height2xNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjWidth2x()));
        disconnect(ui.Width2xNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjHeight2x()));
        disconnect(ui.WidthNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjWidth()));
        disconnect(ui.HeightNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjHeight()));

        ModelUpscale();

        ui.Width2xNUD->setMinimum(VideoInfo::GetWidth());
        ui.Height2xNUD->setMinimum(VideoInfo::GetHeight());

        ui.WidthNUD->setMaximum(VideoInfo::GetWidth());
        ui.HeightNUD->setMaximum(VideoInfo::GetHeight());
        ui.WidthNUD->setValue(VideoInfo::GetWidth());
        ui.HeightNUD->setValue(VideoInfo::GetHeight());
        ui.EksNUD->setMaximum(VideoInfo::GetWidth());
        ui.WhyNUD->setMaximum(VideoInfo::GetHeight());
        ui.OutHeightNUD->setMaximum(VideoInfo::GetHeight());
        ui.OutWidthNUD->setMaximum(VideoInfo::GetWidth());

        connect(ui.Height2xNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjWidth2x()));
        connect(ui.Width2xNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjHeight2x()));
        connect(ui.WidthNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjWidth()));
        connect(ui.HeightNUD, SIGNAL(valueChanged(int)), this, SLOT(AutoAdjHeight()));

        if (ui.Height2xNUD->value() > 4352) {
            ui.Height2xNUD->setValue(4352);
            ui.Height2xNUD->setMaximum(4352);
            ui.HeightNUD->setValue(4352);
            ui.HeightNUD->setMaximum(4352);
        }
        if (ui.Width2xNUD->value() > 8192) {
            ui.Width2xNUD->setValue(8192);
            ui.Width2xNUD->setMaximum(8192);
            ui.WidthNUD->setValue(8192);
            ui.WidthNUD->setMaximum(8192);
        }

        InterpFactor();
    }

    if (CHECKED(ui.GetVidInfoCB)) {
        SetVideoInfo();
        SetAudioInfo();

        connect(ui.AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audio_track()));
    }
}

void EncodeGUI::ModelUpscale() {
    if (ui.ToolUpscaleDD->currentIndex() == 0 && ui.ModelUpscaleDD->currentIndex() != 3) {
        ui.Width2xNUD->setMaximum(VideoInfo::GetWidth() * 2);
        ui.Height2xNUD->setMaximum(VideoInfo::GetHeight() * 2);
        ui.Width2xNUD->setValue(VideoInfo::GetWidth() * 2);
        ui.Height2xNUD->setValue(VideoInfo::GetHeight() * 2);
    }
    else if (ui.ToolUpscaleDD->currentIndex() == 1) {
        ui.Width2xNUD->setMaximum(VideoInfo::GetWidth() * 4);
        ui.Height2xNUD->setMaximum(VideoInfo::GetHeight() * 4);
        ui.Width2xNUD->setValue(VideoInfo::GetWidth() * 4);
        ui.Height2xNUD->setValue(VideoInfo::GetHeight() * 4);
    }
}

void EncodeGUI::InterpFactor() {
    if (ui.ToolInterpDD->currentIndex() == 1 && (ui.BackendDD->currentIndex() == 0 || ui.BackendDD->currentIndex() == 2))
        ui.OutputFPSNUD->setValue(static_cast<double>(VideoInfo::GetFrameRate().toDouble()) * ui.InterpFactorNUD->value());
    else if (ui.ToolInterpDD->currentIndex() == 1 && ui.BackendDD->currentIndex() == 1)
        ui.OutputFPSNUD->setValue(static_cast<double>(VideoInfo::GetFrameRate().toDouble()) * 2.0);
}

void EncodeGUI::GetProcessor() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    ui.LimitThreadsNUD->setMaximum(sysInfo.dwNumberOfProcessors);
    ui.LimitThreadsNUD->setValue(sysInfo.dwNumberOfProcessors);
}

void EncodeGUI::CancelAllClick() {
    if (ui.JobQueue->rowCount() == 0)
        return;

    QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Question, "Cancel confirmation", "Are you sure you want to cancel ALL jobs? All curent progress will be lost.", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

    if (msg == QMessageBox::Yes) {
        if (ffloader->encode && ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Active"))
            if (ffloader->encode->state() == QProcess::Running) {
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Canceled");
                ffloader->CloseProcess(ffloader->encode);

                if (ffloader->vs)
                    ffloader->CloseProcess(ffloader->vs);
            }

        FOR_EACH(ui.JobQueue->rowCount())
            if (!ui.JobQueue->item(i, 1)->text().contains("Paused"))
                ui.JobQueue->item(i, 1)->setText("Canceled");
            else {
                MsgBoxHelper(MessageType::Warning, "EncodeGUI warning", "The currently paused process could not be canceled. Please resume it first then cancel it.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                WriteLog("All jobs in the queue have been canceled except the currenly paused job. Resume it to cancel it.", false, false, false);
            }

        if (!ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Paused")) {
            ui.ProgressBarLabel->setText(QString());
            ui.progressBar->setValue(0);

            WriteLog("All jobs in the queue have been canceled.", false, false, false);
        }
    }
}

void EncodeGUI::closeEvent(QCloseEvent* evnt) {
    if (ffloader->encode && ffloader->encode->state() == QProcess::Running) {
        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Please cancel the current running process before closing EncodeGUI", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        evnt->ignore();
    }
    else if (ffloader->encode) {
        if (ffloader->encode->state() == QProcess::NotRunning) {
            Quitting();
            evnt->accept();
        }
    }
    else {
        Quitting();
        evnt->accept();
    }
}

void EncodeGUI::ResetJob() {
    ui.JobQueue->item(selectedJob, 1)->setText("Waiting");
    
    if (arguments.at(selectedJob).contains("pass 2") || arguments.at(selectedJob).contains("pass=2"))
        arguments.replace(selectedJob, QString(arguments.at(selectedJob)).replace("-pass 2", "-pass 1").replace(AudioArgs.at(selectedJob), "-an").replace("\"" + tempList.at(selectedJob) + "\"", QString("-passlogfile \"%1\"").arg(QDir::toNativeSeparators(QDir::tempPath())) + " -f NULL nul").replace("pass=2", "pass=1"));

    WriteLog(QString("Job %1 has been reset.").arg(job.at(selectedJob)), false, false, false);
}

void EncodeGUI::RemoveJob() {
    if (selectedJob == ffloader->currentJob || ui.JobQueue->item(selectedJob, 1)->text().contains("Paused")) {
        if (ffloader->encode && ffloader->encode->state() == QProcess::Running) {
            MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Please cancel the current job before removing it from the queue.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            return;
        }
    }

    arguments.removeAt(selectedJob);
    vapourScript.removeAt(selectedJob);
    tempList.removeAt(selectedJob);
    AudioArgs.removeAt(selectedJob);
    outputList.removeAt(selectedJob);
    inputList.removeAt(selectedJob);

    VideoInfoList::RemoveDuration(selectedJob);
    VideoInfoList::RemoveFrameRate(selectedJob);

    ui.JobQueue->removeRow(selectedJob);

    if (ffloader->currentJob != 0)
        FOR_EACH(ui.JobQueue->rowCount())
            if (ui.JobQueue->item(i, 1)->text().contains("Active") || ui.JobQueue->item(i, 1)->text().contains("Paused"))
                ffloader->currentJob = i;

    QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(job.at(selectedJob)))).removeRecursively();

    job.removeAt(selectedJob);
}

void EncodeGUI::ClearFinished() {
    FOR_EACH(arguments.count())
        if (ui.JobQueue->item(i, 1)->text().contains("Finished")) {
            ui.JobQueue->removeRow(i);

            arguments.removeAt(i);
            vapourScript.removeAt(i);
            tempList.removeAt(i);
            AudioArgs.removeAt(i);
            outputList.removeAt(i);
            inputList.removeAt(i);

            QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1")).arg(job.at(i))).removeRecursively();

            job.removeAt(i);

            VideoInfoList::RemoveDuration(i);
            VideoInfoList::RemoveFrameRate(i);

            i--;
        }

    if (ffloader->currentJob != 0)
        FOR_EACH(arguments.count())
            if (ui.JobQueue->item(i, 1)->text().contains("Active") || ui.JobQueue->item(i, 1)->text().contains("Paused"))
                ffloader->currentJob = i;
}

void EncodeGUI::CancelMain() {
    QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Question, "Cancel confirmation", "Are you sure you want to cancel the current job? All curent progress will be lost.", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

    if (msg == QMessageBox::Yes)
        FOR_EACH(ui.JobQueue->rowCount())
            if (ui.JobQueue->item(i, 1)->text().contains("Active")) {
                ui.JobQueue->item(i, 1)->setText("Canceled");
                WriteLog(QString("Job %1 canceled by the user").arg(job.at(i)), false, false, false);

                ffloader->CloseProcess(ffloader->encode);

                if (ffloader->vs)
                    ffloader->CloseProcess(ffloader->vs);
            }
            else if (ui.JobQueue->item(i, 1)->text().contains("Paused"))
                MsgBoxHelper(MessageType::Error, "EncodeGUI error", "The selected job must be running for it to be canceled.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void EncodeGUI::CancelClick() {
    QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Question, "Cancel confirmation", "Are you sure you want to cancel the selected job? All curent progress will be lost.", QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton);

    if (msg == QMessageBox::Yes) {
        if (ui.JobQueue->item(selectedJob, 1)->text().contains("Active")) {
            ui.JobQueue->item(selectedJob, 1)->setText("Canceled");
            WriteLog(QString("Job %1 canceled by user").arg(job.at(selectedJob)), false, false, false);

            if (selectedJob == ffloader->currentJob) {
                ffloader->CloseProcess(ffloader->encode);

                if (ffloader->vs)
                    ffloader->CloseProcess(ffloader->vs);
            }
        }
        else
            MsgBoxHelper(MessageType::Error, "EncodeGUI error", "A job must be running to cancel it", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void EncodeGUI::Quitting() {
    FOR_EACH(arguments.count()) {
        selectedJob = i;
        RemoveJob();
        i--;
    }
}

void EncodeGUI::PauseClick() {
    if (ui.PauseBttn->text().contains("Pause")) {
        ui.PauseBttn->setText("Resume");
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Paused");
        ui.JobStatusValueLabel->setText("Paused");

        ffloader->PauseProcess(ffloader->encode, true);
        ffloader->PauseTime = ProgressInfo::GetTimeElapsed();
    }
    else {
        ui.PauseBttn->setText("Pause");
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Active");
        ui.JobStatusValueLabel->setText("Active");

        ffloader->PauseProcess(ffloader->encode, false);
        ffloader->Timer.restart();
    }
}

void EncodeGUI::NewExtract() {
    FOR_EACH(arguments.count())
        if (ui.JobQueue->item(i, 1)->text().contains("Waiting")) {
            ffloader->currentJob = i;

            QDir().mkpath(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\Preview")));

            ui.JobQueue->item(i, 1)->setText("Active");

            ffloader->Encode(QString("\"%1\\ffmpeg\\ffmpeg.exe\" -i \"%2\" -vf fps=1 -q:v 27 \"%3\"").arg(QDir::toNativeSeparators(QDir::currentPath())).arg(inputList.at(i))
                .arg(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\Preview\\%d.jpg"))), QString(), true);

            if (CHECKED(ui.AutoDelSourceCB))
                WriteLog("WARNING: Auto delete source is enabled in preferences. Disable it before the encoding process ends if you do not want the source video to be deleted", false, false, true);

            Paletter(ui.JobStartValueLabel);
            ui.JobStartValueLabel->setText(QDateTime::currentDateTime().toString());

            Paletter(ui.JobStatusValueLabel);
            ui.JobStatusValueLabel->setText("Active");

            Paletter(ui.JobIDValueLabel);
            ui.JobIDValueLabel->setText(ui.JobQueue->item(i, 0)->text());

            break;
        }
}

void EncodeGUI::ExtracterComplete() {
    ui.progressBar->setMaximum(100);
    ui.ProgressBarLabel->setText(QString());
    ui.progressBar->setValue(0);

    if (!ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Canceled"))
        NewTask();
    else
        NewJob();
}

void EncodeGUI::Start() {
    int jobs = ui.JobQueue->rowCount();
    int count = 0;

    EncodingAudio = false;

    if (jobs > 0) {
        WriteLog("Attempting to start the job queue...", false, false, false);

        FOR_EACH(jobs)
            if (ui.JobQueue->item(i, 1)->text().contains("Waiting")) {
                NewExtract();
                WriteLog(QString("Extracting frames for job %1").arg(job.at(i)), false, false, false);

                SET_ENABLED(ui.PauseBttn);
                SET_ENABLED(ui.CancelBttn);
                SET_DISABLED(ui.StartBttn);
                
                count++;
                return;
            }
    }

    if (count == 0 || jobs == 0)
        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "There are no waiting jobs in the queue", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void EncodeGUI::NewTask() {
    if (Checks::CheckFFMpeg(QDir::toNativeSeparators(QDir::currentPath()) + "\\ffmpeg\\ffmpeg.exe")) {
        if (Checks::CheckInputExists(inputList.at(ffloader->currentJob))) {
            if (Checks::CheckVsPipe(QDir::toNativeSeparators(QDir::currentPath() + "\\vapoursynth\\vspipe.exe"))) {
                WriteLog(QString("Starting video encoding for job: %1").arg(job.at(ffloader->currentJob)), false, false, false);
                        
                ProcessError::ClearAll();
                ProcessErrorRegex::ClearBools();

                if (QFile(outputList.at(ffloader->currentJob)).exists())
                    QFile(outputList.at(ffloader->currentJob)).remove();

                if (!QDir(QDir::toNativeSeparators(QDir::tempPath().replace("Temp", QString("EncodeGUI\\job-%1").arg(job.at(ffloader->currentJob))))).exists())
                    QDir().mkpath(QDir::toNativeSeparators(QDir::tempPath().replace("Temp", QString("EncodeGUI\\job-%1").arg(job.at(ffloader->currentJob)))));

                LogFile.close();
                LogFile.setFileName(QDir::toNativeSeparators(QDir::tempPath().replace("Temp", QString("EncodeGUI\\job-%1\\ProcessLogs-%1.txt").arg(job.at(ffloader->currentJob)))));
                LogFile.open(QIODevice::WriteOnly);
                FileStream.clear();

                if (CHECKED(ui.EnablePreviewCB))
                    OpenPreview();

                FileStream << "#================================================#";
                FileStream << QString("EncodeGUI process logs for job %1").arg(job.at(ffloader->currentJob));
                FileStream << QString("Video encoding arguments: %1 | %2").arg(vapourScript.at(ffloader->currentJob)).arg(arguments.at(ffloader->currentJob));
                FileStream << QString("Audio encoding arguments: %1").arg(AudioArgs.at(ffloader->currentJob));
                FileStream << "#================================================#\n";

                if (Checks::CheckVsScript(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1\\%1.vpy").arg(job.at(ffloader->currentJob)))))
                    ffloader->Encode(arguments.at(ffloader->currentJob), vapourScript.at(ffloader->currentJob), false);
                else {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("Could not find VapourSynth script for job id: %1\nExiting job.").arg(job.at(ffloader->currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
                    WriteLog(QString("Error: could not find VapourSynth script for job %1").arg(job.at(ffloader->currentJob)), false, true, false);
                    EncodeFinished();
                }

                ui.ProgressBarLabel->setText("Creating index file...");
                ui.progressBar->setMaximum(0);
            }
            else {
                MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Required dependency \"vspipe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                QApplication::quit();
            }
        }
        else {
            MsgBoxHelper(MessageType::Error, "EncodeUI error", QString("The source video file at \"%1\" is missing or does not exist.").arg(inputList.at(ffloader->currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
            WriteLog(QString("Error: could not find source file for job %1").arg(job.at(ffloader->currentJob)), false, true, false);
            FileStream << QString("EncodeGUI error: could not find source file for job %1").arg(job.at(ffloader->currentJob));
            EncodeFinished();
        }
    }
    else {
        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Required dependency \"ffmpeg.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::OpenLogs() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI"))));
}

void EncodeGUI::EncodeFinished() {
    QFile(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.lwi").arg(job.at(ffloader->currentJob)))).remove();
    
    if (preview) {
        preview->SetPicture(":/EncodeGUI/Preview.png");
        preview->SetScaled(true);
    }

    ui.progressBar->setMaximum(100);
    ui.ProgressBarLabel->setText(QString());
    ui.progressBar->setValue(0);

    QMessageBox::StandardButton msg;

    if (ProcessError::Error()) {
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
        
        if (ProcessError::GetCudaError()) {
            WriteLog(QString("Error: Job %1 failed due to the CUDA runtime failing to load. Try updating the selected GPU drivers. Else, the selected GPU is not supported. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "CUDA runtime failed to load.\nTry updating the selected GPU drivers. If this error still occurs then the selected GPU isn't supported.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetNvencError()) {
            WriteLog(QString("Error: Job %1 failed due to the NVENC drivers missing. Try to reinstall the selected Nvidia GPU drivers. Else, the selected Nvidia GPU doesn't support NVENC. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Could not find the required NVENC drivers.\nTry updating the selected Nvidia GPU drivers. If this error still occurs then the selected Nvidia GPU doesn't support NVENC.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetQuickSyncError()) {
            WriteLog(QString("Error: Job %1 failed due to the QuickSync drivers missing. Try to reinstall the selected Intel GPU drivers. Else, the selected Intel GPU doesn't support QuickSync. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Could not find the required QuickSync drivers.\nTry updating the selected Intel GPU drivers. If this error still occurs then the selected Intel GPU doesn't support QuickSync.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetAmfError()) {
            WriteLog(QString("Error: Job %1 failed due to the AMF drivers missing. Try to reinstall the selected AMD GPU drivers. Else, the selected AMD GPU doesn't support AMF. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Could not find the required AMF drivers.\nTry updating the selected AMD GPU drivers. If this error still occurs then the selected AMD GPU doesn't support AMF.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetGpuThreadError()) {
            WriteLog(QString("Error: Job %1 failed due to too many GPU threads being utilized. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("GPU thread count for the NCNN process is too high. Threads must be between %1 and %2").arg(ProcessError::GetMinThreads()).arg(ProcessError::GetMaxThreads()), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetVkMemoryError()) {
            WriteLog(QString("Error: Job %1 failed due to NCNN being unable to allocate memory for its process. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Failed to allocate memory for the NCNN process (vkAllocateMemory failed). Try decreasing the number of GPU threads for the NCNN process.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetVkQueueError() && !ProcessError::GetVkMemoryError()) {
            WriteLog(QString("Error: Job %1 failed due to Vulkan queue submit failure. Follow the directions on https://encodegui.com/support to fix. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Failed to queue the NCNN process (vkQueueSubmit failed). Add registry keys to delay the Vulkan queue submit timeout (see https://encodegui.com/support for more details).", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetNcnnError()) {
            WriteLog(QString("Error: Job %1 failed due to the NCNN process not starting. Either the selected GPU drivers are out of date or the selected GPU isn't supported. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);

            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Failed to start the NCNN process.\nEnsure the selected GPU supports Vulkan and that the drivers are updated. If you still get this error, then the selected GPU isn't supported.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetNvencBitError()) {
            WriteLog(QString("Error: Job %1 failed. Only 8-bit videos are supported for NVENC in AVC. Use NVENC in HEVC for higher bit depth videos.").arg(job.at(ffloader->currentJob)), false, true, false);
            
            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Only 8-bit videos are supported for NVENC in AVC. Use NVENC in HEVC for higher bit depth videos.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::GetPageError()) {
            WriteLog(QString("Error: Job %1 failed. Paging file for CUDA is too small. Ensure that there are no duplicate instances of EncodeGUI running in the background.").arg(job.at(ffloader->currentJob)), false, true, false);

            if (CHECKED(ui.ErrorMessageCB))
                msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Paging file for CUDA is too small. Ensure that there are no duplicate instances of EncodeGUI running in the background.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }

        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));
    }
    else if (ProcessError::GetPipeError()) {
        if (CHECKED(ui.ErrorMessageCB))
            msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "The process failed due to FFMpeg recieving invaild data from VSPipe. Click \"Open\" below to see the associate process logs.", QMessageBox::Ok, QMessageBox::Help, QMessageBox::Open);
    }
    else if (ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Failed")) {
        WriteLog(QString("Error: Job %1 failed due to an unknown process error. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "An unknown error occured with the current process. Click \"Open\" below to open the current job's logs.", QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));
    }
    else if (arguments.at(ffloader->currentJob).contains("-f NULL")) {
        FileStream << "\n#================================================#";
        FileStream << "Begin pass 2 video encoding...";

        arguments.replace(ffloader->currentJob, QString(arguments.at(ffloader->currentJob)).replace("-pass 1", "-pass 2").replace("-an", AudioArgs.at(ffloader->currentJob)).replace("-f NULL nul", "\"" + tempList.at(ffloader->currentJob) + "\"").replace("pass=1", "pass=2"));
        ffloader->Encode(arguments.at(ffloader->currentJob), vapourScript.at(ffloader->currentJob), false);
        
        FileStream << QString("Pass 2 video encoding arguments: %1 | %2").arg(vapourScript.at(ffloader->currentJob)).arg(arguments.at(ffloader->currentJob));
        FileStream << "#================================================#\n";

        ui.progressBar->setMaximum(0);
        ui.ProgressBarLabel->setText("Waiting for 2nd pass start...");
        return;
    }
    else if (!AudioArgs.at(ffloader->currentJob).contains("-an") && (!QFile(tempList.at(ffloader->currentJob)).exists() || QFile(tempList.at(ffloader->currentJob)).size() < 100000) && !ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Canceled")) {
        ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");
        
        WriteLog(QString("Error: Job %1 failed due to an unknown process error. See the associated process logs for more details.").arg(job.at(ffloader->currentJob)), false, true, false);
        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "An unknown error occured with the current process. Click \"Open\" below to open the current job's logs.", QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);
            
        if (msg == QMessageBox::Open)
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));
    }
    else {
        if (!ui.JobQueue->item(ffloader->currentJob, 1)->text().contains("Canceled")) {
            if (!QFile(outputList.at(ffloader->currentJob)).exists() && !EncodingAudio) {
                FileStream << "\n#================================================#";
                FileStream << "Begin audio encoding";
                FileStream << "#================================================#\n";

                WriteLog(QString("Begun logging audio/subtitle encoding for job %1").arg(job.at(ffloader->currentJob)), false, false, false);
                WriteLog(QString("Starting audio/subtitle encoding for job: %1").arg(job.at(ffloader->currentJob)), false, false, false);
                ffloader->Encode(AudioArgs.at(ffloader->currentJob), QString(), false);
                EncodingAudio = true;

                return;
            }
            else if (EncodingAudio && !QFile(outputList.at(ffloader->currentJob)).exists()) {
                ui.JobQueue->item(ffloader->currentJob, 2)->setText("0%");
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Failed");

                QMessageBox::StandardButton sb = MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Audio and/or subtitle encoding failed. Click \"Open\" below to see the associated process logs.",
                    QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help);

                if (sb == QMessageBox::Open)
                    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(job.at(ffloader->currentJob)))));
                if (sb == QMessageBox::Help)
                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));
            }
            else {
                ui.JobQueue->item(ffloader->currentJob, 2)->setText("100%");
                ui.JobQueue->item(ffloader->currentJob, 1)->setText("Finished");

                if (CHECKED(ui.AutoDelSourceCB)) {
                    QFile(inputList.at(ffloader->currentJob)).remove();
                    WriteLog(QString("Deleting source file for job %1").arg(job.at(ffloader->currentJob)), false, false, false);
                }

                WriteLog(QString("Job %1 complete! Checking to see if there are any other jobs...").arg(job.at(ffloader->currentJob)), false, false, false);
            }
        }
    }

    EncodingAudio = false;
    ffloader->PauseTime = QTime(0, 0, 0);

    if (!FileStream.isEmpty() && LogFile.exists()) {
        FileStream << "\n#================================================#";
        FileStream << "End of logs";
        FileStream << "#================================================#";

        QTextStream stream(&LogFile);

        foreach(QString line, FileStream)
            stream << line + "\n";

        LogFile.close();
        FileStream.clear();

        WriteLog(QString("Finished writing logs for job %1").arg(job.at(ffloader->currentJob)), false, false, false);
    }

    NewJob();
}

void EncodeGUI::NewJob() {
    SET_DISABLED(ui.PauseBttn);
    SET_DISABLED(ui.CancelBttn);
    SET_ENABLED(ui.StartBttn);

    Paletter(ui.JobStartValueLabel);
    ui.JobStartValueLabel->setText("?");

    Paletter(ui.JobStatusValueLabel);
    ui.JobStatusValueLabel->setText("?");

    Paletter(ui.JobIDValueLabel);
    ui.JobIDValueLabel->setText("?");

    QFile(QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1.mkv").arg(job.at(ffloader->currentJob)))).remove();
    WriteLog(QString("Deleting temp video file for job %1...").arg(job.at(ffloader->currentJob)), false, false, false);

    if (QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\Preview"))).removeRecursively()) {
        WriteLog(QString("Deleting extracted preview files for job %1...").arg(job.at(ffloader->currentJob)), false, false, false);
        int isDone = 0;

        FOR_EACH(ui.JobQueue->rowCount())
            if (ui.JobQueue->item(i, 1)->text().contains("Waiting") && !ui.JobQueue->item(i, 1)->text().contains("Failed"))
                isDone++;

        if (isDone > 0)
            NewExtract();
        else {
            switch (ui.WhenEncCompleteDD->currentIndex()) {
            case 0:
                if (ui.JobQueue->rowCount() > 0) {
                    WriteLog("All jobs in the queue are completed.", false, false, false);

                    if (CHECKED(ui.CompleteMessageCB))
                        MsgBoxHelper(MessageType::Info, "Done processing jobs", "No more jobs to process.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                }
                break;
            case 1:
                QApplication::quit();
                break;
            case 2:
                QApplication::quit();
                ffloader->Action(false);
                break;
            case 3:
                QApplication::quit();
                ffloader->Action(true);
                break;
            }
        }
    }
}

void EncodeGUI::OpenJobLogs() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(job.at(selectedJob)))));
}

void EncodeGUI::UpdateProgress() {
    ui.progressBar->setMaximum(100);

    if (ProcessError::GetProbeError()) {
        WriteLog(QString("Warning: unable to determine exact output frame rate for job %1 due to limited probe size.").arg(job.at(ffloader->currentJob)), false, false, true);
        ProcessError::SetProbeError(false);
    }

    if (!ProcessError::GetVkMemoryError() && !ProcessError::GetVkQueueError()) {
        QString progress;

        if (!EncodingAudio) {
            if (CHECKED(ui.JobsCB)) {
                progress.append(QString("Job %1 of %2").arg(ffloader->currentJob + 1).arg(ui.JobQueue->rowCount()));

                if (arguments.at(ffloader->currentJob).contains("pass 1") || arguments.at(ffloader->currentJob).contains("pass=1"))
                    progress.append(" (pass 1 of 2)");
                else if (arguments.at(ffloader->currentJob).contains("pass 2") || arguments.at(ffloader->currentJob).contains("pass=2"))
                    progress.append(" (pass 2 of 2)");

                if (CHECKED(ui.FPSCB) || CHECKED(ui.BitrateCB) || CHECKED(ui.TimeLeftCB) || CHECKED(ui.TimeElapsedCB) || CHECKED(ui.PercentageCB))
                    progress.append(" - ");
            }
            if (CHECKED(ui.FPSCB))
                progress.append(QString("FPS: %1").arg(ProgressInfo::GetFps()));
            if (CHECKED(ui.BitrateCB)) {
                if (CHECKED(ui.FPSCB))
                    progress.append(", ");

                progress.append(QString("Bitrate: %1kb/s").arg(ProgressInfo::GetBitrate()));
            }
            if (CHECKED(ui.TimeLeftCB)) {
                if (CHECKED(ui.BitrateCB) || CHECKED(ui.FPSCB))
                    progress.append(", ");

                if (ProgressInfo::GetTimeLeft().isValid())
                    progress.append(QString("Time left: %1").arg(ProgressInfo::GetTimeLeft().toString()));            
                else
                    progress.append(QString("Time left: > day"));
            }
            if (CHECKED(ui.TimeElapsedCB)) {
                if (CHECKED(ui.TimeLeftCB) || CHECKED(ui.BitrateCB) || CHECKED(ui.FPSCB))
                    progress.append(", ");

                if (ProgressInfo::GetTimeElapsed().isValid())
                    progress.append(QString("Time elapsed: %1").arg(ProgressInfo::GetTimeElapsed().toString()));
                else
                    progress.append(QString("Time elapsed: > day"));
            }
            if (CHECKED(ui.PercentageCB) && VideoInfoList::GetDuration(ffloader->currentJob).isValid()) {
                if (CHECKED(ui.FPSCB) || CHECKED(ui.BitrateCB) || CHECKED(ui.TimeLeftCB) || CHECKED(ui.TimeElapsedCB))
                    progress.append(" - ");

                progress.append(QString("%1%").arg(ProgressInfo::GetPercentage()));
            }
            if (QDir(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\Preview"))).exists()) {
                if (preview) {
                    preview->SetPicture(QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\Preview\\%1.jpg")).arg((int)(QTime(0, 0, 0, 0).secsTo(ProgressInfo::GetTime()))));
                    preview->SetScaled(false);
                }
            }
        }
        else {
            if (CHECKED(ui.JobsCB))
                progress.append(QString("Job %1 of %2 - ").arg(ffloader->currentJob + 1).arg(ui.JobQueue->rowCount()));

            progress.append("Audio and/or Subtitle encoding");

            if (CHECKED(ui.PercentageCB))
                progress.append(QString(" - %1%").arg(ProgressInfo::GetPercentage()));
        }

        if (VideoInfoList::GetDuration(ffloader->currentJob).isValid()) {
            ui.JobQueue->item(ffloader->currentJob, 2)->setText(QString("%1%").arg(ProgressInfo::GetPercentage()));
            ui.progressBar->setValue((int)ProgressInfo::GetPercentage());
        }

        ui.ProgressBarLabel->setText(progress);
    }
    else {
        ffloader->KillProcess(ffloader->encode);
        ffloader->KillProcess(ffloader->vs);
    }
}

void EncodeGUI::WriteFile(QString output) {
    FileStream << output;
}

void EncodeGUI::GPUFinished() {
    IDXGIAdapter* adapter;
    IDXGIFactory* factory = NULL;
    DXGI_ADAPTER_DESC desc;

    std::vector<IDXGIAdapter*> videoAdapters;
    CreateDXGIFactory1(__uuidof(IDXGIFactory), (void**)&factory);

    for (UINT i = 0; factory->EnumAdapters(i, &adapter) != DXGI_ERROR_NOT_FOUND; i++)
        videoAdapters.push_back(adapter);

    if (factory)
        factory->Release();

    FOR_EACH(videoAdapters.size()) {
        videoAdapters.at(i)->GetDesc(&desc);

        if (!QString::fromStdWString(desc.Description).toLower().contains("microsoft") && !QString::fromStdWString(desc.Description).toLower().contains("parsec")) {
            gpuNames << QString::fromStdWString(desc.Description);

            ui.GPUInterpDD->addItem(QString::fromStdWString(desc.Description));
            ui.GPUUpscaleDD->addItem(QString::fromStdWString(desc.Description));
        }
    }

    WriteLog(QString("Found %1 GPU device(s): %2").arg(gpuNames.count()).arg(gpuNames.join(", ")), false, false, false);

    this->setWindowTitle(QString("EncodeGUI v%1 (free, stable) - [GPU 0: %2]").arg(VERSION).arg(gpuNames.at(0)));
}

void EncodeGUI::OutBttn() {
    QString output, container, ext;
    
    switch (ui.VideoEncDD->currentIndex()) {
        case 0:
            container = QString("%1 Files (*%2)").arg(ui.OutContainerx264DD->currentText().toUpper().remove(".")).arg(ui.OutContainerx264DD->currentText());
            ext = ui.OutContainerx264DD->currentText();
            break;
        case 1:
            container = QString("%1 Files (*%2)").arg(ui.OutContainerx265DD->currentText().toUpper().remove(".")).arg(ui.OutContainerx265DD->currentText());
            ext = ui.OutContainerx265DD->currentText();
            break;
        case 2:
            container = QString("%1 Files (*%2)").arg(ui.OutContainerProResDD->currentText().toUpper().remove(".")).arg(ui.OutContainerProResDD->currentText());
            ext = ui.OutContainerProResDD->currentText();
            break;
        case 3:
            container = QString("%1 Files (*%2)").arg(ui.OutContainerTheoraDD->currentText().toUpper().remove(".")).arg(ui.OutContainerTheoraDD->currentText());
            ext = ui.OutContainerTheoraDD->currentText();
            break;
        case 4:
            container = QString("%1 Files (*%2)").arg(ui.OutContainerVPXDD->currentText().toUpper().remove(".")).arg(ui.OutContainerVPXDD->currentText());
            ext = ui.OutContainerVPXDD->currentText();
            break;
        case 5:
            container = QString("%1 Files (*%2)").arg(ui.OutContainerx264DD->currentText().toUpper().remove(".")).arg(ui.OutContainerx264DD->currentText());
            ext = ui.OutContainerx264DD->currentText();
            break;
    }

    output = QFileDialog::getSaveFileName(this, tr("Save Output File"), ui.SelectInTxtBox->text(), container);
    output = QDir::toNativeSeparators(output);
    
    if (!output.contains(ext))
        output += ext;

    if (output.contains(ui.SelectInTxtBox->text()) && output.length() == ui.SelectInTxtBox->text().length()) {
        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Output destination cannot be equivalent to the source file path.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        return;
    }

    if (output.isEmpty() && !ui.SaveOutTxtBox->text().isEmpty())
        output = ui.SaveOutTxtBox->text();

    ui.SaveOutTxtBox->setText(output);
}

void EncodeGUI::WriteLog(QString log, bool bold, bool red, bool yellow) {
    ui.LogsOutRTxtBox->insertPlainText(QString("[%1]: ").arg(QTime::currentTime().toString()));
    
    if (bold)
        ui.LogsOutRTxtBox->setFontWeight(QFont::Bold);
    if (yellow)
        ui.LogsOutRTxtBox->setTextColor(Qt::darkYellow);
    if (red)
        ui.LogsOutRTxtBox->setTextColor(Qt::red);
    
    ui.LogsOutRTxtBox->insertPlainText(log + "\n");
    ui.LogsOutRTxtBox->setTextColor(Qt::black);

    if (bold)
        ui.LogsOutRTxtBox->setFontWeight(QFont::Normal);
}

void EncodeGUI::container_ch() {
    ui.SaveOutTxtBox->setText(QString());
}

void EncodeGUI::cpu_thread() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("threads", CHECKED(ui.LimitThreadsCB));

    if (CHECKED(ui.LimitThreadsCB))
        SET_ENABLED(ui.LimitThreadsNUD);
    else
        SET_DISABLED(ui.LimitThreadsNUD);
}

void EncodeGUI::JobsCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("jobs", CHECKED(ui.JobsCB));
}

void EncodeGUI::FpsCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("fps", CHECKED(ui.FPSCB));
}

void EncodeGUI::BitrateCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("bitrate", CHECKED(ui.BitrateCB));
}

void EncodeGUI::TimeLeftCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("timeleft", CHECKED(ui.TimeLeftCB));
}

void EncodeGUI::TimerCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("timer", CHECKED(ui.TimeElapsedCB));
}

void EncodeGUI::PercentCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("percent", CHECKED(ui.PercentageCB));
}

void EncodeGUI::SampleVid() {
    if (CHECKED(ui.SampleVidCB))
        if (QFile(QDir::toNativeSeparators(QDir::currentPath() + "\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv")).exists()) {
            ui.SelectInTxtBox->setText(QDir::toNativeSeparators(QDir::currentPath() + "\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv"));
            
            SET_DISABLED(ui.SelectInBttn);
            input_bttn();
        }
        else {
            WriteLog("Error: unable to load sample video.", false, true, false);
            MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("The sample video file is either missing or does not exist in \"%1\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv\"").arg(QDir::toNativeSeparators(QDir::currentPath())),
                QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

            ui.SampleVidCB->setChecked(false);
        }
    else {
        SET_ENABLED(ui.SelectInBttn);
        ui.SelectInTxtBox->setText(QString());
    }
}

void EncodeGUI::UpscaleGB() {
    if (CHECKED(ui.UpscalingGB)) {
        SET_DISABLED(ui.ResizeGB);
        ui.ResizeGB->setChecked(false);
    }
    else
        SET_ENABLED(ui.ResizeGB);
}

void EncodeGUI::FlipDD() {
    if (CHECKED(ui.FlipCB))
        SET_ENABLED(ui.FlipDD);
    else
        SET_DISABLED(ui.FlipDD);
}

void EncodeGUI::hide_sub() {
    if (CHECKED(ui.SubtitlesCB))
        SET_ENABLED(ui.SubtitlesDD);
    else
        SET_DISABLED(ui.SubtitlesDD);
}

void EncodeGUI::ThresholdNUD() {
    if (CHECKED(ui.SCThresholdCB))
        SET_ENABLED(ui.SCThresholdNUD);
    else
        SET_DISABLED(ui.SCThresholdNUD);

    QSettings(QSettings::NativeFormat, QSettings::UserScope, "DaGoose", "EncodeGUI").setValue("sc", CHECKED(ui.SCThresholdCB));
}

void EncodeGUI::AlgoDD() {
    if (CHECKED(ui.ResizeAlgoCB))
        SET_ENABLED(ui.ResizeAlgoDD);
    else
        SET_DISABLED(ui.ResizeAlgoDD);
}

void EncodeGUI::ResizeGB() {
    if (CHECKED(ui.ResizeGB)) {
        SET_DISABLED(ui.UpscalingGB);
        ui.UpscalingGB->setChecked(false);
    }
    else
        SET_ENABLED(ui.UpscalingGB);
}

void EncodeGUI::AutoAdjust() {
    if (CHECKED(ui.AutoAdjResCB)) {
        SET_ENABLED(ui.AutoAdjResDD);
        AutoAdjustDD();
    }
    else {
        SET_ENABLED(ui.WidthNUD);
        SET_ENABLED(ui.HeightNUD);
        SET_DISABLED(ui.AutoAdjResDD);
    }
}

void EncodeGUI::AutoAdjHeight() {
    if (CHECKED(ui.AutoAdjResCB) && !ui.WidthNUD->isEnabled() && VideoInfo::GetHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::GetWidth()) / VideoInfo::GetHeight();
        ui.WidthNUD->setValue((int)(ui.HeightNUD->value() * multi));
    }
}

void EncodeGUI::AutoAdjWidth() {
    if (CHECKED(ui.AutoAdjResCB) && !ui.HeightNUD->isEnabled() && VideoInfo::GetHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::GetHeight()) / VideoInfo::GetWidth();
        ui.HeightNUD->setValue((int)(ui.WidthNUD->value() * multi));
    }
}

void EncodeGUI::AutoAdjustDD() {
    if (CHECKED(ui.AutoAdjResCB))
        switch (ui.AutoAdjResDD->currentIndex()) {
        case 0:
            SET_DISABLED(ui.HeightNUD);
            SET_ENABLED(ui.WidthNUD);
            break;
        case 1:
            SET_DISABLED(ui.WidthNUD);
            SET_ENABLED(ui.HeightNUD);
            break;
        }
}

void EncodeGUI::HideEnc() {
    if (ui.VideoEncDD->currentIndex() >= 0 && ui.VideoEncDD->currentIndex() <= 4) {
        if (!ui.Tabs->isTabVisible(ui.Tabs->indexOf(ui.VideoTab)))
            ui.Tabs->insertTab(ui.Tabs->indexOf(ui.HomeTab) + 1, ui.VideoTab, "Video");
    }

    ui.SaveOutTxtBox->setText(QString());

    switch (ui.VideoEncDD->currentIndex()) {
    case 0:
        if (!ui.VideoTabs->isTabVisible(ui.VideoTabs->indexOf(ui.x264Tab))) {
            ui.VideoTabs->insertTab(0, ui.x264Tab, "AVC");
            SET_VISIBLE(ui.OutContainerx264DD);
        }

        RemoveTabs(ui.x264Tab);
        break;
    case 1:
        if (!ui.VideoTabs->isTabVisible(ui.VideoTabs->indexOf(ui.x265Tab))) {
            ui.VideoTabs->insertTab(0, ui.x265Tab, "HEVC");
            SET_VISIBLE(ui.OutContainerx265DD);
        }

        RemoveTabs(ui.x265Tab);
        break;
    case 2:
        if (!ui.VideoTabs->isTabVisible(ui.VideoTabs->indexOf(ui.ProResTab))) {
            ui.VideoTabs->insertTab(0, ui.ProResTab, "ProRes");
            SET_VISIBLE(ui.OutContainerProResDD);
        }

        RemoveTabs(ui.ProResTab);
        break;
    case 3:
        if (!ui.VideoTabs->isTabVisible(ui.VideoTabs->indexOf(ui.TheoraTab))) {
            ui.VideoTabs->insertTab(0, ui.TheoraTab, "Theora");
            SET_VISIBLE(ui.OutContainerTheoraDD);
        }

        RemoveTabs(ui.TheoraTab);
        break;
    case 4:
        if (!ui.VideoTabs->isTabVisible(ui.VideoTabs->indexOf(ui.VPXTab))) {
            ui.VideoTabs->insertTab(0, ui.VPXTab, "VP9");
            SET_VISIBLE(ui.OutContainerVPXDD);
        }

        RemoveTabs(ui.VPXTab);
        break;
    case 5:
        if (ui.Tabs->isTabVisible(ui.Tabs->indexOf(ui.VideoTab))) {
            ui.Tabs->removeTab(ui.Tabs->indexOf(ui.VideoTab));
            SET_VISIBLE(ui.OutContainerx264DD);
        }

        RemoveTabs(ui.x264Tab);

        break;
    }
}

void EncodeGUI::RemoveTabs(QWidget* tab) {
    if (tab != ui.x264Tab) {
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.x264Tab));
        SET_INVISIBLE(ui.OutContainerx264DD);
    }
    if (tab != ui.x265Tab) {
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.x265Tab));
        SET_INVISIBLE(ui.OutContainerx265DD);
    }
    if (tab != ui.ProResTab) {
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.ProResTab));
        SET_INVISIBLE(ui.OutContainerProResDD);
    }
    if (tab != ui.TheoraTab) {
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.TheoraTab));
        SET_INVISIBLE(ui.OutContainerTheoraDD);
    }
    if (tab != ui.VPXTab) {
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.VPXTab));
        SET_INVISIBLE(ui.OutContainerVPXDD);
    }

    if (tab != ui.x265Tab)
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.HDRTab));
    else if (tab == ui.x265Tab)
        if (!CHECKED(ui.Hardware265CB) && !ui.VideoTabs->isTabVisible(ui.VideoTabs->indexOf(ui.HDRTab)))
            ui.VideoTabs->insertTab(ui.VideoTabs->indexOf(tab) + 1, ui.HDRTab, "Signals");
}

EncodeGUI::~EncodeGUI() {
    delete ffloader;
    delete preview;
}