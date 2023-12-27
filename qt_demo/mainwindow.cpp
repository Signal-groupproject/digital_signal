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

void mainwindow::on_pushButton_clicked()
{
    Mat image = imread("D:\\lean.tif");

    QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);

    QPixmap pixmap = QPixmap::fromImage(qImage);

    imageLabel->setPixmap(pixmap);

    imageLabel->setFixedSize(pixmap.size());
}