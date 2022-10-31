#include "VideoInfoList.h"

QList<QTime> VideoInfoList::Duration;
QStringList VideoInfoList::FrameRate;
QStringList VideoInfoList::Vk;

/// <summary>
/// Sets the total duration.
/// </summary>
/// <param name="duration">The duration.</param>
void VideoInfoList::SetDuration(QTime duration) {
	Duration << duration;
}

/// <summary>
/// Sets the frame rate.
/// </summary>
/// <param name="frameRate">The frame rate.</param>
void VideoInfoList::SetFrameRate(QString frameRate) {
	FrameRate << frameRate;
}

/// <summary>
/// Sets the GPU device name.
/// </summary>
/// <param name="name">The GPU device name.</param>
void VideoInfoList::SetVk(QString name) {
	Vk << name;
}

/// <summary>
/// Gets the duration from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The duration.</returns>
QTime VideoInfoList::GetDuration(int index) {
	return(Duration.at(index));
}

/// <summary>
/// Gets the frame rate from the video list.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The frame rate.</returns>
QString VideoInfoList::GetFrameRate(int index) {
	return(FrameRate.at(index));
}

/// <summary>
/// Gets the selected GPU device name.
/// </summary>
/// <param name="index">The index to get.</param>
/// <returns>The GPU device name.</returns>
QString VideoInfoList::GetVk(int index) {
	return(Vk.at(index));
}

/// <summary>
/// Removes a duration from the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::RemoveDuration(int index) {
	Duration.removeAt(index);
}

/// <summary>
/// The frame rate to remove at an index in the video list.
/// </summary>
/// <param name="index">The index to remove.</param>
void VideoInfoList::RemoveFrameRate(int index) {
	FrameRate.removeAt(index);
}

/// <summary>
/// Resets GPU device list. 
/// </summary>
void VideoInfoList::ClearVk() {
	Vk.clear();
}

/// <summary>
/// Resets all private variables.
/// </summary>
void VideoInfoList::ClearAll() {
	Duration.clear();
	FrameRate.clear();
}

/// <summary>
/// The total count of GPU devices.
/// </summary>
/// <returns>The total.</returns>
int VideoInfoList::TotalVk() {
	return Vk.count();
}