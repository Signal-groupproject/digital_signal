//
// Created by wei'y'b on 2023/12/30.
//

#include "adjust.h"

// 高斯模糊,平滑处理
cv::Mat adjust::smoothing(const cv::Mat &image, int value) {

}
// 根据拉动角度旋转图片
cv::Mat adjust::rotateImage(const cv::Mat& image, int value) {
    // 计算旋转中心
    cv::Point2f center(image.cols / 2.0, image.rows / 2.0);

    // 获取旋转矩阵
    cv::Mat rotationMatrix = cv::getRotationMatrix2D(center, value, 1.0);

    // 应用旋转矩阵进行图像旋转
    cv::Mat rotatedImage;
    cv::warpAffine(image, rotatedImage, rotationMatrix, image.size());

    return rotatedImage;
}
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
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());
    result.convertTo(result, CV_8U);

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
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());
    result.convertTo(result, CV_8U);

    int channels = result.channels();
    int rows = result.rows;
    int cols = result.cols * channels;

    if (result.isContinuous()) {
        cols *= rows;
        rows = 1;
    }

    // 将曝光因子限制在-100到100之间
    int adjusted_exposure = std::max(-100, std::min(100, value));

    for (int i = 0; i < rows; ++i) {
        uchar* p = result.ptr<uchar>(i);

        for (int j = 0; j < cols; j += channels) {
            int blue = cv::saturate_cast<uchar>(p[j] * (100 + adjusted_exposure) / 100);
            int green = cv::saturate_cast<uchar>(p[j + 1] * (100 + adjusted_exposure) / 100);
            int red = cv::saturate_cast<uchar>(p[j + 2] * (100 + adjusted_exposure) / 100);

            p[j] = blue;
            p[j + 1] = green;
            p[j + 2] = red;
        }
    }

    return result;
}

//对比度调整
cv::Mat adjust::contrast_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());
    result.convertTo(result, CV_8U);

    int channels = result.channels();
    int rows = result.rows;
    int cols = result.cols;

    for (int i = 0; i < rows; ++i) {
        uchar* row_ptr = result.ptr<uchar>(i);

        for (int j = 0; j < cols; ++j) {
            int blue = row_ptr[j * channels];
            int green = row_ptr[j * channels + 1];
            int red = row_ptr[j * channels + 2];

            // 将对比度因子限制在-100到100之间
            int adjusted_contrast = std::max(-100, std::min(100, value));

            // 计算对比度调整的倍数
            float contrast_multiplier = (100.0f + adjusted_contrast) / 100.0f;

            // 调整每个通道的颜色值
            row_ptr[j * channels] = cv::saturate_cast<uchar>(contrast_multiplier * blue);
            row_ptr[j * channels + 1] = cv::saturate_cast<uchar>(contrast_multiplier * green);
            row_ptr[j * channels + 2] = cv::saturate_cast<uchar>(contrast_multiplier * red);
        }
    }

    return result;
}

//锐化
cv::Mat adjust::sharpen_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());
    result.convertTo(result, CV_8U);
    int channels = image.channels();
    for (int y = 1; y < image.rows - 1; ++y) {
        const uchar* current_row = image.ptr<uchar>(y);
        uchar* result_row = result.ptr<uchar>(y);

        for (int x = channels; x < channels * (image.cols - 1); ++x) {
            int sum = 5 * current_row[x];
            sum -= current_row[x - channels];
            sum -= current_row[x + channels];
            sum -= current_row[x - channels * image.cols];
            sum -= current_row[x + channels * image.cols];

            result_row[x] = cv::saturate_cast<uchar>(current_row[x] + value * sum / 255);
        }
    }

    return result;
}

//色温
cv::Mat adjust::cot_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());

    int image_rows = image.rows;
    int image_cols = image.cols;
    int level = value / 2;

    for (int i = 0; i < image_rows; ++i) {
        const uchar *input_pixel = image.ptr<uchar>(i);
        uchar *output_pixel = result.ptr<uchar>(i);

        for (int j = 0; j < image_cols; ++j) {
            for (int c = 2; c >= 0; --c) { // Loop through B, G, R channels
                int value = input_pixel[j * 3 + c] + ((c == 0) ? -level : level);
                output_pixel[j * 3 + c] = cv::saturate_cast<uchar>(value);
            }
        }
    }

    return result;
}

//色调
cv::Mat adjust::tone_adjust(const cv::Mat &image, int value) {
    cv::Mat result(image.size(),image.type());
    return result;
}

//饱和度调整
cv::Mat adjust::saturation_adjust(const cv::Mat &image, int value) {
    cv::Mat result = image.clone();

    if (image.channels() == 3) {
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                cv::Vec3b &pixel = result.at<cv::Vec3b>(i, j);

                float h, s, v;
                cv::Mat3f pixel_hsv;
                cv::cvtColor(cv::Mat(1, 1, CV_8UC3, pixel), pixel_hsv, cv::COLOR_BGR2HSV);
                h = pixel_hsv(0, 0)[0] / 180.0;
                s = pixel_hsv(0, 0)[1];
                v = pixel_hsv(0, 0)[2];

                s = std::max(0.0f, std::min(s + value / 100.0f, 1.0f));

                pixel_hsv(0, 0)[0] = h * 180.0;
                pixel_hsv(0, 0)[1] = s;
                pixel_hsv(0, 0)[2] = v;

                cv::cvtColor(pixel_hsv, cv::Mat(1, 1, CV_8UC3, pixel), cv::COLOR_HSV2BGR);
            }
        }
    }
}

//曲线调色
//HSL