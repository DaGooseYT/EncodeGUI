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