#pragma once

#ifndef PREVIEW_H
#define PREVIEW_H

#include <QDialog>

#ifdef Q_OS_WINDOWS
#include "windows/ui_preview.hpp"
#endif
#ifdef Q_OS_DARWIN
#include "darwin/ui_preview.hpp"
#endif

class Preview : public QDialog {
public:
	Preview(QWidget *parent = Q_NULLPTR);
	void setPicture(QString path);
	void setScaled(bool scale);

private:
	Ui::PreviewWindow _pw;
};

#endif // !PREVIEW_H
