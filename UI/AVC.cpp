#include "EncodeGUI.h"

void EncodeGUI::refsldr_264() {
    ui.Reference264LED->display(ui.Reference264Sldr->value());
}

void EncodeGUI::bsldr_264() {
    ui.Bframe264LED->display(ui.BFrame264Sldr->value());
}

void EncodeGUI::hide_tun264() {
    if (CHECKED(ui.Tune264CB))
        SET_ENABLED(ui.Tune264DD);
    else
        SET_DISABLED(ui.Tune264DD);
}

void EncodeGUI::hide_pre264() {
    if (CHECKED(ui.Preset264CB))
        SET_ENABLED(ui.Preset264DD);
    else
        SET_DISABLED(ui.Preset264DD);
}

void EncodeGUI::profile_gb264() {
    if (CHECKED(ui.Profile264GB))
        profile_264();
    else {
        SET_DISABLED(ui.BitDepth264DD);
        SET_DISABLED(ui.ColorSpace264DD);
    }
}

void EncodeGUI::profile_264() {
    if (ui.Profile264DD->currentIndex() >= 0 && ui.Profile264DD->currentIndex() <= 2) {
        ui.BitDepth264DD->setCurrentIndex(0);
        SET_DISABLED(ui.BitDepth264DD);
        ui.ColorSpace264DD->setCurrentIndex(0);
        SET_DISABLED(ui.ColorSpace264DD);
    }
    else if (ui.Profile264DD->currentIndex() == 3) {
        SET_ENABLED(ui.BitDepth264DD);
        SET_DISABLED(ui.ColorSpace264DD);
        ui.ColorSpace264DD->setCurrentIndex(0);
    }
    else {
        SET_ENABLED(ui.BitDepth264DD);
        SET_ENABLED(ui.ColorSpace264DD);
    }
}

void EncodeGUI::hdwr_264() {
    if (CHECKED(ui.Hardware264CB)) {
        SET_ENABLED(ui.Hardware264DD);
        SET_DISABLED(ui.Tune264CB);
        SET_DISABLED(ui.Preset264CB);
        ui.Tune264CB->setChecked(false);
        ui.Preset264CB->setChecked(false);
        ui.Profile264GB->setChecked(false);
        SET_DISABLED(ui.Profile264GB);
        ui.x264Tabs->removeTab(1);
        hdwr_264d();
        mode_264();
    }
    else {
        SET_DISABLED(ui.Hardware264DD);
        SET_VISIBLE(ui.EncodeMode264DD);
        SET_ENABLED(ui.EncodeMode264DD);
        SET_INVISIBLE(ui.EncodeMode264HWDD);
        SET_ENABLED(ui.Tune264CB);
        SET_ENABLED(ui.Preset264CB);
        SET_ENABLED(ui.Profile264GB);
        ui.x264Tabs->insertTab(1, ui.Fames264Tab, "Frames");
        mode_264();
    }
}

void EncodeGUI::hdwr_264d() {
    if (CHECKED(ui.Hardware264CB)) {
        if (ui.Hardware264DD->count() == 2 && ui.Hardware264DD->currentIndex() == 0) {
            SET_INVISIBLE(ui.EncodeMode264DD);
            SET_DISABLED(ui.EncodeMode264DD);
            SET_VISIBLE(ui.EncodeMode264HWDD);
            SET_ENABLED(ui.EncodeMode264HWDD);
        }
        if (ui.Hardware264DD->count() == 1 || ui.Hardware264DD->currentIndex() == 1) {
            SET_VISIBLE(ui.EncodeMode264HWDD);
            ui.EncodeMode264HWDD->setCurrentIndex(1);
            SET_DISABLED(ui.EncodeMode264HWDD);
            SET_INVISIBLE(ui.EncodeMode264DD);
            SET_DISABLED(ui.EncodeMode264DD);
        }
    }
}

void EncodeGUI::mode_264() {
    if (ui.EncodeMode264DD->isEnabled()) {
        if (ui.EncodeMode264DD->currentIndex() == 2 || ui.EncodeMode264DD->currentIndex() == 1) {
            SET_VISIBLE(ui.Bitrate264NUD);
            SET_VISIBLE(ui.Bitrate264Label);
            SET_INVISIBLE(ui.Quantizer264Label);
            SET_INVISIBLE(ui.Quantizer264NUD);
            SET_INVISIBLE(ui.CRFValueLabel);
            SET_INVISIBLE(ui.CRFValue264NUD);
        }

        switch (ui.EncodeMode264DD->currentIndex()) {
        case 0:
            SET_INVISIBLE(ui.Bitrate264NUD);
            SET_INVISIBLE(ui.Bitrate264Label);
            SET_INVISIBLE(ui.Quantizer264Label);
            SET_INVISIBLE(ui.Quantizer264NUD);
            SET_VISIBLE(ui.CRFValueLabel);
            SET_VISIBLE(ui.CRFValue264NUD);
            break;
        case 3:
            SET_INVISIBLE(ui.Bitrate264NUD);
            SET_INVISIBLE(ui.Bitrate264Label);
            SET_VISIBLE(ui.Quantizer264Label);
            SET_VISIBLE(ui.Quantizer264NUD);
            SET_INVISIBLE(ui.CRFValueLabel);
            SET_INVISIBLE(ui.CRFValue264NUD);
            break;
        }
    }
    else {
        if (ui.EncodeMode264HWDD->currentIndex() == 0) {
            SET_INVISIBLE(ui.Bitrate264NUD);
            SET_INVISIBLE(ui.Bitrate264Label);
            SET_VISIBLE(ui.Quantizer264Label);
            SET_VISIBLE(ui.Quantizer264NUD);
            SET_INVISIBLE(ui.CRFValueLabel);
            SET_INVISIBLE(ui.CRFValue264NUD);
        }
        else {
            SET_VISIBLE(ui.Bitrate264NUD);
            SET_VISIBLE(ui.Bitrate264Label);
            SET_INVISIBLE(ui.Quantizer264Label);
            SET_INVISIBLE(ui.Quantizer264NUD);
            SET_INVISIBLE(ui.CRFValueLabel);
            SET_INVISIBLE(ui.CRFValue264NUD);
        }
    }
}