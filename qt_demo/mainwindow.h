#ifndef QT_DEMO_MAINWINDOW_H
#define QT_DEMO_MAINWINDOW_H

#include <QWidget>
#include <QFileDialog>
#include <QPainter>
#include <QMessageBox>
#include <QString>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "ImageProcessingFunctions/revolve.h"
#include "ImageProcessingFunctions/adjust.h"
#include "ImageProcessingFunctions/histogramEqualization.h"
#define test std::cout<<"This is a test"
using namespace cv;

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);
    ~mainwindow() override;

    QImage Image_Processing(const QImage&);

private:
    Ui::mainwindow *ui;
    cv::Rect selectCropRegion(const cv::Mat& image);

private slots:
    void on_Contrast_pressed();//图像对比，按钮按下时显示原图
    void on_Contrast_released();//图像对比，按钮释时显示处理后的图
    void on_Load_Image_clicked();//加载图片
    void on_Crop_Image_clicked();//裁剪图片 有点难度，先放着
    void on_horizontalSlider_valueChanged(int value);//角度滑动条变化，图像随着旋转角度变化而变化先放着
    void on_pushButton1_clicked();//顺时针90°
    void on_pushButton2_clicked();//逆时针90°
    void on_pushButton3_clicked();//x轴对称
    void on_pushButton4_clicked();//y轴对称
    void on_light_perception_valueChanged(int value);//光感滑动条变化
    void on_exposure_valueChanged(int value);//曝光滑动条变化
    void on_contrast_ratio_valueChanged(int value);//对比度滑动条变化
    void on_sharpening_valueChanged(int value);//锐化滑动条变化
    void on_color_temperature_valueChanged(int value);//色温滑动条变化
    void on_tone_valueChanged(int value);//色调滑动条变化

    void on_Equalize_clicked(); // 直方图均衡化
    void on_Save_Image_clicked(); // 保存图片
};

#endif //QT_DEMO_MAINWINDOW_H
