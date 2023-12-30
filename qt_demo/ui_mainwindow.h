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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
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
    QPushButton *Equalize;
    QWidget *widget;
    QPushButton *Contrast;
    QLabel *label_show;
    QPushButton *Withdraw;
    QPushButton *Save_Image;
    QCheckBox *checkBox;
    QPushButton *Remake;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *angle_2;
    QLabel *label_3;
    QSlider *light_perception;
    QLabel *label_5;
    QSlider *exposure;
    QLabel *angle_4;
    QLabel *label_6;
    QSlider *contrast_ratio;
    QLabel *angle_5;
    QLabel *label_7;
    QSlider *sharpening;
    QLabel *angle_6;
    QLabel *label_8;
    QSlider *color_temperature;
    QLabel *angle_7;
    QLabel *label_9;
    QSlider *tone;
    QLabel *angle_8;
    QWidget *tab_2;

    void setupUi(QWidget *mainwindow)
    {
        if (mainwindow->objectName().isEmpty())
            mainwindow->setObjectName("mainwindow");
        mainwindow->resize(1133, 752);
        dockWidget = new QDockWidget(mainwindow);
        dockWidget->setObjectName("dockWidget");
        dockWidget->setGeometry(QRect(0, 0, 181, 751));
        dockWidget->setMinimumSize(QSize(172, 111));
        dockWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
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
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 90, 54, 16));
        label_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        pushButton1 = new QPushButton(dockWidgetContents);
        pushButton1->setObjectName("pushButton1");
        pushButton1->setGeometry(QRect(10, 170, 71, 71));
        pushButton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: #FFFFFF;\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    border-radius: 20px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"	image:url(:/1.png)\n"
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
        pushButton1->setIconSize(QSize(32, 32));
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
"    image:url(:/2.png)\n"
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
"	image:url(:/X.svg)\n"
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
"	image:url(:/Y.svg)\n"
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
        Equalize = new QPushButton(dockWidgetContents);
        Equalize->setObjectName("Equalize");
        Equalize->setGeometry(QRect(0, 350, 181, 31));
        Equalize->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Equalize->setCheckable(false);
        dockWidget->setWidget(dockWidgetContents);
        widget = new QWidget(mainwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 0, 771, 751));
        Contrast = new QPushButton(widget);
        Contrast->setObjectName("Contrast");
        Contrast->setGeometry(QRect(670, 420, 31, 31));
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
        label_show->setGeometry(QRect(60, 50, 611, 401));
        label_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
" border: 2px solid qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1,stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"}"));
        label_show->setFrameShape(QFrame::WinPanel);
        label_show->setLineWidth(1);
        Withdraw = new QPushButton(widget);
        Withdraw->setObjectName("Withdraw");
        Withdraw->setGeometry(QRect(560, 470, 31, 31));
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
        Save_Image = new QPushButton(widget);
        Save_Image->setObjectName("Save_Image");
        Save_Image->setGeometry(QRect(250, 480, 111, 31));
        Save_Image->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        Save_Image->setCheckable(false);
        checkBox = new QCheckBox(widget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(400, 490, 79, 20));
        Remake = new QPushButton(widget);
        Remake->setObjectName("Remake");
        Remake->setGeometry(QRect(610, 470, 31, 31));
        Remake->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        tabWidget = new QTabWidget(mainwindow);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(950, 0, 181, 761));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 0);"));
        tab = new QWidget();
        tab->setObjectName("tab");
        angle_2 = new QLabel(tab);
        angle_2->setObjectName("angle_2");
        angle_2->setGeometry(QRect(70, 0, 61, 16));
        angle_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 0, 54, 16));
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        light_perception = new QSlider(tab);
        light_perception->setObjectName("light_perception");
        light_perception->setGeometry(QRect(10, 30, 161, 22));
        light_perception->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
        light_perception->setMinimum(-100);
        light_perception->setMaximum(100);
        light_perception->setOrientation(Qt::Horizontal);
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 60, 54, 16));
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        exposure = new QSlider(tab);
        exposure->setObjectName("exposure");
        exposure->setGeometry(QRect(10, 90, 161, 22));
        exposure->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
        exposure->setMinimum(-100);
        exposure->setMaximum(100);
        exposure->setOrientation(Qt::Horizontal);
        angle_4 = new QLabel(tab);
        angle_4->setObjectName("angle_4");
        angle_4->setGeometry(QRect(70, 60, 61, 16));
        angle_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        label_6 = new QLabel(tab);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(10, 120, 71, 16));
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        contrast_ratio = new QSlider(tab);
        contrast_ratio->setObjectName("contrast_ratio");
        contrast_ratio->setGeometry(QRect(10, 150, 161, 22));
        contrast_ratio->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
        contrast_ratio->setMinimum(-100);
        contrast_ratio->setMaximum(100);
        contrast_ratio->setOrientation(Qt::Horizontal);
        angle_5 = new QLabel(tab);
        angle_5->setObjectName("angle_5");
        angle_5->setGeometry(QRect(80, 120, 61, 16));
        angle_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        label_7 = new QLabel(tab);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 180, 54, 16));
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        sharpening = new QSlider(tab);
        sharpening->setObjectName("sharpening");
        sharpening->setGeometry(QRect(10, 210, 161, 22));
        sharpening->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
        sharpening->setMinimum(0);
        sharpening->setMaximum(100);
        sharpening->setOrientation(Qt::Horizontal);
        angle_6 = new QLabel(tab);
        angle_6->setObjectName("angle_6");
        angle_6->setGeometry(QRect(50, 180, 61, 16));
        angle_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        label_8 = new QLabel(tab);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 240, 54, 16));
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        color_temperature = new QSlider(tab);
        color_temperature->setObjectName("color_temperature");
        color_temperature->setGeometry(QRect(10, 270, 161, 22));
        color_temperature->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
        color_temperature->setMinimum(-100);
        color_temperature->setMaximum(100);
        color_temperature->setOrientation(Qt::Horizontal);
        angle_7 = new QLabel(tab);
        angle_7->setObjectName("angle_7");
        angle_7->setGeometry(QRect(70, 240, 61, 16));
        angle_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        label_9 = new QLabel(tab);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 310, 54, 16));
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        tone = new QSlider(tab);
        tone->setObjectName("tone");
        tone->setGeometry(QRect(10, 340, 161, 22));
        tone->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
"}\n"
"\n"
"QSlider::sub-page:Horizontal {\n"
"    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, stop:0 #ffd26f, stop:1 #3677ff);\n"
"    height: 4px;\n"
"	background-color:rgba(255,255,255,0);\n"
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
        tone->setMinimum(-100);
        tone->setMaximum(100);
        tone->setOrientation(Qt::Horizontal);
        angle_8 = new QLabel(tab);
        angle_8->setObjectName("angle_8");
        angle_8->setGeometry(QRect(70, 310, 61, 16));
        angle_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    color: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, stop: 0 #ffd26f, stop: 1 #3677ff);\n"
"background-color:rgba(255,255,255,0);\n"
"}\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());

        retranslateUi(mainwindow);

        tabWidget->setCurrentIndex(0);


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
        Equalize->setText(QCoreApplication::translate("mainwindow", "\347\233\264\346\226\271\345\233\276\345\235\207\350\241\241\345\214\226", nullptr));
        Contrast->setText(QString());
        label_show->setText(QString());
        Withdraw->setText(QString());
        Save_Image->setText(QCoreApplication::translate("mainwindow", "\344\277\235\345\255\230\345\233\276\347\211\207", nullptr));
        checkBox->setText(QCoreApplication::translate("mainwindow", "\346\260\264\345\215\260", nullptr));
        Remake->setText(QString());
        angle_2->setText(QString());
        label_3->setText(QCoreApplication::translate("mainwindow", "\345\205\211\346\204\237\350\260\203\346\225\264\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("mainwindow", "\346\233\235\345\205\211\350\260\203\346\225\264\357\274\232", nullptr));
        angle_4->setText(QString());
        label_6->setText(QCoreApplication::translate("mainwindow", "\345\257\271\346\257\224\345\272\246\350\260\203\346\225\264\357\274\232", nullptr));
        angle_5->setText(QString());
        label_7->setText(QCoreApplication::translate("mainwindow", "\351\224\220\345\214\226\357\274\232", nullptr));
        angle_6->setText(QString());
        label_8->setText(QCoreApplication::translate("mainwindow", "\350\211\262\346\270\251\357\274\232", nullptr));
        angle_7->setText(QString());
        label_9->setText(QCoreApplication::translate("mainwindow", "\350\211\262\350\260\203\357\274\232", nullptr));
        angle_8->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("mainwindow", "\345\237\272\347\241\200\350\260\203\346\225\2641", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("mainwindow", "\345\237\272\347\241\200\350\260\203\346\225\2642", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
