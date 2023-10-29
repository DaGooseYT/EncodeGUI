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

#include "updater.hpp"

Update::Update(QWidget* parent) : QDialog(parent) {
	_up = new Ui::Updater();
	_up->setupUi(this);
}

void Update::setText(QString text) {
	_up->textBrowser->insertPlainText(text + QString("\n"));
}

QPushButton *Update::getSkip() {
	return(_up->SkipBttn);
}

QPushButton *Update::getNow() {
	return(_up->UpdateBttn);
}

QPushButton *Update::getLater() {
	return(_up->RemindBttn);
}

Ui::Updater *Update::getUpdate() {
	return(_up);
}