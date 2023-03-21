#include "../../include/videoinfo.hpp"

QString VideoInfo::VideoCodec;
QTime VideoInfo::Duration;
QString VideoInfo::DurationStrng;
QString VideoInfo::Resolution;
QString VideoInfo::Bitrate;
QString VideoInfo::Colors;
QString VideoInfo::Matrix;
QString VideoInfo::Transfer;
QString VideoInfo::Primaries;
QString VideoInfo::FrameRate;
int VideoInfo::Width;
int VideoInfo::Height;

/// <summary>
/// Sets the video codec.
/// </summary>
/// <param name="codec">The codec.</param>
void VideoInfo::SetVideoCodec(QString videoCodec) {
	VideoCodec = videoCodec;
}

/// <summary>
/// Sets the video duratiom in time.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfo::SetDuration(QTime duration) {
	Duration = duration;
}

/// <summary>
/// Sets the video duration in a string.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfo::SetDurationStrng(QString duration) {
	DurationStrng = duration;
}

/// <summary>
/// Sets the video resolution.
/// </summary>
/// <param name="resolution">the resolution.</param>
void VideoInfo::SetResolution(QString resolution) {
	Resolution = resolution;
}

/// <summary>
/// Sets the video width.
/// </summary>
/// <param name="width">The width.</param>
void VideoInfo::SetWidth(int width) {
	Width = width;
}

/// <summary>
/// Sets the video height.
/// </summary>
/// <param name="height">The height.</param>
void VideoInfo::SetHeight(int height) {
	Height = height;
}

/// <summary>
/// Sets the total bitrate.
/// </summary>
/// <param name="bitrate">The bitrate.</param>
void VideoInfo::SetBitrate(QString bitrate) {
	Bitrate = bitrate;
}

/// <summary>
/// Sets the video colors.
/// </summary>
/// <param name="colors">The colors.</param>
void VideoInfo::SetColors(QString colors) {
	Colors = colors;
}

/// <summary>
/// Sets the color matrix.
/// </summary>
/// <param name="matrix">The matrix.</param>
void VideoInfo::SetMatrix(QString matrix) {
	Matrix = matrix;
}

/// <summary>
/// Sets the color transfer.
/// </summary>
/// <param name="transfer">The transfer.</param>
void VideoInfo::SetTransfer(QString transfer) {
	Transfer = transfer;
}

/// <summary>
/// Sets the color primaries.
/// </summary>
/// <param name="primaries">The primaries.</param>
void VideoInfo::SetPrimaries(QString primaries) {
	Primaries = primaries;
}

/// <summary>
/// Sets the video frame rate.
/// </summary>
/// <param name="frameRate">The frame rate.</param>
void VideoInfo::SetFrameRate(QString frameRate) {
	FrameRate = frameRate;
}

/// <summary>
/// Gets the video codec.
/// </summary>
/// <returns>The video codec.</returns>
QString VideoInfo::GetVideoCodec() {
	return(VideoCodec);
}

/// <summary>
/// Gets the duration time.
/// </summary>
/// <returns>The duration.</returns>
QTime VideoInfo::GetDuration() {
	return(Duration);
}

/// <summary>
/// Gets the duration string.
/// </summary>
/// <returns>The duration.</returns>
QString VideoInfo::GetDurationStrng() {
	return(DurationStrng);
}

/// <summary>
/// Gets the resolution.
/// </summary>
/// <returns>The resolution.</returns>
QString VideoInfo::GetResolution() {
	return(Resolution);
}

/// <summary>
/// Gets the video width.
/// </summary>
/// <returns>The width.</returns>
int VideoInfo::GetWidth() {
	return(Width);
}

/// <summary>
/// Gets the video height.
/// </summary>
/// <returns>The height.</returns>
int VideoInfo::GetHeight() {
	return(Height);
}

/// <summary>
/// Gets the video bitrate.
/// </summary>
/// <returns>The bitrate.</returns>
QString VideoInfo::GetBitrate() {
	return(Bitrate);
}

/// <summary>
/// Gets the video colors.
/// </summary>
/// <returns>The colors.</returns>
QString VideoInfo::GetColors() {
	return(Colors);
}

/// <summary>
/// Gets the color matrix.
/// </summary>
/// <returns>The matrix.</returns>
QString VideoInfo::GetMatrix() {
	return(Matrix);
}

/// <summary>
/// Gets the color transfer.
/// </summary>
/// <returns>The transfer.</returns>
QString VideoInfo::GetTransfer() {
	return(Transfer);
}

/// <summary>
/// Gets the color primaries.
/// </summary>
/// <returns>The primaries.</returns>
QString VideoInfo::GetPrimaries() {
	return(Primaries);
}

/// <summary>
/// Gets the video frame rate.
/// </summary>
/// <returns>The frame rate.</returns>
QString VideoInfo::GetFrameRate() {
	return(FrameRate);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void VideoInfo::ClearAll() {
	VideoCodec = QString("?");
	Duration = QTime(0, 0, 0, 0);
	DurationStrng = QString("?");
	Resolution = QString("?");
	Width = 0;
	Height = 0;
	Bitrate = QString("?");
	Colors = QString("?");
	Matrix = QString("?");
	Transfer = QString("?");
	Primaries = QString("?");
	FrameRate = QString("?");
}