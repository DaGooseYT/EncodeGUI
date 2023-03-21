#include "../../include/updater.hpp"

Update::Update(QWidget* parent) : QDialog(parent) {
	up.setupUi(this);
}

void Update::SetText(QString text) {
	up.textBrowser->insertPlainText(text + "\n");
}

QPushButton* Update::GetSkip() {
	return up.SkipBttn;
}

QPushButton* Update::GetNow() {
	return up.UpdateBttn;
}

QPushButton* Update::GetLater() {
	return up.RemindBttn;
}