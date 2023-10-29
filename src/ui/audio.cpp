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

void EncodeGUI::hideAud() {
    if (CHECKED(_ui->AudioCB)) {
        if (!CHECKED(_ui->BatchCB)) {
            SET_ENABLED(_ui->AudioDD);
            hideAudTab();
        }
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
    _stream.clear();
    _isTitle->clear();
    _title->clear();
    _isLang->clear();
    _audioLangs->clear();
    _audioInputs->clear();
    _audioStream->clear();
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

    int input = _audioStream->at(_selectedAudio).toInt();
    int index = 0;
    
    _channels->removeAt(_selectedAudio);
    _quality->removeAt(_selectedAudio);
    _bitrate->removeAt(_selectedAudio);
    _isEncoding->removeAt(_selectedAudio);
    _audioCodec->removeAt(_selectedAudio);
    _isTitle->removeAt(_selectedAudio);
    _title->removeAt(_selectedAudio);
    _isLang->removeAt(_selectedAudio);
    _audioLangs->removeAt(_selectedAudio);
    _audioStream->removeAt(_selectedAudio);

    [&] {
        for (int i = 0; i < _stream.count(); i++)
            for (int j = 0; j < _stream.at(i).toStringList().count(); j++) {
                if (index == _selectedAudio) {
                    if (_stream.at(i).toStringList().count() > 1) {
                        QStringList newStream(_stream.at(i).toStringList());
                        newStream.removeAt(j);
                        _stream.replace(i, newStream);
                    }
                    else if (_stream.at(i).toStringList().count() == 1) {
                        _stream.removeAt(i);
                        i--;
                    }

                    return;
                }

                index++;
            }
    }();

    if (!_subtitleStream->contains(QString("%1").arg(input)) && !_audioStream->contains(QString("%1").arg(input))) {
        if (!_ui->SelectInTxtBox->text().contains(_streamInputs->at(input - 1)) && _ui->VideoEncDD->currentIndex() != 6)
            _streamInputs->removeAt(input - 1);
    }
    if (!_audioStream->contains(QString("%1").arg(input)))
        _audioInputs->removeAt(input - 1);

    for (int i = 0; i < _stream.count(); i++)
        if (_audioStream->at(i).toInt() > _stream.count())
            _audioStream->replace(i, QString("%1").arg(_stream.count()));

    index = 0;

    for (int i = 0; i < _streamSub.count(); i++)
        for (int j = 0; j < _streamSub.at(i).toStringList().count(); j++) {
            if (_subtitleStream->at(index).toInt() > _streamInputs->count())
                _subtitleStream->replace(index, QString("%1").arg(_streamInputs->count()));

            index++;
        }

    for (int i = 0; i < _ui->AudioQueue->rowCount(); i++) {
        _ui->AudioQueue->setItem(i, 0, new QTableWidgetItem(_ui->AudioQueue->item(i, 0)->text().replace(_ui->AudioQueue->item(i, 0)->text().at(_ui->AudioQueue->item(i, 0)->text().indexOf(QRegularExpression("[1-8]"))), QString("%1").arg(i + 1))));
        _ui->AudioQueue->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }

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

void EncodeGUI::audioFinished() {
    setAudioInfo();

    if (AudioInfo::totalStreams() == 0) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The selected source does not contain any audio files."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _ui->AudioSourceTxtBox->setText(QString());
    }
    else
        msgBoxHelper(MessageType::Info, QString("Extracted info"), QString("Successfully loaded the audio from source."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);

    connect(_ui->AudioTrackDD, SIGNAL(currentIndexChanged(int)), this, SLOT(audioTrack()));
}

void EncodeGUI::setAudioInfo() {
    if (AudioInfo::totalStreams() > 0) {
        SET_ENABLED(_ui->AudioTrackDD);

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

        if (CHECKED(_ui->BatchCB))
            SET_DISABLED(_ui->AudioCB);

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