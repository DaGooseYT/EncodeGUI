#pragma once

#ifndef PREVIEW_H
#define PREVIEW_H

#include "../x64/Release/uic/ui_preview.h"
#include <QDialog>

class Preview : public QDialog {
public:
	Preview(QWidget* parent = Q_NULLPTR);
	void SetPicture(QString);
	void SetScaled(bool);

private:
	Ui::PreviewWindow pw;
};

#endif // !PREVIEW_H
