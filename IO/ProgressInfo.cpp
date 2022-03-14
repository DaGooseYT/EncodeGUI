#include "ProgressInfo.h"

QTime ProgressInfo::TimeLeft;
QTime ProgressInfo::TimeElapsed;
int ProgressInfo::ProcessedFrames;
int ProgressInfo::TotalFrames;
QTime ProgressInfo::Time;
QString ProgressInfo::Fps;
QString ProgressInfo::Bitrate;
double ProgressInfo::Percentage;

/// <summary>
/// Sets the time left.
/// </summary>
/// <param name="timeLeft">The amount of time left.</param>
void ProgressInfo::SetTimeLeft(QTime timeLeft) {
	TimeLeft = timeLeft;
}

/// <summary>
/// Sets the time elapsed.
/// </summary>
/// <param name="timeElapsed">The amount of time elapsed.</param>
void ProgressInfo::SetTimeElapsed(QTime timeElapsed) {
	TimeElapsed = timeElapsed;
}

/// <summary>
/// Sets the processed frames.
/// </summary>
/// <param name="processedFrames">The amount of frames processed.</param>
void ProgressInfo::SetProcessedFrames(int processedFrames) {
	ProcessedFrames = processedFrames;
}

/// <summary>
/// Sets the total number of frames.
/// </summary>
/// <param name="totalFrames">The total number of frames.</param>
void ProgressInfo::SetTotalFrames(int totalFrames) {
	TotalFrames = totalFrames;
}

/// <summary>
/// Sets the time processed.
/// </summary>
/// <param name="time">The time processed.</param>
void ProgressInfo::SetTime(QTime time) {
	Time = time;
}

/// <summary>
/// Sets the fps.
/// </summary>
/// <param name="fps">The fps.</param>
void ProgressInfo::SetFps(QString fps) {
	Fps = fps;
}

/// <summary>
/// Sets the bitrate.
/// </summary>
/// <param name="bitrate">The bitrate.</param>
void ProgressInfo::SetBitrate(QString bitrate) {
	Bitrate = bitrate;
}

/// <summary>
/// Sets the encoding percentage.
/// </summary>
/// <param name="percentage">The percentage.</param>
void ProgressInfo::SetPercentage(double percentage) {
	Percentage = percentage;
}

/// <summary>
/// Gets the time left.
/// </summary>
/// <returns>The time left.</returns>
QTime ProgressInfo::GetTimeLeft() {
	return(TimeLeft);
}

/// <summary>
/// Gets the time elapsed.
/// </summary>
/// <returns>The time elapsed.</returns>
QTime ProgressInfo::GetTimeElapsed() {
	return(TimeElapsed);
}

/// <summary>
/// Gets the processed frames.
/// </summary>
/// <returns>The number of processed frames.</returns>
int ProgressInfo::GetProcessedFrames() {
	return(ProcessedFrames);
}

/// <summary>
/// Gets the total number of frames.
/// </summary>
/// <returns>The total number of frames.</returns>
int ProgressInfo::GetTotalFrames() {
	return(TotalFrames);
}

/// <summary>
/// Gets the time processed.
/// </summary>
/// <returns>The time processed.</returns>
QTime ProgressInfo::GetTime() {
	return(Time);
}

/// <summary>
/// Gets the fps.
/// </summary>
/// <returns>The fps.</returns>
QString ProgressInfo::GetFps() {
	return(Fps);
}

/// <summary>
/// Gets the bitrate.
/// </summary>
/// <returns>The bitrate.</returns>
QString ProgressInfo::GetBitrate() {
	return(Bitrate);
}

/// <summary>
/// Gets the percentage.
/// </summary>
/// <returns>The percentage.</returns>
double ProgressInfo::GetPercentage() {
	return(Percentage);
}

/// <summary>
/// Resets all private variables.
/// </summary>
void ProgressInfo::ClearAll() {
	TimeLeft = QTime();
	TimeElapsed = QTime();
	ProcessedFrames = 0;
	TotalFrames = 0;
	Time = QTime();
	Fps.clear();
	Bitrate.clear();
	Percentage = 0.0;
}