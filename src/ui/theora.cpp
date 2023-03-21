#include "../../include/encodegui.hpp"

void EncodeGUI::mode_theora() {
    switch (ui.EncodeModeTDD->currentIndex()) {
    case 0:
        SET_VISIBLE(ui.BitrateThLabel);
        SET_VISIBLE(ui.BitrateThNUD);
        SET_INVISIBLE(ui.QualityLabel);
        SET_INVISIBLE(ui.QualityNUD);
        break;
    case 1:
        SET_INVISIBLE(ui.BitrateThLabel);
        SET_INVISIBLE(ui.BitrateThNUD);
        SET_VISIBLE(ui.QualityLabel);
        SET_VISIBLE(ui.QualityNUD);
        break;
    }
}