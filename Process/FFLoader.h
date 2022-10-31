#pragma once

#ifndef FFLOADER_H
#define FFLOADER_H

#include "..\Regex\AudioSubInfoRegex.h"
#include "..\Regex\ProcessErrorRegex.h"
#include "..\Regex\ProgressInfoRegex.h"
#include "..\Regex\VideoInfoRegex.h"
#include "..\IO\VideoInfoList.h"

#include <QProcess>
#include <QtGlobal>
#include <QTime>
#include <QDir>

enum class ProcessType {
	Encode,
	VideoInfo,
	VideoFinish,
	EncodeFinish,
	Vs,
	ExtractInfo,
	ExtractFinish,
	VkInfo,
	VkFinish
};

class ProcessWorker : public QObject {
public:
	void NewProcess(QProcess*, QStringList, QString);
	void PauseProcess(QProcess*, bool);
	void CloseProcess(QProcess*);
	void KillProcess(QProcess*);
	void Deconstruct(QProcess*);

	QProcess *video, *encode, *vs, *vk;
	int currentJob;
};

class FFLoader : public ProcessWorker {
	Q_OBJECT;

public:
	void Encode(QString, QString, bool);
	void VideoInfo(QString);
	void Action(bool);
	void GPU();
	void Connector(QProcess*, ProcessType);
	void Disconnecter(QProcess*, ProcessType);
	void Finisher(QProcess*, ProcessType);
	void OutputData(QProcess*, ProcessType);
	void OutputDataVideo();
	void OutputDataExtract();
	void OutputDataInfo();
	void OutputDataVs();
	void OutputDataVk();
	void ExtractFinished();
	void VideoFinished();
	void EncodeFinished();
	void VkFinished();

	QElapsedTimer Timer;
	QTime PauseTime;

signals:
	void setVideoInfo();
	void setProgress();
	void Completed();
	void VkComplete();
	void ExtractInfo();
	void ExtractComplete();
	void Logs(QString);
};

#endif // !FFLOADER_H