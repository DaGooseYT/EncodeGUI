#include "EncodeGUI.h"

void EncodeGUI::refsldr_265() {
    ui.Reference265LED->display(ui.Reference265Sldr->value());
}

void EncodeGUI::bsldr_265() {
    ui.Bframe265LED->display(ui.BFrame265Sldr->value());
}

void EncodeGUI::hide_tun265() {
    if (CHECKED(ui.Tune265CB))
        SET_ENABLED(ui.Tune265DD);
    else
        SET_DISABLED(ui.Tune265DD);
}

void EncodeGUI::hide_pre265() {
    if (CHECKED(ui.Preset265CB))
        SET_ENABLED(ui.Preset265DD);
    else
        SET_DISABLED(ui.Preset265DD);
}

void EncodeGUI::profile_gb265() {
    if (CHECKED(ui.Profile265GB))
        profile_265();
    else {
        SET_DISABLED(ui.BitDepth265DD);
        SET_DISABLED(ui.ColorSpace265DD);
    }
}

void EncodeGUI::profile_265() {
    if (ui.Profile265DD->currentIndex() == 0) {
        SET_DISABLED(ui.BitDepth265DD);
        ui.BitDepth264DD->setCurrentIndex(0);
        ui.ColorSpace265DD->setCurrentIndex(0);
        SET_DISABLED(ui.ColorSpace265DD);
    }
    else if (ui.Profile265DD->currentIndex() == 1) {
        SET_ENABLED(ui.BitDepth265DD);
        SET_DISABLED(ui.ColorSpace265DD);
        ui.ColorSpace265DD->setCurrentIndex(0);
        ui.BitDepth265DD->setCurrentIndex(0);
        ui.BitDepth265DD->removeItem(2);
    }
    else if (ui.Profile265DD->currentIndex() == 2) {
        SET_ENABLED(ui.BitDepth265DD);
        SET_DISABLED(ui.ColorSpace265DD);
        ui.ColorSpace265DD->setCurrentIndex(0);
        ui.BitDepth265DD->setCurrentIndex(0);
        if (ui.BitDepth265DD->count() != 3)
            ui.BitDepth265DD->addItem("12-bit");
    }
    else {
        SET_ENABLED(ui.BitDepth265DD);
        SET_ENABLED(ui.ColorSpace265DD);
        if (ui.BitDepth265DD->count() != 3)
            ui.BitDepth265DD->addItem("12-bit");
    }
}

void EncodeGUI::hdwr_265() {
    if (CHECKED(ui.Hardware265CB)) {
        SET_ENABLED(ui.Hardware265DD);
        SET_DISABLED(ui.Tune265CB);
        SET_DISABLED(ui.Preset265CB);
        ui.Tune265CB->setChecked(false);
        ui.Preset265CB->setChecked(false);
        ui.Profile265GB->setChecked(false);
        SET_DISABLED(ui.Profile265GB);
        ui.x265Tabs->removeTab(1);
        ui.VideoTabs->removeTab(ui.VideoTabs->indexOf(ui.HDRTab));
        hdwr_265d();
        mode_265();
    }
    else {
        SET_DISABLED(ui.Hardware265DD);
        SET_VISIBLE(ui.EncodeMode265DD);
        SET_ENABLED(ui.EncodeMode265DD);
        SET_INVISIBLE(ui.EncodeMode265HWDD);
        SET_ENABLED(ui.Tune265CB);
        SET_ENABLED(ui.Preset265CB);
        SET_ENABLED(ui.Profile265GB);
        ui.x265Tabs->insertTab(1, ui.Fames265Tab, "Frames");

        if (ui.VideoEncDD->currentIndex() == 1)
            ui.VideoTabs->insertTab(ui.VideoTabs->indexOf(ui.VSTab), ui.HDRTab, "Signals");
        
        mode_265();
    }
}

void EncodeGUI::hdwr_265d() {
    if (CHECKED(ui.Hardware265CB)) {
        if (ui.Hardware265DD->count() == 2 && ui.Hardware265DD->currentIndex() == 0) {
            SET_INVISIBLE(ui.EncodeMode265DD);
            SET_DISABLED(ui.EncodeMode265DD);
            SET_VISIBLE(ui.EncodeMode265HWDD);
            SET_ENABLED(ui.EncodeMode265HWDD);
        }
        if (ui.Hardware265DD->count() == 1 || ui.Hardware265DD->currentIndex() == 1) {
            SET_VISIBLE(ui.EncodeMode265HWDD);
            ui.EncodeMode265HWDD->setCurrentIndex(1);
            SET_DISABLED(ui.EncodeMode265HWDD);
            SET_INVISIBLE(ui.EncodeMode265DD);
            SET_DISABLED(ui.EncodeMode265DD);
        }
    }
}

void EncodeGUI::mode_265() {
    if (ui.EncodeMode265DD->isEnabled()) {
        switch (ui.EncodeMode265DD->currentIndex()) {
        case 0:
            SET_INVISIBLE(ui.FastPass265CB);
            SET_INVISIBLE(ui.FastPass265Label);
            SET_INVISIBLE(ui.Bitrate265NUD);
            SET_INVISIBLE(ui.Bitrate265Label);
            SET_INVISIBLE(ui.Quantizer265Label);
            SET_INVISIBLE(ui.Quantizer265NUD);
            SET_VISIBLE(ui.CRFValue265Label);
            SET_VISIBLE(ui.CRFValue265NUD);
            break;
        case 1:
            SET_INVISIBLE(ui.FastPass265CB);
            SET_INVISIBLE(ui.FastPass265Label);
            SET_VISIBLE(ui.Bitrate265NUD);
            SET_VISIBLE(ui.Bitrate265Label);
            SET_INVISIBLE(ui.Quantizer265Label);
            SET_INVISIBLE(ui.Quantizer265NUD);
            SET_INVISIBLE(ui.CRFValue265Label);
            SET_INVISIBLE(ui.CRFValue265NUD);
            break;
        case 2:
            SET_VISIBLE(ui.FastPass265CB);
            SET_VISIBLE(ui.FastPass265Label);
            SET_VISIBLE(ui.Bitrate265NUD);
            SET_VISIBLE(ui.Bitrate265Label);
            SET_INVISIBLE(ui.Quantizer265Label);
            SET_INVISIBLE(ui.Quantizer265NUD);
            SET_INVISIBLE(ui.CRFValue265Label);
            SET_INVISIBLE(ui.CRFValue265NUD);
            break;
        case 3:
            SET_INVISIBLE(ui.FastPass265CB);
            SET_INVISIBLE(ui.FastPass265Label);
            SET_INVISIBLE(ui.Bitrate265NUD);
            SET_INVISIBLE(ui.Bitrate265Label);
            SET_VISIBLE(ui.Quantizer265Label);
            SET_VISIBLE(ui.Quantizer265NUD);
            SET_INVISIBLE(ui.CRFValue265Label);
            SET_INVISIBLE(ui.CRFValue265NUD);
            break;
        }
    }
    else {
        SET_INVISIBLE(ui.FastPass265CB);
        SET_INVISIBLE(ui.FastPass265Label);

        if (ui.EncodeMode264HWDD->currentIndex() == 0) {
            SET_INVISIBLE(ui.Bitrate265NUD);
            SET_INVISIBLE(ui.Bitrate265Label);
            SET_VISIBLE(ui.Quantizer265Label);
            SET_VISIBLE(ui.Quantizer265NUD);
            SET_INVISIBLE(ui.CRFValue265Label);
            SET_INVISIBLE(ui.CRFValue265NUD);
        }
        else {
            SET_VISIBLE(ui.Bitrate265NUD);
            SET_VISIBLE(ui.Bitrate265Label);
            SET_INVISIBLE(ui.Quantizer265Label);
            SET_INVISIBLE(ui.Quantizer265NUD);
            SET_INVISIBLE(ui.CRFValue265Label);
            SET_INVISIBLE(ui.CRFValue265NUD);
        }
    }
}