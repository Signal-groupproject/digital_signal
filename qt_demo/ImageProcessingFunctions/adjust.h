//
// Created by wei'y'b on 2023/12/30.
//

#ifndef QT_DEMO_ADJUST_H
#define QT_DEMO_ADJUST_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <QString>
#include <QPainter>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QColorDialog>

#define max2(a,b) (a>b?a:b)
#define max3(a,b,c) (a>b?max2(a,c):max2(b,c))
#define min2(a,b) (a<b?a:b)
#define min3(a,b,c) (a<b?min2(a,c):min2(b,c))


class adjust {
public:
    static cv::Mat light_adjust(const cv::Mat &image, int value);
    static cv::Mat exposure_adjust(const cv::Mat& image, int value);
    static cv::Mat contrast_adjust(const cv::Mat& image, int value);
    static cv::Mat sharpen_adjust(const cv::Mat& image, int value);
    static cv::Mat cot_adjust(const cv::Mat& image, int value);
    static cv::Mat tone_adjust(const cv::Mat& image, int value);
    static cv::Mat equalization(const cv::Mat& image);
    static cv::Mat saturation_adjust(const cv::Mat& image, int value);
    static cv::Mat rotateImage(const cv::Mat &image, int value);
    static cv::Mat smoothing(const cv::Mat &image, int value);
    static cv::Mat grayscale(const cv::Mat &image);
    static cv::Mat edge_detection(const cv::Mat &image);
    static cv::Mat addTextToImage(const cv::Mat &image, const QString &text);
    static cv::Mat processFace(const cv::Mat &image);
    static cv::Mat defog(const cv::Mat &image);
    static cv::Mat particle_adjust(const cv::Mat &image, int value);
};


#endif //QT_DEMO_ADJUST_H
