//
// Created by luokon on 2023/12/30.
//

#include "revolve.h"

// 向左旋转90°
cv::Mat Revolve90::left90(const cv::Mat& image) {
    cv::Mat result(image.cols, image.rows, image.type());

    int rows = image.rows;
    int cols = image.cols;

    int channels = image.channels();

    // 分别对每行的数据进行旋转
    if (channels == 1) {
        // 灰度图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                result.at<uchar>(cols - x - 1, y) = image.at<uchar>(y, x);
            }
        }
    } else if (channels == 3) {
        // 彩色图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                result.at<cv::Vec3b>(cols - x - 1, y) = image.at<cv::Vec3b>(y, x);
            }
        }
    }

    return result;
}
// 向右旋转90°
cv::Mat Revolve90::right90(const cv::Mat& image) {
    cv::Mat result(image.cols, image.rows, image.type());

    int rows = image.rows;
    int cols = image.cols;

    int channels = image.channels();

    // 分别对每行的数据进行旋转
    if (channels == 1) {
        // 灰度图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                result.at<uchar>(x, rows - y - 1) = image.at<uchar>(y, x);
            }
        }
    } else if (channels == 3) {
        // 彩色图像处理逻辑
        for (int y = 0; y < rows; y++) {
            for (int x = 0; x < cols; x++) {
                result.at<cv::Vec3b>(x, rows - y - 1) = image.at<cv::Vec3b>(y, x);
            }
        }
    }

    return result;
}

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
                result.at<cv::Vec3b>(y, x) = image.at<cv::Vec3b>(rows - y - 1, x);
            }
        }
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
                result.at<cv::Vec3b>(y, x) = image.at<cv::Vec3b>(y, cols - x - 1);
            }
        }
    }

    return result;
}