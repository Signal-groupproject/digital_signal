//
// Created by luokon on 2023/12/31.
//

#include "copper.h"

ImageLabel::ImageLabel(QWidget* parent)
        : QLabel(parent), isMousePressed(false)
{
}

void ImageLabel::setImage(const QPixmap& pixmap)
{
    originalPixmap = pixmap;
    setPixmap(originalPixmap);
}

void ImageLabel::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        isMousePressed = true;
        startPoint = event->pos();
    }
}

void ImageLabel::mouseMoveEvent(QMouseEvent* event)
{
    if (isMousePressed) {
        endPoint = event->pos();
        update(); // 重新绘制窗口以实时显示用户选择的裁剪区域
    }
}

void ImageLabel::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && isMousePressed) {
        isMousePressed = false;
        endPoint = event->pos();
        update(); // 重新绘制窗口以显示最终的裁剪区域

        performCrop(); // 执行裁剪操作

//        close(); // 关闭窗口
    }
}

void ImageLabel::paintEvent(QPaintEvent* event)
{
    QLabel::paintEvent(event);

    if (isMousePressed) {
        QPainter painter(this);
        painter.setPen(QColor(0, 0, 255));
        painter.drawRect(QRect(startPoint, endPoint));
    }
}

void ImageLabel::performCrop()
{
    int x = std::min(startPoint.x(), endPoint.x());
    int y = std::min(startPoint.y(), endPoint.y());
    int width = std::abs(startPoint.x() - endPoint.x());
    int height = std::abs(startPoint.y() - endPoint.y());

    QRect rect(x, y, width, height);
    QPixmap croppedPixmap = originalPixmap.copy(rect);

    QImage image = croppedPixmap.toImage().convertToFormat(QImage::Format_RGB888);
    cv::Mat mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine());
    cv::cvtColor(mat, mat, cv::COLOR_RGB2BGR); // 将颜色通道顺序从RGB转换为BGR
    result = mat;
    QLabel* croppedLabel = new QLabel(this);
    croppedLabel->setPixmap(croppedPixmap);
    croppedLabel->show();
}

