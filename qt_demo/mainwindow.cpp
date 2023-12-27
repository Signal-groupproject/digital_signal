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
    // 读取图像
    Mat image = imread("D:\\lean.tif");

    // 将OpenCV的Mat转换为Qt的QImage
    QImage qImage(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);

    // 将QImage转换为QPixmap
    QPixmap pixmap = QPixmap::fromImage(qImage);

    // 设置label的 pixmap
    imageLabel->setPixmap(pixmap);

    // 调整label的大小以适应图像
    imageLabel->setFixedSize(pixmap.size());
}