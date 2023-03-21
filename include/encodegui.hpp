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

#pragma once
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "Opengl32.lib")

#ifndef ENCODEGUI_H
#define ENCODEGUI_H

#include "../x64/Release/uic/ui_encodegui.h"
#include "scriptbuilder.hpp"
#include "mediaconfig.hpp"
#include "ffloader.hpp"
#include "checks.hpp"
#include "preview.hpp"
#include "updater.hpp"

#include "Windows.h"
#include "DxGi.h"

#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"
#include <QtWidgets/QMainWindow>
#include <QDesktopServices>
#include <QStyleFactory>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QMetaType>
#include <QShortcut>
#include <QSettings>
#include <QMimeData>
#include <QProcess>
#include <QVector>
#include <QMenu>

#define FOR_EACH(total) for (int i = 0; i < total; i++)
#define SET_ENABLED(control) (control->setEnabled(true))
#define SET_DISABLED(control) (control->setEnabled(false))
#define SET_VISIBLE(control) (control->setVisible(true))
#define SET_INVISIBLE(control) (control->setVisible(false))
#define CHECKED(control) (control->isChecked())

#define ERROR 0
#define WARNING 1
#define INFO 2
#define QUESTION 3

#define VERSION QString("1.1.5")

class EncodeGUI : public QMainWindow {
    Q_OBJECT

public:
    enum MessageType {
        Error = 0,
        Warning = 1,
        Info = 2,
        Question = 3
    };

    EncodeGUI(QWidget* parent = Q_NULLPTR);
    ~EncodeGUI();

    QString ConfigureArgs(QString, QString, QString, QString, bool, int);
    QString ConfigureVS(QString);
    QString ConfigureAudioP(int, QString, QString);
    QString ConfigureAudioM(int, int, QString, QString, QString);
    QString ConfigureMux(QString, QString, QString);
    QString ConfigureSubtitle(int, QString, QString);
    QString BuildScript(int, int, QString);
    QMessageBox::StandardButton MsgBoxHelper(MessageType, QString, QString, QMessageBox::StandardButton, QMessageBox::StandardButton, QMessageBox::StandardButton);
    void WriteLog(QString, bool, bool, bool);
    void SetVideoInfo();
    void SetAudioInfo();
    int Multi(double, double);
    int Devices;

    QStringList arguments;
    QStringList job;
    QStringList vapourScript;
    QStringList inputList;
    QStringList outputList;
    QStringList tempList;
    QStringList state;

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

private:
    Ui::EncodeGUIMV ui;

    void RemoveTabs(QWidget*);
    void UpscaleMD(int, int);
    void RemoveAudio();
    void NewTask();
    void GetVideoInfo(QString, QString);
    void dragEnterEvent(QDragEnterEvent* d);
    void dropEvent(QDropEvent* d);
    void NewJob();
    void Updater();
    void SaveSettings();
    void SetState();
    void SetJobSetting();
    int DecimalCounter(QString);
    int Counter(QString);
    void setup_queue();
    void CheckEncoders();
    void GetProcessor();
    void LoadSysSetting();
    void Paletter(QLabel*);

    int selectedJob;
    int selectedAudio;

    QString winDir;
    QStringList AudioArgs;

    Preview* preview;

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

    QStringList FileStream;

    QFile LogFile;
    FFLoader* ffloader;

private slots:
    void Start();
    void CreateJob();
    void OpenOutput();
    void CheckGPU();
    void VkFinished();
    void Skip();
    void MediaInfo();
    void NextJob();
    void GoToUpdate();
    void GenOutput();
    void ModelVK();
    void Later();
    void AudioLang();
    void PatreonClick();
    void YouClick();
    void UpdateOpt();
    void UpdaterFinished();
    void DisClick();
    void IgClick();
    void InputClick();
    void HDRMeta();
    void ErrorMsg();
    void DelSource();
    void DualGPU();
    void GPU1();
    void GPU2();
    void EnablePreview();
    void OpenLogs();
    void ExtracterInfo();
    void ExtracterComplete();
    void NewExtract();
    void OpenPreview();
    void WriteFile(QString);
    void CancelAllClick();
    void CancelClick();
    void CancelMain();
    void AddAudioJob();
    void AutoAjustU();
    void AutoAdjWidth2x();
    void AutoAdjWidth();
    void ThresholdNUD();
    void JobsCB();
    void FpsCB();
    void BitrateCB();
    void OpenJobLogs();
    void TimeLeftCB();
    void TimerCB();
    void PercentCB();
    void ModelUpscale();
    void AlgoDD();
    void ModelUpScaleGB();
    void UpscaleGB();
    void ResizeGB();
    void FlipDD();
    void AutoAdjHeight();
    void AutoAdjHeight2x();
    void AutoAdjust();
    void AutoAdjustDD();
    void AutoAdjustUD();
    void ClearFinished();
    void RemoveAudioClick();
    void RemoveJob();
    void ResetJob();
    void JobContext(QPoint);
    void AudioSubContext(QPoint);
    void PauseClick();
    void UpdateProgress();
    void EncodeFinished();
    void AudioTitle();
    void GPUFinished();
    void RegexFinished();
    void DonateDaGoose();
    void DonateGlitch();
    void HideEnc();
    void hide_aud();
    void hide_sub();
    void hdwr_264();
    void mode_264();
    void hide_pre264();
    void hide_tun264();
    void profile_264();
    void profile_vpx();
    void input_bttn();
    void profile_gb264();
    void refsldr_264();
    void bsldr_264();
    void OutBttn();
    void SampleVid();
    void refsldr_265();
    void bsldr_265();
    void hdwr_265();
    void hdwr_265d();
    void hdwr_264d();
    void mode_265();
    void audio_dd();
    void downmix_cb();
    void cpu_thread();
    void mode_vpx();
    void mode_av1();
    void mode_theora();
    void hide_pre265();
    void hide_tun265();
    void profile_265();
    void profile_gb265();
    void hide_audtab();
    void hide_interpgpu();
    void hide_interpgpucb();
    void tool_interp();
    void audio_track();
    void hide_params();
    void hide_upscale();
    
protected:
    void closeEvent(QCloseEvent*);
};

#endif // !ENCODEGUI_H