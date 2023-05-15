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

#ifndef FFLOADER_H
#define FFLOADER_H

#include <QProcess>
#include <QtGlobal>
#include <QTime>
#include <QDir>

#include "audiosubinforegex.hpp"
#include "processerrorregex.hpp"
#include "progressinforegex.hpp"
#include "videoinforegex.hpp"
#include "videoinfolist.hpp"

enum class ProcessType {
	Encode,
	VideoInfo,
	VideoFinish,
	EncodeFinish,
	Vs,
	ExtractInfo,
	ExtractFinish,
	VkInfo,
	VkFinish,
	ExtractRPU,
	ExtractRPUFinish,
	Dovi
};

class ProcessWorker : public QObject {
public:
	void newProcess(QProcess *process, QStringList arguments, QString program);
	void pauseProcess(QProcess *process, bool pause);
	void closeProcess(QProcess *process);
	void killProcess(QProcess *process);
	void deconstruct(QProcess *process);

	QProcess *_dovi, *_extract, *_video, *_encode, *_vs, *_vk;
	int _currentJob;
};

class FFLoader : public ProcessWorker {
	Q_OBJECT;

public:
	void encode(QStringList args, QStringList vsArgs, QString ffmpeg, QString vsPipe, bool extracti);
	void videoInfo(QStringList args, QString ffprobe);
	void extractRPU(QStringList args, QStringList doviArgs, QString doviTool, QString ffmpeg);
	void action(bool sd);
	void gpu();
	void connector(QProcess *process, ProcessType type);
	void disconnecter(QProcess *process, ProcessType type);
	void finisher(QProcess *process, ProcessType type);
	void outputData(QProcess *process, ProcessType type);
	void outputDataVideo();
	void outputDataExtract();
	void outputDataInfo();
	void outputDataVs();
	void outputDataVk();
	void outputDataRPU();
	void extractFinished();
	void videoFinished();
	void encodeFinished();
	void vkFinished();
	void extractRPUFinished();

	QElapsedTimer *_timer;
	QTime *_pauseTime;

signals:
	void setVideoInfo();
	void setProgress();
	void completed();
	void vkComplete();
	void rpuFinished();
	void extractInfo();
	void extractComplete();
	void logs(QString);
	void errorLogs(QString);
};

#endif // !FFLOADER_H