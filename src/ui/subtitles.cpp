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

void EncodeGUI::hideSubtitle() {
    if (CHECKED(_ui->SubtitlesCB)) {
        if (!CHECKED(_ui->BatchCB)) {
            SET_ENABLED(_ui->SubtitlesDD);
            hideSubtitleTab();
        }
    }
    else {
        SET_DISABLED(_ui->SubtitlesDD);
        _ui->Tabs->removeTab(_ui->Tabs->indexOf(_ui->SubtitlesTab));
    }
}

void EncodeGUI::removeSubtitle() {
    _ui->SubtitleQueue->setRowCount(0);

    _isEncodingSub->clear();
    _subtitleCodec->clear();
    _streamSub.clear();
    _isTitleSub->clear();
    _titleSub->clear();
    _isLangSub->clear();
    _subtitleLangs->clear();
    _subtitleInputs->clear();
    _subtitleStream->clear();
}

void EncodeGUI::subtitleTitle() {
    if (CHECKED(_ui->SubtitleTitleCB))
        SET_ENABLED(_ui->SubtitleTitleTxtBox);
    else
        SET_DISABLED(_ui->SubtitleTitleTxtBox);
}

void EncodeGUI::subtitleLang() {
    if (CHECKED(_ui->SubtitleLangCB))
        SET_ENABLED(_ui->SubtitleLangDD);
    else
        SET_DISABLED(_ui->SubtitleLangDD);
}

void EncodeGUI::subtitleClick() {
    if (!_ui->SelectedSubtitleDD->currentText().isEmpty())
        msgBoxHelper(MessageType::Info, QString("Subtitle info"), QString("Subtitle info from stream %1\n").arg(SubtitleInfo::getStream(_ui->SelectedSubtitleDD->currentIndex())) + QString("Codec: %1\n").arg(SubtitleInfo::getCodec(_ui->SelectedSubtitleDD->currentIndex())) + QString("Language: %1").arg(SubtitleInfo::getLanguage(_ui->SelectedSubtitleDD->currentIndex())), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
    else
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("Please import a subtitle stream first."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void EncodeGUI::subtitleFinished() {
    setSubtitleInfo();

    if (AudioInfo::totalStreams() == 0) {
        msgBoxHelper(MessageType::Error, QString("EncodeGUI error"), QString("The selected source does not contain any subtitles."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
        _ui->SubSourceTxtBox->setText(QString());
    }
    else
        msgBoxHelper(MessageType::Info, QString("Extracted info"), QString("Successfully loaded the subtitles from source."), QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton);
}

void EncodeGUI::setSubtitleInfo() {
    if (SubtitleInfo::totalStreams() != 0) {
        FOR_EACH(SubtitleInfo::totalStreams()) {
            if (SubtitleInfo::getLanguage(i).contains(QString("?")))
                _ui->SelectedSubtitleDD->addItem(QString("T%1 - (%2)").arg(i + 1).arg(QString("UND")));
            else
                _ui->SelectedSubtitleDD->addItem(QString("T%1 - (%2)").arg(i + 1).arg(SubtitleInfo::getLanguage(i)));
        }
    }
}

void EncodeGUI::removeSubtitleClick() {
    _ui->SubtitleQueue->removeRow(_selectedSubtitle);

    int input = _subtitleStream->at(_selectedSubtitle).toInt();
    int index = 0;

    _isEncodingSub->removeAt(_selectedSubtitle);
    _subtitleCodec->removeAt(_selectedSubtitle);
    _isTitleSub->removeAt(_selectedSubtitle);
    _titleSub->removeAt(_selectedSubtitle);
    _isLangSub->removeAt(_selectedSubtitle);
    _subtitleLangs->removeAt(_selectedSubtitle);
    _subtitleStream->removeAt(_selectedSubtitle);

    [&] {
        for (int i = 0; i < _streamSub.count(); i++)
            for (int j = 0; j < _streamSub.at(i).toStringList().count(); j++) {
                if (index == _selectedSubtitle) {
                    if (_streamSub.at(i).toStringList().count() > 1) {
                        QStringList newStream(_streamSub.at(i).toStringList());
                        newStream.removeAt(j);
                        _streamSub.replace(i, newStream);
                    }
                    else if (_streamSub.at(i).toStringList().count() == 1) {
                        _streamSub.removeAt(i);
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
    if (!_subtitleStream->contains(QString("%1").arg(input)))
        _subtitleInputs->removeAt(input - 1);

    for (int i = 0; i < _streamSub.count(); i++)
        if (_subtitleStream->at(i).toInt() > _streamSub.count())
            _subtitleStream->replace(i, QString("%1").arg(_streamSub.count()));

    index = 0;

    for (int i = 0; i < _stream.count(); i++)
        for (int j = 0; j < _stream.at(i).toStringList().count(); j++) {
            if (_audioStream->at(index).toInt() > _streamInputs->count())
                _audioStream->replace(index, QString("%1").arg(_streamInputs->count()));

            index++;
        }

    for (int i = 0; i < _ui->SubtitleQueue->rowCount(); i++) {
        _ui->SubtitleQueue->setItem(i, 0, new QTableWidgetItem(_ui->SubtitleQueue->item(i, 0)->text().replace(_ui->SubtitleQueue->item(i, 0)->text().at(_ui->SubtitleQueue->item(i, 0)->text().indexOf(QRegularExpression("[1-8]"))), QString("%1").arg(i + 1))));
        _ui->SubtitleQueue->item(i, 0)->setTextAlignment(Qt::AlignCenter);
    }

    delete(sender());
}

void EncodeGUI::hideSubtitleTab() {
    if (_ui->SubtitlesDD->currentIndex() == 0 || _ui->SubtitlesDD->currentIndex() == 1)
        _ui->Tabs->removeTab(_ui->Tabs->indexOf(_ui->SubtitlesTab));
    else
        if (_ui->Tabs->indexOf(_ui->VideoTab) == 1) {
            if (_ui->Tabs->indexOf(_ui->AudioTab) == 2)
                _ui->Tabs->insertTab(3, _ui->SubtitlesTab, QString("Subtitles"));
            else
                _ui->Tabs->insertTab(2, _ui->SubtitlesTab, QString("Subtitles"));
        }
        else {
            if (_ui->Tabs->indexOf(_ui->AudioTab) == 1)
                _ui->Tabs->insertTab(2, _ui->SubtitlesTab, QString("Subtitles"));
            else
                _ui->Tabs->insertTab(1, _ui->SubtitlesTab, QString("Subtitles"));
        }  
}