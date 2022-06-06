#include "EncodeGUI.h"

void EncodeGUI::hide_aud() {
    if (CHECKED(ui.AudioCB)) {
        SET_ENABLED(ui.AudioDD);
        hide_audtab();
    }
    else {
        SET_DISABLED(ui.AudioDD);
        ui.Tabs->removeTab(ui.Tabs->indexOf(ui.AudioTab));
    }
}

void EncodeGUI::RemoveAudio() {
    ui.AudioQueue->setRowCount(0);

    Channels.clear();
    Quality.clear();
    Bitrate.clear();
    IsEncoding.clear();
    AudioCodec.clear();
    Stream.clear();
    IsTitle.clear();
    Title.clear();
}

void EncodeGUI::AudioTitle() {
    if (CHECKED(ui.AudioTitleCB))
        SET_ENABLED(ui.AudioTitleTxtBox);
    else
        SET_DISABLED(ui.AudioTitleTxtBox);
}

void EncodeGUI::RemoveAudioClick() {
    ui.AudioQueue->removeRow(selectedAudio);
    
    Channels.removeAt(selectedAudio);
    Quality.removeAt(selectedAudio);
    Bitrate.removeAt(selectedAudio);
    IsEncoding.removeAt(selectedAudio);
    AudioCodec.removeAt(selectedAudio);
    Stream.removeAt(selectedAudio);
    IsTitle.removeAt(selectedAudio);
    Title.removeAt(selectedAudio);
}

void EncodeGUI::downmix_cb() {
    if (CHECKED(ui.DownmixCB))
        SET_ENABLED(ui.DownmixDD);
    else
        SET_DISABLED(ui.DownmixDD);
}

void EncodeGUI::hide_audtab() {
    if (ui.AudioDD->currentIndex() == 0)
        ui.Tabs->removeTab(ui.Tabs->indexOf(ui.AudioTab));
    else
        if (ui.Tabs->indexOf(ui.VideoTab) == 1)
            ui.Tabs->insertTab(2, ui.AudioTab, "Audio");
        else
            ui.Tabs->insertTab(1, ui.AudioTab, "Audio");
}

void EncodeGUI::audio_dd() {
    if (ui.AudioEncoderDD->currentIndex() == 4) {
        SET_INVISIBLE(ui.RealAudioBitrateLabel);
        SET_INVISIBLE(ui.AudioBitrateNUD);
        SET_VISIBLE(ui.AudioQualityLabel);
        SET_VISIBLE(ui.AudioQualityNUD);
    }
    else {
        SET_VISIBLE(ui.RealAudioBitrateLabel);
        SET_VISIBLE(ui.AudioBitrateNUD);
        SET_INVISIBLE(ui.AudioQualityLabel);
        SET_INVISIBLE(ui.AudioQualityNUD);
    }
}

void EncodeGUI::SetAudioInfo() {
    if (AudioInfo::TotalStreams() != 0) {
        FOR_EACH(AudioInfo::TotalStreams()) {
            ui.AudioTrackDD->addItem(QString("%1").arg(i + 1));

            if (AudioInfo::TotalStreams() != 0)
                if (AudioInfo::GetLanguage(i).contains("?"))
                    ui.SelectedAudioDD->addItem(QString("%1 - (%2)").arg(i + 1).arg("UND"));
                else
                    ui.SelectedAudioDD->addItem(QString("%1 - (%2)").arg(i + 1).arg(AudioInfo::GetLanguage(i)));
        }

        if (AudioInfo::TotalStreams() > 0) {
            Paletter(ui.FormatValueLabel);
            ui.FormatValueLabel->setText(AudioInfo::GetCodec(0));

            Paletter(ui.AudioLanguageValueLabel);
            ui.AudioLanguageValueLabel->setText(AudioInfo::GetLanguage(0));

            Paletter(ui.SampleRateValueLabel);
            ui.SampleRateValueLabel->setText(AudioInfo::GetSampleRate(0));

            Paletter(ui.ChannelsValueLabel);
            ui.ChannelsValueLabel->setText(AudioInfo::GetChannels(0));
        }
    }
    else {
        SET_DISABLED(ui.AudioTrackDD);
        SET_DISABLED(ui.AudioCB);
        ui.AudioCB->setChecked(false);

        Paletter(ui.FormatValueLabel);
        ui.FormatValueLabel->setText("?");

        Paletter(ui.AudioLanguageValueLabel);
        ui.AudioLanguageValueLabel->setText("?");

        Paletter(ui.SampleRateValueLabel);
        ui.SampleRateValueLabel->setText("?");

        Paletter(ui.ChannelsValueLabel);
        ui.ChannelsValueLabel->setText("?");
    }
}

void EncodeGUI::audio_track() {
    ui.FormatValueLabel->setText(AudioInfo::GetCodec(ui.AudioTrackDD->currentIndex()));
    ui.AudioLanguageValueLabel->setText(AudioInfo::GetLanguage(ui.AudioTrackDD->currentIndex()));
    ui.SampleRateValueLabel->setText(AudioInfo::GetSampleRate(ui.AudioTrackDD->currentIndex()));
    ui.ChannelsValueLabel->setText(AudioInfo::GetChannels(ui.AudioTrackDD->currentIndex()));
}