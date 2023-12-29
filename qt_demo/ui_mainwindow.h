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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainwindow
{
public:
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QPushButton *Load_Image;
    QPushButton *Crop_Image;
    QSlider *horizontalSlider;
    QLabel *angle;
    QLabel *label_2;
    QPushButton *pushButton1;
    QPushButton *pushButton2;
    QPushButton *pushButton3;
    QPushButton *pushButton4;
    QWidget *widget;
    QPushButton *Contrast;
    QLabel *label_show;
    QPushButton *Withdraw;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(1131, 752);
        dockWidget = new QDockWidget(mainwindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setGeometry(QRect(0, 0, 181, 751));
        dockWidget->setMinimumSize(QSize(172, 111));
        dockWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName("dockWidgetContents");
        Load_Image = new QPushButton(dockWidgetContents);
        Load_Image->setObjectName("Load_Image");
        Load_Image->setGeometry(QRect(0, 10, 181, 31));
        Load_Image->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        Load_Image->setCheckable(false);
        Crop_Image = new QPushButton(dockWidgetContents);
        Crop_Image->setObjectName("Crop_Image");
        Crop_Image->setGeometry(QRect(0, 50, 181, 31));
        Crop_Image->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        Crop_Image->setCheckable(false);
        horizontalSlider = new QSlider(dockWidgetContents);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 120, 161, 22));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"\n"
"}\n"
"\n"
"QSlider::groove:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 10px;\n"
"}\n"
"\n"
"QSlider::handle:Horizontal {\n"
"    width: 8px;\n"
"    margin: -4 0px;\n"
"    background: qradialgradient(cx:0, cy:0, radius:1, fx:0.5, fy:0.5, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        horizontalSlider->setMinimum(-45);
        horizontalSlider->setMaximum(45);
        horizontalSlider->setOrientation(Qt::Horizontal);
        angle = new QLabel(dockWidgetContents);
        angle->setObjectName("angle");
        angle->setGeometry(QRect(70, 90, 61, 16));
        angle->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"}\n"
""));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 54, 16));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"}\n"
""));
        pushButton1 = new QPushButton(dockWidgetContents);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(10, 170, 75, 71));
        pushButton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        pushButton2 = new QPushButton(dockWidgetContents);
        pushButton2->setObjectName("pushButton2");
        pushButton2->setGeometry(QRect(100, 170, 75, 71));
        pushButton2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        pushButton3 = new QPushButton(dockWidgetContents);
        pushButton3->setObjectName("pushButton3");
        pushButton3->setGeometry(QRect(10, 260, 75, 71));
        pushButton3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        pushButton4 = new QPushButton(dockWidgetContents);
        pushButton4->setObjectName("pushButton4");
        pushButton4->setGeometry(QRect(100, 260, 75, 71));
        pushButton4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        dockWidget->setWidget(dockWidgetContents);
        widget = new QWidget(mainwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 0, 771, 751));
        Contrast = new QPushButton(widget);
        Contrast->setObjectName("Contrast");
        Contrast->setGeometry(QRect(690, 420, 31, 31));
        Contrast->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        label_show = new QLabel(widget);
        label_show->setObjectName("label_show");
        label_show->setGeometry(QRect(80, 50, 611, 401));
        label_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
" border: 2px solid qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"}"));
        label_show->setFrameShape(QFrame::WinPanel);
        label_show->setLineWidth(1);
        Withdraw = new QPushButton(widget);
        Withdraw->setObjectName("Withdraw");
        Withdraw->setGeometry(QRect(690, 380, 31, 31));
        Withdraw->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton:hover,\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
"\n"
"QPushButton:pressed,\n"
"QPushButton:checked {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"}\n"
""));
        dockWidget_2 = new QDockWidget(mainwindow);
        dockWidget_2->setObjectName("dockWidget_2");
        dockWidget_2->setGeometry(QRect(950, 0, 181, 751));
        dockWidget_2->setMinimumSize(QSize(172, 111));
        dockWidget_2->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 100);"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName("dockWidgetContents_2");
        dockWidget_2->setWidget(dockWidgetContents_2);

        retranslateUi(mainwindow);

        QMetaObject::connectSlotsByName(mainwindow);
    } // setupUi

    void retranslateUi(QWidget *mainwindow)
    {
        mainwindow->setWindowTitle(QCoreApplication::translate("mainwindow", "mainwindow", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("mainwindow", "\345\267\245\345\205\267\347\256\261", nullptr));
        Load_Image->setText(QCoreApplication::translate("mainwindow", "\345\212\240\350\275\275\345\233\276\347\211\207", nullptr));
        Crop_Image->setText(QCoreApplication::translate("mainwindow", "\350\243\201\345\211\252", nullptr));
        angle->setText(QString());
        label_2->setText(QCoreApplication::translate("mainwindow", "\346\227\213\350\275\254\350\247\222\345\272\246\357\274\232", nullptr));
        pushButton1->setText(QString());
        pushButton2->setText(QString());
        pushButton3->setText(QString());
        pushButton4->setText(QString());
        Contrast->setText(QString());
        label_show->setText(QString());
        Withdraw->setText(QString());
        dockWidget_2->setWindowTitle(QCoreApplication::translate("mainwindow", "\345\237\272\346\234\254\350\260\203\346\225\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
