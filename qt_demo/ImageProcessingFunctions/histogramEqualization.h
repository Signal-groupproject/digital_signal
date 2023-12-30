//
// Created by luokon on 2023/12/30.
//

#ifndef QT_DEMO_HISTOGRAMEQUALIZATION_H
#define QT_DEMO_HISTOGRAMEQUALIZATION_H
#include <opencv2/opencv.hpp>
#include <vector>

class histogramEqualization {
public:
    static cv::Mat equalization(const cv::Mat& image);
};


#endif //QT_DEMO_HISTOGRAMEQUALIZATION_H
