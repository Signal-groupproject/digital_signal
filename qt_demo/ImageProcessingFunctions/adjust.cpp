//
// Created by wei'y'b on 2023/12/30.
//

#include "adjust.h"

// 直方图均衡化
cv::Mat adjust::equalization(const cv::Mat& image)
{
    int numRows = image.rows;
    int numCols = image.cols;

    // 判断图像类型
    int numChannels = image.channels();
    bool isColorImage = (numChannels == 3);

    // 创建输出图像
    cv::Mat result(numRows, numCols, image.type());

    // 灰度图像处理逻辑
    if (!isColorImage) {
        // 计算直方图
        std::vector<int> histogram(256, 0);
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                int pixelValue = image.at<uchar>(i, j);
                histogram[pixelValue]++;
            }
        }

        // 计算累积分布函数
        std::vector<int> cdf(256, 0);
        cdf[0] = histogram[0];
        for (int i = 1; i < 256; ++i) {
            cdf[i] = cdf[i - 1] + histogram[i];
        }

        // 进行均衡化
        int numPixels = numRows * numCols;
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                int pixelValue = image.at<uchar>(i, j);
                int newPixelValue = (cdf[pixelValue] * 255) / numPixels;
                result.at<uchar>(i, j) = newPixelValue;
            }
        }
    }
        // 彩色图像处理逻辑
    else {
        std::vector<cv::Mat> channels;
        cv::split(image, channels);

        for (int c = 0; c < numChannels; ++c) {
            // 计算直方图
            std::vector<int> histogram(256, 0);
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    int pixelValue = channels[c].at<uchar>(i, j);
                    histogram[pixelValue]++;
                }
            }

            // 计算累积分布函数
            std::vector<int> cdf(256, 0);
            cdf[0] = histogram[0];
            for (int i = 1; i < 256; ++i) {
                cdf[i] = cdf[i - 1] + histogram[i];
            }

            // 进行均衡化
            int numPixels = numRows * numCols;
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    int pixelValue = channels[c].at<uchar>(i, j);
                    int newPixelValue = (cdf[pixelValue] * 255) / numPixels;
                    result.at<cv::Vec3b>(i, j)[c] = newPixelValue;
                }
            }
        }
    }

    return result;
}

//光感调整
cv::Mat adjust::light_adjust(const cv::Mat &image, int value) {
    CV_Assert(image.depth() == CV_8U);

    cv::Mat result = image.clone();

    int channels = result.channels();
    int rows = result.rows;
    int cols = result.cols * channels;

    if (result.isContinuous()) {
        cols *= rows;
        rows = 1;
    }

    for (int i = 0; i < rows; ++i) {
        uchar* p = result.ptr<uchar>(i);

        for (int j = 0; j < cols; j += channels) {
            int blue = p[j] + value;
            int green = p[j + 1] + value;
            int red = p[j + 2] + value;

            p[j] = cv::saturate_cast<uchar>((blue < 0) ? 0 : (blue > 255) ? 255 : blue);
            p[j + 1] = cv::saturate_cast<uchar>((green < 0) ? 0 : (green > 255) ? 255 : green);
            p[j + 2] = cv::saturate_cast<uchar>((red < 0) ? 0 : (red > 255) ? 255 : red);
        }
    }

    return result;
}

//曝光调整
cv::Mat adjust::exposure_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());
    return result;
}

//对比度调整
cv::Mat adjust::contrast_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());
    return result;
}

//锐化
cv::Mat adjust::sharpen_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());
    return result;
}

//色温
cv::Mat adjust::cot_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());
    return result;
}

//色调
cv::Mat adjust::tone_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());
    return result;
}

//直方图均衡化
//曲线调整
//饱和度调整
//曲线调色
//HSL