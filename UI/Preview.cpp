#include "Preview.h"

Preview::Preview(QWidget* parent) : QDialog(parent) {
	pw.setupUi(this);
}

void Preview::SetPicture(QString path) {
	if (!path.contains(":/EncodeGUI"))
		pw.PreviewPix->setPixmap(QPixmap(path).scaled(426, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation));
	else
		pw.PreviewPix->setPixmap(QPixmap(path));
	
	pw.PreviewPix->setAlignment(Qt::AlignCenter);
}

void Preview::SetScaled(bool scale) {
	pw.PreviewPix->setScaledContents(scale);
}