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

QMessageBox::StandardButton EncodeGUI::msgBoxHelper(MessageType type, QString title, QString message, QMessageBox::StandardButton button1, QMessageBox::StandardButton button2, QMessageBox::StandardButton button3) {
	QMessageBox::StandardButton msg;
	
	switch (type) {
	case MessageType::Error:
		msg = QMessageBox::critical(this, title, message, button1 | button2 | button3);
		break;
	case MessageType::Warning:
		msg = QMessageBox::warning(this, title, message, button1 | button2 | button3);
		break;
	case MessageType::Info:
		msg = QMessageBox::information(this, title, message, button1 | button2 | button3);
		break;
	case MessageType::Question:
		msg = QMessageBox::question(this, title, message, button1 | button2 | button3);
		break;
	}
	
	return(msg);
}