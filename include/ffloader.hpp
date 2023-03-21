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

#include "audiosubinforegex.hpp"
#include "processerrorregex.hpp"
#include "progressinforegex.hpp"
#include "videoinforegex.hpp"
#include "videoinfolist.hpp"

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