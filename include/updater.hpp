#pragma once

#ifndef UPDATER
#define UPDATER

#include <QtWidgets/QPushButton>
#include <QDialog>

#ifdef Q_OS_WINDOWS
#include "windows/ui_updater.hpp"
#endif
#ifdef Q_OS_DARWIN
#include "darwin/ui_updater.hpp"
#endif

class Update : public QDialog {
public:
	Update(QWidget *parent = Q_NULLPTR);
	void setText(QString);

	Ui::Updater *getUpdate();
	QPushButton *getSkip();
	QPushButton *getNow();
	QPushButton *getLater();

private:
	Ui::Updater *_up;
};

#endif // !UPDATER