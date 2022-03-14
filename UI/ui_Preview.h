/********************************************************************************
** Form generated from reading UI file 'Preview.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEW_H
#define UI_PREVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PreviewWindow
{
public:
    QLabel *PreviewPix;

    void setupUi(QDialog *PreviewWindow)
    {
        if (PreviewWindow->objectName().isEmpty())
            PreviewWindow->setObjectName(QString::fromUtf8("PreviewWindow"));
        PreviewWindow->resize(436, 250);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PreviewWindow->sizePolicy().hasHeightForWidth());
        PreviewWindow->setSizePolicy(sizePolicy);
        PreviewWindow->setMinimumSize(QSize(436, 250));
        PreviewWindow->setMaximumSize(QSize(436, 250));
        PreviewPix = new QLabel(PreviewWindow);
        PreviewPix->setObjectName(QString::fromUtf8("PreviewPix"));
        PreviewPix->setGeometry(QRect(5, 5, 426, 240));
        PreviewPix->setMinimumSize(QSize(426, 240));
        PreviewPix->setMaximumSize(QSize(426, 240));
        PreviewPix->setTextFormat(Qt::RichText);
        PreviewPix->setPixmap(QPixmap(QString::fromUtf8(":/EncodeGUI/Preview.png")));
        PreviewPix->setScaledContents(true);
        PreviewPix->setAlignment(Qt::AlignCenter);
        PreviewPix->setWordWrap(false);

        retranslateUi(PreviewWindow);

        QMetaObject::connectSlotsByName(PreviewWindow);
    } // setupUi

    void retranslateUi(QDialog *PreviewWindow)
    {
        PreviewWindow->setWindowTitle(QCoreApplication::translate("PreviewWindow", "EncodeGUI - Live Encoding Preview", nullptr));
        PreviewPix->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class PreviewWindow: public Ui_PreviewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEW_H
