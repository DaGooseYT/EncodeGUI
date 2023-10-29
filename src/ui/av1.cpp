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

#include "encodegui.hpp"

void EncodeGUI::modeAv1() {
    if (_ui->EncodeModeAV1DD->currentIndex() == 0) {
        SET_INVISIBLE(_ui->BitrateAV1Label);
        SET_INVISIBLE(_ui->BitrateAV1NUD);
        SET_VISIBLE(_ui->crfAV1Label);
        SET_VISIBLE(_ui->crfAV1NUD);
    }
    else {
        SET_VISIBLE(_ui->BitrateAV1Label);
        SET_VISIBLE(_ui->BitrateAV1NUD);
        SET_INVISIBLE(_ui->crfAV1Label);
        SET_INVISIBLE(_ui->crfAV1NUD);
    }
}