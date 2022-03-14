#pragma once

#ifndef VIDEOINFO_H
#define VIDEOINFO_H

#include <QTime>
#include <QString>

class VideoInfo {
public:
	static void SetVideoCodec(QString);
	static void SetDuration(QTime);
	static void SetDurationStrng(QString);
	static void SetResolution(QString);
	static void SetWidth(int);
	static void SetHeight(int);
	static void SetBitrate(QString);
	static void SetColors(QString);
	static void SetMatrix(QString);
	static void SetTransfer(QString);
	static void SetPrimaries(QString);
	static void SetFrameRate(QString);

	static QString GetVideoCodec();
	static QTime GetDuration();
	static QString GetDurationStrng();
	static QString GetResolution();
	static int GetWidth();
	static int GetHeight();
	static QString GetBitrate();
	static QString GetColors();
	static QString GetMatrix();
	static QString GetTransfer();
	static QString GetPrimaries();
	static QString GetFrameRate();

	static void ClearAll();

private:
	static QString VideoCodec;
	static QTime Duration;
	static QString DurationStrng;
	static QString Resolution;
	static int Width;
	static int Height;
	static QString Bitrate;
	static QString Colors;
	static QString Matrix;
	static QString Transfer;
	static QString Primaries;
	static QString FrameRate;
};

#endif // !VIDEOINFO_H