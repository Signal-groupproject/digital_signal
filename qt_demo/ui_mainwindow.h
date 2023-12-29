/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QPushButton *select_Image;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(1131, 723);
        select_Image = new QPushButton(mainwindow);
        select_Image->setObjectName("select_Image");
        select_Image->setGeometry(QRect(40, 150, 121, 51));
        select_Image->setCheckable(false);
        scrollArea = new QScrollArea(mainwindow);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(220, 150, 711, 381));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 709, 379));
        scrollArea->setWidget(scrollAreaWidgetContents);
        pushButton_2 = new QPushButton(mainwindow);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(40, 270, 121, 51));
        pushButton_2->setCheckable(false);
        pushButton_3 = new QPushButton(mainwindow);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(40, 210, 121, 51));
        pushButton_3->setCheckable(false);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "mainwindow", nullptr));
        select_Image->setText(QCoreApplication::translate("mainwindow", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mainwindow", "\350\243\201\345\211\252", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mainwindow", "\346\230\276\347\244\272\345\216\237\345\233\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
