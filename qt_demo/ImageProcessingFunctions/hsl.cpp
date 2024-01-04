//
// Created by luokon on 2024/1/1.
//

#include "hsl.h"

// 色相
cv::Mat HSL::changeHue(const cv::Mat& image, int value, int cho)
{
    // 将图像从BGR颜色空间转换为HSV颜色空间
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);
    value /= 10;
    // 定义颜色的HSV范围
    cv::Scalar lower, upper;
    if (cho == 0) { // 红色
        lower = cv::Scalar(0, 50, 50);
        upper = cv::Scalar(10, 255, 255);
    } else if (cho == 1) { // 绿色
        lower = cv::Scalar(35, 50, 50);
        upper = cv::Scalar(85, 255, 255);
    } else if (cho == 2) { // 蓝色
        lower = cv::Scalar(95, 50, 50);
        upper = cv::Scalar(145, 255, 255);
    } else {
        return image; // 如果 cho 不是 0、1、2，则返回原始图像
    }

    // 在HSV图像中找到指定颜色区域的掩码
    cv::Mat mask;
    cv::inRange(hsvImage, lower, upper, mask);

    // 调整指定颜色区域的色相
    cv::Mat modifiedImage = hsvImage.clone();
    for (int i = 0; i < modifiedImage.rows; ++i) {
        for (int j = 0; j < modifiedImage.cols; ++j) {
            if (mask.at<uchar>(i, j) > 0) {
                modifiedImage.at<cv::Vec3b>(i, j)[0] = (modifiedImage.at<cv::Vec3b>(i, j)[0] + value)%180;
            }
        }
    }

    // 将图像从HSV颜色空间转换回BGR颜色空间
    cv::Mat bgrImage;
    cv::cvtColor(modifiedImage, bgrImage, cv::COLOR_HSV2BGR);

    return bgrImage;
}
// 饱和度
cv::Mat HSL::changeSaturation(const cv::Mat& image, int value, int cho) {
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);
    if(value < 0) value /= 2;
    // 定义颜色的HSV范围
    cv::Scalar lower, upper;
    if (cho == 0) { // 红色
        lower = cv::Scalar(0, 50, 50);
        upper = cv::Scalar(10, 255, 255);
    } else if (cho == 1) { // 绿色
        lower = cv::Scalar(35, 50, 50);
        upper = cv::Scalar(85, 255, 255);
    } else if (cho == 2) { // 蓝色
        lower = cv::Scalar(95, 50, 50);
        upper = cv::Scalar(145, 255, 255);
    } else {
        return image; // 如果 cho 不是 0、1、2，则返回原始图像
    }

    // 在HSV图像中找到指定颜色区域的掩码
    cv::Mat mask;
    cv::inRange(hsvImage, lower, upper, mask);

    // 对指定颜色区域进行饱和度处理
    cv::Mat modifiedImage = hsvImage.clone();
    for (int i = 0; i < modifiedImage.rows; ++i) {
        for (int j = 0; j < modifiedImage.cols; ++j) {
            if (mask.at<uchar>(i, j) > 0) {
                modifiedImage.at<cv::Vec3b>(i, j)[1] = std::min(modifiedImage.at<cv::Vec3b>(i, j)[1] + value, 255); // 修改饱和度分量（S）
                modifiedImage.at<cv::Vec3b>(i, j)[2] = std::max(modifiedImage.at<cv::Vec3b>(i, j)[2]+0, 0);
            }
        }
    }

    // 将图像从HSV颜色空间转换回BGR颜色空间
    cv::Mat bgrImage;
    cv::cvtColor(modifiedImage, bgrImage, cv::COLOR_HSV2BGR);

    return bgrImage;
}

// 明度
cv::Mat HSL::changeBrightness(const cv::Mat& image, int value, int cho) {
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);
    if(value < 0) value /= 2;
    // 定义颜色的HSV范围
    cv::Scalar lower, upper;
    if (cho == 0) { // 红色
        lower = cv::Scalar(0, 50, 50);
        upper = cv::Scalar(10, 255, 255);
    } else if (cho == 1) { // 绿色
        lower = cv::Scalar(35, 50, 50);
        upper = cv::Scalar(85, 255, 255);
    } else if (cho == 2) { // 蓝色
        lower = cv::Scalar(95, 50, 50);
        upper = cv::Scalar(145, 255, 255);
    } else {
        return image; // 如果 cho 不是 0、1、2，则返回原始图像
    }

    // 在HSV图像中找到指定颜色区域的掩码
    cv::Mat mask;
    cv::inRange(hsvImage, lower, upper, mask);

    // 对指定颜色区域进行明度处理
    cv::Mat modifiedImage = hsvImage.clone();
    for (int i = 0; i < modifiedImage.rows; ++i) {
        for (int j = 0; j < modifiedImage.cols; ++j) {
            if (mask.at<uchar>(i, j) > 0) {
                modifiedImage.at<cv::Vec3b>(i, j)[2] = std::min(modifiedImage.at<cv::Vec3b>(i, j)[2] + value, 255);
                modifiedImage.at<cv::Vec3b>(i, j)[2] = std::max(modifiedImage.at<cv::Vec3b>(i, j)[2]+0, 0);
            }
        }
    }

    // 将图像从HSV颜色空间转换回BGR颜色空间
    cv::Mat bgrImage;
    cv::cvtColor(modifiedImage, bgrImage, cv::COLOR_HSV2BGR);

    return bgrImage;
}