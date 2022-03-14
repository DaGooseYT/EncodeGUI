#include "EncodeGUI.h"

QMessageBox::StandardButton EncodeGUI::MsgBoxHelper(MessageType type, QString title, QString message, QMessageBox::StandardButton button1, QMessageBox::StandardButton button2, QMessageBox::StandardButton button3) {
	QMessageBox::StandardButton msg;
	
	switch (type) {
	case ERROR:
		msg = QMessageBox::critical(this, title, message, button1 | button2 | button3);
		break;
	case WARNING:
		msg = QMessageBox::warning(this, title, message, button1 | button2 | button3);
		break;
	case INFO:
		msg = QMessageBox::information(this, title, message, button1 | button2 | button3);
		break;
	case QUESTION:
		msg = QMessageBox::question(this, title, message, button1 | button2 | button3);
		break;
	}
	
	return msg;
}