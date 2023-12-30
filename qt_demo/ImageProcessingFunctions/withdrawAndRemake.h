//
// Created by luokon on 2023/12/30.
//

#ifndef QT_DEMO_WITHDRAWANDREMAKE_H
#define QT_DEMO_WITHDRAWANDREMAKE_H
#include <opencv2/opencv.hpp>
#include <QWidget>
#include <iostream>
#include <vector>

static std::vector<cv::Mat> imageStates;

class WithdrawAndRemake {
    static cv::Mat withdraw(const cv::Mat& image);
    static cv::Mat remake(const cv::Mat& image);
};


#endif //QT_DEMO_WITHDRAWANDREMAKE_H
