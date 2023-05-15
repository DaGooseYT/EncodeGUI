#include "encodegui.hpp"

void EncodeGUI::hideAud() {
    if (CHECKED(_ui->AudioCB)) {
        SET_ENABLED(_ui->AudioDD);
        hideAudTab();
    }
    else {
        SET_DISABLED(_ui->AudioDD);
        _ui->Tabs->removeTab(_ui->Tabs->indexOf(_ui->AudioTab));
    }
}

void EncodeGUI::removeAudio() {
    _ui->AudioQueue->setRowCount(0);

    _channels->clear();
    _quality->clear();
    _bitrate->clear();
    _isEncoding->clear();
    _audioCodec->clear();
    _stream->clear();
    _isTitle->clear();
    _title->clear();
    _isLang->clear();
    _audioLangs->clear();
}

void EncodeGUI::audioTitle() {
    if (CHECKED(_ui->AudioTitleCB))
        SET_ENABLED(_ui->AudioTitleTxtBox);
    else
        SET_DISABLED(_ui->AudioTitleTxtBox);
}

void EncodeGUI::audioLang() {
    if (CHECKED(_ui->LangAudioCB))
        SET_ENABLED(_ui->LangAudioDD);
    else
        SET_DISABLED(_ui->LangAudioDD);
}

void EncodeGUI::removeAudioClick() {
    _ui->AudioQueue->removeRow(_selectedAudio);
    
    _channels->removeAt(_selectedAudio);
    _quality->removeAt(_selectedAudio);
    _bitrate->removeAt(_selectedAudio);
    _isEncoding->removeAt(_selectedAudio);
    _audioCodec->removeAt(_selectedAudio);
    _stream->removeAt(_selectedAudio);
    _isTitle->removeAt(_selectedAudio);
    _title->removeAt(_selectedAudio);
    _isLang->removeAt(_selectedAudio);
    _audioLangs->removeAt(_selectedAudio);

    delete(sender());
}

void EncodeGUI::downmixCB() {
    if (CHECKED(_ui->DownmixCB))
        SET_ENABLED(_ui->DownmixDD);
    else
        SET_DISABLED(_ui->DownmixDD);
}

void EncodeGUI::hideAudTab() {
    if (_ui->AudioDD->currentIndex() == 0)
        _ui->Tabs->removeTab(_ui->Tabs->indexOf(_ui->AudioTab));
    else
        if (_ui->Tabs->indexOf(_ui->VideoTab) == 1)
            _ui->Tabs->insertTab(2, _ui->AudioTab, QString("Audio"));
        else
            _ui->Tabs->insertTab(1, _ui->AudioTab, QString("Audio"));
}

void EncodeGUI::audioDD() {
    if (_ui->AudioEncoderDD->currentIndex() == 4) {
        SET_INVISIBLE(_ui->RealAudioBitrateLabel);
        SET_INVISIBLE(_ui->AudioBitrateNUD);
        SET_VISIBLE(_ui->AudioQualityLabel);
        SET_VISIBLE(_ui->AudioQualityNUD);
    }
    else {
        SET_VISIBLE(_ui->RealAudioBitrateLabel);
        SET_VISIBLE(_ui->AudioBitrateNUD);
        SET_INVISIBLE(_ui->AudioQualityLabel);
        SET_INVISIBLE(_ui->AudioQualityNUD);
    }
}

void EncodeGUI::setAudioInfo() {
    if (AudioInfo::totalStreams() > 0) {
        FOR_EACH(AudioInfo::totalStreams()) {
            _ui->AudioTrackDD->addItem(QString("%1").arg(i + 1));

            if (AudioInfo::getLanguage(i).contains(QString("?")))
                _ui->SelectedAudioDD->addItem(QString("T%1 - (%2)").arg(i + 1).arg(QString("UND")));
            else
                _ui->SelectedAudioDD->addItem(QString("T%1 - (%2)").arg(i + 1).arg(AudioInfo::getLanguage(i)));
        }

        paletter(_ui->FormatValueLabel);
        _ui->FormatValueLabel->setText(AudioInfo::getCodec(0));

        paletter(_ui->AudioLanguageValueLabel);
        _ui->AudioLanguageValueLabel->setText(AudioInfo::getLanguage(0));

        paletter(_ui->SampleRateValueLabel);
        _ui->SampleRateValueLabel->setText(AudioInfo::getSampleRate(0));

        paletter(_ui->ChannelsValueLabel);
        _ui->ChannelsValueLabel->setText(AudioInfo::getChannels(0));
    }
    else {
        SET_DISABLED(_ui->AudioTrackDD);
        SET_DISABLED(_ui->AudioCB);
        _ui->AudioCB->setChecked(false);

        paletter(_ui->FormatValueLabel);
        _ui->FormatValueLabel->setText(QString("?"));

        paletter(_ui->AudioLanguageValueLabel);
        _ui->AudioLanguageValueLabel->setText(QString("?"));

        paletter(_ui->SampleRateValueLabel);
        _ui->SampleRateValueLabel->setText(QString("?"));

        paletter(_ui->ChannelsValueLabel);
        _ui->ChannelsValueLabel->setText(QString("?"));
    }
}

void EncodeGUI::audioTrack() {
    _ui->FormatValueLabel->setText(AudioInfo::getCodec(_ui->AudioTrackDD->currentIndex()));
    _ui->AudioLanguageValueLabel->setText(AudioInfo::getLanguage(_ui->AudioTrackDD->currentIndex()));
    _ui->SampleRateValueLabel->setText(AudioInfo::getSampleRate(_ui->AudioTrackDD->currentIndex()));
    _ui->ChannelsValueLabel->setText(AudioInfo::getChannels(_ui->AudioTrackDD->currentIndex()));
}