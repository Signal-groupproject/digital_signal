//
// Created by wei'y'b on 2023/12/30.
//
#include <opencv2/core/types_c.h>
#include "adjust.h"

// 识别人脸
cv::Mat adjust::processFace(const cv::Mat& image) {
    cv::CascadeClassifier faceCascade;
    std::string cascadePath = "./cascade/haarcascade_frontalface_alt.xml";
    if (!faceCascade.load(cascadePath)) {
        QMessageBox *messageBox = new QMessageBox();
        QMessageBox::information(nullptr, "错误提示", "加载级联分类器失败");
        return image;
    }

    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(grayImage, grayImage);

    cv::Mat blurredImage = image.clone();  // 创建一个副本用于结果

    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(grayImage, faces, 1.1, 3);

    for (const cv::Rect& faceRect : faces) {
        // 获取人脸区域
        cv::Mat faceROI = blurredImage(faceRect);

        // 创建一个5x5的高斯模糊内核
        int kernelSize = 5;
        float sigma = 1.0f;
        int radius = kernelSize / 2;

        cv::Mat kernel(kernelSize, kernelSize, CV_32FC1);

        float sum = 0.0f;
        for (int x = -radius; x <= radius; ++x) {
            for (int y = -radius; y <= radius; ++y) {
                float value = std::exp(-(x * x + y * y) / (2 * sigma * sigma));
                kernel.at<float>(x + radius, y + radius) = value;
                sum += value;
            }
        }

        // 标准化内核
        kernel /= sum;
        // 执行卷积运算
        cv::filter2D(faceROI, faceROI, -1, kernel);

        // 将处理后的人脸区域重新放回原图
        faceROI.copyTo(blurredImage(faceRect));
    }

    return blurredImage;
}
// 把文字放图片上
cv::Mat adjust::addTextToImage(const cv::Mat &image, const QString& text)
{
    // 获取用户选择的文字大小
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());
    result.convertTo(result, CV_8U);

    bool ok;
    int fontSize = QInputDialog::getInt(nullptr, "选择文字大小", "请输入文字大小（单位：像素）", 10, 1, 100, 1, &ok);
    if(!ok)
    {
        QMessageBox *messageBox = new QMessageBox();
        QMessageBox::information(nullptr, "错误提示", "获取文字大小失败");
        return image;
    }

    // 获取用户选择的文字颜色
    QColor textColor = QColorDialog::getColor(Qt::black, nullptr, "选择文字颜色");
    if(!textColor.isValid())
    {
        QMessageBox *messageBox = new QMessageBox();
        QMessageBox::information(nullptr, "错误提示", "获取文字颜色失败");
        return image;
    }
// 选择文字位置
    QMessageBox::information(nullptr, "选择位置", "请点击图片选择文字位置");
    cv::Point textPosition;
    cv::namedWindow("选择位置");
    cv::imshow("选择位置", image);
    cv::setMouseCallback("选择位置", [](int event, int x, int y, int flags, void* userdata) {
        if (event == cv::EVENT_LBUTTONDOWN)
        {
            cv::Point* position = static_cast<cv::Point*>(userdata);
            position->x = x;
            position->y = y;
            cv::destroyWindow("选择位置");
        }
    }, &textPosition);
    cv::waitKey();

    // 在图片上绘制文字
    cv::Scalar textColorScalar(textColor.blue(), textColor.green(), textColor.red());
    cv::putText(result, text.toStdString(), textPosition, cv::FONT_HERSHEY_SIMPLEX, fontSize / 10.0, textColorScalar, 2);
    return result;
}

// 高斯模糊,平滑处理
cv::Mat adjust::smoothing(const cv::Mat &image, int value) {
    value = 2*value+1;  // 确保奇数，内核大小为value*value
    cv::Mat smoothed;
    cv::GaussianBlur(image, smoothed, cv::Size(value, value), 0);

    return smoothed;
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
    int adjusted_exposure = (value >= -100 && value <= -70) ? -70 : value;

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

            // 计算对比度调整的倍数
            float contrast_multiplier = (100.0f + value/3 - 5) / 100.0f + 1e-3;

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
    cv::Mat result;
    cv::Mat s = image.clone();
    cv::Mat kernel;
    switch (image.channels())
    {
        case 0:
            kernel = (cv::Mat_<int>(3, 3) <<
                                          0, -1, 0,
                    -1, 4, -1,
                    0, -1, 0
            );
        case 1:
            kernel = (cv::Mat_<int>(3, 3) <<
                                          -1, -1, -1,
                    -1, 8, -1,
                    -1, -1, -1
            );
        default:
            kernel = (cv::Mat_<int>(3, 3) <<
                                          0, -1, 0,
                    -1, 4, -1,
                    0, -1, 0
            );
    }
    cv::filter2D(s, s, s.depth(), kernel);
    result = image + s * 0.01 * value;
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
            for (int c = 2; c >= 0; --c) {
                int value = input_pixel[j * 3 + c] + ((c == 0) ? -level : level);
                output_pixel[j * 3 + c] = cv::saturate_cast<uchar>(value);
            }
        }
    }

    return result;
}

//色调
cv::Mat adjust::tone_adjust(const cv::Mat &image, int value) {
    cv::Mat result = image.clone();
    cv::cvtColor(result, result, cv::COLOR_BGR2HSV);

    int rows = result.rows;
    int cols = result.cols;

    // 调整因子，控制颜色变化的程度
    float scale = 0.04f;

    for (int i = 0; i < rows; ++i) {
        cv::Vec3b* row_ptr = result.ptr<cv::Vec3b>(i);

        for (int j = 0; j < cols; ++j) {
            int hue = row_ptr[j][0];

            // 根据 value 值调整色调
            hue -= value * scale;

            // 确保色调值在有效范围内 [0, 179]
            if (hue < 0)
                hue += 180;
            else if (hue >= 180)
                hue -= 180;

            row_ptr[j][0] = hue;
        }
    }

    cv::cvtColor(result, result, cv::COLOR_HSV2BGR);
    return result;
}

//饱和度调整
cv::Mat adjust::saturation_adjust(const cv::Mat &image, int value) {
    float increment = value * 1.0f / 100;
    cv::Mat result = image.clone();
    int row = image.rows;
    int col = image.cols;

    for (int i = 0; i < row; ++i) {
        uchar* t = result.ptr<uchar>(i);
        const uchar* s = image.ptr<uchar>(i);

        for (int j = 0; j < col; ++j) {
            uchar b = s[3 * j];
            uchar g = s[3 * j + 1];
            uchar r = s[3 * j + 2];

            float max_val = max3(r, g, b);
            float min_val = min3(r, g, b);
            float delta = (max_val - min_val) / 255;
            if (delta == 0)
                continue;

            float temp = (max_val + min_val) / 255;
            float L = temp / 2;
            float S = 0, alpha = 0;

            if (L < 0.5)
                S = delta / temp;
            else
                S = delta / (2 - temp);

            if (increment >= 0) {
                if ((increment + S) >= 1)
                    alpha = S;
                else
                    alpha = 1 - increment;
                alpha = 1 / alpha - 1;
                t[3 * j + 2] = static_cast<uchar>(r + (r - L * 255) * alpha);
                t[3 * j + 1] = static_cast<uchar>(g + (g - L * 255) * alpha);
                t[3 * j] = static_cast<uchar>(b + (b - L * 255) * alpha);
            } else {
                alpha = increment;
                t[3 * j + 2] = static_cast<uchar>(L * 255 + (r - L * 255) * (1 + alpha));
                t[3 * j + 1] = static_cast<uchar>(L * 255 + (g - L * 255) * (1 + alpha));
                t[3 * j] = static_cast<uchar>(L * 255 + (b - L * 255) * (1 + alpha));
            }
        }
    }
    return result;
}

//灰度化
cv::Mat adjust::grayscale(const cv::Mat &image) {
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());
    result.convertTo(result, CV_8U);

    for (int y = 0; y < image.rows; y++) {
        for (int x = 0; x < image.cols; x++) {
            // 获取像素值
            cv::Vec3b pixel = image.at<cv::Vec3b>(y, x);

            // 灰度转换的一种方法(RGB求平均值)
            int average = (pixel[0] + pixel[1] + pixel[2]) / 3;

            // 设置新图像的像素值
            result.at<cv::Vec3b>(y, x) = cv::Vec3b(average, average, average);
        }
    }

    return result;
}

//边缘检测
cv::Mat adjust::edge_detection(const cv::Mat &image) {
    // 深拷贝输入图像
    cv::Mat result(image.rows, image.cols, image.type());
    memcpy(result.data, image.data, image.total() * image.elemSize());

    // 转换为8位灰度图像
    result.convertTo(result, CV_8U);

    // 使用Laplacian算子进行边缘检测
    cv::Mat laplacian;
    cv::Laplacian(result, laplacian, CV_16S, 3, 1, 0, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(laplacian, result);

    // 模糊平滑处理以去除高频噪声
    cv::GaussianBlur(result, result, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

    return result;
}

// 去雾
cv::Mat adjust::defog(const cv::Mat &image) {
    cv::Mat blue, green, red;
    cv::Mat bgr[3];
    cv::split(image, bgr);

    blue = bgr[0];
    green = bgr[1];
    red = bgr[2];

    cv::Mat blue_equ, green_equ, red_equ;
    cv::equalizeHist(blue, blue_equ);
    cv::equalizeHist(green, green_equ);
    cv::equalizeHist(red, red_equ);

    cv::Mat result;
    cv::merge(std::vector<cv::Mat>{blue_equ, green_equ, red_equ}, result);

    return result;
}

//颗粒感
cv::Mat adjust::particle_adjust(const cv::Mat &image, int value) {
    int row = image.rows;
    int col = image.cols;
    if (value > 100)
        value = 100;
    if (value < 0)
        value = 0;
    cv::Mat result = image.clone();
    for (int i = 0; i < row; ++i) {
        uchar *t = result.ptr<uchar>(i);

        for (int j = 0; j < col; ++j) {
            for (int k = 0; k < 3; ++k) {
                int temp = t[3 * j + k];

// 限制随机变化在 [0, 2 * value] 范围内
                temp += ((rand() % (2 * value + 1)) - value);

// 修正越界值
                temp = std::max(0, std::min(255, temp));

                t[3 * j + k] = temp;
            }
        }
    }
    return result;
}

