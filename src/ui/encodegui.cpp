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

EncodeGUI::EncodeGUI(QWidget *parent) : QMainWindow(parent) {
    _ui = new Ui::EncodeGUIMV();
    _ui->setupUi(this);
    setupQueue();
    _preview = new Preview(this);

    connect(_ui->VideoEncDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hideEnc()));
    connect(_ui->UseGPUCB, SIGNAL(stateChanged(int)), this, SLOT(hideInterpGpu()));
    connect(_ui->BackendDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hideInterpGpuCB()));
    connect(_ui->ToolInterpDD, SIGNAL(currentIndexChanged(int)), this, SLOT(toolInterp()));
    connect(_ui->ToolUpscaleDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hideUpscale()));
    connect(_ui->AudioCB, SIGNAL(stateChanged(int)), this, SLOT(hideAud()));
    connect(_ui->SubtitlesCB, SIGNAL(stateChanged(int)), this, SLOT(hideSubtitle()));
    connect(_ui->AudioDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hideAudTab()));
    connect(_ui->EncodeMode264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode264()));
    connect(_ui->Preset264CB, SIGNAL(stateChanged(int)), this, SLOT(hidePre264()));
    connect(_ui->Tune264CB, SIGNAL(stateChanged(int)), this, SLOT(hideTun264()));
    connect(_ui->Profile264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(profile264()));
    connect(_ui->Profile264GB, SIGNAL(toggled(bool)), this, SLOT(profileGB264()));
    connect(_ui->Reference264Sldr, SIGNAL(valueChanged(int)), this, SLOT(refsldr264()));
    connect(_ui->BFrame264Sldr, SIGNAL(valueChanged(int)), this, SLOT(bsldr264()));
    connect(_ui->SceneChangeCB, SIGNAL(stateChanged(int)), this, SLOT(thresholdNUD()));
    connect(_ui->EncodeMode265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode265()));
    connect(_ui->Preset265CB, SIGNAL(stateChanged(int)), this, SLOT(hidePre265()));
    connect(_ui->Tune265CB, SIGNAL(stateChanged(int)), this, SLOT(hideTun265()));
    connect(_ui->Profile265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(profile265()));
    connect(_ui->Profile265GB, SIGNAL(toggled(bool)), this, SLOT(profileGB265()));
    connect(_ui->Reference265Sldr, SIGNAL(valueChanged(int)), this, SLOT(refsldr265()));
    connect(_ui->BFrame265Sldr, SIGNAL(valueChanged(int)), this, SLOT(bsldr265()));
    connect(_ui->EncodeModeTDD, SIGNAL(currentIndexChanged(int)), this, SLOT(modeTheora()));
    connect(_ui->AudioEncoderDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioDD()));
    connect(_ui->DownmixCB, SIGNAL(stateChanged(int)), this, SLOT(downmixCB()));
    connect(_ui->EncodeModeVPXDD, SIGNAL(currentIndexChanged(int)), this, SLOT(modeVpx()));
    connect(_ui->ProfileVPXDD, SIGNAL(currentIndexChanged(int)), this, SLOT(profileVpx()));
    connect(_ui->SelectInBttn, SIGNAL(clicked(bool)), this, SLOT(inputBttn()));
    connect(_ui->SampleVidCB, SIGNAL(stateChanged(int)), this, SLOT(sampleVid()));
    connect(_ui->SaveOutBttn, SIGNAL(clicked(bool)), this, SLOT(outBttn()));
    connect(_ui->AddJobBttn, SIGNAL(clicked(bool)), this, SLOT(createJob()));
    connect(_ui->StartBttn, SIGNAL(clicked(bool)), this, SLOT(start()));
    connect(_ui->CancelBttn, SIGNAL(clicked(bool)), this, SLOT(cancelMain()));
    connect(_ui->PauseBttn, SIGNAL(clicked(bool)), this, SLOT(pauseClick()));
    connect(_ui->CancelQueueBttn, SIGNAL(clicked(bool)), this, SLOT(cancelAllClick()));
    connect(_ui->ClearJobsBttn, SIGNAL(clicked(bool)), this, SLOT(clearFinished()));
    connect(_ui->AddAudioJobBttn, SIGNAL(clicked(bool)), this, SLOT(addAudioJob()));
    connect(_ui->RIFEModelVKDD, SIGNAL(currentIndexChanged(int)), this, SLOT(modelVK()));
    connect(_ui->LogsDirBttn, SIGNAL(clicked(bool)), this, SLOT(openLogs()));
    connect(_ui->PreviewBttn, SIGNAL(clicked(bool)), this, SLOT(openPreview()));
    connect(_ui->AutoAdjCB, SIGNAL(stateChanged(int)), this, SLOT(autoAjustU()));
    connect(_ui->AutoAdjDD, SIGNAL(currentIndexChanged(int)), this, SLOT(autoAdjustUD()));
    connect(_ui->AutoAdjResCB, SIGNAL(stateChanged(int)), this, SLOT(autoAdjust()));
    connect(_ui->AutoAdjResDD, SIGNAL(currentIndexChanged(int)), this, SLOT(autoAdjustDD()));
    connect(_ui->ResizeAlgoCB, SIGNAL(stateChanged(int)), this, SLOT(algoDD()));
    connect(_ui->FlipCB, SIGNAL(stateChanged(int)), this, SLOT(flipDD()));
    connect(_ui->ModelUpscaleDD, SIGNAL(currentIndexChanged(int)), this, SLOT(modelUpScaleGB()));
    connect(_ui->UpscalingGB, SIGNAL(toggled(bool)), this, SLOT(upscaleGB()));
    connect(_ui->ResizeGB, SIGNAL(toggled(bool)), this, SLOT(resizeGB()));
    connect(_ui->ToolUpscaleDD, SIGNAL(currentIndexChanged(int)), this, SLOT(modelUpscale()));
    connect(_ui->JobsCB, SIGNAL(stateChanged(int)), this, SLOT(jobsCB()));
    connect(_ui->FPSCB, SIGNAL(stateChanged(int)), this, SLOT(fpsCB()));
    connect(_ui->BitrateCB, SIGNAL(stateChanged(int)), this, SLOT(bitrateCB()));
    connect(_ui->TimeLeftCB, SIGNAL(stateChanged(int)), this, SLOT(timeLeftCB()));
    connect(_ui->TimeElapsedCB, SIGNAL(stateChanged(int)), this, SLOT(timerCB()));
    connect(_ui->PercentageCB, SIGNAL(stateChanged(int)), this, SLOT(percentCB()));
    connect(_ui->DonateToDaGooseBttn, SIGNAL(clicked(bool)), this, SLOT(donateDaGoose()));
    connect(_ui->DonateToGlitchBttn, SIGNAL(clicked(bool)), this, SLOT(donateGlitch()));
    connect(_ui->YoutubeBttn, SIGNAL(clicked(bool)), this, SLOT(youClick()));
    connect(_ui->DiscordBttn, SIGNAL(clicked(bool)), this, SLOT(disClick()));
    connect(_ui->InstaBttn, SIGNAL(clicked(bool)), this, SLOT(igClick()));
    connect(_ui->EnablePreviewCB, SIGNAL(stateChanged(int)), this, SLOT(enablePreview()));
    connect(_ui->ErrorMessageCB, SIGNAL(stateChanged(int)), this, SLOT(errorMsg()));
    connect(_ui->UpdateOptCB, SIGNAL(stateChanged(int)), this, SLOT(updateOpt()));
    connect(_ui->DynamicMetadataBttn, SIGNAL(clicked(bool)), this, SLOT(hdrMeta()));
    connect(_ui->RpuFileBttn, SIGNAL(clicked(bool)), this, SLOT(rpu()));
    connect(_ui->GetVidInfoCB, SIGNAL(stateChanged(int)), this, SLOT(mediaInfo()));
    connect(_ui->AudioTitleCB, SIGNAL(stateChanged(int)), this, SLOT(audioTitle()));
    connect(_ui->GenerateOutCB, SIGNAL(stateChanged(int)), this, SLOT(genOutput()));
    connect(_ui->EncodeModeAV1DD, SIGNAL(currentIndexChanged(int)), this, SLOT(modeAv1()));
    connect(_ui->LangAudioCB, SIGNAL(stateChanged(int)), this, SLOT(audioLang()));
    connect(_ui->SubtitleTitleCB, SIGNAL(stateChanged(int)), this, SLOT(subtitleTitle()));
    connect(_ui->SubtitleLangCB, SIGNAL(stateChanged(int)), this, SLOT(subtitleLang()));
    connect(_ui->SubtitlesDD, SIGNAL(currentIndexChanged(int)), this, SLOT(hideSubtitleTab()));
    connect(_ui->AddSubtitleJobBttn, SIGNAL(clicked(bool)), this, SLOT(addSubtitleJob()));
    connect(_ui->BatchCB, SIGNAL(stateChanged(int)), this, SLOT(batch()));
    connect(_ui->NotificationCB, SIGNAL(stateChanged(int)), this, SLOT(nextJob()));
    connect(_ui->SelectBttn, SIGNAL(clicked(bool)), this, SLOT(audioSelectClick()));
    connect(_ui->SubSelectBttn, SIGNAL(clicked(bool)), this, SLOT(subtitleSelectClick()));
    connect(_ui->SubtitleInfoBttn, SIGNAL(clicked(bool)), this, SLOT(subtitleClick()));
    connect(_ui->ClearBttn, SIGNAL(clicked(bool)), this, SLOT(clearBttn()));
    connect(_ui->LicensesBttn, SIGNAL(clicked(bool)), this, SLOT(licenseBttn()));

    #ifdef Q_OS_WINDOWS
    connect(_ui->MultiGPUGB, SIGNAL(toggled(bool)), this, SLOT(dualGPU()));
    connect(_ui->TestGPUBttn, SIGNAL(clicked(bool)), this, SLOT(checkGPU()));
    connect(_ui->EncodeMode265HWDD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode265()));
    connect(_ui->Hardware265CB, SIGNAL(stateChanged(int)), this, SLOT(hdwr265()));
    connect(_ui->LimitThreadsCB, SIGNAL(stateChanged(int)), this, SLOT(cpuThread()));
    connect(_ui->EncodeMode264HWDD, SIGNAL(currentIndexChanged(int)), this, SLOT(mode264()));
    connect(_ui->Hardware264CB, SIGNAL(stateChanged(int)), this, SLOT(hdwr264()));
    connect(_ui->ParamsCB, SIGNAL(stateChanged(int)), this, SLOT(hideParams()));
    connect(_ui->GPU1IDNUD, SIGNAL(valueChanged(int)), this, SLOT(gpu1()));
    connect(_ui->GPU2IDNUD, SIGNAL(valueChanged(int)), this, SLOT(gpu2()));
    #endif

    #ifdef VERIFY
    connect(_ui->RegistrationBttn, SIGNAL(clicked(bool)), this, SLOT(verifyClick()));
    #endif

    mAlloc();

    connect(_ffloader, SIGNAL(extractInfo()), this, SLOT(extracterInfo()));
    connect(_ffloader, SIGNAL(extractComplete()), this, SLOT(extracterComplete()));
    connect(_ffloader, SIGNAL(setAudioInfo()), this, SLOT(audioFinished()));
    connect(_ffloader, SIGNAL(setSubtitleInfo()), this, SLOT(subtitleFinished()));
    connect(_ffloader, SIGNAL(setVideoInfo()), this, SLOT(regexFinished()));
    connect(_ffloader, SIGNAL(setBatchInfo()), this, SLOT(batchFinished()));
    connect(_ffloader, SIGNAL(setProgress()), this, SLOT(updateProgress()));
    connect(_ffloader, SIGNAL(completed()), this, SLOT(encodeFinished()));
    connect(_ffloader, SIGNAL(vkComplete()), this, SLOT(vkFinished()));
    connect(_ffloader, SIGNAL(logs(QString)), this, SLOT(writeFile(QString)));
    connect(_ffloader, SIGNAL(errorLogs(QString)), this, SLOT(writeFile(QString)));
    connect(_ffloader, SIGNAL(rpuFinished()), this, SLOT(extractRPUFinished()));
    
    hideEnc();
    hideAud();
    hideSubtitle();
    
    mode264();
    hidePre264();
    hideTun264();
    audioDD();
    profile264();
    hideInterpGpu();
    profileVpx();
    refsldr264();
    bsldr264();
    subtitleTitle();
    profileGB264();
    batch();
    sampleVid();
    audioLang();
    mode265();
    modeVpx();
    modeAv1();
    downmixCB();
    modeTheora();
    hidePre265();
    hideTun265();
    profile265();
    profileGB265();
    refsldr265();
    bsldr265();
    hideSubtitleTab();
    subtitleLang();
    thresholdNUD();
    hideUpscale();
    autoAjustU();
    autoAdjustUD();
    autoAdjust();
    autoAdjustDD();
    flipDD();
    audioTitle();
    algoDD();

    #ifdef Q_OS_WINDOWS
    toolInterp();
    hideParams();
    hideInterpGpuCB();
    hdwr265d();
    hdwr264();
    hdwr264d();
    hdwr265();
    #endif

    //fix disabled bug
    _ui->InterpolationCB->setChecked(true);
    _ui->InterpolationCB->setChecked(false);
    _ui->SceneChangeCB->setChecked(true);
    _ui->SceneChangeCB->setChecked(false);
    _ui->UpscalingGB->setChecked(true);
    _ui->UpscalingGB->setChecked(false);
    _ui->Preset264DD->setCurrentIndex(6);
    _ui->Preset265DD->setCurrentIndex(6);
    _ui->ResizeGB->setChecked(true);
    _ui->ResizeGB->setChecked(false);

    #ifdef Q_OS_WINDOWS
    if (!QDir(QDir::toNativeSeparators(LOGPATH_WIN)).exists())
        QDir().mkpath(QDir::toNativeSeparators(LOGPATH_WIN));
    #endif
    #ifdef Q_OS_DARWIN
    if (!QDir(QDir::toNativeSeparators(LOGPATH_DAR)).exists())
        QDir().mkpath(QDir::toNativeSeparators(LOGPATH_DAR));
    #endif

    writeLog(QString("Welcome to EncodeGUI! You are using the v%1 build.").arg(VERSION), false, false, false);

    #ifdef Q_OS_WINDOWS
    writeLog(QString("This is a user information log and will not be accepted in an issue/bug report."), true, false, false);
    #endif
    #ifdef Q_OS_DARWIN
    writeLog(QString("This is a user information log and will not be accepted in an issue/bug report."), false, false, false);
    #endif

    writeLog(QString("Visit https://encodegui.com/support for directions on how to submit a proper issue/bug report."), false, false, false);

    gpuFinished();

    #ifdef Q_OS_DARWIN
    _ui->UseGPUCB->setChecked(true);
    SET_DISABLED(_ui->UseGPUCB);
    #endif

    #ifdef Q_OS_WINDOWS
    _ui->BackendDD->removeItem(2);
    checkEncoders();
    getProcessor();
    #endif

    connect(_ui->AutoDelSourceCB, SIGNAL(stateChanged(int)), this, SLOT(delSource()));

    connect(new QShortcut(QKeySequence(Qt::Key_F1), this), &QShortcut::activated, []() { QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support"))); });
    
    if (CHECKED(_ui->UpdateOptCB))
        updater();
    else
        writeLog(QString("The user had selected to opt-out of automatically checking for updates in preferences. Skipping update search..."), false, false, false);

    loadSysSetting();

    FOR_EACH(_arguments.count()) {
        _ui->JobQueue->insertRow(_ui->JobQueue->rowCount());

        #ifdef Q_OS_WINDOWS
        bool checkVsScript = Checks::checkVsScript(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1\\%1.vpy")).arg(_job->at(i))) && Checks::checkInputExists(_inputList->at(i));
        #endif
        #ifdef Q_OS_DARWIN
        bool checkVsScript = Checks::checkVsScript(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1/%1.vpy")).arg(_job->at(i))) && Checks::checkInputExists(_inputList->at(i));
        #endif

        if (checkVsScript) {
            _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 0, new QTableWidgetItem(_job->at(i)));
            _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 1, new QTableWidgetItem(_state->at(i)));

            if (_state->at(i).contains(QString("Finished")))
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 2, new QTableWidgetItem(QString("100%")));
            else
                _ui->JobQueue->setItem(_ui->JobQueue->rowCount() - 1, 2, new QTableWidgetItem(QString("0%")));

            bttns();

            for (int i = 0; i < 3; i++)
                _ui->JobQueue->item(_ui->JobQueue->rowCount() - 1, i)->setTextAlignment(Qt::AlignCenter);

            writeLog(QString("Loaded job %1 from backup successfully.").arg(_job->at(i)), false, false, false);
        }
        else {
            writeLog(QString("Error: Job %1 automatically removed from job queue because either the source file or VapourSynth script file is missing or does not exist.").arg(_job->at(i)), false, true, false);

            _ui->JobQueue->removeRow(i);

            _arguments.removeAt(i);

            #ifdef Q_OS_WINDOWS
            _vapourScript.removeAt(i);
            #endif

            _tempList->removeAt(i);
            _audioArgs.removeAt(i);
            _outputList->removeAt(i);
            _inputList->removeAt(i);
            _state->removeAt(i);

            #ifdef Q_OS_WINDOWS
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif
            #ifdef Q_OS_DARWIN
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif

            _job->removeAt(i);

            VideoInfoList::removeJobDuration(i);
            VideoInfoList::removeJobFrameRate(i);
            
            i--;
        }
    }

    queueScrollBar();
    saveSettings();
    setJobSetting();
}

void EncodeGUI::showEvent(QShowEvent *event) {
    QWidget::showEvent(event);

    #ifdef Q_OS_WINDOWS
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libssl-1_1-x64.dll"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"libssl-1_1-x64.dll\" is missing in the EncodeGUI installation folder. A clean install should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\libcrypto-1_1-x64.dll"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"libcrypto-1_1-x64.dll\" is missing in the EncodeGUI installation folder. A clean install should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\tls\\qopensslbackend.dll"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"qopensslbackend.dll\" is missing in the EncodeGUI installation folder. A clean install should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    #endif
    #ifdef Q_OS_DARWIN
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/../PlugIns/tls/libqsecuretransportbackend.dylib"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("FrameGUI error"), QString("Required dependency \"libqsecuretransportbackend.dylib\" is missing in the FrameGUI installation folder. A clean install (uninstall + reinstall) should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        std::exit(0);
    }
    #endif
}

void EncodeGUI::jobBttn() {
    int row = sender()->property("row").toInt();
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Info, QString("Job %1 input").arg(_job->at(row)), QString("Path: \"%1\"").arg(_inputList->at(row)), QMessageBox::Open, QMessageBox::Ok, QMessageBox::NoButton));

    if (msg == QMessageBox::Open)
        QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(_inputList->at(row))));
}

void EncodeGUI::jobBttn2() {
    int row = sender()->property("row").toInt();
    QMessageBox::StandardButton bttn;

    if (QFile(_outputList->at(row)).exists() && _state->at(row).contains(QString("Finished")))
        bttn = QMessageBox::Open;
    else
        bttn = QMessageBox::NoButton;

    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Info, QString("Job %1 output").arg(_job->at(row)), QString("Path: \"%1\"").arg(_outputList->at(row)), QMessageBox::Ok, bttn, QMessageBox::NoButton));

    if (msg == QMessageBox::Open)
        QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(_outputList->at(row))));
}

void EncodeGUI::licenseBttn() {
    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\licenses"))));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/licenses"))));
    #endif
}

void EncodeGUI::clearBttn() {
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Warning, QString("Warning"), QString("Clearing the saved data will remove ALL inactive jobs in the queue. Continue?"), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::No)
        return;
    else if (msg == QMessageBox::Yes) {
        FOR_EACH(_arguments.count())
            if (!_ui->JobQueue->item(i, 1)->text().contains(QString("Active")) && !_ui->JobQueue->item(i, 1)->text().contains(QString("Paused"))) {
                _ui->JobQueue->removeRow(i);
                _arguments.removeAt(i);

                #ifdef Q_OS_WINDOWS
                _vapourScript.removeAt(i);
                #endif

                _tempList->removeAt(i);
                _audioArgs.removeAt(i);
                _outputList->removeAt(i);
                _inputList->removeAt(i);
                _state->removeAt(i);

                delete(_inputBttn->at(i));
                delete(_outputBttn->at(i));
                delete(_logsBttn->at(i));
                _inputBttn->removeAt(i);
                _outputBttn->removeAt(i);
                _logsBttn->removeAt(i);

                #ifdef Q_OS_WINDOWS
                QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(i))).removeRecursively();
                #endif
                #ifdef Q_OS_DARWIN
                QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(i))).removeRecursively();
                #endif

                _job->removeAt(i);

                VideoInfoList::removeJobDuration(i);
                VideoInfoList::removeJobFrameRate(i);

                i--;
            }

        QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("key"), QVariantList());

        reIndexBttns();
        saveSettings();
        setJobSetting();

        msgBoxHelper(MessageType::Info, QString("Saved data deleted"), QString("Save data was cleared successfully."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::checkEncoders() {
    _ui->Hardware264DD->clear();
    _ui->Hardware265DD->clear();

    QString dir(QDir::homePath().at(0));
    _winDir = QString("%1:\\Windows").arg(dir);

    if (QFile().exists(QString("%1\\System32\\nvEncodeAPI64.dll").arg(_winDir))) {
        _ui->Hardware264DD->addItem(QString("NVENC"));
        _ui->Hardware265DD->addItem(QString("NVENC"));
    }
    else
        writeLog(QString("Warning: No NVENC drivers found. Removing NVENC support in AVC and HEVC."), false, false, true);

    if (QFile().exists(QString("%1\\System32\\amfrt64.dll").arg(_winDir))) {
        _ui->Hardware264DD->addItem(QString("AMF"));
        _ui->Hardware265DD->addItem(QString("AMF"));
    }
    else {
        writeLog(QString("Warning: No AMF drivers found. Removing AMF support in AVC and HEVC."), false, false, true);

        _ui->Hardware264DD->addItem(QString("QuickSync"));
        _ui->Hardware265DD->addItem(QString("QuickSync"));
    }

    if (_ui->Hardware264DD->count() == 0) {
        SET_DISABLED(_ui->Hardware264CB);
        SET_DISABLED(_ui->Hardware265CB);
        _ui->Hardware264CB->setChecked(false);
        _ui->Hardware265CB->setChecked(false);
    }
    else {
        connect(_ui->Hardware265DD, SIGNAL(currentIndexChanged(int)), this, SLOT(hdwr265d()));
        connect(_ui->Hardware264DD, SIGNAL(currentIndexChanged(int)), this, SLOT(hdwr264d()));
    }
}
#endif

void EncodeGUI::mediaInfo() {
    if (!CHECKED(_ui->GetVidInfoCB)) {
        VideoInfo::clearAll();
        AudioInfo::clearAll();
        SubtitleInfo::clearAll();
        setVideoInfo();
        setAudioInfo();

        disconnect(_ui->AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioTrack()));

        _ui->AudioTrackDD->clear();
        _ui->SelectedAudioDD->clear();
        _ui->SelectInTxtBox->clear();

        _ui->SubtitlesCB->setChecked(false);
        SET_DISABLED(_ui->SubtitlesCB);
        SET_DISABLED(_ui->SubtitlesDD);

        _ui->ChaptersCB->setChecked(false);
        SET_DISABLED(_ui->ChaptersCB);
    }
}

void EncodeGUI::updater() {
    QNetworkRequest req;
    req.setUrl(QUrl(QString("https://encodegui.com/update.txt")));
    req.setHeader(QNetworkRequest::UserAgentHeader, QString("EncodeGUI Updater"));

    QNetworkAccessManager *nam(new QNetworkAccessManager());
    QNetworkReply *reply(nam->get(req));

    connect(reply, SIGNAL(finished()), this, SLOT(updaterFinished()));
}

void EncodeGUI::updaterFinished() {
    if (qobject_cast<QNetworkReply*>(sender())->error() == QNetworkReply::NoError) {
        QString output;

        QStringList lst;
        QTextStream stream(qobject_cast<QNetworkReply*>(sender()));

        bool newUp = false;

        while (!stream.atEnd()) {
            output = stream.readLine();

            if (output.contains(QString("Version=")))
                if (!output.contains(VERSION) && !output.contains(QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).value(QString("update"), VERSION).toString()))
                    newUp = true;
                else {
                    _vers = output.remove(QString("Version="));
                    break;
                }

            if (!output.contains(QString("Version=")))
                lst << output;
            else
                _vers = output.remove(QString("Version="));
        }

        if (newUp) {
            _up = new Update(this);

            _up->setText(lst.join(QString("\n")));
            _up->show();
            _up->activateWindow();

            connect(_up->getSkip(), SIGNAL(clicked(bool)), this, SLOT(skip()));
            connect(_up->getNow(), SIGNAL(clicked(bool)), this, SLOT(goToUpdate()));
            connect(_up->getLater(), SIGNAL(clicked(bool)), this, SLOT(later()));
        }
        else
            writeLog(QString("Checked for updates, either no new updates were found or the user had selected to skip the latest update (latest version: v%1).").arg(_vers), false, false, false);
    }
    else
        writeLog(QString("Error: Unable to check for updates due to a network error: %1").arg(qobject_cast<QNetworkReply*>(sender())->errorString()), false, true, false);

    disconnect(sender(), SIGNAL(finished()), this, SLOT(updaterFinished()));
    delete(sender());
}

void EncodeGUI::dragEnterEvent(QDragEnterEvent *d) {
    const QMimeData *md(d->mimeData());

    if (md->hasUrls())
        d->acceptProposedAction();
}

void EncodeGUI::dropEvent(QDropEvent *d) {
    const QMimeData *md(d->mimeData());

    QList<QUrl> urlList(md->urls());

    if (CHECKED(_ui->SampleVidCB))
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("EncodeGUI is currently not accepting drag and drop input as the sample video input option is enabled."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    else {
        #ifdef Q_OS_WINDOWS
        QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\ffprobe.exe")));
        #endif
        #ifdef Q_OS_DARWIN
        QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe")));
        #endif

        QString input(QDir::toNativeSeparators(urlList.at(0).toLocalFile()));

        getVideoInfo(input, ffprobe);
    }
}

void EncodeGUI::queueScrollBar() {
    if (_ui->JobQueue->rowCount() > 9) {
        _ui->JobQueue->setColumnWidth(3, 95);
        _ui->JobQueue->setColumnWidth(4, 95);
        _ui->JobQueue->setColumnWidth(5, 95);
    }
    else {
        _ui->JobQueue->setColumnWidth(3, 101);
        _ui->JobQueue->setColumnWidth(4, 101);
        _ui->JobQueue->setColumnWidth(5, 101);
    }
}

void EncodeGUI::skip() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("update"), _vers);
    _up->close();
    delete(_up->getUpdate());
    delete(_up);
}

void EncodeGUI::goToUpdate() {
    QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/downloads")));
    _up->close();
    delete(_up->getUpdate());
    delete(_up);
}

void EncodeGUI::later() {
    _up->close();
    delete(_up->getUpdate());
    delete(_up);
}

void EncodeGUI::paletter(QLabel *label) {
    QPalette palette(label->palette());
    palette.setColor(label->foregroundRole(), Qt::darkGreen);
    label->setPalette(palette);
}

void EncodeGUI::setVideoInfo() {
    paletter(_ui->VidformatValueLabel);
    _ui->VidformatValueLabel->setText(VideoInfo::getVideoCodec());

    paletter(_ui->DurationValueLabel);
    _ui->DurationValueLabel->setText(VideoInfo::getDurationStrng());

    paletter(_ui->ResolutionValueLabel);
    _ui->ResolutionValueLabel->setText(VideoInfo::getResolution());

    paletter(_ui->BitrateValueLabel);
    if (!VideoInfo::getBitrate().contains(QString("?")))
        _ui->BitrateValueLabel->setText(VideoInfo::getBitrate() + QString("kb/s"));
    else
        _ui->BitrateValueLabel->setText(VideoInfo::getBitrate());

    paletter(_ui->ColorsValueLabel);
    _ui->ColorsValueLabel->setText(VideoInfo::getColors());

    paletter(_ui->MatrixValueLabel);
    _ui->MatrixValueLabel->setText(VideoInfo::getMatrix());

    paletter(_ui->TransferValueLabel);
    _ui->TransferValueLabel->setText(VideoInfo::getTransfer());

    paletter(_ui->PrimariesValueLabel);
    _ui->PrimariesValueLabel->setText(VideoInfo::getPrimaries());

    paletter(_ui->FPSValueLabel);
    if (!VideoInfo::getFrameRate().contains(QString("?")))
        _ui->FPSValueLabel->setText(VideoInfo::getFrameRate() + QString("fps"));
    else
        _ui->FPSValueLabel->setText(VideoInfo::getFrameRate());
}

void EncodeGUI::batch() {
    _ui->SelectInTxtBox->setText(QString());
    _ui->SaveOutTxtBox->setText(QString());

    if (CHECKED(_ui->BatchCB)) {
        SET_DISABLED(_ui->AudioDD);
        SET_DISABLED(_ui->SubtitlesDD);
        _ui->AudioDD->setCurrentIndex(0);
        _ui->SubtitlesDD->setCurrentIndex(0);
        _ui->SelectInBttn->setText(QString("Select folder"));
        _ui->SampleVidCB->setChecked(false);
        SET_DISABLED(_ui->SampleVidCB);
        _ui->GenerateOutCB->setChecked(false);
        SET_DISABLED(_ui->GenerateOutCB);
    }
    else {
        SET_ENABLED(_ui->SampleVidCB);
        SET_ENABLED(_ui->GenerateOutCB);

        if (CHECKED(_ui->AudioCB))
            SET_ENABLED(_ui->AudioDD);
        
        if (CHECKED(_ui->SubtitlesCB))
            SET_ENABLED(_ui->SubtitlesDD);

        _ui->SelectInBttn->setText(QString("Select input"));
    }
}

void EncodeGUI::inputBttn() {
    QString input;
    
    #ifdef Q_OS_WINDOWS
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\ffprobe.exe")));
    #endif
    #ifdef Q_OS_DARWIN
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe")));
    #endif

    if (!CHECKED(_ui->BatchCB)) {
        if (!CHECKED(_ui->SampleVidCB))
            input = QFileDialog::getOpenFileName(this, QString("Select input"), _ui->SelectInTxtBox->text(), QString("All files (*.*)"));
        else
            input = _ui->SelectInTxtBox->text();

        if (input.isEmpty() && !_ui->SelectInTxtBox->text().isEmpty())
            input = _ui->SelectInTxtBox->text();

        getVideoInfo(QDir::toNativeSeparators(input), ffprobe);
    }
    else {
        input = QFileDialog::getExistingDirectory(this, QString("Select input"), _ui->SelectInTxtBox->text(), QFileDialog::ShowDirsOnly);

        if (input.isEmpty() && !_ui->SelectInTxtBox->text().isEmpty())
            input = _ui->SelectInTxtBox->text();

        getBatchInfo(QDir::toNativeSeparators(input), ffprobe);
    }
}

void EncodeGUI::getBatchInfo(QString input, QString ffprobe) {
    if (Checks::checkFFProbe(ffprobe)) {
        _ui->SelectInTxtBox->setText(input);

        if (!_ui->SelectInTxtBox->text().isEmpty()) {
            disconnect(_ui->AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioTrack()));

            VideoInfoList::clearAll();
            VideoInfo::clearAll();
            AudioInfo::clearAll();
            SubtitleInfo::clearAll();

            VideoInfoRegex::_durationLine.clear();

            _batchFiles->clear();
            _batchIndex = 0;

            _ui->AudioTrackDD->clear();
            _ui->SelectedAudioDD->clear();
            _ui->RpuTxtBox->clear();
            _ui->AudioQueue->setRowCount(0);
            _ui->SubtitleQueue->setRowCount(0);
            removeAudio();
            removeSubtitle();

            SET_DISABLED(_ui->AudioTrackDD);

            QDirIterator dir(input, QDir::Files);

            while (dir.hasNext())
                _batchFiles->append(QDir::toNativeSeparators(dir.next()));

            if (_batchFiles->isEmpty()) {
                msgBoxHelper(MessageType::Error, QString("Input directory error"), QString("The selected source directory does not contain any files."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                _ui->SelectInTxtBox->setText(QString());
                return;
            }
            if (_batchFiles->count() < 2) {
                msgBoxHelper(MessageType::Error, QString("Input directory error"), QString("The selected source directory must have more than 1 video file."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                _ui->SelectInTxtBox->setText(QString());
                return;
            }

            _ffloader->batchInfo(QStringList() << QString("-hide_banner") << QString("-i") << _batchFiles->at(0), ffprobe);
        }
    }
    else {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"ffprobe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::audioSelectClick() {
    QString ffprobe(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\lib\\ffprobe.exe")));
    QString input(QFileDialog::getOpenFileName(this, QString("Select audio input"), _ui->AudioSourceTxtBox->text(), QString("All files (*.*)")));

    if (input.isEmpty() && !_ui->AudioSourceTxtBox->text().isEmpty())
        input = _ui->AudioSourceTxtBox->text();
    else if (!input.isEmpty())
        getAudioInfo(QDir::toNativeSeparators(input), ffprobe);
}

void EncodeGUI::subtitleSelectClick() {
    QString input(QFileDialog::getOpenFileName(this, QString("Select subtitle input"), _ui->SubSourceTxtBox->text(), QString("All files (*.*)")));
    
    #ifdef Q_OS_WINDOWS
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\ffmpeg\\ffprobe.exe")));
    #endif
    #ifdef Q_OS_DARWIN
    QString ffprobe(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/ffprobe")));
    #endif

    if (input.isEmpty() && !_ui->SubSourceTxtBox->text().isEmpty())
        input = _ui->SubSourceTxtBox->text();
    else if (!input.isEmpty())
        getSubtitleInfo(QDir::toNativeSeparators(input), ffprobe);
}

void EncodeGUI::getAudioInfo(QString input, QString ffprobe) {
    if (Checks::checkFFProbe(ffprobe)) {
        _ui->AudioSourceTxtBox->setText(input);

        if (!_ui->AudioSourceTxtBox->text().isEmpty()) {
            disconnect(_ui->AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioTrack()));

            AudioInfo::clearAll();
            _ui->AudioTrackDD->clear();
            _ui->SelectedAudioDD->clear();

            _ffloader->audioInfo(QStringList() << QString("-hide_banner") << QString("-i") << input, ffprobe);
        }
    }
    else {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"ffprobe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::getSubtitleInfo(QString input, QString ffprobe) {
    if (Checks::checkFFProbe(ffprobe)) {
        _ui->SubSourceTxtBox->setText(input);

        if (!_ui->SubSourceTxtBox->text().isEmpty()) {
            SubtitleInfo::clearAll();
            _ui->SelectedSubtitleDD->clear();

            _ffloader->subtitleInfo(QStringList() << QString("-hide_banner") << QString("-i") << input, ffprobe);
        }
    }
    else {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"ffprobe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::getVideoInfo(QString input, QString ffprobe) {
    if (Checks::checkFFProbe(ffprobe)) {
        _ui->SelectInTxtBox->setText(input);

        if (!_ui->SelectInTxtBox->text().isEmpty()) {
            disconnect(_ui->AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioTrack()));

            VideoInfo::clearAll();
            AudioInfo::clearAll();
            SubtitleInfo::clearAll();

            VideoInfoRegex::_durationLine.clear();

            _ui->AudioTrackDD->clear();
            _ui->SelectedAudioDD->clear();
            _ui->RpuTxtBox->clear();
            _ui->AudioQueue->setRowCount(0);
            _ui->SubtitleQueue->setRowCount(0);

            _streamInputs->clear();
            removeAudio();
            removeSubtitle();

            _ffloader->videoInfo(QStringList() << QString("-hide_banner") << QString("-i") << input, ffprobe);

            if (CHECKED(_ui->GenerateOutCB)) {
                QFileInfo fi(_ui->SelectInTxtBox->text().left(_ui->SelectInTxtBox->text().lastIndexOf(QString("."))));
                QString fn(fi.fileName());

                _ui->SaveOutTxtBox->setText(_ui->SelectInTxtBox->text().left(_ui->SelectInTxtBox->text().lastIndexOf(QString("."))).replace(fn, QString("%1-egui").arg(fn)));
            }
        }
    }
    else {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"ffprobe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::openPreview() {
    _preview->show();
    _preview->activateWindow();
}

void EncodeGUI::hdrMeta() {
    QString input(QFileDialog::getOpenFileName(this, QString("Select dynamic metadata file"), QDir::toNativeSeparators(QApplication::applicationDirPath()), QString("DHDR10 file (*.json)")));

    if (!input.isEmpty())
        _ui->DynamicHDRTxtBox->setText(QDir::toNativeSeparators(input));
}

void EncodeGUI::rpu() {
    #ifdef Q_OS_WINDOWS
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\lib\\dovi_tool.exe"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"dovi_tool.exe\" is missing in EncodeGUI installation. A clean reinstall should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        return;
    }
    #endif
    #ifdef Q_OS_DARWIN
    if (!QFile(QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("/lib/dovi_tool"))).exists()) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"dovi_tool\" is missing in EncodeGUI installation. A clean reinstall should fix this."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        return;
    }
    #endif

    ProcessError::clearRPU();

    QFile source(_ui->SelectInTxtBox->text());
    QFileInfo info(source.fileName());

    if (!_ui->SelectInTxtBox->text().isEmpty()) {
        #ifdef Q_OS_WINDOWS
        _ffloader->extractRPU(QStringList() << QString("-hide_banner") << QString("-i") << _ui->SelectInTxtBox->text() << QString("-bsf:v") << QString("hevc_mp4toannexb") << QString("-c:v") << QString("copy") << QString("-f") << QString("hevc") << QString("-"), QStringList() << QString("extract-rpu") << QString("-") << QString("-o") << QString("%1\\rpu_%2.bin").arg(TEMPPATH_WIN).arg(info.fileName()), QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\lib\\dovi_tool.exe")), FFMPEGPATH_WIN);
        #endif
        #ifdef Q_OS_DARWIN
        _ffloader->extractRPU(QStringList() << QString("-hide_banner") << QString("-i") << _ui->SelectInTxtBox->text() << QString("-bsf:v") << QString("hevc_mp4toannexb") << QString("-c:v") << QString("copy") << QString("-f") << QString("hevc") << QString("-"), QStringList() << QString("extract-rpu") << QString("-") << QString("-o") << QString("%1/rpu_%2.bin").arg(TEMPPATH_DAR).arg(info.fileName()), QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/lib/dovi_tool")), FFMPEGPATH_DAR);
        #endif
    }
    else {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("A source file must be specified to use this feature."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        return;
    }

    SET_DISABLED(_ui->RpuFileBttn);
}

void EncodeGUI::extractRPUFinished() {
    SET_ENABLED(_ui->RpuFileBttn);

    QFile source(_ui->SelectInTxtBox->text());
    QFileInfo info(source.fileName());

    if (!ProcessError::getDolbyError()) {
        msgBoxHelper(MessageType::Info, QString("Extract complete"), QString("RPU file extracted successfully."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        #ifdef Q_OS_WINDOWS
        _ui->RpuTxtBox->setText(QString("%1\\rpu_%2.bin").arg(TEMPPATH_WIN).arg(info.fileName()));
        #endif
        #ifdef Q_OS_DARWIN
        _ui->RpuTxtBox->setText(QString("%1/rpu_%2.bin").arg(TEMPPATH_DAR).arg(info.fileName()));
        #endif
    }
    else
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The source video does not have supported Dolby Vision metadata."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

    #ifdef Q_OS_WINDOWS
    if (!ProcessError::getDolbyError() && !QFile(QString("%1\\rpu_%2.bin").arg(TEMPPATH_WIN).arg(info.fileName())).exists())
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Unknown error occured while extracting RPU file."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    #endif
    #ifdef Q_OS_DARWIN
    if (!ProcessError::getDolbyError() && !QFile(QString("%1/rpu_%2.bin").arg(TEMPPATH_DAR).arg(info.fileName())).exists())
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Unknown error occured while extracting RPU file."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    #endif
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::gpu1() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("gpu1"), _ui->GPU1IDNUD->value());
}

void EncodeGUI::gpu2() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("gpu2"), _ui->GPU2IDNUD->value());
}
#endif

void EncodeGUI::errorMsg() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("errormsg"), CHECKED(_ui->ErrorMessageCB));
}

void EncodeGUI::enablePreview() {
    if (CHECKED(_ui->EnablePreviewCB))
        SET_ENABLED(_ui->PreviewBttn);
    else
        SET_DISABLED(_ui->PreviewBttn);

    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("preview"), CHECKED(_ui->EnablePreviewCB));
}

void EncodeGUI::nextJob() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("nextjob"), CHECKED(_ui->NotificationCB));
}

void EncodeGUI::updateOpt() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("updateopt"), CHECKED(_ui->UpdateOptCB));
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::dualGPU() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("dgpu"), CHECKED(_ui->MultiGPUGB));
}
#endif

void EncodeGUI::delSource() {
    if (CHECKED(_ui->AutoDelSourceCB)) {
        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Warning, QString("Warning"), QString("This option is destructive as it deletes the source video after a successful encode. It will stay enabled until you disable it, even if you close and reopen EncodeGUI. Would you still like to enable this option anyway?\n\nRemember: the EncodeGUI developers are never held reponsible for the loss of information due to distructive behaviors in EncodeGUI."),
            QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

        if (msg == QMessageBox::No)
            _ui->AutoDelSourceCB->setChecked(false);
    }

    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("delsource"), CHECKED(_ui->AutoDelSourceCB));
}

void EncodeGUI::donateDaGoose() {
    QDesktopServices::openUrl(QUrl(QString("https://www.paypal.com/donate/?hosted_button_id=CLBETTY9GBM28")));
}

void EncodeGUI::donateGlitch() {
    QDesktopServices::openUrl(QUrl(QString("https://www.paypal.com/donate/?hosted_button_id=4KSB88LADE3WU")));
}

void EncodeGUI::youClick() {
    QDesktopServices::openUrl(QUrl(QString("https://youtube.com/c/DaGoose")));
}

void EncodeGUI::disClick() {
    QDesktopServices::openUrl(QUrl(QString("https://discord.gg/PmcbXJVBNu")));
}

void EncodeGUI::igClick() {
    QDesktopServices::openUrl(QUrl(QString("https://www.instagram.com/dagooseyt/")));
}

void EncodeGUI::genOutput() {
    if (CHECKED(_ui->GenerateOutCB) && CHECKED(_ui->SampleVidCB)) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("You cannot automatically generate the output file name while the sample video is being used."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        disconnect(_ui->GenerateOutCB, SIGNAL(stateChanged(int)), this, SLOT(genOutput()));
        _ui->GenerateOutCB->setChecked(false);
        connect(_ui->GenerateOutCB, SIGNAL(stateChanged(int)), this, SLOT(genOutput()));
        return;
    }

    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("genout"), CHECKED(_ui->GenerateOutCB));

    if (CHECKED(_ui->GenerateOutCB)) {
        SET_DISABLED(_ui->SaveOutBttn);
        _ui->SaveOutTxtBox->setText(QString());

        if (!_ui->SelectInTxtBox->text().isEmpty()) {
            QFileInfo fi(_ui->SelectInTxtBox->text().left(_ui->SelectInTxtBox->text().lastIndexOf(QString("."))));
            QString fn(fi.fileName());

            _ui->SaveOutTxtBox->setText(_ui->SelectInTxtBox->text().left(_ui->SelectInTxtBox->text().lastIndexOf(QString("."))).replace(fn, QString("%1-egui").arg(fn)));
        }
    }
    else {
        SET_ENABLED(_ui->SaveOutBttn);
        _ui->SaveOutTxtBox->setText(QString());
    }
}

void EncodeGUI::extracterInfo() {
    QString progress;

    if (VideoInfoList::getJobDuration(_ffloader->_currentJob).isValid()) {
        #ifdef Q_OS_WINDOWS
        if (_tbProgress) {
            if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Paused")))
                _tbProgress->SetProgressState((HWND)this->winId(), TBPF_NORMAL);

            _tbProgress->SetProgressValue((HWND)this->winId(), (ULONGLONG)ProgressInfo::getPercentage(), 100ULL);
        }
        #endif

        _ui->progressBar->setValue((int)ProgressInfo::getPercentage());
    }

    progress.append(QString("Extracting"));
    
    if (CHECKED(_ui->PercentageCB) && VideoInfoList::getJobDuration(_ffloader->_currentJob).isValid())
        progress.append(QString(" - %1%").arg(ProgressInfo::getPercentage()));

    _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("%1%").arg(ProgressInfo::getPercentage()));
    _ui->ProgressBarLabel->setText(progress);
}

void EncodeGUI::regexFinished() {
    if (VideoInfo::getVideoCodec().contains(QString("?"))) {
        msgBoxHelper(MessageType::Error, QString("Import file error"), QString("The selected input file is not a video. Only choose video files as the input.\n"), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _ui->SelectInTxtBox->setText(QString());
        return;
    }
    else if (VideoInfo::getDurationStrng().contains(QString("?")) && !VideoInfo::getVideoCodec().contains(QString("?"))) {
        writeLog(QString("Warning: the source file (%1) duration could not be found. Some encoding progress info will be unavailable for the associated job.").arg(_ui->SelectInTxtBox->text()), false, false, true);
        msgBoxHelper(MessageType::Warning, QString("Input Error"), QString("EncodeGUI was unable to find the duration of the selected file. As a result, encoding progress info for this source will be limited."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }

    #ifdef Q_OS_WINDOWS
    toolInterp();
    #endif

    if (!CHECKED(_ui->InterpolationCB)) {
        _ui->InterpolationCB->setChecked(true);
        _ui->InterpolationCB->setChecked(false);
    }

    if (AudioInfo::totalStreams() != 0) {
        SET_ENABLED(_ui->AudioCB);
        _ui->AudioCB->setChecked(true);
    }
    if (SubtitleInfo::totalStreams() != 0) {
        SET_ENABLED(_ui->SubtitlesCB);
        _ui->SubtitlesCB->setChecked(true);
    }
    if (!SubtitleInfo::getChapter()) {
        SET_DISABLED(_ui->ChaptersCB);
        SET_DISABLED(_ui->ChaptersLabel);
        _ui->ChaptersCB->setChecked(false);
    }
    else {
        SET_ENABLED(_ui->ChaptersCB);
        SET_ENABLED(_ui->ChaptersLabel);
        _ui->ChaptersCB->setChecked(true);
    }

    disconnect(_ui->Height2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth2x()));
    disconnect(_ui->Width2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight2x()));
    disconnect(_ui->WidthNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth()));
    disconnect(_ui->HeightNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight()));

    modelUpscale();

    _ui->Width2xNUD->setMinimum(VideoInfo::getWidth());
    _ui->Height2xNUD->setMinimum(VideoInfo::getHeight());
    _ui->WidthNUD->setValue(VideoInfo::getWidth());
    _ui->HeightNUD->setValue(VideoInfo::getHeight());
    _ui->EksNUD->setMaximum(VideoInfo::getWidth());
    _ui->WhyNUD->setMaximum(VideoInfo::getHeight());
    _ui->OutHeightNUD->setMaximum(VideoInfo::getHeight());
    _ui->OutWidthNUD->setMaximum(VideoInfo::getWidth());

    connect(_ui->Height2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth2x()));
    connect(_ui->Width2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight2x()));
    connect(_ui->WidthNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth()));
    connect(_ui->HeightNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight()));

    if (_ui->Height2xNUD->value() > 4352) {
        _ui->Height2xNUD->setValue(4352);
        _ui->Height2xNUD->setMaximum(4352);
        _ui->HeightNUD->setValue(4352);
        _ui->HeightNUD->setMaximum(4352);
    }
    if (_ui->Width2xNUD->value() > 8192) {
        _ui->Width2xNUD->setValue(8192);
        _ui->Width2xNUD->setMaximum(8192);
        _ui->WidthNUD->setValue(8192);
        _ui->WidthNUD->setMaximum(8192);
    }

    setAudioInfo();
    setSubtitleInfo();

    if (AudioInfo::totalStreams() > 0)
        _ui->AudioSourceTxtBox->setText(_ui->SelectInTxtBox->text());
    if (SubtitleInfo::totalStreams() > 0)
        _ui->SubSourceTxtBox->setText(_ui->SelectInTxtBox->text());

    if (CHECKED(_ui->GetVidInfoCB)) {
        setVideoInfo();
        connect(_ui->AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioTrack()));
    }
}

void EncodeGUI::batchFinished() {
    if (VideoInfoList::totalCodec() != _batchIndex + 1) {
        msgBoxHelper(MessageType::Error, QString("Import file error"), QString("The input file (%1) is not a video. Skipping...\n").arg(_batchFiles->at(_batchIndex)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _batchFiles->removeAt(_batchIndex);

        if (_batchIndex < _batchFiles->count()) {
            VideoInfoRegex::_durationLine.clear();

            #ifdef Q_OS_WINDOWS
            _ffloader->batchInfo(QStringList() << QString("-hide_banner") << QString("-i") << _batchFiles->at(_batchIndex), QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\lib\\ffprobe.exe")));
            #endif
            #ifdef Q_OS_DARWIN
            _ffloader->batchInfo(QStringList() << QString("-hide_banner") << QString("-i") << _batchFiles->at(_batchIndex), QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/lib/ffprobe")));
            #endif
        }

        return;
    }

    if (VideoInfoList::getCodec(_batchIndex).contains(QString("?"))) {
        msgBoxHelper(MessageType::Error, QString("Import file error"), QString("The input file (%1) is not a video. Skipping...\n").arg(_batchFiles->at(_batchIndex)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

        _batchFiles->removeAt(_batchIndex);
        VideoInfoList::removeCodec(_batchIndex);
        VideoInfoList::removeMatrix(_batchIndex);
        VideoInfoList::removeTransfer(_batchIndex);
        VideoInfoList::removePrimaries(_batchIndex);
        VideoInfoList::removeDuration(_batchIndex);
        VideoInfoList::removeFrameRate(_batchIndex);
        VideoInfoList::removeHeight(_batchIndex);
        VideoInfoList::removeWidth(_batchIndex);

        _ui->SelectInTxtBox->setText(QString());
        return;
    }
    else if (VideoInfoList::getDuration(_batchIndex).toString().contains(QString("?")) && !VideoInfoList::getCodec(_batchIndex).contains(QString("?"))) {
        writeLog(QString("Warning: the source file (%1) duration could not be found. Some encoding progress info will be unavailable for the associated job.").arg(_batchFiles->at(_batchIndex)), false, false, true);
        msgBoxHelper(MessageType::Warning, QString("Input error"), QString("EncodeGUI was unable to find the duration for the input (%1). As a result, some encoding progress info will be unavailable for the associated job.").arg(_batchFiles->at(_batchIndex)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }

    #ifdef Q_OS_WINDOWS
    toolInterp();
    #endif

    if (!CHECKED(_ui->InterpolationCB)) {
        _ui->InterpolationCB->setChecked(true);
        _ui->InterpolationCB->setChecked(false);
    }

    _ui->ChaptersCB->setChecked(true);

    if (_batchIndex > 0) {
        disconnect(_ui->Height2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth2x()));
        disconnect(_ui->Width2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight2x()));
        disconnect(_ui->WidthNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth()));
        disconnect(_ui->HeightNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight()));

        modelUpscale();

        if (VideoInfoList::getWidth(_batchIndex) > VideoInfoList::getHeight(_batchIndex)) {
            if (VideoInfoList::getWidth(_batchIndex) > VideoInfoList::getWidth(_batchIndex - 1)) {
                _ui->Width2xNUD->setMinimum(VideoInfoList::getWidth(_batchIndex - 1));
                _ui->Height2xNUD->setMinimum(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->WidthNUD->setValue(VideoInfoList::getWidth(_batchIndex - 1));
                _ui->HeightNUD->setValue(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->EksNUD->setMaximum(VideoInfoList::getWidth(_batchIndex - 1));
                _ui->WhyNUD->setMaximum(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->OutHeightNUD->setMaximum(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->OutWidthNUD->setMaximum(VideoInfoList::getWidth(_batchIndex - 1));
            }
        }
        else if (VideoInfoList::getWidth(_batchIndex) < VideoInfoList::getHeight(_batchIndex)) {
            if (VideoInfoList::getHeight(_batchIndex) > VideoInfoList::getHeight(_batchIndex - 1)) {
                _ui->Width2xNUD->setMinimum(VideoInfoList::getWidth(_batchIndex - 1));
                _ui->Height2xNUD->setMinimum(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->WidthNUD->setValue(VideoInfoList::getWidth(_batchIndex - 1));
                _ui->HeightNUD->setValue(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->EksNUD->setMaximum(VideoInfoList::getWidth(_batchIndex - 1));
                _ui->WhyNUD->setMaximum(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->OutHeightNUD->setMaximum(VideoInfoList::getHeight(_batchIndex - 1));
                _ui->OutWidthNUD->setMaximum(VideoInfoList::getWidth(_batchIndex - 1));
            }
        }

        connect(_ui->Height2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth2x()));
        connect(_ui->Width2xNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight2x()));
        connect(_ui->WidthNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjWidth()));
        connect(_ui->HeightNUD, SIGNAL(valueChanged(int)), this, SLOT(autoAdjHeight()));
    }

    _batchIndex++;

    if (_batchIndex < _batchFiles->count()) {
        VideoInfoRegex::_durationLine.clear();

        #ifdef Q_OS_WINDOWS
        _ffloader->batchInfo(QStringList() << QString("-hide_banner") << QString("-i") << _batchFiles->at(_batchIndex), QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\lib\\ffprobe.exe")));
        #endif
        #ifdef Q_OS_DARWIN
        _ffloader->batchInfo(QStringList() << QString("-hide_banner") << QString("-i") << _batchFiles->at(_batchIndex), QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/lib/ffprobe")));
        #endif
    }

    if (_batchIndex == _batchFiles->count() && _batchFiles->count() < 2) {
        msgBoxHelper(MessageType::Error, QString("Input error"), QString("The selected source directory must have more than 1 video file."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _ui->SelectInTxtBox->setText(QString());
        return;
    }

    if (CHECKED(_ui->GetVidInfoCB) && _batchIndex == _batchFiles->count()) {
        paletter(_ui->VidformatValueLabel);
        _ui->VidformatValueLabel->setText("<batch>");

        paletter(_ui->DurationValueLabel);
        _ui->DurationValueLabel->setText("<batch>");

        paletter(_ui->ResolutionValueLabel);
        _ui->ResolutionValueLabel->setText("<batch>");

        paletter(_ui->BitrateValueLabel);
        _ui->BitrateValueLabel->setText("<batch>");

        paletter(_ui->ColorsValueLabel);
        _ui->ColorsValueLabel->setText("<batch>");

        paletter(_ui->MatrixValueLabel);
        _ui->MatrixValueLabel->setText("<batch>");

        paletter(_ui->TransferValueLabel);
        _ui->TransferValueLabel->setText("<batch>");

        paletter(_ui->PrimariesValueLabel);
        _ui->PrimariesValueLabel->setText("<batch>");

        paletter(_ui->FPSValueLabel);
        _ui->FPSValueLabel->setText("<batch>");

        paletter(_ui->FormatValueLabel);
        _ui->FormatValueLabel->setText("<batch>");

        paletter(_ui->AudioLanguageValueLabel);
        _ui->AudioLanguageValueLabel->setText("<batch>");

        paletter(_ui->SampleRateValueLabel);
        _ui->SampleRateValueLabel->setText("<batch>");

        paletter(_ui->ChannelsValueLabel);
        _ui->ChannelsValueLabel->setText("<batch>");
    }
}

void EncodeGUI::modelUpscale() {
    if (_ui->ToolUpscaleDD->currentIndex() == 0 && _ui->ModelUpscaleDD->currentIndex() != 3) {
        _ui->Width2xNUD->setMaximum(VideoInfo::getWidth() * 2);
        _ui->Height2xNUD->setMaximum(VideoInfo::getHeight() * 2);
        _ui->Width2xNUD->setValue(VideoInfo::getWidth() * 2);
        _ui->Height2xNUD->setValue(VideoInfo::getHeight() * 2);
    }
    else if (_ui->ToolUpscaleDD->currentIndex() == 1) {
        _ui->Width2xNUD->setMaximum(VideoInfo::getWidth() * 4);
        _ui->Height2xNUD->setMaximum(VideoInfo::getHeight() * 4);
        _ui->Width2xNUD->setValue(VideoInfo::getWidth() * 4);
        _ui->Height2xNUD->setValue(VideoInfo::getHeight() * 4);
    }

    if (_ui->Height2xNUD->value() > 4352) {
        _ui->Height2xNUD->setValue(4352);
        _ui->Height2xNUD->setMaximum(4352);
        _ui->HeightNUD->setValue(4352);
        _ui->HeightNUD->setMaximum(4352);
    }
    if (_ui->Width2xNUD->value() > 8192) {
        _ui->Width2xNUD->setValue(8192);
        _ui->Width2xNUD->setMaximum(8192);
        _ui->WidthNUD->setValue(8192);
        _ui->WidthNUD->setMaximum(8192);
    }
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::getProcessor() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    _ui->LimitThreadsNUD->setMaximum(sysInfo.dwNumberOfProcessors);
    _ui->LimitThreadsNUD->setValue(sysInfo.dwNumberOfProcessors);
}
#endif

void EncodeGUI::cancelAllClick() {
    if (_ui->JobQueue->rowCount() == 0)
        return;

    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Cancel confirmation"), QString("Are you sure you want to cancel ALL jobs? All curent progress will be lost."), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::Yes) {
        FOR_EACH(_ui->JobQueue->rowCount())
            if (!_ui->JobQueue->item(i, 1)->text().contains(QString("Paused")) && !_ui->JobQueue->item(i, 1)->text().contains(QString("Active"))) {
                _ui->JobQueue->item(i, 1)->setText(QString("Canceled"));
                _state->replace(i, QString("Canceled"));
            }
            else if (_ui->JobQueue->item(i, 1)->text().contains(QString("Paused"))) {
                msgBoxHelper(MessageType::Warning, QString("EncodeGUI warning"), QString("The currently paused process could not be canceled. Please resume it first then cancel it."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
                writeLog(QString("All jobs in the queue have been canceled except the currenly paused job. Resume it to cancel it."), false, false, false);
            }

        if (_ffloader->_encode && _ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Active")))
            if (_ffloader->_encode->state() == QProcess::Running) {
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Canceled"));
                _state->replace(_ffloader->_currentJob, QString("Canceled"));

                _ffloader->closeProcess(_ffloader->_encode);

                if (_ffloader->_vs)
                    _ffloader->closeProcess(_ffloader->_vs);
            }

        if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Paused"))) {
            _ui->ProgressBarLabel->setText(QString());
            _ui->progressBar->setValue(0);

            writeLog(QString("All jobs in the queue have been canceled."), false, false, false);
        }

        setState();
    }
}

void EncodeGUI::closeEvent(QCloseEvent *event) {
    if (_ffloader->_encode && _ffloader->_encode->state() == QProcess::Running) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Please cancel the current running process before closing EncodeGUI"), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        event->ignore();
    }
    else if (_ffloader->_encode) {
        if (_ffloader->_encode->state() == QProcess::NotRunning)
            event->accept();
    }
    else
        event->accept();
}

void EncodeGUI::resetJob() {
    _ui->JobQueue->item(_selectedJob, 1)->setText(QString("Waiting"));
    _state->replace(_selectedJob, QString("Waiting"));

    if (_arguments.at(_selectedJob).toStringList().join(QString(" ")).contains(QString("pass 2")) || _arguments.at(_selectedJob).toStringList().join(QString(" ")).contains(QString("pass=2"))) {
        QStringList newArgs(_arguments.at(_selectedJob).toStringList());

        if (newArgs.join(QString(" ")).contains(QString("pass 2")))
            newArgs.replace(newArgs.indexOf(QString("-pass")) + 1, QString("1"));
        if (newArgs.join(QString(" ")).contains(QString("pass=2"))) {
            #ifdef Q_OS_WINDOWS
            newArgs.replace(newArgs.indexOf(QString("pass=2:stats='%1\\x265.log'").arg(TEMPPATH_WIN)), QString("pass=1:stats='%1\\x265.log'").arg(TEMPPATH_WIN));
            #endif
            #ifdef Q_OS_DARWIN
            newArgs.replace(newArgs.indexOf(QString("pass=2:stats='%1\\x265.log'").arg(TEMPPATH_DAR)), QString("pass=1:stats='%1\\x265.log'").arg(TEMPPATH_DAR));
            #endif
        }

        newArgs.removeLast();
        newArgs << QString("-f") << QString("NULL") << QString("nul");

        _arguments.removeAt(_selectedJob);
        _arguments.insert(_selectedJob, newArgs);
    }

    writeLog(QString("Job %1 has been reset.").arg(_job->at(_selectedJob)), false, false, false);
    setState();

    delete(sender());
}

void EncodeGUI::removeJob() {
    if (_selectedJob == _ffloader->_currentJob || _ui->JobQueue->item(_selectedJob, 1)->text().contains(QString("Paused"))) {
        if (_ffloader->_encode && _ffloader->_encode->state() == QProcess::Running) {
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Please cancel the current job before removing it from the queue."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            return;
        }
    }

    _arguments.removeAt(_selectedJob);

    #ifdef Q_OS_WINDOWS
    _vapourScript.removeAt(_selectedJob);
    #endif

    _tempList->removeAt(_selectedJob);
    _audioArgs.removeAt(_selectedJob);
    _outputList->removeAt(_selectedJob);
    _inputList->removeAt(_selectedJob);
    _state->removeAt(_selectedJob);

    delete(_inputBttn->at(_selectedJob));
    delete(_outputBttn->at(_selectedJob));
    delete(_logsBttn->at(_selectedJob));
    _inputBttn->removeAt(_selectedJob);
    _outputBttn->removeAt(_selectedJob);
    _logsBttn->removeAt(_selectedJob);

    VideoInfoList::removeJobDuration(_selectedJob);
    VideoInfoList::removeJobFrameRate(_selectedJob);

    _ui->JobQueue->removeRow(_selectedJob);

    if (_ffloader->_currentJob != 0)
        FOR_EACH(_ui->JobQueue->rowCount())
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Active")) || _ui->JobQueue->item(i, 1)->text().contains(QString("Paused")))
                _ffloader->_currentJob = i;

    #ifdef Q_OS_WINDOWS
    QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(_selectedJob))).removeRecursively();
    #endif
    #ifdef Q_OS_DARWIN
    QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(_selectedJob))).removeRecursively();
    #endif

    _job->removeAt(_selectedJob);

    queueScrollBar();
    reIndexBttns();
    saveSettings();
    setJobSetting();

    delete(sender());
}

void EncodeGUI::clearFinished() {
    FOR_EACH(_arguments.count())
        if (_ui->JobQueue->item(i, 1)->text().contains(QString("Finished"))) {
            _ui->JobQueue->removeRow(i);

            _arguments.removeAt(i);

            #ifdef Q_OS_WINDOWS
            _vapourScript.removeAt(i);
            #endif

            _tempList->removeAt(i);
            _audioArgs.removeAt(i);
            _outputList->removeAt(i);
            _inputList->removeAt(i);
            _state->removeAt(i);

            delete(_inputBttn->at(i));
            delete(_outputBttn->at(i));
            delete(_logsBttn->at(i));
            _inputBttn->removeAt(i);
            _outputBttn->removeAt(i);
            _logsBttn->removeAt(i);

            #ifdef Q_OS_WINDOWS
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif
            #ifdef Q_OS_DARWIN
            QDir(QDir::toNativeSeparators(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1"))).arg(_job->at(i))).removeRecursively();
            #endif

            _job->removeAt(i);

            VideoInfoList::removeJobDuration(i);
            VideoInfoList::removeJobFrameRate(i);

            i--;
        }

    if (_ffloader->_currentJob != 0)
        FOR_EACH(_arguments.count())
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Active")) || _ui->JobQueue->item(i, 1)->text().contains(QString("Paused")))
                _ffloader->_currentJob = i;

    queueScrollBar();
    reIndexBttns();
    saveSettings();
    setJobSetting();
}

void EncodeGUI::cancelMain() {
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Cancel confirmation"), QString("Are you sure you want to cancel the currently running job? All current progress will be lost."), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::Yes) {
        if (_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Active"))) {
            _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Canceled"));
            _state->replace(_ffloader->_currentJob, QString("Canceled"));

            writeLog(QString("Job %1 canceled by user").arg(_job->at(_ffloader->_currentJob)), false, false, false);

            _ffloader->closeProcess(_ffloader->_encode);

            if (_ffloader->_vs)
                _ffloader->closeProcess(_ffloader->_vs);

            setState();
        }
        else
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("A job must be running to cancel it"), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void EncodeGUI::setState() {
    _sState.clear();

    foreach(QString sta, *_state)
        _sState.append(sta);

    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("state"), _sState);
}

void EncodeGUI::cancelClick() {
    QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Question, QString("Cancel confirmation"), QString("Are you sure you want to cancel the selected job? All progress will be lost."), QMessageBox::Yes, QMessageBox::No, QMessageBox::NoButton));

    if (msg == QMessageBox::Yes) {
        if (_ui->JobQueue->item(_selectedJob, 1)->text().contains(QString("Active"))) {
            _ui->JobQueue->item(_selectedJob, 1)->setText(QString("Canceled"));
            writeLog(QString("Job %1 canceled by user").arg(_job->at(_selectedJob)), false, false, false);

            if (_selectedJob == _ffloader->_currentJob) {
                if (_ffloader->_vs)
                    _ffloader->closeProcess(_ffloader->_vs);
                
                _ffloader->closeProcess(_ffloader->_encode);
            }

            _state->replace(_selectedJob, QString("Canceled"));
            setState();
        }
        else
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("A job must be running to cancel it."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
}

void EncodeGUI::pauseClick() {
    if (_ui->PauseBttn->text().contains(QString("Pause"))) {
        _ui->PauseBttn->setText(QString("Resume"));
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Paused"));
        _ui->JobStatusValueLabel->setText(QString("Paused"));

        #ifdef Q_OS_WINDOWS
        if (_tbProgress)
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_PAUSED);
        #endif  

        _ffloader->pauseProcess(_ffloader->_encode, true);
        *_ffloader->_pauseTime = ProgressInfo::getTimeElapsed();
    }
    else {
        _ui->PauseBttn->setText(QString("Pause"));
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Active"));
        _ui->JobStatusValueLabel->setText(QString("Active"));

        #ifdef Q_OS_WINDOWS
        if (_tbProgress)
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_NORMAL);
        #endif

        _ffloader->pauseProcess(_ffloader->_encode, false);
        _ffloader->_timer->restart();
    }
}

void EncodeGUI::newExtract() {
    FOR_EACH(_arguments.count())
        if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting"))) {
            _ffloader->_currentJob = i;

            #ifdef Q_OS_WINDOWS
            if (S_OK == CoCreateInstance(CLSID_TaskbarList, 0, CLSCTX_INPROC_SERVER, IID_ITaskbarList3, (void**)&_tbProgress)) {
                _tbProgress->HrInit();
                _tbProgress->SetProgressState((HWND)this->winId(), TBPF_NORMAL);
            }

            QDir().mkpath(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\Preview")));
            _ffloader->encode(QStringList() << QString("-i") << _inputList->at(i) << QString("-vf") << QString("fps=1") << QString("-q:v") << QString("27") << LOGPATH_WIN + QString("\\Preview\\%d.jpg"), QStringList(), FFMPEGPATH_WIN, QString(), true);
            #endif

            _ui->JobQueue->item(i, 1)->setText(QString("Active"));

            #ifdef Q_OS_DARWIN
            QDir().mkpath(QDir::toNativeSeparators(LOGPATH_DAR + QString("/Preview")));
            _ffloader->encode(QStringList() << QString("-i") << _inputList->at(i) << QString("-vf") << QString("fps=1") << QString("-q:v") << QString("27") << LOGPATH_DAR + QString("/Preview/%d.jpg"), QStringList(), FFMPEGPATH_DAR, QString(), true);
            #endif

            if (CHECKED(_ui->AutoDelSourceCB))
                writeLog(QString("WARNING: Auto delete source is enabled in preferences. Disable it before the encoding process ends if you do not want the source video to be deleted."), false, false, true);

            paletter(_ui->JobStartValueLabel);
            _ui->JobStartValueLabel->setText(QDateTime::currentDateTime().toString());

            paletter(_ui->JobStatusValueLabel);
            _ui->JobStatusValueLabel->setText(QString("Active"));

            paletter(_ui->JobIDValueLabel);
            _ui->JobIDValueLabel->setText(_ui->JobQueue->item(i, 0)->text());

            break;
        }
}

void EncodeGUI::extracterComplete() {
    _ui->progressBar->setMaximum(100);
    _ui->ProgressBarLabel->setText(QString());
    _ui->progressBar->setValue(0);

    if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Canceled")))
        newTask();
    else
        newJob();
}

void EncodeGUI::start() {
    int jobs = _ui->JobQueue->rowCount();
    int count = 0;

    _encodingAudio = false;

    if (jobs > 0) {
        writeLog(QString("Attempting to start the job queue..."), false, false, false);

        FOR_EACH(jobs)
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting"))) {
                if (CHECKED(_ui->EnablePreviewCB) && !_arguments.at(i).toStringList().join(QString(" ")).contains(QString("-c:v copy"))) {
                    newExtract();
                    writeLog(QString("Extracting frames for job %1").arg(_job->at(i)), false, false, false);
                }
                else if (_arguments.at(i).toStringList().join(QString(" ")).contains(QString("-c:v copy")) || !CHECKED(_ui->EnablePreviewCB)) {
                    _ffloader->_currentJob = i;

                    _ui->JobQueue->item(i, 1)->setText(QString("Active"));

                    if (CHECKED(_ui->AutoDelSourceCB))
                        writeLog(QString("WARNING: Auto delete source is enabled in preferences. Disable it before the encoding process ends if you do not want the source video to be deleted."), false, false, true);

                    paletter(_ui->JobStartValueLabel);
                    _ui->JobStartValueLabel->setText(QDateTime::currentDateTime().toString());

                    paletter(_ui->JobStatusValueLabel);
                    _ui->JobStatusValueLabel->setText(QString("Active"));

                    paletter(_ui->JobIDValueLabel);
                    _ui->JobIDValueLabel->setText(_ui->JobQueue->item(i, 0)->text());

                    extracterComplete();
                }

                SET_ENABLED(_ui->PauseBttn);
                SET_ENABLED(_ui->CancelBttn);
                SET_DISABLED(_ui->StartBttn);
                
                count++;
                return;
            }
    }

    if (count == 0 || jobs == 0)
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("There are no waiting jobs in the queue."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::vkFinished() {
    QString list;

    _ui->TestGPUBttn->setText(QString("Identify GPU Device IDs"));
    SET_ENABLED(_ui->TestGPUBttn);

    #ifdef Q_OS_WINDOWS
    QFile(QString("%1\\dummy.lwi").arg(TEMPPATH_WIN)).remove();
    #endif
    #ifdef Q_OS_DARWIN
    QFile(QString("%1/dummy.lwi").arg(TEMPPATH_DAR)).remove();
    #endif

    if (VideoInfoList::totalVk() == 0) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Unable to check GPU device IDs. Ensure that at least one GPU on your system supports Vulkan graphics API."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        return;
    }

    FOR_EACH(VideoInfoList::totalVk())
        list.append(QString("GPU %1: %2\n").arg(i).arg(VideoInfoList::getVk(i)));

    msgBoxHelper(MessageType::Info, QString("GPU device list"), list, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}
#endif

#ifdef Q_OS_WINDOWS
void EncodeGUI::checkGPU() {
    _ui->TestGPUBttn->setText(QString("(Checking...)"));
    SET_DISABLED(_ui->TestGPUBttn);

    VideoInfoList::clearVk();

    if (Checks::checkVsPipe(VSPIPEPATH)) {
        if (Checks::checkVsScript(QString("%1\\vs\\dummy.vpy").arg(QDir::toNativeSeparators(QApplication::applicationDirPath())))) {
            if (Checks::checkVsScript(QString("%1\\vs\\dummy.mkv").arg(QDir::toNativeSeparators(QApplication::applicationDirPath()))))
                _ffloader->gpu();
            else
                msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required VsVideo (dummy.mkv) dependency is missing. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        }
        else
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required VsScript (dummy.vpy) dependency is missing. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    }
    else
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency VSPipe.exe is missing. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}
#endif

void EncodeGUI::newTask() {
    #ifdef Q_OS_WINDOWS
    QString fileName(LOGPATH_WIN);
    #endif
    #ifdef Q_OS_DARWIN
    QString fileName(LOGPATH_DAR);
    #endif

    if (Checks::checkInputExists(_inputList->at(_ffloader->_currentJob))) {
        if (!checkEnviornment().isEmpty()) {
            QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"%1\" is missing in the EncodeGUI installation folder. A clean reinstall should fix this.").arg(checkEnviornment()), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton));
            if (msg == QMessageBox::Help)
                QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

            QApplication::quit();
            return;
        }

        #ifdef Q_OS_WINDOWS
        if (S_OK == CoCreateInstance(CLSID_TaskbarList, 0, CLSCTX_INPROC_SERVER, IID_ITaskbarList3, (void**)&_tbProgress))
            _tbProgress->HrInit();

        _tbProgress->SetProgressState((HWND)this->winId(), TBPF_INDETERMINATE);
        #endif

        writeLog(QString("Starting video encoding/muxing for job: %1").arg(_job->at(_ffloader->_currentJob)), false, false, false);

        #ifdef Q_OS_WINDOWS
        if (QFile(QDir::toNativeSeparators(fileName + QString("\\job-%1\\ProcessLogs-%1.txt").arg(_job->at(_ffloader->_currentJob)))).exists())
            QFile(QDir::toNativeSeparators(fileName + QString("\\job-%1\\ProcessLogs-%1.txt").arg(_job->at(_ffloader->_currentJob)))).remove();

        _logFile->setFileName(QDir::toNativeSeparators(fileName + QString("\\job-%1\\ProcessLogs-%1.txt").arg(_job->at(_ffloader->_currentJob))));
        #endif
        #ifdef Q_OS_DARWIN
        if (QFile(QDir::toNativeSeparators(fileName + QString("/job-%1/ProcessLogs-%1.txt").arg(_job->at(_ffloader->_currentJob)))).exists())
            QFile(QDir::toNativeSeparators(fileName + QString("/job-%1/ProcessLogs-%1.txt").arg(_job->at(_ffloader->_currentJob)))).remove();

        _logFile->setFileName(QDir::toNativeSeparators(fileName + QString("/job-%1/ProcessLogs-%1.txt").arg(_job->at(_ffloader->_currentJob))));
        #endif
                        
        ProcessError::clearAll();
        ProcessErrorRegex::clearBools();

        if (QFile(_outputList->at(_ffloader->_currentJob)).exists())
            QFile(_outputList->at(_ffloader->_currentJob)).remove();

        #ifdef Q_OS_WINDOWS
        if (QDir(QDir::toNativeSeparators(fileName + QString("\\Preview"))).exists())
            openPreview();

        if (!QDir(QDir::toNativeSeparators(fileName + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob)))).exists())
            QDir().mkpath(QDir::toNativeSeparators(fileName + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob))));
        #endif
        #ifdef Q_OS_DARWIN
        if (QDir(QDir::toNativeSeparators(fileName + QString("/Preview"))).exists())
            openPreview();

        if (!QDir(QDir::toNativeSeparators(fileName + QString("/job-%1").arg(_job->at(_ffloader->_currentJob)))).exists())
            QDir().mkpath(QDir::toNativeSeparators(fileName + QString("/job-%1").arg(_job->at(_ffloader->_currentJob))));
        #endif

        writeLogFile(QString("#================================================#"));
        writeLogFile(QString("EncodeGUI process logs for job %1").arg(_job->at(_ffloader->_currentJob)));

        if (!_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("-c:v copy"))) {
            #ifdef Q_OS_WINDOWS
            writeLogFile(QString("Video encoding arguments: %1 %2 | %3 %4").arg(VSPIPEPATH).arg(_vapourScript.at(_ffloader->_currentJob).toStringList().join(QString(" "))).arg(FFMPEGPATH_WIN).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
            writeLogFile(QString("Audio encoding arguments: %1 %2").arg(FFMPEGPATH_WIN).arg(_audioArgs.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
            #endif
            #ifdef Q_OS_DARWIN
            writeLogFile(QString("Video encoding arguments: %1 %2").arg(FFMPEGPATH_DAR).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
            writeLogFile(QString("Audio encoding arguments: %1 %2").arg(FFMPEGPATH_DAR).arg(_audioArgs.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
            #endif
        }
        else {
            #ifdef Q_OS_WINDOWS
            writeLogFile(QString("Video encoding arguments: %1 %2").arg(FFMPEGPATH_WIN).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
            #endif
            #ifdef Q_OS_DARWIN
            writeLogFile(QString("Video encoding arguments: %1 %2").arg(FFMPEGPATH_DAR).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
            #endif
        }

        writeLogFile(QString("#================================================#\n"));

        #ifdef Q_OS_WINDOWS
        if (Checks::checkVsScript(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1\\%1.vpy").arg(_job->at(_ffloader->_currentJob)))))
            _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), _vapourScript.at(_ffloader->_currentJob).toStringList(), FFMPEGPATH_WIN, VSPIPEPATH, false);
        #endif
        #ifdef Q_OS_DARWIN
        if (Checks::checkVsScript(QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1/%1.vpy").arg(_job->at(_ffloader->_currentJob)))))
            _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_DAR, QString(), false);
        #endif
        else if (_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("-c:v copy"))) {
            #ifdef Q_OS_WINDOWS
            _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_WIN, QString(), false);
            #endif
            #ifdef Q_OS_DARWIN
            _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_DAR, QString(), false);
            #endif  
        }
        else {
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Could not find VapourSynth script for job id: %1\nExiting job.").arg(_job->at(_ffloader->_currentJob)), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
            writeLog(QString(QString("Error: could not find VapourSynth script for job %1")).arg(_job->at(_ffloader->_currentJob)), false, true, false);
            encodeFinished();
        }

        if (!_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("-c:v copy"))) {
            _ui->ProgressBarLabel->setText(QString("Initializing components... (this may take some time)"));
            _ui->progressBar->setMaximum(0);
        }
    }
    else {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Required dependency \"vspipe.exe\" is missing in EncodeGUI installation. Please reinstall EncodeGUI."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }
}

void EncodeGUI::openLogs() {
    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN)));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR)));
    #endif
}

void EncodeGUI::encodeFinished() {
    #ifdef Q_OS_WINDOWS
    QFile(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1.lwi").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif
    #ifdef Q_OS_DARWIN
    QFile(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1.lwi").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif
    
    if (_preview) {
        _preview->setPicture(QString(":/EncodeGUI/Preview.png"));
        _preview->setScaled(true);
    }

    _ui->progressBar->setMaximum(100);
    _ui->ProgressBarLabel->setText(QString());
    _ui->progressBar->setValue(0);

    QMessageBox::StandardButton msg;

    if (ProcessError::error()) {
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
        _state->replace(_ffloader->_currentJob, QString("Failed"));

        #ifdef Q_OS_WINDOWS
        if (_tbProgress) {
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_ERROR);
            _tbProgress->SetProgressValue((HWND)this->winId(), 100ULL, 100ULL);
        }
        #endif
        
        if (CHECKED(_ui->NotificationCB))
            pushNotification(QString("Job %1 failed").arg(_job->at(_ffloader->_currentJob)), QString("See the process logs for this job for full details."));
        
        if (ProcessError::getCudaError()) {
            writeLog(QString("Error: Job %1 failed due to the CUDA runtime failing to load. Try updating the selected GPU drivers. Else, the selected GPU is not supported. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("CUDA runtime failed to load.\nTry updating the selected GPU drivers. If this error still occurs then the selected GPU isn't supported."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getNvencError()) {
            writeLog(QString("Error: Job %1 failed due to the NVENC drivers missing. Try to reinstall the selected Nvidia GPU drivers. Else, the selected Nvidia GPU doesn't support NVENC. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Could not find the required NVENC drivers.\nTry updating the selected Nvidia GPU drivers. If this error still occurs then the selected Nvidia GPU doesn't support NVENC."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getQuickSyncError()) {
            writeLog(QString("Error: Job %1 failed due to the QuickSync drivers missing. Try to reinstall the selected Intel GPU drivers. Else, the selected Intel GPU doesn't support QuickSync. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Could not find the required QuickSync drivers.\nTry updating the selected Intel GPU drivers. If this error still occurs then the selected Intel GPU doesn't support QuickSync."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getAmfError()) {
            writeLog(QString("Error: Job %1 failed due to the AMF drivers missing. Try to reinstall the selected AMD GPU drivers. Else, the selected AMD GPU doesn't support AMF. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Could not find the required AMF drivers.\nTry updating the selected AMD GPU drivers. If this error still occurs then the selected AMD GPU doesn't support AMF."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getGpuThreadError()) {
            writeLog(QString("Error: Job %1 failed due to too many GPU threads being utilized. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("GPU thread count for the NCNN process is too high. Threads must be between %1 and %2").arg(ProcessError::getMinThreads()).arg(ProcessError::getMaxThreads()), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getVkMemoryError()) {
            writeLog(QString("Error: Job %1 failed due to NCNN being unable to allocate memory for its process. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to allocate memory for the NCNN process (vkAllocateMemory failed). Try decreasing the number of GPU threads for the NCNN process."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getVkQueueError() && !ProcessError::getVkMemoryError()) {
            writeLog(QString("Error: Job %1 failed due to Vulkan queue submit failure. Follow the directions on https://encodegui.com/support to fix. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to queue the NCNN process (vkQueueSubmit failed). Add registry keys to delay the Vulkan queue submit timeout (see https://encodegui.com/support for more details)."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getNcnnError()) {
            writeLog(QString("Error: Job %1 failed due to the NCNN process not starting. Either the selected GPU drivers are out of date or the selected GPU isn't supported. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to start the NCNN process.\nEnsure the selected GPU supports Vulkan and that the drivers are updated. If you still get this error, then the selected GPU isn't supported."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getNvencBitError()) {
            writeLog(QString("Error: Job %1 failed. Only 8-bit videos are supported for NVENC in AVC. Use NVENC in HEVC for higher bit depth videos.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
            
            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Only 8-bit videos are supported for NVENC in AVC. Use NVENC in HEVC for higher bit depth videos."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getPageError()) {
            writeLog(QString("Error: Job %1 failed. Paging file for CUDA is too small. Ensure that there are no duplicate instances of EncodeGUI running in the background.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Paging file for CUDA is too small. Ensure that there are no duplicate instances of EncodeGUI running in the background."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getAllocateMemory()) {
            writeLog(QString("Error: Job %1 failed. Failed to allocate memory for CUDA process.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to allocate memory for CUDA process. The selected Nvidia GPU does not have enough free VRAM to perform the operation."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getGpuInstance()) {
            writeLog(QString("Error: Job %1 failed. Failed to create GPU instance in the NCNN process.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to create GPU instance in the NCNN process. The selected GPU may not be supported."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getIndexError()) {
            writeLog(QString("Error: Job %1 failed. Failed to create index file for the source video.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to create the index file for the source video. You may not have permissions to access the source video or the codec is not supported."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getIndexDeviceError()) {
            writeLog(QString("Error: Job %1 failed. Invalid GPU device ordinal for the CUDA interpolation process.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Invalid GPU device ordinal for the CUDA interpolation process. The selected GPU may not be supported."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getInvalidGpuError()) {
            writeLog(QString("Error: Job %1 failed. Invalid GPU index for the NCNN process.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Invalid GPU index for the NCNN process. The selected GPU may not be supported."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }
        if (ProcessError::getVramError()) {
            writeLog(QString("Error: Job %1 failed. Failed to allocate memory for CUDA process.").arg(_job->at(_ffloader->_currentJob)), false, true, false);

            if (CHECKED(_ui->ErrorMessageCB))
                msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Failed to allocate memory for CUDA process. The selected Nvidia GPU does not have enough free VRAM to perform the operation."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::NoButton);
        }

        if (msg == QMessageBox::Open) {
            #ifdef Q_OS_WINDOWS
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
            #ifdef Q_OS_DARWIN
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
        }
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

        setState();
    }
    else if (ProcessError::getPipeError()) {
        #ifdef Q_OS_WINDOWS
        if (_tbProgress) {
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_ERROR);
            _tbProgress->SetProgressValue((HWND)this->winId(), 100ULL, 100ULL);
        }
        #endif

        if (CHECKED(_ui->NotificationCB))
            pushNotification(QString("Job %1 failed").arg(_job->at(_ffloader->_currentJob)), QString("See the process logs for this job for full details."));

        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
        _state->replace(_ffloader->_currentJob, QString("Failed"));

        if (CHECKED(_ui->ErrorMessageCB))
            msg = msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The process failed due to FFmpeg receiving invalid data from VSPipe. The most common reason for this error is that your GPU's drivers are out of date or your GPU is not supported for a particular filter.\nClick \"Open\" below to see the associate process logs for more details."), QMessageBox::Ok, QMessageBox::Help, QMessageBox::Open);

        if (msg == QMessageBox::Open) {
            #ifdef Q_OS_WINDOWS
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
            #ifdef Q_OS_DARWIN
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
        }
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

        setState();
    }
    else if (_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Failed"))) {
        #ifdef Q_OS_WINDOWS
        if (_tbProgress) {
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_ERROR);
            _tbProgress->SetProgressValue((HWND)this->winId(), 100ULL, 100ULL);
        }
        #endif 

        if (CHECKED(_ui->NotificationCB))
            pushNotification(QString("Job %1 failed").arg(_job->at(_ffloader->_currentJob)), QString("See the process logs for this job for full details."));

        writeLog(QString("Error: Job %1 failed due to an unknown process error. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("An unknown error occured with the current process. Click \"Open\" below to open the current job's logs."), QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help));

        if (msg == QMessageBox::Open) {
            #ifdef Q_OS_WINDOWS
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
            #ifdef Q_OS_DARWIN
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
        }
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

        _state->replace(_ffloader->_currentJob, QString("Failed"));
        setState();
    }
    else if (_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("-f NULL"))) {
        #ifdef Q_OS_WINDOWS
        if (_tbProgress)
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_INDETERMINATE);
        #endif

        if (CHECKED(_ui->NotificationCB))
            pushNotification(QString("Job manager"), QString("Encoding pass 2 started for job %1.").arg(_job->at(_ffloader->_currentJob)));

        writeLogFile(QString("\n#================================================#"));
        writeLogFile(QString("Begin pass 2 video encoding..."));

        QStringList newArgs(_arguments.at(_ffloader->_currentJob).toStringList());
        
        for (int i = 0; i < 3; i++)
            newArgs.removeLast();
       
        if (newArgs.join(QString(" ")).contains(QString("pass 1")))
            newArgs.replace(newArgs.indexOf(QString("-pass")) + 1, QString("2"));
        if (newArgs.join(QString(" ")).contains(QString("pass=1"))) {
            #ifdef Q_OS_WINDOWS
            newArgs.replace(newArgs.indexOf(QString("pass=1:stats='%1\\x265.log'").arg(TEMPPATH_WIN)), QString("pass=2:stats='%1\\x265.log'").arg(TEMPPATH_WIN));
            #endif
            #ifdef Q_OS_DARWIN
            newArgs.replace(newArgs.indexOf(QString("pass=1:stats='%1/x265.log'").arg(TEMPPATH_DAR)), QString("pass=2:stats='%1\\x265.log'").arg(TEMPPATH_DAR));
            #endif
        }

        newArgs.append(_tempList->at(_ffloader->_currentJob));

        _arguments.removeAt(_ffloader->_currentJob);
        _arguments.insert(_ffloader->_currentJob, newArgs);
        
        #ifdef Q_OS_WINDOWS
        _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), _vapourScript.at(_ffloader->_currentJob).toStringList(), FFMPEGPATH_WIN, VSPIPEPATH, false);
        writeLogFile(QString("Pass 2 video encoding arguments: %1 %2 | %3 %4").arg(VSPIPEPATH).arg(_vapourScript.at(_ffloader->_currentJob).toStringList().join(QString(" "))).arg(FFMPEGPATH_WIN).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
        #endif
        #ifdef Q_OS_DARWIN
        _ffloader->encode(_arguments.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_DAR, QString(), false);
        writeLogFile(QString("Pass 2 video encoding arguments: %1 %2").arg(FFMPEGPATH_DAR).arg(_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" "))));
        #endif
        writeLogFile(QString("#================================================#\n"));

        _ui->progressBar->setMaximum(0);
        _ui->ProgressBarLabel->setText(QString("Waiting for 2nd pass start..."));
        return;
    }
    else if (!_audioArgs.at(_ffloader->_currentJob).toList().contains(QString("-an")) && !_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("-c:v copy")) && (!QFile(_tempList->at(_ffloader->_currentJob)).exists() || QFile(_tempList->at(_ffloader->_currentJob)).size() < 100000) && !_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Canceled"))) {
        #ifdef Q_OS_WINDOWS
        if (_tbProgress) {
            _tbProgress->SetProgressState((HWND)this->winId(), TBPF_ERROR);
            _tbProgress->SetProgressValue((HWND)this->winId(), 100ULL, 100ULL);
        }
        #endif  
        
        if (CHECKED(_ui->NotificationCB))
            pushNotification(QString("Job %1 failed").arg(_job->at(_ffloader->_currentJob)), QString("See the process logs for this job for full details."));
        
        _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));
        
        writeLog(QString("Error: Job %1 failed due to an unknown process error. See the associated process logs for more details.").arg(_job->at(_ffloader->_currentJob)), false, true, false);
        QMessageBox::StandardButton msg(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("An unknown error occured with the current process. Click \"Open\" below to open the current job's logs."), QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help));
            
        if (msg == QMessageBox::Open) {
            #ifdef Q_OS_WINDOWS
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
            #ifdef Q_OS_DARWIN
            QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(_ffloader->_currentJob)))));
            #endif
        }
        if (msg == QMessageBox::Help)
            QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

        _state->replace(_ffloader->_currentJob, QString("Failed"));
        setState();
    }
    else {
        if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Canceled"))) {
            if (!QFile(_outputList->at(_ffloader->_currentJob)).exists() && !_encodingAudio && !_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("-c:v copy"))) {
                writeLogFile(QString("\n#================================================#"));
                writeLogFile(QString("Begin audio encoding"));
                writeLogFile(QString("#================================================#\n"));

                writeLog(QString("Starting audio/subtitle encoding for job: %1").arg(_job->at(_ffloader->_currentJob)), false, false, false);

                #ifdef Q_OS_WINDOWS
                _ffloader->encode(_audioArgs.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_WIN, QString(), false);
                #endif
                #ifdef Q_OS_DARWIN
                _ffloader->encode(_audioArgs.at(_ffloader->_currentJob).toStringList(), QStringList(), FFMPEGPATH_DAR, QString(), false);
                #endif               

                _encodingAudio = true;

                return;
            }
            else if (_encodingAudio && !QFile(_outputList->at(_ffloader->_currentJob)).exists() || QFile(_outputList->at(_ffloader->_currentJob)).size() < 10000) {
                if (CHECKED(_ui->NotificationCB))
                    pushNotification(QString("Job %1 failed").arg(_job->at(_ffloader->_currentJob)), QString("See the process logs for this job for full details."));

                _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("0%"));
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Failed"));

                QMessageBox::StandardButton sb(msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Audio/subtitle encoding/muxing failed. Click \"Open\" below to see the associated process logs."),
                    QMessageBox::Ok, QMessageBox::Open, QMessageBox::Help));

                if (sb == QMessageBox::Open) {
                    #ifdef Q_OS_WINDOWS
                    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(_ffloader->_currentJob)))));
                    #endif
                    #ifdef Q_OS_DARWIN
                    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(_ffloader->_currentJob)))));
                    #endif
                }
                if (sb == QMessageBox::Help)
                    QDesktopServices::openUrl(QUrl(QString("https://encodegui.com/support")));

                _state->replace(_ffloader->_currentJob, QString("Failed"));
                setState();
            }
            else {
                if (CHECKED(_ui->NotificationCB))
                    pushNotification(QString("Job finished"), QString("Encoding job %1 finished successfully without error(s).").arg(_job->at(_ffloader->_currentJob)));

                _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("100%"));
                _ui->JobQueue->item(_ffloader->_currentJob, 1)->setText(QString("Finished"));

                if (CHECKED(_ui->AutoDelSourceCB)) {
                    #ifdef Q_OS_WINDOWS
                    if (!_inputList->at(_ffloader->_currentJob).contains(QDir::toNativeSeparators(("%1\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv")).arg(QDir::toNativeSeparators(QApplication::applicationDirPath())))) {
                    #endif
                    #ifdef Q_OS_DARWIN
                    if (!_inputList->at(_ffloader->_currentJob).contains(QDir::toNativeSeparators(("%1/demo/Big_Buck_Bunny_Trailer_1080p.ogv")).arg(QDir::toNativeSeparators(QApplication::applicationDirPath())))) {
                    #endif
                        QFile(_inputList->at(_ffloader->_currentJob)).remove();
                        writeLog(QString("Deleting source file for job %1").arg(_job->at(_ffloader->_currentJob)), false, false, false);
                    }
                    else
                        writeLog(QString("Aborting source file deletion for job %1 since the source video is the sample video.").arg(_job->at(_ffloader->_currentJob)), false, false, false);
                }

                writeLog(QString("Job %1 complete! Checking to see if there are any other jobs...").arg(_job->at(_ffloader->_currentJob)), false, false, false);

                _state->replace(_ffloader->_currentJob, QString("Finished"));
                setState();
            }
        }
    }

    _encodingAudio = false;
    delete(_ffloader->_pauseTime);

    writeLogFile(QString("\n#================================================#"));
    writeLogFile(QString("End of ffmpeg/vs logs"));
    writeLogFile(QString("#================================================#"));

    writeLog(QString("Finished writing logs for job %1").arg(_job->at(_ffloader->_currentJob)), false, false, false);
    newJob();
}

void EncodeGUI::pushNotification(QString title, QString message) {
    QSystemTrayIcon sti(this);
    sti.setIcon(QIcon(":/EncodeGUI/egui.png"));
    sti.setVisible(false);
    sti.show();
    sti.showMessage(title, message, QSystemTrayIcon::NoIcon);
    sti.hide();
}

void EncodeGUI::writeLogFile(QString content) {
    _logFile->open(QIODevice::ReadWrite);

    _logsStream->readAll();
    *_logsStream << content + QString("\n");

    _logFile->flush();
    _logFile->close();
}

void EncodeGUI::newJob() {
    paletter(_ui->JobStartValueLabel);
    _ui->JobStartValueLabel->setText(QString("?"));

    paletter(_ui->JobStatusValueLabel);
    _ui->JobStatusValueLabel->setText(QString("?"));

    paletter(_ui->JobIDValueLabel);
    _ui->JobIDValueLabel->setText(QString("?"));

    #ifdef Q_OS_WINDOWS
    QFile(QDir::toNativeSeparators(TEMPPATH_WIN + QString("\\%1.mkv").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif
    #ifdef Q_OS_DARWIN
    QFile(QDir::toNativeSeparators(TEMPPATH_DAR + QString("/%1.mkv").arg(_job->at(_ffloader->_currentJob)))).remove();
    #endif

    writeLog(QString("Deleting temp video file for job %1...").arg(_job->at(_ffloader->_currentJob)), false, false, false);

    #ifdef Q_OS_WINDOWS
    if (_tbProgress) {
        _tbProgress->SetProgressState((HWND)this->winId(), TBPF_NOPROGRESS);
        _tbProgress->Release();
    }
    #endif  

    #ifdef Q_OS_WINDOWS
    QDir(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\Preview"))).removeRecursively();
    #endif
    #ifdef Q_OS_DARWIN
    QDir(QDir::toNativeSeparators(LOGPATH_DAR + QString("/Preview"))).removeRecursively();
    #endif

    writeLog(QString("Deleting extracted preview files for job %1...").arg(_job->at(_ffloader->_currentJob)), false, false, false);
    int isDone = 0;

    FOR_EACH(_ui->JobQueue->rowCount())
        if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting")) && !_ui->JobQueue->item(i, 1)->text().contains(QString("Failed")))
            isDone++;

    if (isDone > 0) {
        FOR_EACH(_ui->JobQueue->rowCount())
            if (_ui->JobQueue->item(i, 1)->text().contains(QString("Waiting"))) {
                if (CHECKED(_ui->EnablePreviewCB) && !_arguments.at(i).toStringList().join(QString(" ")).contains(QString("-c:v copy"))) {
                    newExtract();
                    writeLog(QString("Extracting frames for job %1").arg(_job->at(i)), false, false, false);
                    break;
                }
                else if (_arguments.at(i).toStringList().join(QString(" ")).contains(QString("-c:v copy")) || !CHECKED(_ui->EnablePreviewCB)) {
                    _ffloader->_currentJob = i;

                    _ui->JobQueue->item(i, 1)->setText(QString("Active"));

                    if (CHECKED(_ui->AutoDelSourceCB))
                        writeLog(QString("WARNING: Auto delete source is enabled in preferences. Disable it before the encoding process ends if you do not want the source video to be deleted"), false, false, true);

                    paletter(_ui->JobStartValueLabel);
                    _ui->JobStartValueLabel->setText(QDateTime::currentDateTime().toString());

                    paletter(_ui->JobStatusValueLabel);
                    _ui->JobStatusValueLabel->setText(QString("Active"));

                    paletter(_ui->JobIDValueLabel);
                    _ui->JobIDValueLabel->setText(_ui->JobQueue->item(i, 0)->text());

                   extracterComplete();
                   break;
                }
            }
    }
    else {
        SET_DISABLED(_ui->PauseBttn);
        SET_DISABLED(_ui->CancelBttn);
        SET_ENABLED(_ui->StartBttn);

        switch (_ui->WhenEncCompleteDD->currentIndex()) {
        case 0:
            if (_ui->JobQueue->rowCount() > 0) {
                writeLog(QString("All jobs in the queue are completed."), false, false, false);
                msgBoxHelper(MessageType::Info, QString("Done processing jobs"), QString("No more jobs to process."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            }
            break;
        case 1:
            QApplication::quit();
            break;
        case 2:
            QApplication::quit();
            _ffloader->action(false);
            break;
        case 3:
            QApplication::quit();
            _ffloader->action(true);
            break;
        }
    }
}

void EncodeGUI::openJobLogs() {
    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(_selectedJob)))));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(_selectedJob)))));
    #endif
}

void EncodeGUI::openOutput() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(_outputList->at(_selectedJob)).absolutePath())));
}

void EncodeGUI::updateProgress() {
    _ui->progressBar->setMaximum(100);

    if (!ProcessError::getVkMemoryError() && !ProcessError::getVkQueueError()) {
        QString progress;

        if (!_encodingAudio) {
            if (CHECKED(_ui->JobsCB)) {
                progress.append(QString("Job %1/%2").arg(_ffloader->_currentJob + 1).arg(_ui->JobQueue->rowCount()));

                if (_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("pass 1")) || _arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("pass=1")))
                    progress.append(QString(" (pass 1/2)"));
                else if (_arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("pass 2")) || _arguments.at(_ffloader->_currentJob).toStringList().join(QString(" ")).contains(QString("pass=2")))
                    progress.append(QString(" (pass 2/2)"));

                if (CHECKED(_ui->FPSCB) || CHECKED(_ui->BitrateCB) || CHECKED(_ui->TimeLeftCB) || CHECKED(_ui->TimeElapsedCB) || CHECKED(_ui->PercentageCB))
                    progress.append(QString(" - "));
            }
            if (CHECKED(_ui->FPSCB))
                progress.append(QString("FPS: %1").arg(ProgressInfo::getFps()));
            if (CHECKED(_ui->BitrateCB)) {
                if (CHECKED(_ui->FPSCB))
                    progress.append(QString(", "));

                progress.append(QString("Bitrate: %1kbits/s").arg(ProgressInfo::getBitrate()));
            }
            if (CHECKED(_ui->TimeLeftCB)) {
                if (CHECKED(_ui->BitrateCB) || CHECKED(_ui->FPSCB))
                    progress.append(QString(", "));

                if (ProgressInfo::getTimeLeft().isValid())
                    progress.append(QString("Time left: %1").arg(ProgressInfo::getTimeLeft().toString()));            
                else
                    progress.append(QString("Time left: > day"));
            }
            if (VideoInfoList::getJobDuration(_ffloader->_currentJob).isValid()) {
                if (CHECKED(_ui->TimeElapsedCB)) {
                    if (CHECKED(_ui->TimeLeftCB) || CHECKED(_ui->BitrateCB) || CHECKED(_ui->FPSCB))
                        progress.append(QString(", "));

                    if (ProgressInfo::getTimeElapsed().isValid())
                        progress.append(QString("Time elapsed: %1").arg(ProgressInfo::getTimeElapsed().toString()));
                    else
                        progress.append(QString("Time elapsed: > day"));
                }
                if (CHECKED(_ui->PercentageCB)) {
                    if (CHECKED(_ui->FPSCB) || CHECKED(_ui->BitrateCB) || CHECKED(_ui->TimeLeftCB) || CHECKED(_ui->TimeElapsedCB))
                        progress.append(QString(" - "));

                    progress.append(QString("%1%").arg(ProgressInfo::getPercentage()));
                }
            }
            #ifdef Q_OS_WINDOWS
            if (QDir(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\Preview"))).exists()) {
                if (_preview) {
                    _preview->setPicture(QDir::toNativeSeparators(LOGPATH_WIN + QString("\\Preview\\%1.jpg").arg((int)(QTime(0, 0, 0, 0).secsTo(ProgressInfo::getTime())))));
                    _preview->setScaled(false);
                }
            }
            #endif
            #ifdef Q_OS_DARWIN
            if (QDir(QDir::toNativeSeparators(LOGPATH_DAR + QString("/Preview"))).exists()) {
                if (_preview) {
                    _preview->setPicture(QDir::toNativeSeparators(LOGPATH_DAR + QString("/Preview/%1.jpg").arg((int)(QTime(0, 0, 0, 0).secsTo(ProgressInfo::getTime())))));
                    _preview->setScaled(false);
                }
            }
            #endif
        }
        else {
            if (CHECKED(_ui->JobsCB))
                progress.append(QString("Job %1/%2 - ").arg(_ffloader->_currentJob + 1).arg(_ui->JobQueue->rowCount()));

            progress.append(QString("Audio and/or Subtitle encoding"));

            if (CHECKED(_ui->PercentageCB))
                progress.append(QString(" - %1%").arg(ProgressInfo::getPercentage()));
        }

        if (VideoInfoList::getJobDuration(_ffloader->_currentJob).isValid()) {
            #ifdef Q_OS_WINDOWS
            if (_tbProgress) {
                if (!_ui->JobQueue->item(_ffloader->_currentJob, 1)->text().contains(QString("Paused")))
                    _tbProgress->SetProgressState((HWND)this->winId(), TBPF_NORMAL);

                _tbProgress->SetProgressValue((HWND)this->winId(), (ULONGLONG)ProgressInfo::getPercentage(), 100ULL);
            }
            #endif

            _ui->JobQueue->item(_ffloader->_currentJob, 2)->setText(QString("%1%").arg(ProgressInfo::getPercentage()));
            _ui->progressBar->setValue((int)ProgressInfo::getPercentage());
            _ui->progressBar->repaint();
        }

        _ui->ProgressBarLabel->setText(progress);
    }
    else {
        _ffloader->killProcess(_ffloader->_encode);
        _ffloader->killProcess(_ffloader->_vs);
    }
}

void EncodeGUI::writeFile(QString output) {
    writeLogFile(output);
}

void EncodeGUI::gpuFinished() {
    #ifdef Q_OS_WINDOWS
    IDXGIAdapter *adapter;
    IDXGIFactory *factory = NULL;
    DXGI_ADAPTER_DESC desc;

    std::vector<IDXGIAdapter*> videoAdapters;
    CreateDXGIFactory1(__uuidof(IDXGIFactory), (void**)&factory);

    for (UINT i = 0; factory->EnumAdapters(i, &adapter) != DXGI_ERROR_NOT_FOUND; i++)
        videoAdapters.push_back(adapter);

    if (factory)
        factory->Release();

    FOR_EACH(videoAdapters.size()) {
        videoAdapters.at(i)->GetDesc(&desc);

        if (!QString::fromStdWString(desc.Description).toLower().contains(QString("microsoft")) && !QString::fromStdWString(desc.Description).toLower().contains(QString("parsec"))) {
            _gpuNames->append(QString::fromStdWString(desc.Description));

            _ui->GPUInterpDD->addItem(QString::fromStdWString(desc.Description));
            _ui->GPUUpscaleDD->addItem(QString::fromStdWString(desc.Description));
        }
    }

    if (_gpuNames->size() == 0) {
        msgBoxHelper(MessageType::Error, QString("Critical"), QString("No GPU device detected."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        QApplication::quit();
    }

    if (adapter)
        adapter->Release();

    writeLog(QString("Found %1 GPU device(s): %2").arg(_gpuNames->count()).arg(_gpuNames->join(QString(", "))), false, false, false);

    this->setWindowTitle(QString("EncodeGUI v%1 - [GPU 0: %2]").arg(VERSION).arg(_gpuNames->at(0)));
    #endif
    #ifdef Q_OS_DARWIN
    char buf[100];
    size_t buflen = 100;
    sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

    _gpuNames->append(QString(buf));
    _ui->GPUInterpDD->addItem(QString(buf));
    _ui->GPUUpscaleDD->addItem(QString(buf));
    
    writeLog(QString("Found 1 GPU device: %1").arg(_gpuNames->join(QString(", "))), false, false, false);
    this->setWindowTitle(QString("EncodeGUI v%1 - [GPU: %2]").arg(VERSION).arg(_gpuNames->at(0)));
    #endif
}

void EncodeGUI::reIndexBttns() {
    _logsBttn->clear();
    _outputBttn->clear();
    _inputBttn->clear();

    FOR_EACH(_arguments.count()) {
        QPushButton *jobButtn(new QPushButton(QString("See path"), _ui->JobQueue));
        QPushButton *jobButtn2(new QPushButton(QString("See path"), _ui->JobQueue));
        QPushButton *logButtn(new QPushButton(QString("Open"), _ui->JobQueue));

        #ifdef Q_OS_DARWIN
        jobButtn->setGeometry(QRect(0, 0, 108, 30));
        jobButtn->setMinimumWidth(50);
        jobButtn->setMinimumHeight(32);
        jobButtn->setMaximumHeight(32);
        jobButtn->setFocusPolicy(Qt::NoFocus);
        jobButtn2->setGeometry(QRect(0, 0, 108, 30));
        jobButtn2->setMinimumWidth(50);
        jobButtn2->setMinimumHeight(32);
        jobButtn2->setMaximumHeight(32);
        jobButtn2->setFocusPolicy(Qt::NoFocus);
        logButtn->setGeometry(QRect(0, 0, 108, 30));
        logButtn->setMinimumWidth(50);
        logButtn->setMinimumHeight(32);
        logButtn->setMaximumHeight(32);
        logButtn->setFocusPolicy(Qt::NoFocus);
        #endif

        _ui->JobQueue->removeCellWidget(i, 3);
        jobButtn->setProperty("row", i);
        connect(jobButtn, SIGNAL(clicked(bool)), this, SLOT(jobBttn()));
        _ui->JobQueue->setCellWidget(i, 3, jobButtn);

        _ui->JobQueue->removeCellWidget(i, 4);
        jobButtn2->setProperty("row", i);
        connect(jobButtn2, SIGNAL(clicked(bool)), this, SLOT(jobBttn2()));
        _ui->JobQueue->setCellWidget(i, 4, jobButtn2);

        _ui->JobQueue->removeCellWidget(i, 5);
        logButtn->setProperty("row", i);
        connect(logButtn, SIGNAL(clicked(bool)), this, SLOT(logsClick()));
        _ui->JobQueue->setCellWidget(i, 5, logButtn);

        _inputBttn->append(jobButtn);
        _outputBttn->append(jobButtn2);
        _logsBttn->append(logButtn);
    }
}

void EncodeGUI::bttns() {
    QPushButton *jobButtn(new QPushButton(QString("See path"), _ui->JobQueue));
    QPushButton *jobButtn2(new QPushButton(QString("See path"), _ui->JobQueue));
    QPushButton *logButtn(new QPushButton(QString("Open"), _ui->JobQueue));

    #ifdef Q_OS_DARWIN
    jobButtn->setGeometry(QRect(0, 0, 108, 30));
    jobButtn->setMinimumWidth(50);
    jobButtn->setMinimumHeight(32);
    jobButtn->setMaximumHeight(32);
    jobButtn->setFocusPolicy(Qt::NoFocus);
    jobButtn2->setGeometry(QRect(0, 0, 108, 30));
    jobButtn2->setMinimumWidth(50);
    jobButtn2->setMinimumHeight(32);
    jobButtn2->setMaximumHeight(32);
    jobButtn2->setFocusPolicy(Qt::NoFocus);
    logButtn->setGeometry(QRect(0, 0, 108, 30));
    logButtn->setMinimumWidth(50);
    logButtn->setMinimumHeight(32);
    logButtn->setMaximumHeight(32);
    logButtn->setFocusPolicy(Qt::NoFocus);
    #endif

    jobButtn->setProperty("row", _ui->JobQueue->rowCount() - 1);
    connect(jobButtn, SIGNAL(clicked(bool)), this, SLOT(jobBttn()));
    _ui->JobQueue->setCellWidget(_ui->JobQueue->rowCount() - 1, 3, jobButtn);

    jobButtn2->setProperty("row", _ui->JobQueue->rowCount() - 1);
    connect(jobButtn2, SIGNAL(clicked(bool)), this, SLOT(jobBttn2()));
    _ui->JobQueue->setCellWidget(_ui->JobQueue->rowCount() - 1, 4, jobButtn2);

    logButtn->setProperty("row", _ui->JobQueue->rowCount() - 1);
    connect(logButtn, SIGNAL(clicked(bool)), this, SLOT(logsClick()));
    _ui->JobQueue->setCellWidget(_ui->JobQueue->rowCount() - 1, 5, logButtn);

    _inputBttn->append(jobButtn);
    _outputBttn->append(jobButtn2);
    _logsBttn->append(logButtn);
}

void EncodeGUI::inputClick() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(_inputList->at(_selectedJob)).absolutePath())));
    delete(sender());
}

void EncodeGUI::logsClick() {
    int row = sender()->property("row").toInt();

    #ifdef Q_OS_WINDOWS
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(LOGPATH_WIN + QString("\\job-%1").arg(_job->at(row)))));
    #endif
    #ifdef Q_OS_DARWIN
    QDesktopServices::openUrl(QUrl(QString("file://") + QDir::toNativeSeparators(LOGPATH_DAR + QString("/job-%1").arg(_job->at(row)))));
    #endif
}

void EncodeGUI::outputClick() {
    QDesktopServices::openUrl(QUrl(QString("file:///") + QDir::toNativeSeparators(QFileInfo(_outputList->at(_selectedJob)).absolutePath())));
    delete(sender());
}

void EncodeGUI::outBttn() {
    QString output;

    if (CHECKED(_ui->BatchCB))
        output = QDir::toNativeSeparators(QFileDialog::getExistingDirectory(this, QString("Save output"), _ui->SelectInTxtBox->text(), QFileDialog::ShowDirsOnly));
    else
        output = QDir::toNativeSeparators(QFileDialog::getSaveFileName(this, QString("Save output file"), _ui->SelectInTxtBox->text().left(_ui->SelectInTxtBox->text().lastIndexOf(QString("."))), QString("Supported extensions")));

    if (output.isEmpty() && !_ui->SaveOutTxtBox->text().isEmpty())
        output = _ui->SaveOutTxtBox->text();

    _ui->SaveOutTxtBox->setText(output);
}

void EncodeGUI::writeLog(QString log, bool bold, bool red, bool yellow) {
    _ui->LogsOutRTxtBox->insertPlainText(QString("[%1]: ").arg(QTime::currentTime().toString()));
    
    if (bold)
        _ui->LogsOutRTxtBox->setFontWeight(QFont::Bold);
    if (yellow)
        _ui->LogsOutRTxtBox->setTextColor(Qt::darkYellow);
    if (red)
        _ui->LogsOutRTxtBox->setTextColor(Qt::red);
    
    _ui->LogsOutRTxtBox->insertPlainText(log + QString("\n"));
    _ui->LogsOutRTxtBox->setTextColor(Qt::black);

    if (bold)
        _ui->LogsOutRTxtBox->setFontWeight(QFont::Normal);
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::cpuThread() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("threads"), CHECKED(_ui->LimitThreadsCB));

    if (CHECKED(_ui->LimitThreadsCB))
        SET_ENABLED(_ui->LimitThreadsNUD);
    else
        SET_DISABLED(_ui->LimitThreadsNUD);
}
#endif

void EncodeGUI::jobsCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("jobs"), CHECKED(_ui->JobsCB));
}

void EncodeGUI::fpsCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("fps"), CHECKED(_ui->FPSCB));
}

void EncodeGUI::bitrateCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("bitrate"), CHECKED(_ui->BitrateCB));
}

void EncodeGUI::timeLeftCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("timeleft"), CHECKED(_ui->TimeLeftCB));
}

void EncodeGUI::timerCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("timer"), CHECKED(_ui->TimeElapsedCB));
}

void EncodeGUI::percentCB() {
    QSettings(QSettings::NativeFormat, QSettings::UserScope, QString("DaGoose"), QString("EncodeGUI")).setValue(QString("percent"), CHECKED(_ui->PercentageCB));
}

void EncodeGUI::sampleVid() {
    if (CHECKED(_ui->GenerateOutCB) && CHECKED(_ui->SampleVidCB)) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The sample video file cannot be used while the output file name is being automatically generated."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        disconnect(_ui->SampleVidCB, SIGNAL(stateChanged(int)), this, SLOT(sampleVid()));
        _ui->SampleVidCB->setChecked(false);
        connect(_ui->SampleVidCB, SIGNAL(stateChanged(int)), this, SLOT(sampleVid()));
        return;
    }

    if (CHECKED(_ui->SampleVidCB)) {
        #ifdef Q_OS_WINDOWS
        if (QFile(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv"))).exists()) {
            _ui->SelectInTxtBox->setText(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv")));
        #endif
        #ifdef Q_OS_DARWIN
        if (QFile(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/demo/Big_Buck_Bunny_Trailer_1080p.ogv"))).exists()) {
            _ui->SelectInTxtBox->setText(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/demo/Big_Buck_Bunny_Trailer_1080p.ogv")));
        #endif

            SET_DISABLED(_ui->SelectInBttn);
            inputBttn();
        }
        else {
            writeLog(QString("Error: unable to load sample video."), false, true, false);

            #ifdef Q_OS_WINDOWS
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The sample video file is either missing or does not exist in \"%1\"").arg(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\demo\\Big_Buck_Bunny_Trailer_1080p.ogv"))),
                QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            #endif
            #ifdef Q_OS_DARWIN
            msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The sample video file is either missing or does not exist in \"%1\"").arg(QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/demo/Big_Buck_Bunny_Trailer_1080p.ogv"))),
                QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
            #endif

            _ui->SampleVidCB->setChecked(false);
        }
    }
    else {
        SET_ENABLED(_ui->SelectInBttn);
        _ui->SelectInTxtBox->setText(QString());
    }
}

void EncodeGUI::upscaleGB() {
    if (CHECKED(_ui->UpscalingGB)) {
        SET_DISABLED(_ui->ResizeGB);
        _ui->ResizeGB->setChecked(false);
    }
    else
        SET_ENABLED(_ui->ResizeGB);
}

void EncodeGUI::flipDD() {
    if (CHECKED(_ui->FlipCB))
        SET_ENABLED(_ui->FlipDD);
    else
        SET_DISABLED(_ui->FlipDD);
}

void EncodeGUI::thresholdNUD() {
    if (CHECKED(_ui->SceneChangeCB))
        SET_ENABLED(_ui->SCThresholdNUD);
    else
        SET_DISABLED(_ui->SCThresholdNUD);
}

void EncodeGUI::algoDD() {
    if (CHECKED(_ui->ResizeAlgoCB))
        SET_ENABLED(_ui->ResizeAlgoDD);
    else
        SET_DISABLED(_ui->ResizeAlgoDD);
}

void EncodeGUI::resizeGB() {
    if (CHECKED(_ui->ResizeGB)) {
        SET_DISABLED(_ui->UpscalingGB);
        _ui->UpscalingGB->setChecked(false);
    }
    else
        SET_ENABLED(_ui->UpscalingGB);
}

void EncodeGUI::autoAdjust() {
    if (CHECKED(_ui->AutoAdjResCB)) {
        SET_ENABLED(_ui->AutoAdjResDD);
        autoAdjustDD();
    }
    else {
        SET_ENABLED(_ui->WidthNUD);
        SET_ENABLED(_ui->HeightNUD);
        SET_DISABLED(_ui->AutoAdjResDD);
    }
}

void EncodeGUI::autoAdjHeight() {
    if (CHECKED(_ui->AutoAdjResCB) && !_ui->WidthNUD->isEnabled() && VideoInfo::getHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::getWidth()) / VideoInfo::getHeight();
        _ui->WidthNUD->setValue((int)(_ui->HeightNUD->value() * multi));
    }
}

void EncodeGUI::autoAdjWidth() {
    if (CHECKED(_ui->AutoAdjResCB) && !_ui->HeightNUD->isEnabled() && VideoInfo::getHeight() != 0) {
        double multi = static_cast<double>(VideoInfo::getHeight()) / VideoInfo::getWidth();
        _ui->HeightNUD->setValue((int)(_ui->WidthNUD->value() * multi));
    }
}

void EncodeGUI::autoAdjustDD() {
    if (CHECKED(_ui->AutoAdjResCB))
        switch (_ui->AutoAdjResDD->currentIndex()) {
        case 0:
            SET_DISABLED(_ui->HeightNUD);
            SET_ENABLED(_ui->WidthNUD);
            break;
        case 1:
            SET_DISABLED(_ui->WidthNUD);
            SET_ENABLED(_ui->HeightNUD);
            break;
        }
}

void EncodeGUI::hideEnc() {
    if (_ui->VideoEncDD->currentIndex() >= 0 && _ui->VideoEncDD->currentIndex() <= 5) {
        if (!_ui->Tabs->isTabVisible(_ui->Tabs->indexOf(_ui->VideoTab)))
            _ui->Tabs->insertTab(_ui->Tabs->indexOf(_ui->HomeTab) + 1, _ui->VideoTab, QString("Video"));
    }

    switch (_ui->VideoEncDD->currentIndex()) {
    case 0:
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->x264Tab))) {
            _ui->VideoTabs->insertTab(0, _ui->x264Tab, QString("AVC"));
            SET_VISIBLE(_ui->OutContainerx264DD);
        }

        _ui->WidthNUD->setMaximum(3840);
        _ui->HeightNUD->setMaximum(2160);

        removeTabs(_ui->x264Tab);
        break;
    case 1:
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->x265Tab))) {
            _ui->VideoTabs->insertTab(0, _ui->x265Tab, QString("HEVC"));
            SET_VISIBLE(_ui->OutContainerx265DD);
        }

        _ui->WidthNUD->setMaximum(8192);
        _ui->HeightNUD->setMaximum(4352);

        removeTabs(_ui->x265Tab);
        break;
    case 2:
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->ProResTab))) {
            _ui->VideoTabs->insertTab(0, _ui->ProResTab, QString("ProRes"));
            SET_VISIBLE(_ui->OutContainerProResDD);
        }

        _ui->WidthNUD->setMaximum(8192);
        _ui->HeightNUD->setMaximum(4320);

        removeTabs(_ui->ProResTab);
        break;
    case 3:
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->TheoraTab))) {
            _ui->VideoTabs->insertTab(0, _ui->TheoraTab, QString("Theora"));
            SET_VISIBLE(_ui->OutContainerTheoraDD);
        }

        _ui->WidthNUD->setMaximum(1920);
        _ui->HeightNUD->setMaximum(1080);

        removeTabs(_ui->TheoraTab);
        break;
    case 4:
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->VPXTab))) {
            _ui->VideoTabs->insertTab(0, _ui->VPXTab, QString("VP9"));
            SET_VISIBLE(_ui->OutContainerVPXDD);
        }

        _ui->WidthNUD->setMaximum(8192);
        _ui->HeightNUD->setMaximum(4352);

        removeTabs(_ui->VPXTab);
        break;
    case 5:
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->av1Tab))) {
            _ui->VideoTabs->insertTab(0, _ui->av1Tab, QString("AV1"));
            SET_VISIBLE(_ui->OutContainerAV1DD);
        }

        _ui->WidthNUD->setMaximum(8192);
        _ui->HeightNUD->setMaximum(4352);

        removeTabs(_ui->av1Tab);
        break;
    case 6:
        if (_ui->Tabs->isTabVisible(_ui->Tabs->indexOf(_ui->VideoTab))) {
            _ui->Tabs->removeTab(_ui->Tabs->indexOf(_ui->VideoTab));
            SET_VISIBLE(_ui->OutContainerMuxDD);
        }

        _ui->WidthNUD->setMaximum(8192);
        _ui->HeightNUD->setMaximum(4352);
        
        removeTabs(_ui->VideoTab);
        break;
    }
} 

void EncodeGUI::removeTabs(QWidget *tab) {
    if (tab != _ui->x264Tab) {
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->x264Tab));
        SET_INVISIBLE(_ui->OutContainerx264DD);
    }
    if (tab != _ui->x265Tab) {
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->x265Tab));
        SET_INVISIBLE(_ui->OutContainerx265DD);
    }
    if (tab != _ui->ProResTab) {
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->ProResTab));
        SET_INVISIBLE(_ui->OutContainerProResDD);
    }
    if (tab != _ui->TheoraTab) {
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->TheoraTab));
        SET_INVISIBLE(_ui->OutContainerTheoraDD);
    }
    if (tab != _ui->VPXTab) {
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->VPXTab));
        SET_INVISIBLE(_ui->OutContainerVPXDD);
    }
    if (tab != _ui->av1Tab) {
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->av1Tab));
        SET_INVISIBLE(_ui->OutContainerAV1DD);
    }
    if (tab != _ui->VideoTab) {
        SET_INVISIBLE(_ui->OutContainerMuxDD);
    }

    if (tab != _ui->x265Tab)
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->HDRTab));
    else if (tab == _ui->x265Tab) {
        #ifdef Q_OS_WINDOWS
        if (!CHECKED(_ui->Hardware265CB) && !_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->HDRTab)))
            _ui->VideoTabs->insertTab(_ui->VideoTabs->indexOf(tab) + 1, _ui->HDRTab, QString("Signals"));
        #endif
        #ifdef Q_OS_DARWIN
        if (!_ui->VideoTabs->isTabVisible(_ui->VideoTabs->indexOf(_ui->HDRTab)))
            _ui->VideoTabs->insertTab(_ui->VideoTabs->indexOf(tab) + 1, _ui->HDRTab, QString("Signals"));
        #endif
    }
}

void EncodeGUI::mAlloc() {
    _ffloader = new FFLoader();
    _inputBttn = new QList<QPushButton*>();
    _outputBttn = new QList<QPushButton*>();
    _logsBttn = new QList<QPushButton*>();
    _job = new QStringList();
    _gpuNames = new QStringList();
    _inputList = new QStringList();
    _outputList = new QStringList();
    _tempList = new QStringList();
    _state = new QStringList();
    _channels = new QStringList();
    _quality = new QList<int>();
    _bitrate = new QList<int>();
    _isEncoding = new QList<bool>();
    _isTitle = new QList<bool>();
    _isLang = new QList<bool>();
    _title = new QStringList();
    _logFile = new QFile();
    _logsStream = new QTextStream(_logFile);
    _audioCodec = new QStringList();
    _audioLangs = new QStringList();
    _isEncodingSub = new QList<bool>();
    _isTitleSub = new QList<bool>();
    _isLangSub = new QList<bool>();
    _titleSub = new QStringList();
    _subtitleCodec = new QStringList();
    _subtitleLangs = new QStringList();
    _streamInputs = new QStringList();
    _audioInputs = new QStringList();
    _subtitleInputs = new QStringList();
    _audioStream = new QStringList();
    _subtitleStream = new QStringList();
    _batchFiles = new QStringList();
}

EncodeGUI::~EncodeGUI() {
    delete(_ffloader);
    delete(_preview);
    delete(_inputBttn);
    delete(_outputBttn);
    delete(_logsBttn);
    delete(_job);
    delete(_gpuNames);
    delete(_inputList);
    delete(_outputList);
    delete(_tempList);
    delete(_state);
    delete(_channels);
    delete(_quality);
    delete(_bitrate);
    delete(_isEncoding);
    delete(_isTitle);
    delete(_isLang);
    delete(_title);
    delete(_logsStream);
    delete(_logFile);
    delete(_audioCodec);
    delete(_audioLangs);
    delete(_isEncodingSub);
    delete(_isTitleSub);
    delete(_isLangSub);
    delete(_titleSub);
    delete(_subtitleCodec);
    delete(_subtitleLangs);
    delete(_streamInputs);
    delete(_audioInputs);
    delete(_subtitleInputs);
    delete(_audioStream);
    delete(_subtitleStream);
    delete(_batchFiles);
    delete(_ui);
}