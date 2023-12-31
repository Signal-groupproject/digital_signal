//
// Created by luokon on 2023/12/31.
//

#include <QMainWindow>
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
        delete this;
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

    // 将QPixmap转换为QImage
    QImage qImage = croppedPixmap.toImage();
    // 将QImage转换为cv::Mat
    cv::Mat mat(qImage.height(), qImage.width(), CV_8UC4, qImage.bits(), qImage.bytesPerLine());
    cv::cvtColor(mat, mat, cv::COLOR_RGBA2RGB);
    // 当裁剪操作完成后，触发信号并传递 result 的值给父类对象
    emit cropResultAvailable(mat);
}

