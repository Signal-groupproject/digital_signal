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
#include "ImageProcessingFunctions/copper.h"
#define test std::cout<<"This is a test";
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

private slots:
    void on_Contrast_pressed();//图像对比，按钮按下时显示原图
    void on_Contrast_released();//图像对比，按钮释时显示处理后的图
    void on_Load_Image_clicked();//加载图片
    void on_horizontalSlider_valueChanged(int value);//角度滑动条变化，图像随着旋转角度变化而变化，先放着
    void on_pushButton1_clicked();//顺时针90°
    void on_pushButton2_clicked();//逆时针90°
    void on_pushButton3_clicked();//x轴对称
    void on_pushButton4_clicked();//y轴对称
    void on_light_perception_valueChanged(int value);//光感滑动条变化
    void on_light_perception_sliderReleased();//光感滑动条状态保存
    void on_exposure_valueChanged(int value);//曝光滑动条变化
    void on_exposure_sliderReleased();//曝光滑动条状态保存
    void on_contrast_ratio_valueChanged(int value);//对比度滑动条变化
    void on_contrast_ratio_sliderReleased();//对比度滑动条状态保存
    void on_sharpening_valueChanged(int value);//锐化滑动条变化
    void on_sharpening_sliderReleased();//锐化滑动条状态保存
    void on_color_temperature_valueChanged(int value);//色温滑动条变化
    void on_color_temperature_sliderReleased();//色温滑动条状态保存
    void on_tone_valueChanged(int value);//色调滑动条变化
    void on_tone_sliderReleased();//色调滑动条状态保存
    void updateState(); // 更新图片与显示
    void on_Withdraw_clicked(); // 撤销操作
    void on_Remake_clicked(); // 重做操作
    void on_Equalize_clicked(); // 直方图均衡化
    void on_Save_Image_clicked(); // 保存图片
    void handleCropResult(const Mat &result); // 接收裁剪图片结果的槽函数
    void on_Crop_Image_clicked();   // 裁剪图片
    void on_saturation_valueChanged(int value);//饱和度滑动条变化
    void on_saturation_sliderReleased();//饱和度滑动条状态保存
    void on_horizontalSlider_sliderReleased();//旋转滑动条状态报错
    void on_merge_clicked();//图层合并
    void onCheckBoxStateChanged(int state);//水印
    void on_addText_clicked(); //添加文字
    void on_smoothing_valueChanged(int value); //图像平滑
    void on_smoothing_sliderReleased();
    void on_Grayscale_clicked();//灰度化
    void on_edge_detection_clicked();//边缘检测
};

#endif //QT_DEMO_MAINWINDOW_H
