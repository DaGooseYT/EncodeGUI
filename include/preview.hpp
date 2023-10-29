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

#pragma once

#ifndef PREVIEW_H
#define PREVIEW_H

#include <QtWidgets/QDialog>

#ifdef Q_OS_WINDOWS
#include "windows/ui_preview.hpp"
#endif
#ifdef Q_OS_DARWIN
#include "darwin/ui_preview.hpp"
#endif

class Preview : public QDialog {
public:
	Preview(QWidget *parent = Q_NULLPTR);
	void setPicture(QString path);
	void setScaled(bool scale);

private:
	Ui::PreviewWindow _pw;
};

#endif // !PREVIEW_H
