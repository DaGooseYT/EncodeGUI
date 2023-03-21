#include "../../include/encodegui.hpp"

QStringList AudioArgs;

QStringList Channels;
QList<int> Quality;
QList<int> Bitrate;
QList<int> Stream;
QList<bool> IsEncoding;
QList<bool> IsTitle;
QList<bool> IsLang;
QStringList Title;
QStringList AudioCodec;
QStringList AudioLangs;

QVariantList Varguments;
QVariantList Vjob;
QVariantList VvapourScript;
QVariantList VinputList;
QVariantList VoutputList;
QVariantList VtempList;
QVariantList Vstate;
QVariantList VaudioArgs;
QVariantList Vduration;
QVariantList VframeRate;

void EncodeGUI::setup_queue() {
    ui.JobQueue->setColumnWidth(0, 100);
    ui.JobQueue->setColumnWidth(1, 80);
    ui.JobQueue->setColumnWidth(2, 70);
    ui.JobQueue->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui.JobQueue->horizontalHeader()->setSectionsClickable(false);

    connect(ui.JobQueue, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(JobContext(QPoint)));
    connect(ui.AudioQueue, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(AudioSubContext(QPoint)));
}

void EncodeGUI::AudioSubContext(QPoint pos) {
    QTableWidgetItem* item = ui.AudioQueue->itemAt(pos);

    if (item != nullptr) {
        ui.AudioQueue->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = item->row();
        ui.AudioQueue->selectRow(row);

        QMenu* m = new QMenu(this);

        QAction* remove = new QAction("Remove", this);

        m->setFont(this->font());
        m->addAction(remove);
        m->popup(ui.AudioQueue->viewport()->mapToGlobal(pos));

        selectedAudio = row;
        connect(remove, SIGNAL(triggered()), this, SLOT(RemoveAudioClick()));

        connect(m, &QMenu::aboutToHide, [this]() {
            ui.AudioQueue->selectionModel()->clear();
            ui.AudioQueue->setSelectionMode(QAbstractItemView::NoSelection);
        });
    }
}

void EncodeGUI::JobContext(QPoint pos) {
    QTableWidgetItem* item = ui.JobQueue->itemAt(pos);
    
    if (item != nullptr) {
        ui.JobQueue->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = item->row();
        ui.JobQueue->selectRow(row);

        selectedJob = row;

        QMenu* m = new QMenu(this);

        QAction* logs = new QAction("Open logs path", this);
        QAction* input = new QAction("Open source path", this);
        QAction* output = new QAction("Open output path", this);
        QAction* pause = new QAction("Pause / Resume", this);
        QAction* cancel = new QAction("Cancel", this);
        QAction* remove = new QAction("Remove", this);
        QAction* reset = new QAction("Reset", this);

        if (ui.JobQueue->item(row, 1)->text().contains("Paused") || ui.JobQueue->item(row, 1)->text().contains("Active")) {
            SET_DISABLED(reset);
            SET_DISABLED(remove);
            SET_ENABLED(cancel);
            SET_ENABLED(pause);
        }
        else {
            SET_ENABLED(reset);
            SET_ENABLED(remove);
            SET_DISABLED(cancel);
            SET_DISABLED(pause);
        }

        m->setFont(this->font());
        m->addAction(logs);
        m->addAction(input);
        m->addAction(output);
        m->addAction(pause);
        m->addAction(cancel);
        m->addAction(remove);
        m->addAction(reset);
        m->popup(ui.JobQueue->viewport()->mapToGlobal(pos));

        connect(pause, SIGNAL(triggered()), this, SLOT(PauseClick()));
        connect(input, SIGNAL(triggered()), this, SLOT(InputClick()));
        connect(output, SIGNAL(triggered()), this, SLOT(OpenOutput()));
        connect(logs, SIGNAL(triggered()), this, SLOT(OpenJobLogs()));
        connect(cancel, SIGNAL(triggered()), this, SLOT(CancelClick()));
        connect(remove, SIGNAL(triggered()), this, SLOT(RemoveJob()));
        connect(reset, SIGNAL(triggered()), this, SLOT(ResetJob()));

        connect(m, &QMenu::aboutToHide, [this]() {
            ui.JobQueue->selectionModel()->clear();
            ui.JobQueue->setSelectionMode(QAbstractItemView::NoSelection);
        });
    }
}

void EncodeGUI::AddAudioJob() {
    if (Checks::CheckInputExists(ui.SelectInTxtBox->text())) {
        ui.AudioQueue->insertRow(ui.AudioQueue->rowCount());

        if (CHECKED(ui.EncodingAudioGB)) {
            if (!CHECKED(ui.LangAudioCB))
                ui.AudioQueue->setItem(ui.AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("%1 (%2) - %3")
                    .arg(ui.SelectedAudioDD->currentIndex() + 1).arg(AudioInfo::GetLanguage(ui.SelectedAudioDD->currentIndex()).replace("?", "UND"))
                        .arg(ui.AudioEncoderDD->currentText())));
            else
                ui.AudioQueue->setItem(ui.AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("%1 (%2) - %3")
                    .arg(ui.SelectedAudioDD->currentIndex() + 1).arg(ui.LangAudioDD->currentText().remove(QRegularExpression("[^\\(]*\\(")).remove(")")).arg(ui.AudioEncoderDD->currentText())));
        }
        else {
            if (!CHECKED(ui.LangAudioCB))
                ui.AudioQueue->setItem(ui.AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("%1 (%2) - %3")
                    .arg(ui.SelectedAudioDD->currentIndex() + 1).arg(AudioInfo::GetLanguage(ui.SelectedAudioDD->currentIndex()).replace("?", "UND"))
                        .arg(AudioInfo::GetCodec(ui.SelectedAudioDD->currentIndex()))));
            else
                ui.AudioQueue->setItem(ui.AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("%1 (%2) - %3")
                    .arg(ui.SelectedAudioDD->currentIndex() + 1).arg(ui.LangAudioDD->currentText().remove(QRegularExpression("[^\\(]*\\(")).remove(")"))
                        .arg(AudioInfo::GetCodec(ui.SelectedAudioDD->currentIndex()))));
        }

        ui.AudioQueue->item(ui.AudioQueue->rowCount() - 1, 0)->setTextAlignment(Qt::AlignCenter);
        Stream << ui.SelectedAudioDD->currentIndex();

        if (CHECKED(ui.AudioTitleCB)) {
            Title << ui.AudioTitleTxtBox->text();
            IsTitle << true;
        }
        else {
            Title << QString();
            IsTitle << false;
        }

        if (CHECKED(ui.LangAudioCB)) {
            AudioLangs << ui.LangAudioDD->currentText().remove(QRegularExpression("[^\\(]*\\(")).remove(")");
            IsLang << true;
        }
        else {
            AudioLangs << QString();
            IsLang << false;
        }

        if (CHECKED(ui.EncodingAudioGB)) {
            IsEncoding << true;
            AudioCodec << ui.AudioEncoderDD->currentText().toLower().replace("vorbis", "libvorbis").replace("opus", "libopus").replace("mp3", "libmp3lame").replace("truehd", "truehd -strict -2").replace("dts", "dts -strict -2");
            Bitrate << ui.AudioBitrateNUD->value();
            Quality << ui.AudioQualityNUD->value();

            if (CHECKED(ui.DownmixCB))
                Channels << ui.DownmixDD->currentText().replace("Stereo", "2").replace("Mono", "1").replace("5.1", "6");
            else
                Channels << "0";
        }
        else {
            IsEncoding << false;
            AudioCodec << "copy";
            Channels << "0";
            Bitrate << 0;
            Quality << 0;
        }
    }
    else
        MsgBoxHelper(MessageType::Error, "EncodeGUI Error", "The selected input file is missing or does not exist.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void EncodeGUI::CreateJob() {
    if (Checks::CheckInput(ui.SelectInTxtBox->text())) {
        if (Checks::CheckInputExists(ui.SelectInTxtBox->text())) {
            if (Checks::CheckOutput(ui.SaveOutTxtBox->text())) {
                if (ffloader->video->state() == QProcess::Running) {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Please wait for EncodeGUI to gather media info before adding a job.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                
                if (CHECKED(ui.AudioCB) && ui.AudioDD->currentIndex() == 1 && ui.AudioQueue->rowCount() == 0) {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", "The audio queue cannot be empty.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(ui.UpscalingGB) && ui.Width2xNUD->value() % 2 != 0 || ui.Height2xNUD->value() % 2 != 0) {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Width and height in the \"Upscaling\" tab must consist of even (not odd) integral values.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(ui.ResizeGB) && ui.WidthNUD->value() % 2 != 0 || ui.HeightNUD->value() % 2 != 0) {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Width and height in the \"Size\" tab must consist of even (not odd) integral values.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(ui.InterpolationCB) && CHECKED(ui.UpscalingGB)) {
                    if (ui.GPUInterpDD->currentIndex() == ui.GPUUpscaleDD->currentIndex()) {
                        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "You cannot use the same GPU for both Frame Interpolation and Resolution Upscaling.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }
                if (CHECKED(ui.MultiGPUGB) && CHECKED(ui.UpscalingGB) && ui.GPU1IDNUD->value() == ui.GPU2IDNUD->value()) {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", "You cannot use the same GPU for the Dual-GPU setting (in Preferences > Encoding).", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                QString container;

                switch (ui.VideoEncDD->currentIndex()) {
                case 0:
                    container = ui.OutContainerx264DD->currentText();
                    break;
                case 1:
                    container = ui.OutContainerx265DD->currentText();
                    break;
                case 2:
                    container = ui.OutContainerProResDD->currentText();
                    break;
                case 3:
                    container = ui.OutContainerTheoraDD->currentText();
                    break;
                case 4:
                    container = ui.OutContainerVPXDD->currentText();
                    break;
                case 5:
                    container = ui.OutContainerAV1DD->currentText();
                    break;
                case 6:
                    container = ui.OutContainerMuxDD->currentText();
                    break;
                }
                
                if (ui.VideoEncDD->currentIndex() == 6) {
                    int index = 0;

                    if (VideoInfo::GetVideoCodec().contains("AVC"))
                        index = 0;
                    else if (VideoInfo::GetVideoCodec().contains("HEVC"))
                        index = 1;
                    else if (VideoInfo::GetVideoCodec().contains("ProRes"))
                        index = 2;
                    else if (VideoInfo::GetVideoCodec().contains("Theora"))
                        index = 3;
                    else if (VideoInfo::GetVideoCodec().contains("VP9") || VideoInfo::GetVideoCodec().contains("AV1") || VideoInfo::GetVideoCodec().contains("VP8"))
                        index = 4;
                    else if (VideoInfo::GetVideoCodec().contains("VC1"))
                        index = 5;
                    else if (VideoInfo::GetVideoCodec().contains("MPEG2"))
                        index = 6;
                    else if (VideoInfo::GetVideoCodec().contains("MPEG4"))
                        index = 7;
                    else {
                        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("%1 video codec isn't supported for muxing.")
                            .arg(VideoInfo::GetVideoCodec()), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                        return;
                    }

                    if (!Checks::CheckVideoCompatability(index, container)) {
                        QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("%1 video codec isn't supported with the %2 output container.")
                            .arg(VideoInfo::GetVideoCodec()).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
                        
                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));
                        
                        return;
                    }
                }

                if (CHECKED(ui.AudioCB)) {
                    if (QString(ui.SaveOutTxtBox->text() + container).contains(ui.SelectInTxtBox->text()) && QString(ui.SaveOutTxtBox->text() + container).length() == ui.SelectInTxtBox->text().length() && !ui.SaveOutTxtBox->text().isEmpty()) {
                        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "The output destination path cannot be equivalent to the source file path.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                    if (ui.AudioDD->currentIndex() == 1 && CHECKED(ui.EncodingAudioGB)) {
                        if (!Checks::CheckAudioCompatability(ui.AudioEncoderDD->currentIndex(), container)) {
                            QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("%1 audio codec isn't supported with the %2 output container.")
                                .arg(ui.AudioEncoderDD->currentText()).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);

                            if (msg == QMessageBox::Help)
                                QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                            return;
                        }
                    }
                    else if (ui.AudioDD->currentIndex() == 0) {
                        int index = 0;

                        FOR_EACH(AudioInfo::TotalStreams()) {
                            if (AudioInfo::GetCodec(i).contains("AAC"))
                                index = 0;
                            else if (AudioInfo::GetCodec(i).contains("MP3"))
                                index = 1;
                            else if (AudioInfo::GetCodec(i).contains("AC3") && !AudioInfo::GetCodec(i).contains("EAC3"))
                                index = 2;
                            else if (AudioInfo::GetCodec(i).contains("FLAC"))
                                index = 3;
                            else if (AudioInfo::GetCodec(i).contains("Vorbis"))
                                index = 4;
                            else if (AudioInfo::GetCodec(i).contains("Opus"))
                                index = 5;
                            else if (AudioInfo::GetCodec(i).contains("EAC3"))
                                index = 6;
                            else if (AudioInfo::GetCodec(i).contains("ALAC"))
                                index = 7;
                            else if (AudioInfo::GetCodec(i).contains("WMA"))
                                index = 8;
                            else if (AudioInfo::GetCodec(i).contains("PCM"))
                                index = 9;
                            else if (AudioInfo::GetCodec(i).contains("MP2"))
                                index = 10;
                            else if (AudioInfo::GetCodec(i).contains("DTS"))
                                index = 11;
                            else if (AudioInfo::GetCodec(i).contains("TrueHD"))
                                index = 12;
                            else {
                                QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("%1 audio codec isn't supported in EncodeGUI. Encode the the audio to a supported format using the built in audio encoding options.")
                                    .arg(AudioInfo::GetCodec(i)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

                                if (msg == QMessageBox::Help)
                                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                                return;
                            }

                            if (!Checks::CheckAudioCompatability(index, container)) {
                                QMessageBox::StandardButton msg = MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("%1 audio codec isn't supported with the %2 output container.")
                                    .arg(AudioInfo::GetCodec(i)).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);

                                if (msg == QMessageBox::Help)
                                    QDesktopServices::openUrl(QUrl("https://encodegui.com/support.html"));

                                return;
                            }
                        }
                    }
                }

                if (ui.VideoEncDD->currentIndex() == 0 && CHECKED(ui.Hardware264CB))
                    if (!VideoInfo::GetColors().contains("8-bit")) {
                        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Only 8-bit sources are allowed for hardware encoding in AVC. Use HEVC for higher bit depth videos.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                if (ui.VideoEncDD->currentIndex() == 1 && CHECKED(ui.Hardware265CB))
                    if (!VideoInfo::GetColors().contains("8-bit") && !VideoInfo::GetColors().contains("10-bit")) {
                        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "Only 8-bit and 10-bit sources are allowed for hardware encoding in HEVC. Disable hardware encoding for higher bit depth videos.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                if (CHECKED(ui.SubtitlesCB) && ui.SubtitlesDD->currentIndex() == 1 && (container.contains(".avi") || container.contains(".asf") || container.contains(".ts") || container.contains(".flv") || container.contains(".ogv"))) {
                    MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("The %1 output container does not support subtitles.").arg(container), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                else if (CHECKED(ui.SubtitlesCB) && ui.SubtitlesDD->currentIndex() == 0) {
                    
                    FOR_EACH(SubtitleInfo::TotalStreams())
                        if (!Checks::CheckSubtitleCompatability(SubtitleInfo::GetCodec(i), container)) {
                            MsgBoxHelper(MessageType::Error, "EncodeGUI error", QString("The %1 subtitle codec is not supported in the %2 output container.").arg(SubtitleInfo::GetCodec(i)).arg(container), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                            return;
                        }
                }

                if (CHECKED(ui.InterpolationCB) && ui.BackendDD->currentIndex() == 0)
                    if (!ui.GPUInterpDD->currentText().contains("NVIDIA")) {
                        MsgBoxHelper(MessageType::Error, "EncodeGUI error", "The currently selected GPU for CUDA frame interpolation is not an Nvidia GPU.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                bool twoPass = false;

                QDate date(QDate::currentDate());
                QString audioArgs, subtitleArgs;
                QString id = QString(QTime::currentTime().toString().remove(":")) + QString("%1").arg(date.day());

                ui.JobQueue->insertRow(ui.JobQueue->rowCount());
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 0, new QTableWidgetItem(id));
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 1, new QTableWidgetItem("Waiting"));
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 2, new QTableWidgetItem("0%"));
                ui.JobQueue->setItem(ui.JobQueue->rowCount() - 1, 3, new QTableWidgetItem(ui.SaveOutTxtBox->text() + container));

                state << "Waiting"; Vstate << "Waiting";

                for (int i = 0; i < 3; i++)
                    ui.JobQueue->item(ui.JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);

                QString jobDir = QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI\\job-%1").arg(id));
                QDir().mkpath(jobDir);

                if (ui.VideoEncDD->currentIndex() != 6) {
                    QFile script = QString("%1\\%2.vpy").arg(jobDir).arg(id);;
                    script.open(QIODevice::WriteOnly);

                    QTextStream stream(&script);

                    stream << BuildScript(VideoInfo::GetWidth(), VideoInfo::GetHeight(), id);

                    script.close();
                    vapourScript << ConfigureVS(id); VvapourScript << ConfigureVS(id);
                }
                else {
                    vapourScript << "novs"; VvapourScript << "novs";
                }

                QString tempFile = QString("%1.mkv").arg(id);

                if (CHECKED(ui.AudioCB) && ui.AudioDD->currentIndex() == 1) {
                    for (int i = 0; i < Stream.count(); i++)
                        audioArgs.append(ConfigureAudioM(1, Stream.at(i), QString("%1").arg(i), tempFile, container));

                    AudioArgs << audioArgs; VaudioArgs << audioArgs;
                }
                else if (CHECKED(ui.AudioCB)) {
                    audioArgs.append(ConfigureAudioP(1, tempFile, container));
                    AudioArgs << audioArgs; VaudioArgs << audioArgs;
                }
                else if (!CHECKED(ui.SubtitlesCB)) {
                    AudioArgs << QString(" -an -metadata:g encoding_tool=\"EncodeGUI v%1\"").arg(VERSION); VaudioArgs << QString(" -an -metadata:g encoding_tool=\"EncodeGUI v%1\"").arg(VERSION);
                }
                    

                if (CHECKED(ui.SubtitlesCB) && !CHECKED(ui.AudioCB)) {
                    audioArgs.append(ConfigureSubtitle(1, container, id));
                    AudioArgs << audioArgs;
                }

                switch (ui.VideoEncDD->currentIndex()) {
                case 0:
                    if (ui.Hardware264CB->isChecked())
                        if (ui.EncodeMode264HWDD->currentIndex() == 2)
                            twoPass = true;
                        else
                            twoPass = false;
                    else
                        if (ui.EncodeMode264DD->currentIndex() == 2)\
                            twoPass = true;
                        else
                            twoPass = false;
                    break;
                case 1:
                    if (ui.Hardware265CB->isChecked())
                        if (ui.EncodeMode265HWDD->currentIndex() == 2)
                            twoPass = true;
                        else
                            twoPass = false;
                    else
                        if (ui.EncodeMode265DD->currentIndex() == 2)
                            twoPass = true;
                        else
                            twoPass = false;
                    break;
                case 4:
                    if (ui.EncodeModeVPXDD->currentIndex() == 2)
                        twoPass = true;
                    else
                        twoPass = false;
                    break;
                }

                job << id; Vjob << id;
                
                inputList << ui.SelectInTxtBox->text(); VinputList << ui.SelectInTxtBox->text();
                tempList << QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(tempFile)); VtempList << QDir::toNativeSeparators(QDir::tempPath() + QString("\\%1").arg(tempFile));
                outputList << ui.SaveOutTxtBox->text() + container; VoutputList << ui.SaveOutTxtBox->text() + container;
                
                VideoInfoList::SetDuration(VideoInfo::GetDuration());
                Vduration << VideoInfo::GetDuration();

                if (!CHECKED(ui.InterpolationCB)) {
                    VideoInfoList::SetFrameRate(VideoInfo::GetFrameRate());
                    VframeRate << VideoInfo::GetFrameRate();
                }
                else {
                    VideoInfoList::SetFrameRate(QString("%1").arg(ui.OutputFPSNUD->value()));
                    VframeRate << QString("%1").arg(ui.OutputFPSNUD->value());
                }

                WriteLog(QString("Job with ID %1 successfully added to the Job Queue.").arg(id), false, false, false);

                if (!twoPass) {
                    if (ui.VideoEncDD->currentIndex() != 6) {
                        arguments << ConfigureArgs(container, id, audioArgs, subtitleArgs, twoPass, 0); Varguments << ConfigureArgs(container, id, audioArgs, subtitleArgs, twoPass, 0);
                    }
                    else {
                        arguments << ConfigureMux(container, audioArgs, subtitleArgs); Varguments << ConfigureMux(container, audioArgs, subtitleArgs);
                    }
                }
                else {
                    arguments << ConfigureArgs(container, id, " -an", QString(), twoPass, 1); Varguments << ConfigureArgs(container, id, " -an", QString(), twoPass, 1);
                }

                SetJobSetting();

                MsgBoxHelper(MessageType::Info, tr("Add job"), "Added job with ID: " + id, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            }
            else
                MsgBoxHelper(MessageType::Error, "EncodeGUI Error", "An output file must be specified.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        }
        else
            MsgBoxHelper(MessageType::Error, "EncodeGUI Error", "The selected input file is missing or does not exist.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else
        MsgBoxHelper(MessageType::Error, "EncodeGUI Error", "An input file must be specified.", QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}