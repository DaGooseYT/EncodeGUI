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

void EncodeGUI::refsldr264() {
    _ui->Reference264LED->display(_ui->Reference264Sldr->value());
}

void EncodeGUI::bsldr264() {
    _ui->Bframe264LED->display(_ui->BFrame264Sldr->value());
}

void EncodeGUI::hideTun264() {
    if (CHECKED(_ui->Tune264CB))
        SET_ENABLED(_ui->Tune264DD);
    else
        SET_DISABLED(_ui->Tune264DD);
}

void EncodeGUI::hidePre264() {
    if (CHECKED(_ui->Preset264CB))
        SET_ENABLED(_ui->Preset264DD);
    else
        SET_DISABLED(_ui->Preset264DD);
}

void EncodeGUI::profileGB264() {
    if (CHECKED(_ui->Profile264GB))
        profile264();
    else {
        SET_DISABLED(_ui->BitDepth264DD);
        SET_DISABLED(_ui->ColorSpace264DD);
    }
}

void EncodeGUI::profile264() {
    if (_ui->Profile264DD->currentIndex() >= 0 && _ui->Profile264DD->currentIndex() <= 2) {
        _ui->BitDepth264DD->setCurrentIndex(0);
        SET_DISABLED(_ui->BitDepth264DD);
        _ui->ColorSpace264DD->setCurrentIndex(0);
        SET_DISABLED(_ui->ColorSpace264DD);
    }
    else if (_ui->Profile264DD->currentIndex() == 3) {
        SET_ENABLED(_ui->BitDepth264DD);
        SET_DISABLED(_ui->ColorSpace264DD);
        _ui->ColorSpace264DD->setCurrentIndex(0);
    }
    else {
        SET_ENABLED(_ui->BitDepth264DD);
        SET_ENABLED(_ui->ColorSpace264DD);
    }
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::hdwr264() {
    if (CHECKED(_ui->Hardware264CB)) {
        SET_ENABLED(_ui->Hardware264DD);
        SET_DISABLED(_ui->Tune264CB);
        SET_DISABLED(_ui->Preset264CB);
        _ui->Tune264CB->setChecked(false);
        _ui->Preset264CB->setChecked(false);
        _ui->Profile264GB->setChecked(false);
        SET_DISABLED(_ui->Profile264GB);
        _ui->x264Tabs->removeTab(1);
        hdwr264d();
        mode264();
    }
    else {
        SET_DISABLED(_ui->Hardware264DD);
        SET_VISIBLE(_ui->EncodeMode264DD);
        SET_ENABLED(_ui->EncodeMode264DD);
        SET_INVISIBLE(_ui->EncodeMode264HWDD);
        SET_ENABLED(_ui->Tune264CB);
        SET_ENABLED(_ui->Preset264CB);
        SET_ENABLED(_ui->Profile264GB);
        _ui->x264Tabs->insertTab(1, _ui->Fames264Tab, QString("Frames"));
        mode264();
    }
}

void EncodeGUI::hdwr264d() {
    if (CHECKED(_ui->Hardware264CB)) {
        if (_ui->Hardware264DD->count() == 2 && _ui->Hardware264DD->currentIndex() == 0) {
            SET_INVISIBLE(_ui->EncodeMode264DD);
            SET_DISABLED(_ui->EncodeMode264DD);
            SET_VISIBLE(_ui->EncodeMode264HWDD);
            SET_ENABLED(_ui->EncodeMode264HWDD);
        }
        if (_ui->Hardware264DD->count() == 1 || _ui->Hardware264DD->currentIndex() == 1) {
            SET_VISIBLE(_ui->EncodeMode264HWDD);
            SET_INVISIBLE(_ui->EncodeMode264DD);
            SET_DISABLED(_ui->EncodeMode264DD);
        }
    }
}
#endif

void EncodeGUI::mode264() {
    if (_ui->EncodeMode264DD->isEnabled()) {
        if (_ui->EncodeMode264DD->currentIndex() == 2 || _ui->EncodeMode264DD->currentIndex() == 1) {
            SET_VISIBLE(_ui->Bitrate264NUD);
            SET_VISIBLE(_ui->Bitrate264Label);
            SET_INVISIBLE(_ui->Quantizer264Label);
            SET_INVISIBLE(_ui->Quantizer264NUD);
            SET_INVISIBLE(_ui->CRFValueLabel);
            SET_INVISIBLE(_ui->CRFValue264NUD);
        }

        switch (_ui->EncodeMode264DD->currentIndex()) {
        case 0:
            SET_INVISIBLE(_ui->Bitrate264NUD);
            SET_INVISIBLE(_ui->Bitrate264Label);
            SET_INVISIBLE(_ui->Quantizer264Label);
            SET_INVISIBLE(_ui->Quantizer264NUD);
            SET_VISIBLE(_ui->CRFValueLabel);
            SET_VISIBLE(_ui->CRFValue264NUD);
            break;
        case 3:
            SET_INVISIBLE(_ui->Bitrate264NUD);
            SET_INVISIBLE(_ui->Bitrate264Label);
            SET_VISIBLE(_ui->Quantizer264Label);
            SET_VISIBLE(_ui->Quantizer264NUD);
            SET_INVISIBLE(_ui->CRFValueLabel);
            SET_INVISIBLE(_ui->CRFValue264NUD);
            break;
        }
    }
    #ifdef Q_OS_WINDOWS
    else {
        if (_ui->EncodeMode264HWDD->currentIndex() == 0) {
            SET_INVISIBLE(_ui->Bitrate264NUD);
            SET_INVISIBLE(_ui->Bitrate264Label);
            SET_VISIBLE(_ui->Quantizer264Label);
            SET_VISIBLE(_ui->Quantizer264NUD);
            SET_INVISIBLE(_ui->CRFValueLabel);
            SET_INVISIBLE(_ui->CRFValue264NUD);
        }
        else {
            SET_VISIBLE(_ui->Bitrate264NUD);
            SET_VISIBLE(_ui->Bitrate264Label);
            SET_INVISIBLE(_ui->Quantizer264Label);
            SET_INVISIBLE(_ui->Quantizer264NUD);
            SET_INVISIBLE(_ui->CRFValueLabel);
            SET_INVISIBLE(_ui->CRFValue264NUD);
        }
    }
    #endif
}