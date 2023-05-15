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