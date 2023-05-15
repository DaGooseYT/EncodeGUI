#pragma once

#ifndef UPDATER
#define UPDATER

#include <QtWidgets/QPushButton>
#include <QDialog>

#include "windows/ui_updater.hpp"

class Update : public QDialog {
public:
	Update(QWidget* parent = Q_NULLPTR);
	void setText(QString);

	Ui::Updater *getUpdate();
	QPushButton *getSkip();
	QPushButton *getNow();
	QPushButton *getLater();

private:
	Ui::Updater *_up;
};

#endif // !UPDATER