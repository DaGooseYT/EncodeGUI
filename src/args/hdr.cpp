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

#include "args.hpp"

/// <summary>
/// Enables HDR10 for x265.
/// </summary>
/// <returns>String representation of the argument.</returns>
QString Argument::hdr10Opt() {
	return(QString("hdr-opt=1:repeat-headers=1"));
}

/// <summary>
/// Adds the master display info for HDR10.
/// </summary>
/// <param name="display">The master display parameters.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::masterDisplay(QString display) {
	return(QString("master-display=%1").arg(display));
}

/// <summary>
/// Sets the color video usability info for HDR10.
/// </summary>
/// <param name="matrix">The color matrix to use.</param>
/// <param name="transfer">The color transfer to use.</param>
/// <param name="primaries">The color primaries to use.</param>
/// <param name="range">The color range to use.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::colors(QString matrix, QString transfer, QString primaries, QString range) {
	return(QString("colormatrix=%1:transfer=%2:colorprim=%3:range=%4").arg(matrix).arg(transfer).arg(primaries).arg(range));
}

/// <summary>
/// Set the maximum/minimum light content level for HDR10.
/// </summary>
/// <param name="cll">Maximum luminance.</param>
/// <param name="fall">Minimum luminance.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::maxCllFall(int cll, int fall) {
	return(QString("max-cll=%1,%2").arg(cll).arg(fall));
}

/// <summary>
/// Adds HDR10+ dynamic metadata.
/// </summary>
/// <param name="path">The path to the metadata file.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::hdrPlus(QString path) {
	return(QString("dhdr10-info='%1'").arg(path));
}

/// <summary>
/// Sets the profile for Dolby Vision metadata.
/// </summary>
/// <param name="profile">The profile number.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::dbVisionProfile(QString profile) {
	return(QString("dolby-vision-profile=%1").arg(profile));
}

/// <summary>
/// Sets the RPU path for Dolby Vision metadata.
/// </summary>
/// <param name="path">The path to the RPU.</param>
/// <returns>String representation of the argument.</returns>
QString Argument::dbVisionRPU(QString path) {
	return(QString("dolby-vision-rpu='%1'").arg(path));
}