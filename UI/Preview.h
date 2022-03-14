#pragma once

#ifndef PREVIEW_H
#define PREVIEW_H

#include "ui_Preview.h"

class Preview : public QDialog {
public:
	Preview(QWidget* parent = Q_NULLPTR);
	void SetPicture(QString);
	void SetScaled(bool);

private:
	Ui::PreviewWindow pw;
};

#endif // !PREVIEW_H
