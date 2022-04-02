#pragma once
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "user32.lib")

#ifndef ENCODEGUI_H
#define ENCODEGUI_H

#include "Process\ScriptBuilder.h"
#include "Process\MediaConfig.h"
#include "Process\FFLoader.h"
#include "Checks\Checks.h"
#include "UI_EncodeGUI.h"
#include "Preview.h"
#include "Updater.h"
#include "Windows.h"
#include "DxGi.h"

#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"
#include <QtWidgets/QMainWindow>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include <QCloseEvent>
#include <QSettings>
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

#define VERSION QString("1.0.2")

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

    QString ConfigureArgs(QString, QString, QString, bool, int);
    QString ConfigureVS(QString);
    QString ConfigureAudioP(int, QString, QString);
    QString ConfigureAudioM(int, int, QString, QString, QString);
    void ConfigureSubtitle(int, QString);
    QString BuildScript(int, int, QString);
    QMessageBox::StandardButton MsgBoxHelper(MessageType, QString, QString, QMessageBox::StandardButton, QMessageBox::StandardButton, QMessageBox::StandardButton);
    void WriteLog(QString, bool, bool, bool);
    void SetVideoInfo();
    void SetAudioInfo();
    int Multi(double, double);
    int Devices;

    QStringList arguments;
    QStringList job;
    QList<bool> isTwoPass;
    QStringList encodeAudio;
    QStringList encodeSubs;
    QStringList vapourScript;
    QStringList inputList;
    QStringList outputList;
    QStringList tempList;

private:
    Ui::EncodeGUIMV ui;

    void RemoveTabs(QWidget*);
    void UpscaleMD(int, int);
    void RemoveAudio();
    void NewTask();
    void NewJob();
    void Updater();
    int DecimalCounter(QString);
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
    QStringList AudioCodec;

    QStringList FileStream;

    QFile LogFile;
    FFLoader* ffloader;

private slots:
    void Start();
    void CreateJob();
    void Skip();
    void MediaInfo();
    void GoToUpdate();
    void Later();
    void UpdateFinished();
    void PatreonClick();
    void YouClick();
    void DisClick();
    void IgClick();
    void JobsComplete();
    void HDRMeta();
    void ErrorMsg();
    void DelSource();
    void EnablePreview();
    void ScNUD();
    void Quitting();
    void OpenLogs();
    void InterpFactor();
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
    void GPUFinished();
    void RegexFinished();
    void DonateDaGoose();
    void DonateGlitch();
    void HideEnc();
    void hide_aud();
    void hide_sub();
    void hdwr_264();
    void hdwr_264d();
    void mode_264();
    void hide_pre264();
    void hide_tun264();
    void profile_264();
    void profile_vpx();
    void container_ch();
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
    void mode_265();
    void audio_dd();
    void downmix_cb();
    void cpu_thread();
    void mode_vpx();
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