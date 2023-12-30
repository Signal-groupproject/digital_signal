//
// Created by luokon on 2023/12/30.
//

#ifndef QT_DEMO_SYMMETRY_H
#define QT_DEMO_SYMMETRY_H
#include <opencv2/opencv.hpp>

class Symmetry {
public:
    static cv::Mat xSymmetry(const cv::Mat& image);
    static cv::Mat ySymmetry(const cv::Mat& image);
};

#endif //QT_DEMO_SYMMETRY_H
