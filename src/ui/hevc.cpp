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

void EncodeGUI::refsldr265() {
    _ui->Reference265LED->display(_ui->Reference265Sldr->value());
}

void EncodeGUI::bsldr265() {
    _ui->Bframe265LED->display(_ui->BFrame265Sldr->value());
}

void EncodeGUI::hideTun265() {
    if (CHECKED(_ui->Tune265CB))
        SET_ENABLED(_ui->Tune265DD);
    else
        SET_DISABLED(_ui->Tune265DD);
}

void EncodeGUI::hidePre265() {
    if (CHECKED(_ui->Preset265CB))
        SET_ENABLED(_ui->Preset265DD);
    else
        SET_DISABLED(_ui->Preset265DD);
}

void EncodeGUI::profileGB265() {
    if (CHECKED(_ui->Profile265GB))
        profile265();
    else {
        SET_DISABLED(_ui->BitDepth265DD);
        SET_DISABLED(_ui->ColorSpace265DD);
    }
}

void EncodeGUI::profile265() {
    if (_ui->Profile265DD->currentIndex() == 0) {
        SET_DISABLED(_ui->BitDepth265DD);
        _ui->BitDepth264DD->setCurrentIndex(0);
        _ui->ColorSpace265DD->setCurrentIndex(0);
        SET_DISABLED(_ui->ColorSpace265DD);
    }
    else if (_ui->Profile265DD->currentIndex() == 1) {
        SET_ENABLED(_ui->BitDepth265DD);
        SET_DISABLED(_ui->ColorSpace265DD);
        _ui->ColorSpace265DD->setCurrentIndex(0);
        _ui->BitDepth265DD->setCurrentIndex(0);
        _ui->BitDepth265DD->removeItem(2);
    }
    else if (_ui->Profile265DD->currentIndex() == 2) {
        SET_ENABLED(_ui->BitDepth265DD);
        SET_DISABLED(_ui->ColorSpace265DD);
        _ui->ColorSpace265DD->setCurrentIndex(0);
        _ui->BitDepth265DD->setCurrentIndex(0);
        if (_ui->BitDepth265DD->count() != 3)
            _ui->BitDepth265DD->addItem(QString("12-bit"));
    }
    else {
        SET_ENABLED(_ui->BitDepth265DD);
        SET_ENABLED(_ui->ColorSpace265DD);
        if (_ui->BitDepth265DD->count() != 3)
            _ui->BitDepth265DD->addItem(QString("12-bit"));
    }
}

#ifdef Q_OS_WINDOWS
void EncodeGUI::hdwr265() {
    if (CHECKED(_ui->Hardware265CB)) {
        SET_ENABLED(_ui->Hardware265DD);
        SET_DISABLED(_ui->Tune265CB);
        SET_DISABLED(_ui->Preset265CB);
        _ui->Tune265CB->setChecked(false);
        _ui->Preset265CB->setChecked(false);
        _ui->Profile265GB->setChecked(false);
        SET_DISABLED(_ui->Profile265GB);
        _ui->x265Tabs->removeTab(1);
        _ui->VideoTabs->removeTab(_ui->VideoTabs->indexOf(_ui->HDRTab));
        hdwr265d();
        mode265();
    }
    else {
        SET_DISABLED(_ui->Hardware265DD);
        SET_VISIBLE(_ui->EncodeMode265DD);
        SET_ENABLED(_ui->EncodeMode265DD);
        SET_INVISIBLE(_ui->EncodeMode265HWDD);
        SET_ENABLED(_ui->Tune265CB);
        SET_ENABLED(_ui->Preset265CB);
        SET_ENABLED(_ui->Profile265GB);
        _ui->x265Tabs->insertTab(1, _ui->Fames265Tab, QString("Frames"));

        if (_ui->VideoEncDD->currentIndex() == 1)
            _ui->VideoTabs->insertTab(_ui->VideoTabs->indexOf(_ui->VSTab), _ui->HDRTab, QString("Signals"));
        
        mode265();
    }
}

void EncodeGUI::hdwr265d() {
    if (CHECKED(_ui->Hardware265CB)) {
        if (_ui->Hardware265DD->count() == 2 && _ui->Hardware265DD->currentIndex() == 0) {
            SET_INVISIBLE(_ui->EncodeMode265DD);
            SET_DISABLED(_ui->EncodeMode265DD);
            SET_VISIBLE(_ui->EncodeMode265HWDD);
            SET_ENABLED(_ui->EncodeMode265HWDD);
        }
        if (_ui->Hardware265DD->count() == 1 || _ui->Hardware265DD->currentIndex() == 1) {
            SET_VISIBLE(_ui->EncodeMode265HWDD);
            SET_INVISIBLE(_ui->EncodeMode265DD);
            SET_DISABLED(_ui->EncodeMode265DD);
        }
    }
}
#endif

void EncodeGUI::mode265() {
    if (_ui->EncodeMode265DD->isEnabled()) {
        switch (_ui->EncodeMode265DD->currentIndex()) {
        case 0:
            #ifdef Q_OS_WINDOWS
            SET_INVISIBLE(_ui->FastPass265CB);
            SET_INVISIBLE(_ui->FastPass265Label);
            #endif
            
            SET_INVISIBLE(_ui->Bitrate265NUD);
            SET_INVISIBLE(_ui->Bitrate265Label);
            SET_INVISIBLE(_ui->Quantizer265Label);
            SET_INVISIBLE(_ui->Quantizer265NUD);
            SET_VISIBLE(_ui->CRFValue265Label);
            SET_VISIBLE(_ui->CRFValue265NUD);
            break;
        case 1:
            #ifdef Q_OS_WINDOWS
            SET_INVISIBLE(_ui->FastPass265CB);
            SET_INVISIBLE(_ui->FastPass265Label);
            #endif

            SET_VISIBLE(_ui->Bitrate265NUD);
            SET_VISIBLE(_ui->Bitrate265Label);
            SET_INVISIBLE(_ui->Quantizer265Label);
            SET_INVISIBLE(_ui->Quantizer265NUD);
            SET_INVISIBLE(_ui->CRFValue265Label);
            SET_INVISIBLE(_ui->CRFValue265NUD);
            break;
        case 2:
            #ifdef Q_OS_WINDOWS
            SET_VISIBLE(_ui->FastPass265CB);
            SET_VISIBLE(_ui->FastPass265Label);
            #endif

            SET_VISIBLE(_ui->Bitrate265NUD);
            SET_VISIBLE(_ui->Bitrate265Label);
            SET_INVISIBLE(_ui->Quantizer265Label);
            SET_INVISIBLE(_ui->Quantizer265NUD);
            SET_INVISIBLE(_ui->CRFValue265Label);
            SET_INVISIBLE(_ui->CRFValue265NUD);
            break;
        case 3:
            #ifdef Q_OS_WINDOWS
            SET_INVISIBLE(_ui->FastPass265CB);
            SET_INVISIBLE(_ui->FastPass265Label);
            #endif

            SET_INVISIBLE(_ui->Bitrate265NUD);
            SET_INVISIBLE(_ui->Bitrate265Label);
            SET_VISIBLE(_ui->Quantizer265Label);
            SET_VISIBLE(_ui->Quantizer265NUD);
            SET_INVISIBLE(_ui->CRFValue265Label);
            SET_INVISIBLE(_ui->CRFValue265NUD);
            break;
        }
    }
    #ifdef Q_OS_WINDOWS
    else {
        SET_INVISIBLE(_ui->FastPass265CB);
        SET_INVISIBLE(_ui->FastPass265Label);

        if (_ui->EncodeMode265HWDD->currentIndex() == 0) {
            SET_INVISIBLE(_ui->Bitrate265NUD);
            SET_INVISIBLE(_ui->Bitrate265Label);
            SET_VISIBLE(_ui->Quantizer265Label);
            SET_VISIBLE(_ui->Quantizer265NUD);
            SET_INVISIBLE(_ui->CRFValue265Label);
            SET_INVISIBLE(_ui->CRFValue265NUD);
        }
        else {
            SET_VISIBLE(_ui->Bitrate265NUD);
            SET_VISIBLE(_ui->Bitrate265Label);
            SET_INVISIBLE(_ui->Quantizer265Label);
            SET_INVISIBLE(_ui->Quantizer265NUD);
            SET_INVISIBLE(_ui->CRFValue265Label);
            SET_INVISIBLE(_ui->CRFValue265NUD);
        }
    }
    #endif
}