#include "preview.hpp"

Preview::Preview(QWidget *parent) : QDialog(parent) {
	_pw.setupUi(this);
}

void Preview::setPicture(QString path) {
	if (!path.contains(QString(":/EncodeGUI")))
		_pw.PreviewPix->setPixmap(QPixmap(path).scaled(426, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	else
		_pw.PreviewPix->setPixmap(QPixmap(path));
	
	_pw.PreviewPix->setAlignment(Qt::AlignCenter);
}

void Preview::setScaled(bool scale) {
	_pw.PreviewPix->setScaledContents(scale);
}