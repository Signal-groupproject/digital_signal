#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
using namespace cv;

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);
    imageLabel = new QLabel;
    ui->scrollArea->setWidget(imageLabel);
}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::on_select_Image_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open Image"), "", tr("Images (*.png *.jpg *.bmp *.tif)"));

    if (filePath.isEmpty()) {
        return;
    }
    Mat image = imread(filePath.toStdString());

    if (image.empty()) {
        return;
    }


    QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);

    QPixmap pixmap = QPixmap::fromImage(qImage);

    imageLabel->setPixmap(pixmap);

    imageLabel->setFixedSize(pixmap.size());
}