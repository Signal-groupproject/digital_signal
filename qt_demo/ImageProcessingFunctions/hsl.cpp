//
// Created by luokon on 2024/1/1.
//

#include "hsl.h"

cv::Mat HSL::changeHue(const cv::Mat& image, int hueChange, int cho)
{
    // 将图像从BGR颜色空间转换为HSV颜色空间
    cv::Mat hsvImage;
    cv::cvtColor(image, hsvImage, cv::COLOR_BGR2HSV);

    // 定义颜色的HSV范围
    cv::Scalar lower, upper;
    if (cho == 0) { // 红色
        lower = cv::Scalar(0, 50, 50);
        upper = cv::Scalar(10, 255, 255);
    } else if (cho == 1) { // 绿色
        lower = cv::Scalar(60, 50, 50);
        upper = cv::Scalar(70, 255, 255);
    } else if (cho == 2) { // 蓝色
        lower = cv::Scalar(120, 50, 50);
        upper = cv::Scalar(130, 255, 255);
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
                modifiedImage.at<cv::Vec3b>(i, j)[0] += hueChange;
            }
        }
    }

    // 将图像从HSV颜色空间转换回BGR颜色空间
    cv::Mat bgrImage;
    cv::cvtColor(modifiedImage, bgrImage, cv::COLOR_HSV2BGR);

    return bgrImage;
}
