#include "EncodeGUI.h"

void EncodeGUI::mode_av1() {
    if (ui.EncodeModeAV1DD->currentIndex() == 0) {
        SET_INVISIBLE(ui.BitrateAV1Label);
        SET_INVISIBLE(ui.BitrateAV1NUD);
        SET_VISIBLE(ui.crfAV1Label);
        SET_VISIBLE(ui.crfAV1NUD);
    }
    else {
        SET_VISIBLE(ui.BitrateAV1Label);
        SET_VISIBLE(ui.BitrateAV1NUD);
        SET_INVISIBLE(ui.crfAV1Label);
        SET_INVISIBLE(ui.crfAV1NUD);
    }
}