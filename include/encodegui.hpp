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

#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include "QtNetwork/QNetworkReply"
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtGui/QDesktopServices>
#include <QtWidgets/QStyleFactory>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
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
#include "windows/ui_encodegui.hpp"
#include "preview.hpp"
#include "updater.hpp"

#include "windows.h"
#include "dxgi.h"

#define FOR_EACH(total) for (int i = 0; i < total; i++)
#define SET_ENABLED(control) (control->setEnabled(true))
#define SET_DISABLED(control) (control->setEnabled(false))
#define SET_VISIBLE(control) (control->setVisible(true))
#define SET_INVISIBLE(control) (control->setVisible(false))
#define CHECKED(control) (control->isChecked())

#define VSPIPEPATH (QDir::toNativeSeparators(QCoreApplication::applicationDirPath() + QString("\\vs\\vspipe.exe")))
#define FFMPEGPATH_WIN (QDir::toNativeSeparators(QApplication::applicationDirPath() + QString("\\lib\\ffmpeg.exe")))
#define TEMPPATH_WIN (QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\Temp")))
#define LOGPATH_WIN (QDir::toNativeSeparators(QDir::homePath() + QString("\\AppData\\Local\\EncodeGUI")))

#define VERSION QString("1.1.7")

class EncodeGUI : public QMainWindow {
    Q_OBJECT

public:
    enum MessageType {
        Error = 0,
        Warning = 1,
        Info = 2,
        Question = 3
    };

    EncodeGUI(QWidget *parent = Q_NULLPTR);
    ~EncodeGUI();

    QStringList configureArgs(QString container, QString id, bool twoPass, int pass);
    QStringList configureVS(QString id);
    QStringList configureAudioP(int stream, QString id, QString container);
    QStringList configureAudioM(int stream, int stream2, QString stream3, QString id, QString container);
    QStringList configureMux(QString container, QStringList audio, QStringList subtitles);
    QStringList configureSubtitle(int stream, QString container, QString id);
    QString buildScript(int width, int height, QString jobID);
    QMessageBox::StandardButton msgBoxHelper(MessageType type, QString title, QString message, QMessageBox::StandardButton button1, QMessageBox::StandardButton button2, QMessageBox::StandardButton button3);
    void writeLog(QString log, bool bold, bool red, bool yellow);
    void setVideoInfo();
    void setAudioInfo();

private:
    Ui::EncodeGUIMV *_ui;

    void removeTabs(QWidget *tab);
    void upscaleMD(int width, int height);
    void removeAudio();
    void newTask();
    void getVideoInfo(QString input, QString ffprobe);
    void dragEnterEvent(QDragEnterEvent *d);
    void dropEvent(QDropEvent *d);
    void newJob();
    void updater();
    void saveSettings();
    void reIndexBttns();
    void setState();
    void setJobSetting();
    int decimalCounter(QString value);
    void setupQueue();
    void checkEncoders();
    void getProcessor();
    void queueScrollBar();
    void bttns();
    void writeLogFile(QString content);
    void loadSysSetting();
    void paletter(QLabel *label);
    int multi(double inFPS, double outFPS);
    QString checkEnviornment();

    int _devices;
    int _selectedJob;
    int _selectedAudio;
    bool _encodingAudio;

    QString _winDir;
    QString _vers;

    FFLoader *_ffloader;
    Preview *_preview;
    Update *_up;
    
    QVariantList _vapourScript;
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
    QVariantList _sVapourScript;
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
    QList<int> *_stream;
    QList<bool> *_isEncoding;
    QList<bool> *_isTitle;
    QList<bool> *_isLang;
    QStringList *_title;
    QStringList *_audioCodec;
    QStringList *_audioLangs;

    QTextStream *_logsStream;
    QFile *_logFile;

    QList<QPushButton*> *_inputBttn;
    QList<QPushButton*> *_outputBttn;
    QList<QPushButton*> *_logsBttn;

private slots:
    void start();
    void createJob();
    void openOutput();
    void checkGPU();
    void vkFinished();
    void skip();
    void mediaInfo();
    void nextJob();
    void goToUpdate();
    void genOutput();
    void logsClick();
    void modelVK();
    void later();
    void audioLang();
    void patreonClick();
    void youClick();
    void updateOpt();
    void updaterFinished();
    void extractRPUFinished();
    void disClick();
    void igClick();
    void inputClick();
    void outputClick();
    void hdrMeta();
    void errorMsg();
    void delSource();
    void dualGPU();
    void gpu1();
    void gpu2();
    void enablePreview();
    void openLogs();
    void extracterInfo();
    void extracterComplete();
    void newExtract();
    void openPreview();
    void cancelAllClick();
    void cancelClick();
    void cancelMain();
    void addAudioJob();
    void autoAjustU();
    void jobBttn();
    void jobBttn2();
    void autoAdjWidth2x();
    void autoAdjWidth();
    void thresholdNUD();
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
    void gpuFinished();
    void regexFinished();
    void donateDaGoose();
    void donateGlitch();
    void hideEnc();
    void hideAud();
    void hideSub();
    void hdwr264();
    void mode264();
    void hidePre264();
    void hideTun264();
    void profile264();
    void profileVpx();
    void inputBttn();
    void profileGB264();
    void refsldr264();
    void bsldr264();
    void outBttn();
    void sampleVid();
    void refsldr265();
    void bsldr265();
    void hdwr265();
    void hdwr265d();
    void hdwr264d();
    void mode265();
    void audioDD();
    void downmixCB();
    void cpuThread();
    void modeVpx();
    void modeAv1();
    void modeTheora();
    void hidePre265();
    void hideTun265();
    void profile265();
    void profileGB265();
    void hideAudTab();
    void hideInterpGpu();
    void hideInterpGpuCB();
    void toolInterp();
    void audioTrack();
    void hideParams();
    void hideUpscale();
    void writeFile(QString);
    void jobContext(QPoint);
    void audioSubContext(QPoint);
    
protected:
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
};

#endif // !ENCODEGUI_H