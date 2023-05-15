#include "encodegui.hpp"

void EncodeGUI::setupQueue() {
    _ui->JobQueue->setColumnWidth(0, 79);
    _ui->JobQueue->setColumnWidth(1, 85);
    _ui->JobQueue->setColumnWidth(2, 80);
    _ui->JobQueue->setColumnWidth(3, 101);
    _ui->JobQueue->setColumnWidth(4, 101);
    _ui->JobQueue->setColumnWidth(5, 101);
    _ui->JobQueue->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    _ui->JobQueue->horizontalHeader()->setSectionsClickable(false);

    connect(_ui->JobQueue, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(jobContext(QPoint)));
    connect(_ui->AudioQueue, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(audioSubContext(QPoint)));
}

void EncodeGUI::audioSubContext(QPoint pos) {
    QTableWidgetItem *item(_ui->AudioQueue->itemAt(pos));

    if (item) {
        _ui->AudioQueue->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = item->row();
        _ui->AudioQueue->selectRow(row);

        QMenu *m(new QMenu(this));

        QAction *remove(new QAction(QString("Remove"), this));

        m->setFont(this->font());
        m->addAction(remove);
        m->popup(_ui->AudioQueue->viewport()->mapToGlobal(pos));

        _selectedAudio = row;
        connect(remove, SIGNAL(triggered()), this, SLOT(removeAudioClick()));

        connect(m, &QMenu::aboutToHide, [this]() {
            _ui->AudioQueue->selectionModel()->clear();
            _ui->AudioQueue->setSelectionMode(QAbstractItemView::NoSelection);
        });
    }
}

void EncodeGUI::jobContext(QPoint pos) {
    QTableWidgetItem *item(_ui->JobQueue->itemAt(pos));
    
    if (item) {
        _ui->JobQueue->setSelectionMode(QAbstractItemView::SingleSelection);

        int row = item->row();
        _ui->JobQueue->selectRow(row);
        _selectedJob = row;

        QMenu *m(new QMenu(this));
        QAction *input(new QAction(QString("Open input directory"), this));
        QAction *output(new QAction(QString("Open output directory"), this));
        QAction *pause(new QAction(QString("Pause / Resume"), this));
        QAction *cancel(new QAction(QString("Cancel"), this));
        QAction *remove(new QAction(QString("Remove"), this));
        QAction *reset(new QAction(QString("Reset"), this));

        if (_ui->JobQueue->item(row, 1)->text().contains(QString("Paused")) || _ui->JobQueue->item(row, 1)->text().contains(QString("Active"))) {
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
        m->addAction(input);
        m->addAction(output);
        m->addAction(pause);
        m->addAction(cancel);
        m->addAction(remove);
        m->addAction(reset);
        m->popup(_ui->JobQueue->viewport()->mapToGlobal(pos));

        connect(pause, SIGNAL(triggered()), this, SLOT(pauseClick()));
        connect(input, SIGNAL(triggered()), this, SLOT(inputClick()));
        connect(output, SIGNAL(triggered()), this, SLOT(outputClick()));
        connect(cancel, SIGNAL(triggered()), this, SLOT(cancelClick()));
        connect(remove, SIGNAL(triggered()), this, SLOT(removeJob()));
        connect(reset, SIGNAL(triggered()), this, SLOT(resetJob()));
        connect(m, &QMenu::aboutToHide, [this]() {
            _ui->JobQueue->selectionModel()->clear();
            _ui->JobQueue->setSelectionMode(QAbstractItemView::NoSelection);

            delete(sender());
        });
    }
}

void EncodeGUI::addAudioJob() {
    if (Checks::checkInputExists(_ui->SelectInTxtBox->text())) {
        _ui->AudioQueue->insertRow(_ui->AudioQueue->rowCount());

        if (CHECKED(_ui->EncodingAudioGB)) {
            if (!CHECKED(_ui->LangAudioCB))
                _ui->AudioQueue->setItem(_ui->AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("Track %1 - %2 - %3")
                    .arg(_ui->AudioQueue->rowCount()).arg(AudioInfo::getLanguage(_ui->SelectedAudioDD->currentIndex()).replace(QString("?"), QString("UND")))
                    .arg(_ui->AudioEncoderDD->currentText())));
            else
                _ui->AudioQueue->setItem(_ui->AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("Track %1 - %2 - %3")
                    .arg(_ui->AudioQueue->rowCount()).arg(_ui->LangAudioDD->currentText()).arg(_ui->AudioEncoderDD->currentText())));
        }
        else {
            if (!CHECKED(_ui->LangAudioCB))
                _ui->AudioQueue->setItem(_ui->AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("Track %1 - %2 - %3")
                    .arg(_ui->AudioQueue->rowCount()).arg(AudioInfo::getLanguage(_ui->SelectedAudioDD->currentIndex()).replace(QString("?"), QString("UND")))
                    .arg(AudioInfo::getCodec(_ui->SelectedAudioDD->currentIndex()))));
            else
                _ui->AudioQueue->setItem(_ui->AudioQueue->rowCount() - 1, 0, new QTableWidgetItem(QString("Track %1 - %2 - %3")
                    .arg(_ui->AudioQueue->rowCount()).arg(_ui->LangAudioDD->currentText()).arg(AudioInfo::getCodec(_ui->SelectedAudioDD->currentIndex()))));
        }

        _ui->AudioQueue->item(_ui->AudioQueue->rowCount() - 1, 0)->setTextAlignment(Qt::AlignCenter);
        _stream->append(_ui->SelectedAudioDD->currentIndex());

        if (CHECKED(_ui->AudioTitleCB)) {
            _title->append(_ui->AudioTitleTxtBox->text());
            _isTitle->append(true);
        }
        else {
            _title->append(QString());
            _isTitle->append(false);
        }

        if (CHECKED(_ui->LangAudioCB)) {
            _audioLangs->append(_ui->LangAudioDD->currentText().remove(QRegularExpression("[^\\(]*\\(")).remove(QString(")")));
            _isLang->append(true);
        }
        else {
            _audioLangs->append(QString());
            _isLang->append(false);
        }

        if (CHECKED(_ui->EncodingAudioGB)) {
            _isEncoding->append(true);
            _audioCodec->append(_ui->AudioEncoderDD->currentText().toLower().replace(QString("vorbis"), QString("libvorbis")).replace(QString("opus"), QString("libopus")).replace(QString("mp3"), QString("libmp3lame")).replace(QString("truehd"), QString("truehd -strict -2")).replace(QString("dts"), QString("dts -strict -2")));
            _bitrate->append(_ui->AudioBitrateNUD->value());
            _quality->append(_ui->AudioQualityNUD->value());

            if (CHECKED(_ui->DownmixCB))
                _channels->append(_ui->DownmixDD->currentText().replace(QString("Stereo"), QString("2")).replace(QString("Mono"), QString("1")).replace(QString("5.1"), QString("6")));
            else
                _channels->append(QString("0"));
        }
        else {
            _isEncoding->append(false);
            _audioCodec->append(QString("copy"));
            _channels->append(QString("0"));
            _bitrate->append(0);
            _quality->append(0);
        }
    }
    else
        msgBoxHelper(MessageType::Error, QString("EncodeGUI Error"), QString("The selected input file is missing or does not exist."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void EncodeGUI::createJob() {
    if (Checks::checkInput(_ui->SelectInTxtBox->text())) {
        if (Checks::checkInputExists(_ui->SelectInTxtBox->text())) {
            if (Checks::checkOutput(_ui->SaveOutTxtBox->text())) {
                if (_ffloader->_video->state() == QProcess::Running) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Please wait for EncodeGUI to gather media info before adding a job."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                
                if (CHECKED(_ui->AudioCB) && _ui->AudioDD->currentIndex() == 1 && _ui->AudioQueue->rowCount() == 0) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The audio queue cannot be empty."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(_ui->UpscalingGB) && _ui->Width2xNUD->value() % 2 != 0 || _ui->Height2xNUD->value() % 2 != 0) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Width and height in the \"Upscaling\" tab must consist of even (not odd) integral values."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(_ui->ResizeGB) && _ui->WidthNUD->value() % 2 != 0 || _ui->HeightNUD->value() % 2 != 0) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Width and height in the \"Size\" tab must consist of even (not odd) integral values."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(_ui->InterpolationCB) && CHECKED(_ui->UpscalingGB)) {
                    if (_ui->GPUInterpDD->currentIndex() == _ui->GPUUpscaleDD->currentIndex()) {
                        msgBoxHelper(MessageType::Error, "EncodeGUI error", QString("You cannot use the same GPU for both Frame Interpolation and Resolution Upscaling."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }
                if (CHECKED(_ui->MultiGPUGB) && CHECKED(_ui->UpscalingGB) && _ui->GPU1IDNUD->value() == _ui->GPU2IDNUD->value()) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("You cannot use the same GPU for the Dual-GPU setting (in Preferences > Encoding)."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                QString container;

                switch (_ui->VideoEncDD->currentIndex()) {
                case 0:
                    container = _ui->OutContainerx264DD->currentText();
                    break;
                case 1:
                    container = _ui->OutContainerx265DD->currentText();
                    break;
                case 2:
                    container = _ui->OutContainerProResDD->currentText();
                    break;
                case 3:
                    container = _ui->OutContainerTheoraDD->currentText();
                    break;
                case 4:
                    container = _ui->OutContainerVPXDD->currentText();
                    break;
                case 5:
                    container = _ui->OutContainerAV1DD->currentText();
                    break;
                case 6:
                    container = _ui->OutContainerMuxDD->currentText();
                    break;
                }
                
                if (_ui->VideoEncDD->currentIndex() == 6) {
                    int index = 0;

                    if (VideoInfo::getVideoCodec().contains(QString("AVC")))
                        index = 0;
                    else if (VideoInfo::getVideoCodec().contains(QString("HEVC")))
                        index = 1;
                    else if (VideoInfo::getVideoCodec().contains(QString("ProRes")))
                        index = 2;
                    else if (VideoInfo::getVideoCodec().contains(QString("Theora")))
                        index = 3;
                    else if (VideoInfo::getVideoCodec().contains(QString("VP9")) || VideoInfo::getVideoCodec().contains(QString("AV1")) || VideoInfo::getVideoCodec().contains(QString("VP8")))
                        index = 4;
                    else if (VideoInfo::getVideoCodec().contains(QString("VC1")))
                        index = 5;
                    else if (VideoInfo::getVideoCodec().contains(QString("MPEG2")))
                        index = 6;
                    else if (VideoInfo::getVideoCodec().contains(QString("MPEG4")))
                        index = 7;
                    else if (VideoInfo::getVideoCodec().contains(QString("HuffYUV")))
                        index = 8;
                    else {
                        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("%1 video codec isn't supported for muxing.")
                            .arg(VideoInfo::getVideoCodec()), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton));

                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

                        return;
                    }

                    if (!Checks::checkVideoCompatability(index, container)) {
                        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("%1 video codec isn't supported with the %2 output container.")
                            .arg(VideoInfo::getVideoCodec()).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));
                        
                        if (msg == QMessageBox::Help)
                            QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));
                        
                        return;
                    }
                }

                if (QFile(_ui->SaveOutTxtBox->text() + container).exists()) {
                    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Confirm overwrite"), QString("The output file already exists. Creating and starting this job will automatically overwrite that output file. Continue?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

                    if (msg == QMessageBox::No)
                        return;
                }

                if (QString(_ui->SaveOutTxtBox->text() + container).contains(_ui->SelectInTxtBox->text()) && QString(_ui->SaveOutTxtBox->text() + container).length() == _ui->SelectInTxtBox->text().length() && !_ui->SaveOutTxtBox->text().isEmpty()) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The output destination path cannot be equivalent to the source file path."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                if (CHECKED(_ui->AudioCB)) {
                    if (_ui->AudioDD->currentIndex() == 1 && CHECKED(_ui->EncodingAudioGB)) {
                        if (!Checks::checkAudioCompatability(_ui->AudioEncoderDD->currentIndex(), container)) {
                            QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("%1 audio codec isn't supported with the %2 output container.")
                                .arg(_ui->AudioEncoderDD->currentText()).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));

                            if (msg == QMessageBox::Help)
                                QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

                            return;
                        }
                    }
                    else if (_ui->AudioDD->currentIndex() == 0) {
                        int index = 0;

                        FOR_EACH(AudioInfo::totalStreams()) {
                            if (AudioInfo::getCodec(i).contains(QString("AAC")))
                                index = 0;
                            else if (AudioInfo::getCodec(i).contains(QString("MP3")))
                                index = 1;
                            else if (AudioInfo::getCodec(i).contains(QString("AC3")) && !AudioInfo::getCodec(i).contains(QString("EAC3")))
                                index = 2;
                            else if (AudioInfo::getCodec(i).contains(QString("FLAC")))
                                index = 3;
                            else if (AudioInfo::getCodec(i).contains(QString("Vorbis")))
                                index = 4;
                            else if (AudioInfo::getCodec(i).contains(QString("Opus")))
                                index = 5;
                            else if (AudioInfo::getCodec(i).contains(QString("EAC3")))
                                index = 6;
                            else if (AudioInfo::getCodec(i).contains(QString("ALAC")))
                                index = 7;
                            else if (AudioInfo::getCodec(i).contains(QString("WMA")))
                                index = 8;
                            else if (AudioInfo::getCodec(i).contains(QString("PCM")))
                                index = 9;
                            else if (AudioInfo::getCodec(i).contains(QString("MP2")))
                                index = 10;
                            else if (AudioInfo::getCodec(i).contains(QString("DTS")))
                                index = 11;
                            else if (AudioInfo::getCodec(i).contains(QString("TrueHD")))
                                index = 12;
                            else {
                                QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("%1 audio codec isn't supported in EncodeGUI. Encode the the audio to a supported format using the built in audio encoding options.")
                                    .arg(AudioInfo::getCodec(i)), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));

                                if (msg == QMessageBox::Help)
                                    QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

                                return;
                            }

                            if (!Checks::checkAudioCompatability(index, container)) {
                                QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("%1 audio codec isn't supported with the %2 output container.")
                                    .arg(AudioInfo::getCodec(i)).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));

                                if (msg == QMessageBox::Help)
                                    QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

                                return;
                            }
                        }
                    }
                }

                if (_ui->VideoEncDD->currentIndex() == 0 && CHECKED(_ui->Hardware264CB))
                    if (!VideoInfo::getColors().contains(QString("8-bit"))) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Only 8-bit sources are allowed for hardware encoding in AVC. Use HEVC for higher bit depth videos."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                if (_ui->VideoEncDD->currentIndex() == 1 && CHECKED(_ui->Hardware265CB))
                    if (!VideoInfo::getColors().contains(QString("8-bit")) && !VideoInfo::getColors().contains(QString("10-bit"))) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Only 8-bit and 10-bit sources are allowed for hardware encoding in HEVC. Disable hardware encoding for higher bit depth videos."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 1 && (container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ts")) || container.contains(QString(".flv")) || container.contains(QString(".ogv")))) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The %1 output container does not support subtitles.").arg(container), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                else if (CHECKED(_ui->SubtitlesCB) && _ui->SubtitlesDD->currentIndex() == 0) {
                    
                    FOR_EACH(SubtitleInfo::totalStreams())
                        if (!Checks::checkSubtitleCompatability(SubtitleInfo::getCodec(i), container)) {
                            QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The %1 subtitle codec is not supported in the %2 output container.").arg(SubtitleInfo::getCodec(i)).arg(container), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));
                            
                            if (msg == QMessageBox::Help)
                                QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));
                            
                            return;
                        }
                }

                if (CHECKED(_ui->InterpolationCB) && _ui->BackendDD->currentIndex() == 0)
                    if (!_ui->GPUInterpDD->currentText().contains(QString("NVIDIA"))) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The currently selected GPU for CUDA frame interpolation is not an Nvidia GPU."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }

                if ((CHECKED(_ui->InterpolationCB) && _ui->ToolInterpDD->currentIndex() != 2) && _ui->GPUInterpDD->currentText().contains("Intel") && !_ui->GPUInterpDD->currentText().contains("Arc")) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Intel integrated GPUs are not supported for AI frame interpolation."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }
                if (CHECKED(_ui->UpscalingGB) && _ui->GPUUpscaleDD->currentText().contains("Intel") && !_ui->GPUUpscaleDD->currentText().contains("Arc")) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Intel integrated GPUs are not supported for AI resolution upscaling."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                if (CHECKED(_ui->CropGB) && (_ui->OutWidthNUD->value() > VideoInfo::getWidth() || _ui->OutHeightNUD->value() > VideoInfo::getHeight())) {
                    msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Crop width/height cannot be larger than the source video width/height."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                    return;
                }

                if (CHECKED(_ui->DBVisionGB) && _ui->VideoEncDD->currentIndex() == 1 && !CHECKED(_ui->Hardware265CB)) {
                    if (_ui->RpuTxtBox->text().isEmpty()) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("An RPU file must be specified in the Dolby Vision configuration."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                    if (_ui->EncodeMode265DD->currentIndex() == 0) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Constant rate factor (CRF) encoding mode is not supported with Dolby Vision. Only use average bitrate or target bitrate modes."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                    if (_ui->EncodeMode265DD->currentIndex() == 4) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Constant quantizer (CQ) encoding mode is not supported with Dolby Vision. Only use average bitrate or target bitrate modes."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                    if (!CHECKED(_ui->HDRMetadataGB) || _ui->MasterDisplayTxtBox->text().isEmpty()) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("HDR master display text box must be configured to allow Dolby Vision support."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                    if (!CHECKED(_ui->ColorsHDRGB)) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("HDR color spaces must be enabled and defined to HDR standards to allow Dolby Vision support."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                    if (!CHECKED(_ui->Profile265GB) || _ui->Profile265DD->currentIndex() != 1) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Main 10 HEVC profile must be used to allow Dolby Vision support."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                    if (_ui->BitDepth265DD->currentIndex() != 1) {
                        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("10-bit color bit depth in HEVC must be used to allow Dolby Vision support."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                        return;
                    }
                }

                bool twoPass = false;

                QDate date(QDate::currentDate());
                QStringList audioArgs, subtitleArgs;
                QString id(QString(QTime::currentTime().toString().remove(QString(":"))) + QString("%1").arg(date.day()));

                _ui->JobQueue->insertRow(_ui->JobQueue->rowCount());
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 0, new QTableWidgetItem(id));
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 1, new QTableWidgetItem(QString("Waiting")));
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 2, new QTableWidgetItem(QString("0%")));

                bttns();

                _state->append(QString("Waiting"));
                _sState.append(QString("Waiting"));

                for (int i = 0; i < 3; i++)
                    _ui->JobQueue->item(_ui->JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);

                QString jobDir(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(id)));
                QDir().mkpath(jobDir);

                if (_ui->VideoEncDD->currentIndex() != 6) {
                    QFile script(QString("%1\\%2.vpy").arg(jobDir).arg(id));
                    script.open(QIODevice::WriteOnly);

                    QTextStream stream(&script);

                    stream << buildScript(VideoInfo::getWidth(), VideoInfo::getHeight(), id);
                    script.close();

                    _vapourScript.append(configureVS(id)); 
                    _sVapourScript.append(configureVS(id));
                }
                else {
                    _vapourScript.append(QString("novs"));
                    _sVapourScript.append(QString("novs"));
                }

                QString tempFile(QString("%1.mkv").arg(id));

                if (CHECKED(_ui->AudioCB) && _ui->AudioDD->currentIndex() == 1) {
                    for (int i = 0; i < _stream->count(); i++)
                        audioArgs.append(configureAudioM(1, _stream->at(i), QString("%1").arg(i), tempFile, container));

                    _audioArgs.append(audioArgs); 
                    _sAudioArgs.append(audioArgs);
                }
                else if (CHECKED(_ui->AudioCB)) {
                    audioArgs.append(configureAudioP(1, tempFile, container));
                    
                    _audioArgs.append(audioArgs); 
                    _sAudioArgs.append(audioArgs);
                }
                else if (!CHECKED(_ui->SubtitlesCB)) {
                    _audioArgs.append(QStringList() << QString("-an") << QString("-metadata:g") << QString("encoding_tool=\"EncodeGUI v%1\"").arg(VERSION));
                    _sAudioArgs.append(QStringList() << QString("-an") << QString("-metadata:g") << QString("encoding_tool=\"EncodeGUI v%1\"").arg(VERSION));
                }

                if (CHECKED(_ui->SubtitlesCB) && !CHECKED(_ui->AudioCB)) {
                    audioArgs.append(configureSubtitle(1, container, id));
                    _audioArgs.append(audioArgs);
                }

                switch (_ui->VideoEncDD->currentIndex()) {
                case 0:
                    if (CHECKED(_ui->Hardware264CB)) {
                        if (_ui->EncodeMode264HWDD->currentIndex() == 2)
                            twoPass = true;
                    }
                    else
                        if (_ui->EncodeMode264DD->currentIndex() == 2)
                            twoPass = true;
                    break;
                case 1:
                    if (CHECKED(_ui->Hardware265CB)) {
                        if (_ui->EncodeMode265HWDD->currentIndex() == 2)
                            twoPass = true;
                    }
                    else
                        if (_ui->EncodeMode265DD->currentIndex() == 2)
                            twoPass = true;
                    break;
                case 4:
                    if (_ui->EncodeModeVPXDD->currentIndex() == 2)
                        twoPass = true;
                    break;
                }

                _job->append(id); 
                _sJob.append(id);
                
                _inputList->append(_ui->SelectInTxtBox->text()); 
                _sInputList.append(_ui->SelectInTxtBox->text());

                _tempList->append(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1").arg(tempFile)));
                _sTempList.append(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1").arg(tempFile)));

                _outputList->append(_ui->SaveOutTxtBox->text() + container); 
                _sOutputList.append(_ui->SaveOutTxtBox->text() + container);
                
                VideoInfoList::setDuration(VideoInfo::getDuration());
                _sDuration.append(VideoInfo::getDuration());

                if (!CHECKED(_ui->InterpolationCB)) {
                    VideoInfoList::setFrameRate(VideoInfo::getFrameRate());
                    _sFrameRate.append(VideoInfo::getFrameRate());
                }
                else {
                    VideoInfoList::setFrameRate(QString("%1").arg(_ui->OutputFPSNUD->value()));
                    _sFrameRate.append(QString("%1").arg(_ui->OutputFPSNUD->value()));
                }

                writeLog(QString("Job with ID %1 successfully added to the Job Queue.").arg(id), false, false, false);

                if (!twoPass) {
                    if (_ui->VideoEncDD->currentIndex() != 6) {
                        _arguments.append(configureArgs(container, id, twoPass, 0)); 
                        _sArguments.append(configureArgs(container, id, twoPass, 0));
                    }
                    else {
                        _arguments.append(configureMux(container, audioArgs, subtitleArgs)); 
                        _sArguments.append(configureMux(container, audioArgs, subtitleArgs));
                    }
                }
                else {
                    _arguments.append(configureArgs(container, id, twoPass, 1));
                    _sArguments.append(configureArgs(container, id, twoPass, 1));
                }

                queueScrollBar();
                setJobSetting();

                msgBoxHelper(MessageType::Info, QString("Add job"), QString("Added job with ID: ") + id, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            }
            else
                msgBoxHelper(MessageType::Error, QString("EncodeGUI Error"), QString("An output file must be specified."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        }
        else
            msgBoxHelper(MessageType::Error, QString("EncodeGUI Error"), QString("The selected input file is missing or does not exist."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else
        msgBoxHelper(MessageType::Error, QString("EncodeGUI Error"), QString("An input file must be specified."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}