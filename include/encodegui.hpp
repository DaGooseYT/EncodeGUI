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

#ifdef Q_OS_WINDOWS
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "opengl32.lib")
#endif

#ifndef ENCODEGUI_H
#define ENCODEGUI_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QHttpMultiPart>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QAuthenticator>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtGui/QDesktopServices>
#include <QtWidgets/QStyleFactory>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtCore/QDirIterator>
#include <QtGui/QCloseEvent>
#include <QtCore/QMetaType>
#include <QtGui/QShortcut>
#include <QtCore/QSettings>
#include <QtCore/QMimeData>
#include <QtCore/QProcess>
#include <QtCore/QVector>
#include <QtWidgets/QMenu>

#include "scriptbuilder.hpp"
#include "mediaconfig.hpp"
#include "ffloader.hpp"
#include "checks.hpp"
#include "preview.hpp"
#include "updater.hpp"

#ifdef Q_OS_WINDOWS
#include "windows/ui_encodegui.hpp"
#include "shobjidl.h"
#include "windows.h"
#include "dxgi.h"
#endif
#ifdef Q_OS_DARWIN
#include "darwin/ui_encodegui.hpp"
#include <sys/types.h>
#include <sys/sysctl.h>
#include <stdio.h>
#endif

#define FOR_EACH(total) for (int i = 0; i < total; i++)
#define SET_ENABLED(control) (control->setEnabled(true))
#define SET_DISABLED(control) (control->setEnabled(false))
#define SET_VISIBLE(control) (control->setVisible(true))
#define SET_INVISIBLE(control) (control->setVisible(false))
#define CHECKED(control) (control->isChecked())

#define VERSION QString("1.2.3")
#define VSPIPEPATH (QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vspipe.exe")))
#define TEMPPATH_WIN (QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\Temp")))
#define TEMPPATH_DAR (QDir::toNativeSeparators(QDir::homePath() + QString("/Library/Caches/TemporaryItems")))
#define FFMPEGPATH_WIN (QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\lib\\ffmpeg.exe")))
#define FFMPEGPATH_DAR (QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("/lib/ffmpeg")))
#define LOGPATH_WIN (QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI")))
#define LOGPATH_DAR (QDir::toNativeSeparators(TEMPPATH_DAR + QString("/EncodeGUI")))

class EncodeGUI : public QMainWindow {
    Q_OBJECT

public:
    EncodeGUI(QWidget *parent = Q_NULLPTR);
    ~EncodeGUI();

private:
    enum MessageType {
        Error = 0,
        Warning = 1,
        Info = 2,
        Question = 3
    };

    Ui::EncodeGUIMV *_ui;

    #ifdef Q_OS_WINDOWS
    QStringList configureVS(QString id);
    #endif

    QStringList configureArgs(QString input, int index, QString container, QString id, bool twoPass, int pass);
    QStringList configureAudioP(int stream, int stream2, int index, QString id, QString container);
    QStringList configureAudioM(int stream, int index, QVariantList stream2, QString id, QString container);
    QStringList configureMux(QString container, QStringList audio, QStringList subtitles);
    QStringList configureSubtitle(int stream, int index, QString container, QString id);
    QString buildScript(QString input, QString matrix, QString transfer, QString primaries, QString frameRate, int width, int height, QString jobID);
    QMessageBox::StandardButton msgBoxHelper(MessageType type, QString title, QString message, QMessageBox::StandardButton button1, QMessageBox::StandardButton button2, QMessageBox::StandardButton button3);
    void writeLog(QString log, bool bold, bool red, bool yellow);
    void setVideoInfo();
    void setAudioInfo();
    void removeTabs(QWidget *tab);
    void upscaleMD(int width, int height);
    void removeAudio();
    void removeSubtitle();
    void pushNotification(QString title, QString message);
    void newTask();
    void getVideoInfo(QString input, QString ffprobe);
    void getBatchInfo(QString input, QString ffprobe);
    void getAudioInfo(QString input, QString ffprobe);
    void getSubtitleInfo(QString input, QString ffprobe);
    void dragEnterEvent(QDragEnterEvent *d);
    void dropEvent(QDropEvent *d);
    void newJob();
    void updater();
    void createBatchJob(QString container, int index);
    void saveSettings();
    void reIndexBttns();
    void setState();
    void setJobSetting();
    int decimalCounter(QString value);
    void setupQueue();
    void checkEncoders();
    void getProcessor();
    void queueScrollBar();
    void mAlloc();
    void bttns();
    void writeLogFile(QString content);
    void loadSysSetting();
    void paletter(QLabel *label);
    int multi(double inFPS, double outFPS);
    QString checkEnviornment();

    int _devices;
    int _selectedJob;
    int _selectedAudio;
    int _streamNum;
    int _subStreamNum;
    int _selectedSubtitle;
    int _batchIndex;
    bool _encodingAudio;

    QString _winDir;
    QString _vers;

    FFLoader *_ffloader;
    Preview *_preview;
    Update *_up;
    
    QVariantList _audioArgs;
    QVariantList _arguments;
    QStringList *_gpuNames;
    QStringList *_job;
    QStringList *_inputList;
    QStringList *_outputList;
    QStringList *_tempList;
    QStringList *_state;

    QVariantList _sArguments;
    QVariantList _sJob;
    QVariantList _sInputList;
    QVariantList _sOutputList;
    QVariantList _sTempList;
    QVariantList _sState;
    QVariantList _sAudioArgs;
    QVariantList _sDuration;
    QVariantList _sFrameRate;

    QStringList *_channels;
    QList<int> *_quality;
    QList<int> *_bitrate;
    QList<bool> *_isEncoding;
    QList<bool> *_isTitle;
    QList<bool> *_isLang;
    QStringList *_title;
    QStringList *_audioCodec;
    QStringList *_audioLangs;

    QList<bool> *_isEncodingSub;
    QList<bool> *_isTitleSub;
    QList<bool> *_isLangSub;
    QStringList *_titleSub;
    QStringList *_subtitleCodec;
    QStringList *_subtitleLangs;

    QTextStream *_logsStream;
    QFile *_logFile;

    QStringList *_streamInputs;
    QStringList *_subtitleInputs;
    QStringList *_audioInputs;
    QStringList *_batchFiles;

    QStringList *_audioStream;
    QStringList *_subtitleStream;
    QVariantList _stream;
    QVariantList _streamSub;

    QList<QPushButton*> *_inputBttn;
    QList<QPushButton*> *_outputBttn;
    QList<QPushButton*> *_logsBttn;

    #ifdef Q_OS_WINDOWS
    QVariantList _vapourScript;
    QVariantList _sVapourScript;

    ITaskbarList3 *_tbProgress;
    #endif

private slots:
    void start();
    void createJob();
    void openOutput();
    void skip();
    void mediaInfo();
    void nextJob();
    void goToUpdate();
    void genOutput();
    void logsClick();
    void modelVK();
    void later();
    void audioLang();
    void youClick();
    void updateOpt();
    void updaterFinished();
    void audioSelectClick();
    void subtitleSelectClick();
    void extractRPUFinished();
    void disClick();
    void igClick();
    void audioFinished();
    void subtitleFinished();
    void inputClick();
    void outputClick();
    void hdrMeta();
    void errorMsg();
    void delSource();
    void enablePreview();
    void openLogs();
    void extracterInfo();
    void extracterComplete();
    void newExtract();
    void openPreview();
    void cancelAllClick();
    void batchFinished();
    void cancelClick();
    void clearBttn();
    void cancelMain();
    void addAudioJob();
    void autoAjustU();
    void batch();
    void jobBttn();
    void jobBttn2();
    void autoAdjWidth2x();
    void setSubtitleInfo();
    void autoAdjWidth();
    void thresholdNUD();
    void addSubtitleJob();
    void jobsCB();
    void fpsCB();
    void bitrateCB();
    void openJobLogs();
    void timeLeftCB();
    void timerCB();
    void percentCB();
    void modelUpscale();
    void algoDD();
    void rpu();
    void licenseBttn();
    void modelUpScaleGB();
    void upscaleGB();
    void resizeGB();
    void flipDD();
    void autoAdjHeight();
    void autoAdjHeight2x();
    void autoAdjust();
    void autoAdjustDD();
    void autoAdjustUD();
    void clearFinished();
    void removeAudioClick();
    void removeJob();
    void resetJob();
    void pauseClick();
    void updateProgress();
    void encodeFinished();
    void audioTitle();
    void regexFinished();
    void donateDaGoose();
    void donateGlitch();
    void hideEnc();
    void hideAud();
    void mode264();
    void hidePre264();
    void hideTun264();
    void profile264();
    void profileVpx();
    void inputBttn();
    void profileGB264();
    void subtitleClick();
    void refsldr264();
    void bsldr264();
    void outBttn();
    void sampleVid();
    void refsldr265();
    void bsldr265();
    void hideInterpGpu();
    void gpuFinished();
    void mode265();
    void audioDD();
    void downmixCB();
    void hideSubtitle();
    void modeVpx();
    void modeAv1();
    void modeTheora();
    void hidePre265();
    void subtitleTitle();
    void hideTun265();
    void profile265();
    void profileGB265();
    void hideSubtitleTab();
    void subtitleLang();
    void removeSubtitleClick();
    void hideAudTab();
    void audioTrack();
    void hideUpscale();
    void writeFile(QString);
    void jobContext(QPoint);
    void audioContext(QPoint);
    void subtitleContext(QPoint);

    #ifdef Q_OS_WINDOWS
    void checkGPU();
    void dualGPU();
    void cpuThread();
    void vkFinished();
    void hdwr264();
    void hdwr265();
    void hdwr265d();
    void hdwr264d();
    void hideInterpGpuCB();
    void toolInterp();
    void hideParams();
    void gpu1();
    void gpu2();
    #endif
    
protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
};

#endif // !ENCODEGUI_H