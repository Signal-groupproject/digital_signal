#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#define test std::cout<<"This is a test"

using namespace cv;
Mat image;//保存图片之后，内容重新覆盖一次

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow) {
    ui->setupUi(this);
    imageLabel = new QLabel;
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

}

mainwindow::~mainwindow() {
    delete ui;
}

//图片缩放和居中
QImage mainwindow::Image_Processing(const QImage& qimage, QLabel* qLabel)
{
    QSize imageSize = qimage.size();
    QSize labelSize = qLabel->size();
    QImage image;

    double dWidthRatio = static_cast<double>(imageSize.width()) / labelSize.width();
    double dHeightRatio = static_cast<double>(imageSize.height()) / labelSize.height();

    if (dWidthRatio > dHeightRatio)
    {
        int newHeight = static_cast<int>(imageSize.height() / dWidthRatio);
        image = qimage.scaled(labelSize.width(), newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
    else
    {
        int newWidth = static_cast<int>(imageSize.width() / dHeightRatio);
        image = qimage.scaled(newWidth, labelSize.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    int xOffset = (labelSize.width() - image.width()) / 2;
    int yOffset = (labelSize.height() - image.height()) / 2;

    QImage processed_image(labelSize, QImage::Format_ARGB32);
    processed_image.fill(Qt::transparent);

    QPainter painter(&processed_image);
    painter.drawImage(QPoint(xOffset, yOffset), image);

    return processed_image;
}

//图像对比
void mainwindow::on_Contrast_clicked() {

}

//加载图片
void mainwindow::on_Load_Image_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"), "D:/", tr("Images (*.png *.jpg *.bmp *.tif)"));

    if (filePath.isEmpty()) {
        return;
    }
    image = imread(filePath.toStdString());

    if (image.empty()) {
        return;
    }

    QImage original_image(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(original_image, imageLabel);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}

//裁剪图片
void mainwindow::on_Crop_Image_clicked() {
    if (image.empty()) {
        return;
    }

    // 提示用户选择裁剪区域
    Rect cropRect = selectCropRegion(image);

    // 检查是否选择了有效的裁剪区域
    if (cropRect.width > 0 && cropRect.height > 0) {
        // 执行裁剪
        Mat croppedImage = image(cropRect).clone();

        // 显示裁剪后的图片
        QImage croppedQImage(croppedImage.data, croppedImage.cols, croppedImage.rows, croppedImage.step, QImage::Format_BGR888);
        QImage processedImage = Image_Processing(croppedQImage, imageLabel);
        ui->label_show->setPixmap(QPixmap::fromImage(processedImage));
    }
}

Rect mainwindow::selectCropRegion(const Mat& image) {
    // 使用OpenCV的selectROI函数获取用户选择的矩形区域
    Rect cropRect = selectROI("Select Crop Region", image);

    // 关闭OpenCV的选择框
    destroyAllWindows();

    return cropRect;
}