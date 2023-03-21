#include "../../include/checks.hpp"

/// <summary>
/// Checks to ensure that the video codec is compatible with the selected output video container.
/// </summary>
/// <param name="format">The video codec index.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::CheckVideoCompatability(int format, QString container) {
	bool result = true;

	switch (format) {
	case AVC:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf") || container.contains(".ts") || container.contains(".tts") || container.contains(".flv") || container.contains(".3gp"))
			result = true;
		else
			result = false;
		break;
	case HEVC:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".ts") || container.contains(".tts"))
			result = true;
		else
			result = false;
		break;
	case PRORES:
		if (container.contains(".mkv") || container.contains(".mov") || container.contains(".avi"))
			result = true;
		else
			result = false;
		break;
	case THEORA:
		if (container.contains(".mkv") || container.contains(".ogv"))
			result = true;
		else
			result = false;
		break;
	case VP9:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".avi") || container.contains(".asf") || container.contains(".webm"))
			result = true;
		else
			result = false;
		break;
	case VC1:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".avi"))
			result = true;
		else
			result = false;
		break;
	case MPEG2:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".ts") || container.contains(".tts") || container.contains(".avi") || container.contains(".asf"))
			result = true;
		else
			result = false;
		break;
	case MPEG4:
		if (container.contains(".mp4") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf"))
			result = true;
		else
			result = false;
		break;
	}

	return result;
}

/// <summary>
/// Checks to ensure that the audio codec is compatible with the selected output video container.
/// </summary>
/// <param name="format">The audio codec index.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::CheckAudioCompatability(int format, QString container) {
	bool result = true;
	
	switch (format) {
	case AAC:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf") || container.contains(".ts") || container.contains(".tts") || container.contains(".flv") || container.contains(".3gp"))
			result = true;
		else
			result = false;
		break;
	case MP3:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf") || container.contains(".ts") || container.contains(".tts") || container.contains(".flv"))
			result = true;
		else
			result = false;
		break;
	case AC3:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf") || container.contains(".ts") || container.contains(".tts"))
			result = true;
		else
			result = false;
		break;
	case FLAC:
		if (container.contains(".mkv") || container.contains(".avi") || container.contains(".asf") || container.contains(".ogv"))
			result = true;
		else
			result = false;
		break;
	case VORBIS:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".avi") || container.contains(".asf") || container.contains(".ogv") || container.contains(".webm"))
			result = true;
		else
			result = false;
		break;
	case OPUS:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".ts") || container.contains(".tts") || container.contains(".ogv") || container.contains(".webm"))
			result = true;
		else
			result = false;
		break;
	case DTS:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".asf"))
			result = true;
		else
			result = false;
		break;
	case TRUEHD:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".ts") || container.contains(".tts"))
			result = true;
		else
			result = false;
		break;
	case EAC3:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov"))
			result = true;
		else
			result = false;
		break;
	case ALAC:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov"))
			result = true;
		else
			result = false;
		break;
	case WMA:
		if (container.contains(".mkv") || container.contains(".avi") || container.contains(".asf"))
			result = true;
		else
			result = false;
		break;
	case PCM:
		if (container.contains(".mkv") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf"))
			result = true;
		else
			result = false;
		break;
	case MP2:
		if (container.contains(".mp4") || container.contains(".mkv") || container.contains(".mov") || container.contains(".avi") || container.contains(".asf") || container.contains(".ts") || container.contains(".tts"))
			result = true;
		else
			result = false;
		break;
	}

	return result;
}

/// <summary>
/// Checks to ensure that the subtitle codec is compatible with the selected output container.
/// </summary>
/// <param name="format">The subtitle codec.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::CheckSubtitleCompatability(QString format, QString container) {
	bool result = false;

	if ((format.contains("subrip") || format.contains("srt")) && container.contains(".mkv")) {
		result = true;
		return result;
	}
	else
		result = false;
	if (format.contains("webvtt") && container.contains(".mkv") || container.contains(".webm")) {
		result = true;
		return result;
	}
	else
		result = false;
	if ((format.contains("ass") || format.contains("ssa")) && container.contains(".mkv")) {
		result = true;
		return result;
	}
	else
		result = false;
	if (format.contains("mov_text") && (container.contains(".mp4") || container.contains(".mov") || container.contains(".3gp"))) {
		result = true;
		return result;
	}
	else
		result = false;

	return result;
}