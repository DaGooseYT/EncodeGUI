/****************************************************************************
 * Copyright (C) 2022 DaGoose
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ****************************************************************************/

#ifndef UPDATERUFEOXN_H
#define UPDATERUFEOXN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Updater
{
public:
    QLabel *TitleLabel;
    QLabel *ToDoLabel;
    QPushButton *UpdateBttn;
    QPushButton *RemindBttn;
    QPushButton *SkipBttn;
    QTextBrowser *textBrowser;
    QLabel *DetailsLabel;

    void setupUi(QWidget *Updater)
    {
        if (Updater->objectName().isEmpty())
            Updater->setObjectName(QString::fromUtf8("Updater"));
        Updater->resize(550, 294);
        Updater->setMinimumSize(QSize(550, 294));
        Updater->setMaximumSize(QSize(550, 294));
        TitleLabel = new QLabel(Updater);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));
        TitleLabel->setGeometry(QRect(200, 7, 150, 32));
        TitleLabel->setAlignment(Qt::AlignCenter);
        ToDoLabel = new QLabel(Updater);
        ToDoLabel->setObjectName(QString::fromUtf8("ToDoLabel"));
        ToDoLabel->setGeometry(QRect(7, 264, 111, 16));
        UpdateBttn = new QPushButton(Updater);
        UpdateBttn->setObjectName(QString::fromUtf8("UpdateBttn"));
        UpdateBttn->setGeometry(QRect(200, 259, 95, 32));
        UpdateBttn->setMinimumSize(QSize(0, 32));
        UpdateBttn->setSizeIncrement(QSize(0, 32));
        QFont font;
        font.setBold(true);
        UpdateBttn->setFont(font);
        UpdateBttn->setFocusPolicy(Qt::NoFocus);
        RemindBttn = new QPushButton(Updater);
        RemindBttn->setObjectName(QString::fromUtf8("RemindBttn"));
        RemindBttn->setGeometry(QRect(300, 259, 120, 32));
        RemindBttn->setMinimumSize(QSize(0, 32));
        RemindBttn->setSizeIncrement(QSize(0, 32));
        RemindBttn->setFocusPolicy(Qt::NoFocus);
        SkipBttn = new QPushButton(Updater);
        SkipBttn->setObjectName(QString::fromUtf8("SkipBttn"));
        SkipBttn->setGeometry(QRect(425, 259, 118, 32));
        SkipBttn->setMinimumSize(QSize(0, 32));
        SkipBttn->setSizeIncrement(QSize(0, 32));
        SkipBttn->setFocusPolicy(Qt::NoFocus);
        textBrowser = new QTextBrowser(Updater);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(7, 63, 536, 192));
        DetailsLabel = new QLabel(Updater);
        DetailsLabel->setObjectName(QString::fromUtf8("DetailsLabel"));
        DetailsLabel->setGeometry(QRect(95, 38, 360, 20));
        DetailsLabel->setAlignment(Qt::AlignCenter);

        retranslateUi(Updater);

        QMetaObject::connectSlotsByName(Updater);
    } // setupUi

    void retranslateUi(QWidget *Updater)
    {
        Updater->setWindowTitle(QCoreApplication::translate("Updater", "FrameGUI - Updates", nullptr));
        TitleLabel->setText(QCoreApplication::translate("Updater", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">It's Time to Update!</span></p></body></html>", nullptr));
        ToDoLabel->setText(QCoreApplication::translate("Updater", "Choose an action:", nullptr));
        UpdateBttn->setText(QCoreApplication::translate("Updater", "Update Now", nullptr));
        RemindBttn->setText(QCoreApplication::translate("Updater", "Remind Me Later", nullptr));
        SkipBttn->setText(QCoreApplication::translate("Updater", "Skip This Update", nullptr));
        DetailsLabel->setText(QCoreApplication::translate("Updater", "Below are the details for the next new update for EncodeGUI", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Updater: public Ui_Updater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UPDATERUFEOXN_H