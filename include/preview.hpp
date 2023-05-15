#pragma once

#ifndef PREVIEW_H
#define PREVIEW_H

#include <QDialog>

#include "windows/ui_preview.hpp"

class Preview : public QDialog {
public:
	Preview(QWidget *parent = Q_NULLPTR);
	void setPicture(QString path);
	void setScaled(bool scale);

private:
	Ui::PreviewWindow _pw;
};

#endif // !PREVIEW_H
