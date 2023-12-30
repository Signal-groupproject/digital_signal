//
// Created by luokon on 2023/12/30.
//

#include "symmetry.h"
// X 对称实现
cv::Mat Symmetry::xSymmetry(const cv::Mat& image) {
    cv::Mat result(image.size(), image.type());

    int rows = image.rows;
    int cols = image.cols;

    int channels = image.channels();

    // 分别对每列的数据水平翻转
    if (channels == 1) {
        // 灰度图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                result.at<uchar>(y, x) = image.at<uchar>(rows - y - 1, x);
            }
        }
    } else if (channels == 3) {
        // 彩色图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(y, x);
                result.at<cv::Vec3b>(y, x) = image.at<cv::Vec3b>(rows - y - 1, x);
            }
        }
        // 首先对彩色图像进行翻转操作，在OpenCV中，默认的通道顺序是BGR,所以需要将图像的通道顺序从BGR转换为RGB正确显示
        cv::cvtColor(result, result, cv::COLOR_BGR2RGB);
    }

    return result;
}

// Y 对称实现
cv::Mat Symmetry::ySymmetry(const cv::Mat& image) {
    cv::Mat result(image.size(), image.type());

    int rows = image.rows;
    int cols = image.cols;

    int channels = image.channels();

    // 分别对每行的数据水平翻转
    if (channels == 1) {
        // 灰度图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                result.at<uchar>(y, x) = image.at<uchar>(y, cols - x - 1);
            }
        }
    } else if (channels == 3) {
        // 彩色图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(y, x);
                result.at<cv::Vec3b>(y, x) = image.at<cv::Vec3b>(y, cols - x - 1);
            }
        }
        // 首先对彩色图像进行翻转操作，在OpenCV中，默认的通道顺序是BGR,所以需要将图像的通道顺序从BGR转换为RGB正确显示
        cv::cvtColor(result, result, cv::COLOR_BGR2RGB);
    }

    return result;
}