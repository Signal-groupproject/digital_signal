#ifndef QT_DEMO_MAINWINDOW_H
#define QT_DEMO_MAINWINDOW_H

#include <QWidget>
#include<QLabel>
#include<QScrollArea>
#include<QScrollBar>
#include<QFileDialog>
#include<QPainter>
#include<opencv2/opencv.hpp>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    QLabel *imageLabel;
    Ui::mainwindow *ui;
    cv::Rect selectCropRegion(const cv::Mat& image);

private slots:
    QImage Image_Processing(const QImage& , QLabel*);
    void on_Contrast_clicked();//图像对比
    void on_Load_Image_clicked();//加载图片
    void on_Crop_Image_clicked();//裁剪图片
};

#endif //QT_DEMO_MAINWINDOW_H
