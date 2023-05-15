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