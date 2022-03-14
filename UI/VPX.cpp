#include "EncodeGUI.h"

void EncodeGUI::mode_vpx() {
    if (ui.EncodeModeVPXDD->currentIndex() == 0) {
        SET_INVISIBLE(ui.BitrateVPXLabel);
        SET_INVISIBLE(ui.BitrateVPXNUD);
        SET_VISIBLE(ui.crfVPXLabel);
        SET_VISIBLE(ui.crfVPXNUD);
    }
    else if (ui.EncodeModeVPXDD->currentIndex() == 1 || ui.EncodeModeVPXDD->currentIndex() == 2) {
        SET_VISIBLE(ui.BitrateVPXLabel);
        SET_VISIBLE(ui.BitrateVPXNUD);
        SET_INVISIBLE(ui.crfVPXLabel);
        SET_INVISIBLE(ui.crfVPXNUD);
    }
}

void EncodeGUI::profile_vpx() {
    switch (ui.ProfileVPXDD->currentIndex()) {
    case 0:
        SET_DISABLED(ui.BitDepthVPXDD);
        SET_DISABLED(ui.SampleVPXDD);

        if (ui.BitDepthVPXDD->count() != 3) {
            ui.BitDepthVPXDD->addItem("8-bit");
            ui.BitDepthVPXDD->setCurrentIndex(2);
        }
        if (ui.SampleVPXDD->count() != 3) {
            ui.SampleVPXDD->addItem("4:2:0");
            ui.SampleVPXDD->setCurrentIndex(2);
        }

        break;
    case 1:
        SET_DISABLED(ui.BitDepthVPXDD);

        if (ui.BitDepthVPXDD->count() != 3) {
            ui.BitDepthVPXDD->addItem("8-bit");
            ui.BitDepthVPXDD->setCurrentIndex(2);
        }

        SET_ENABLED(ui.SampleVPXDD);
        ui.SampleVPXDD->setCurrentIndex(0);
        ui.SampleVPXDD->removeItem(2);
        break;
    case 2:
        SET_ENABLED(ui.BitDepthVPXDD);
        ui.BitDepthVPXDD->setCurrentIndex(0);
        ui.BitDepthVPXDD->removeItem(2);
        SET_DISABLED(ui.SampleVPXDD);

        if (ui.SampleVPXDD->count() != 3) {
            ui.SampleVPXDD->addItem("4:2:0");
            ui.SampleVPXDD->setCurrentIndex(2);
        }

        break;
    case 3:
        SET_ENABLED(ui.BitDepthVPXDD);
        ui.BitDepthVPXDD->setCurrentIndex(0);
        SET_ENABLED(ui.SampleVPXDD);
        ui.SampleVPXDD->setCurrentIndex(0);
        ui.BitDepthVPXDD->removeItem(2);
        ui.SampleVPXDD->removeItem(2);
        break;
    }
}