#pragma once

#ifndef UPDATER
#define UPDATER

#include "ui_Updater.h"

#include <QtWidgets/QPushButton>
#include <QDialog>

class Update : public QDialog {
public:
	Update(QWidget* parent = Q_NULLPTR);
	void SetText(QString);

	QPushButton* GetSkip();
	QPushButton* GetNow();
	QPushButton* GetLater();

private:
	Ui::Updater up;
};

#endif // !UPDATER