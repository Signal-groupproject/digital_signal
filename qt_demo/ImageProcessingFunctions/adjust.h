//
// Created by wei'y'b on 2023/12/30.
//

#ifndef QT_DEMO_ADJUST_H
#define QT_DEMO_ADJUST_H
#include <opencv2/opencv.hpp>
#include <vector>

class adjust {
public:
    static cv::Mat light_adjust(const cv::Mat &image, int value);
    static cv::Mat exposure_adjust(const cv::Mat& image, int value);
    static cv::Mat contrast_adjust(const cv::Mat& image, int value);
    static cv::Mat sharpen_adjust(const cv::Mat& image, int value);
    static cv::Mat cot_adjust(const cv::Mat& image, int value);
    static cv::Mat tone_adjust(const cv::Mat& image, int value);
    static cv::Mat equalization(const cv::Mat& image);
};


#endif //QT_DEMO_ADJUST_H
