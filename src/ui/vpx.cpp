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

void EncodeGUI::modeVpx() {
    if (_ui->EncodeModeVPXDD->currentIndex() == 0) {
        SET_INVISIBLE(_ui->BitrateVPXLabel);
        SET_INVISIBLE(_ui->BitrateVPXNUD);
        SET_VISIBLE(_ui->crfVPXLabel);
        SET_VISIBLE(_ui->crfVPXNUD);
    }
    else if (_ui->EncodeModeVPXDD->currentIndex() == 1 || _ui->EncodeModeVPXDD->currentIndex() == 2) {
        SET_VISIBLE(_ui->BitrateVPXLabel);
        SET_VISIBLE(_ui->BitrateVPXNUD);
        SET_INVISIBLE(_ui->crfVPXLabel);
        SET_INVISIBLE(_ui->crfVPXNUD);
    }
}

void EncodeGUI::profileVpx() {
    switch (_ui->ProfileVPXDD->currentIndex()) {
    case 0:
        SET_DISABLED(_ui->BitDepthVPXDD);
        SET_DISABLED(_ui->SampleVPXDD);

        if (_ui->BitDepthVPXDD->count() != 3) {
            _ui->BitDepthVPXDD->addItem(QString("8-bit"));
            _ui->BitDepthVPXDD->setCurrentIndex(2);
        }
        if (_ui->SampleVPXDD->count() != 3) {
            _ui->SampleVPXDD->addItem(QString("4:2:0"));
            _ui->SampleVPXDD->setCurrentIndex(2);
        }

        break;
    case 1:
        SET_DISABLED(_ui->BitDepthVPXDD);

        if (_ui->BitDepthVPXDD->count() != 3) {
            _ui->BitDepthVPXDD->addItem(QString("8-bit"));
            _ui->BitDepthVPXDD->setCurrentIndex(2);
        }

        SET_ENABLED(_ui->SampleVPXDD);
        _ui->SampleVPXDD->setCurrentIndex(0);
        _ui->SampleVPXDD->removeItem(2);
        break;
    case 2:
        SET_ENABLED(_ui->BitDepthVPXDD);
        _ui->BitDepthVPXDD->setCurrentIndex(0);
        _ui->BitDepthVPXDD->removeItem(2);
        SET_DISABLED(_ui->SampleVPXDD);

        if (_ui->SampleVPXDD->count() != 3) {
            _ui->SampleVPXDD->addItem(QString("4:2:0"));
            _ui->SampleVPXDD->setCurrentIndex(2);
        }

        break;
    case 3:
        SET_ENABLED(_ui->BitDepthVPXDD);
        _ui->BitDepthVPXDD->setCurrentIndex(0);
        SET_ENABLED(_ui->SampleVPXDD);
        _ui->SampleVPXDD->setCurrentIndex(0);
        _ui->BitDepthVPXDD->removeItem(2);
        _ui->SampleVPXDD->removeItem(2);
        break;
    }
}