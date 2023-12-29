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
    QWidget *widget;
    QPushButton *Contrast;
    QLabel *label_show;
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
        Load_Image->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #2f3640;\n"
"    background-color: #f5f6fa;\n"
"    border-color: #2f3640;\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"}\n"
"\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"    color: #FFFFFF;\n"
"    background-color: #dcdde1;\n"
"    border-color: #dcdde1;\n"
"}\n"
""));
        Load_Image->setCheckable(false);
        Crop_Image = new QPushButton(dockWidgetContents);
        Crop_Image->setObjectName("Crop_Image");
        Crop_Image->setGeometry(QRect(0, 50, 181, 31));
        Crop_Image->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #2f3640;\n"
"    background-color: #f5f6fa;\n"
"    border-color: #2f3640;\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QPushButton::hover{\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"}\n"
"\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"}\n"
"\n"
"QPushButton::disabled{\n"
"    color: #FFFFFF;\n"
"    background-color: #dcdde1;\n"
"    border-color: #dcdde1;\n"
"}\n"
""));
        Crop_Image->setCheckable(false);
        horizontalSlider = new QSlider(dockWidgetContents);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 420, 160, 22));
        horizontalSlider->setStyleSheet(QString::fromUtf8("QSlider::add-page:Horizontal\n"
"                            {\n"
"                            background-color: rgb(223, 223, 223);\n"
"                            height:4px;\n"
"                            }\n"
"                            QSlider::sub-page:Horizontal\n"
"                            {\n"
"                            background-color:black;\n"
"                            height:4px;\n"
"                            }\n"
"                            QSlider::groove:Horizontal\n"
"                            {\n"
"                            background:transparent;\n"
"                            height:10px;\n"
"                            border-radius: 5px;\n"
"                            }\n"
"                            QSlider::handle:Horizontal\n"
"                            {\n"
"                            height: 20px;\n"
"                            width:20px;\n"
"                            margin: -8 0px;\n"
"                            }\n"
"                        "));
        horizontalSlider->setOrientation(Qt::Horizontal);
        dockWidget->setWidget(dockWidgetContents);
        widget = new QWidget(mainwindow);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(180, 0, 771, 751));
        Contrast = new QPushButton(widget);
        Contrast->setObjectName("Contrast");
        Contrast->setGeometry(QRect(690, 420, 31, 31));
        Contrast->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"    color: #2f3640;\n"
"    background-color: #f5f6fa;\n"
"    border-color: #2f3640;\n"
"    border-radius: 15px;\n"
"    border-style: solid;\n"
"    border-width: 2px;\n"
"    padding: 5px;\n"
"}\n"
"QPushButton::hover{\n"
"    color: #FFFFFF;\n"
"    background-color: #718093;\n"
"    border-color: #2f3640;\n"
"}\n"
"\n"
"QPushButton::pressed,QPushButton::checked{\n"
"    color: #FFFFFF;\n"
"    background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 #273c75, stop:1 #487eb0);\n"
"}"));
        label_show = new QLabel(widget);
        label_show->setObjectName("label_show");
        label_show->setGeometry(QRect(90, 50, 601, 401));
        label_show->setFrameShape(QFrame::WinPanel);
        label_show->setLineWidth(1);
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
        Contrast->setText(QString());
        label_show->setText(QString());
        dockWidget_2->setWindowTitle(QCoreApplication::translate("mainwindow", "\345\267\245\345\205\267\347\256\261", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainwindow: public Ui_mainwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
