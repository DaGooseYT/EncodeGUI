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

void EncodeGUI::modeTheora() {
    switch (_ui->EncodeModeTDD->currentIndex()) {
    case 0:
        SET_VISIBLE(_ui->BitrateThLabel);
        SET_VISIBLE(_ui->BitrateThNUD);
        SET_INVISIBLE(_ui->QualityLabel);
        SET_INVISIBLE(_ui->QualityNUD);
        break;
    case 1:
        SET_INVISIBLE(_ui->BitrateThLabel);
        SET_INVISIBLE(_ui->BitrateThNUD);
        SET_VISIBLE(_ui->QualityLabel);
        SET_VISIBLE(_ui->QualityNUD);
        break;
    }
}