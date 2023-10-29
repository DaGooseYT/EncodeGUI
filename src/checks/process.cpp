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

#include "checks.hpp"

/// <summary>
/// Checks to ensure that the video codec is compatible with the selected output video container.
/// </summary>
/// <param name="format">The video codec index.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::checkVideoCompatability(int format, QString container) {
	bool result = false;

	switch (format) {
	case AVC:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ts")) || container.contains(QString(".tts")) || container.contains(QString(".flv")) || container.contains(QString(".3gp")))
			result = true;
		break;
	case HEVC:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".ts")) || container.contains(QString(".tts")))
			result = true;
		break;
	case PRORES:
		if (container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		break;
	case THEORA:
		if (container.contains(QString(".mkv")) || container.contains(QString(".ogv")))
			result = true;
		break;
	case VP9:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".webm")))
			result = true;
		break;
	case VC1:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")))
			result = true;
		break;
	case MPEG2:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".ts")) || container.contains(QString(".tts")) || container.contains(QString(".avi")) || container.contains(QString(".asf")))
			result = true;
		break;
	case MPEG4:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")))
			result = true;
		break;
	case HUFFYUV:
		if (container.contains(QString(".mkv")))
			result = true;
		break;
	}

	return(result);
}

/// <summary>
/// Checks to ensure that the audio codec is compatible with the selected output video container.
/// </summary>
/// <param name="format">The audio codec index.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::checkAudioCompatability(int format, QString container) {
	bool result = false;
	
	switch (format) {
	case AAC:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ts")) || container.contains(QString(".tts")) || container.contains(QString(".flv")) || container.contains(QString(".3gp")))
			result = true;
		break;
	case MP3:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ts")) || container.contains(QString(".tts")) || container.contains(QString(".flv")))
			result = true;
		break;
	case AC3:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ts")) || container.contains(QString(".tts")))
			result = true;
		break;
	case FLAC:
		if (container.contains(QString(".mkv")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ogv")))
			result = true;
		break;
	case VORBIS:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ogv")) || container.contains(QString(".webm")))
			result = true;
		break;
	case OPUS:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".ts")) || container.contains(QString(".tts")) || container.contains(QString(".ogv")) || container.contains(QString(".webm")))
			result = true;
		break;
	case DTS:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".asf")))
			result = true;
		break;
	case TRUEHD:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".ts")) || container.contains(QString(".tts")))
			result = true;
		break;
	case EAC3:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")))
			result = true;
		break;
	case ALAC:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")))
			result = true;
		break;
	case WMA:
		if (container.contains(QString(".mkv")) || container.contains(QString(".avi")) || container.contains(QString(".asf")))
			result = true;
		break;
	case PCM:
		if (container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")))
			result = true;
		break;
	case MP2:
		if (container.contains(QString(".mp4")) || container.contains(QString(".mkv")) || container.contains(QString(".mov")) || container.contains(QString(".avi")) || container.contains(QString(".asf")) || container.contains(QString(".ts")) || container.contains(QString(".tts")))
			result = true;
		break;
	}

	return(result);
}

/// <summary>
/// Checks to ensure that the subtitle codec is compatible with the selected output container.
/// </summary>
/// <param name="format">The subtitle codec.</param>
/// <param name="container">The output video container.</param>
/// <returns>True or false.</returns>
bool Checks::checkSubtitleCompatability(QString format, QString container) {
	bool result = false;

	if ((format.contains(QString("SRT")) || format.contains(QString("srt"))) && container.contains(QString(".mkv")))
		result = true;
	if (format.contains(QString("WebVTT")) && container.contains(QString(".mkv")) || container.contains(QString(".webm")))
		result = true;
	if ((format.contains(QString("ASS")) || format.contains(QString("ssa"))) && container.contains(QString(".mkv")))
		result = true;
	if (format.contains(QString("TXTT")) && (container.contains(QString(".mp4")) || container.contains(QString(".mov")) || container.contains(QString(".3gp"))))
		result = true;

	return(result);
}