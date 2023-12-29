#ifndef QT_DEMO_MAINWINDOW_H
#define QT_DEMO_MAINWINDOW_H

#include <QWidget>
#include<QLabel>
#include<QScrollArea>
#include<QScrollBar>
#include<QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    QScrollArea *scrollArea;
    QLabel *imageLabel;
    Ui::mainwindow *ui;

private slots:
    void on_select_Image_clicked();
};

#endif //QT_DEMO_MAINWINDOW_H
