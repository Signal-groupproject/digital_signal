//
// Created by luokon on 2023/12/31.
//

#ifndef QT_DEMO_COPPER_H
#define QT_DEMO_COPPER_H

#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QMouseEvent>
#include <QPainter>
#include <opencv2/opencv.hpp>

class ImageLabel : public QLabel
{
Q_OBJECT

public:
    ImageLabel(QWidget* parent = nullptr);

    void setImage(const QPixmap& pixmap);
    cv::Mat result;

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    QPixmap originalPixmap;
    bool isMousePressed;
    QPoint startPoint;
    QPoint endPoint;

    void performCrop();
};

#endif //QT_DEMO_COPPER_H
