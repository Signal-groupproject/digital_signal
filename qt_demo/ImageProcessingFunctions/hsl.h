//
// Created by luokon on 2024/1/1.
//

#ifndef QT_DEMO_HSL_H
#define QT_DEMO_HSL_H
#include <opencv2/opencv.hpp>

class HSL {

public:
    static cv::Mat changeHue(const cv::Mat& image, int value, int cho);
    static cv::Mat changeSaturation(const cv::Mat& image, int value, int cho);
    static cv::Mat changeBrightness(const cv::Mat& image, int value, int cho);
};


#endif //QT_DEMO_HSL_H
