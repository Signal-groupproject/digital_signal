#include "mainwindow.h"
#include "ui_mainwindow.h"


//因为得考虑到回退操作，后续使用Mat图像数组存储操作的图片
//后续在实现保存图片的时候，通过检测按下保存按钮来进行全局变量的覆盖
Mat image,image_se;//保存图片之后，内容重新覆盖一次

mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainwindow) {
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小

}

mainwindow::~mainwindow() {
    delete ui;
}

//图片缩放和居中
QImage mainwindow::Image_Processing(const QImage& qimage)
{
    QSize imageSize = qimage.size();
    QSize labelSize = ui->label_show->size();
    QImage image_temp;

    double dWidthRatio = static_cast<double>(imageSize.width()) / labelSize.width();
    double dHeightRatio = static_cast<double>(imageSize.height()) / labelSize.height();

    if (dWidthRatio > dHeightRatio)
    {
        int newHeight = static_cast<int>(imageSize.height() / dWidthRatio);
        image_temp = qimage.scaled(labelSize.width(), newHeight, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }
    else
    {
        int newWidth = static_cast<int>(imageSize.width() / dHeightRatio);
        image_temp = qimage.scaled(newWidth, labelSize.height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    }

    int xOffset = (labelSize.width() - image_temp.width()) / 2;
    int yOffset = (labelSize.height() - image_temp.height()) / 2;

    QImage processed_image(labelSize, QImage::Format_ARGB32);
    processed_image.fill(Qt::transparent);

    QPainter painter(&processed_image);
    painter.drawImage(QPoint(xOffset, yOffset), image_temp);

    return processed_image;
}

//图像对比
//通过调用全局变量实现图像处理前后对比
void mainwindow::on_Contrast_pressed() {
    QImage original_image(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(original_image);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}

void mainwindow::on_Contrast_released() {
    QImage original_image(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(original_image);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}

//加载图片
void mainwindow::on_Load_Image_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"), "D:/", tr("Images (*.png *.jpg *.bmp *.tif)"));

    if (filePath.isEmpty()) {
        return;
    }

    image = imread(filePath.toStdString());

    if (image.empty()) {
        QMessageBox::warning(this, tr("警告"), tr("图片加载失败，请选择一个有效的图片文件。"));
        return;
    }

    QImage original_image(image.data, image.cols, image.rows, image.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(original_image);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
// 保存图片
void mainwindow::on_Save_Image_clicked()
{
    QString savePath = QFileDialog::getSaveFileName(nullptr, "保存图像", "", "图像文件 (*.png *.jpg *.bmp)");

    if (!savePath.isEmpty()) {
        // 将QString转换为std::string
        std::string savePathStr = savePath.toStdString();

        // 保存图像
        bool success = cv::imwrite(savePathStr, image_se);

        // 显示保存结果弹窗
        if (success) {
            QMessageBox::information(nullptr, "保存结果", "保存成功");
        }
        else {
            QMessageBox::critical(nullptr, "保存结果", "保存失败");
        }
    }
}

//裁剪图片，先调用opencv库应付一下
void mainwindow::on_Crop_Image_clicked() {
    if (image.empty()) {
        return;
    }

    // 提示用户选择裁剪区域
    Rect cropRect = selectCropRegion(image);

    // 检查是否选择了有效的裁剪区域
    if (cropRect.width > 0 && cropRect.height > 0) {
        // 执行裁剪
        Mat croppedImage = image(cropRect).clone();
        image_se = croppedImage;
        // 显示裁剪后的图片
        QImage croppedQImage(croppedImage.data, croppedImage.cols, croppedImage.rows, croppedImage.step, QImage::Format_BGR888);
        QImage processedImage = Image_Processing(croppedQImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processedImage));
    }
}

Rect mainwindow::selectCropRegion(const Mat& image) {
    // 使用OpenCV的selectROI函数获取用户选择的矩形区域
    Rect cropRect = selectROI("Select Crop Region", image);

    // 关闭OpenCV的选择框
    destroyAllWindows();

    return cropRect;
}

//角度滑动条变化，实时显示角度值
void mainwindow::on_horizontalSlider_valueChanged(int value) {
    ui->angle->setText(QString("%1").arg(value));
}
// 向右旋转90°
void mainwindow::on_pushButton1_clicked() {
    image_se = Revolve90::left90(image);
    // 显示对称后的图像
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}
// 向左旋转90°
void mainwindow::on_pushButton2_clicked() {
    image_se = Revolve90::right90(image);
    // 显示对称后的图像
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

// x轴对称
void mainwindow::on_pushButton3_clicked() {
    // 对图像进行x轴对称操作
    image_se = Symmetry::xSymmetry(image);
    // 显示对称后的图像
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

// y轴对称
void mainwindow::on_pushButton4_clicked() {
    // 对图像进行y轴对称操作
    image_se = Symmetry::ySymmetry(image);
    // 显示对称后的图像
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

//光感调整
void mainwindow::on_light_perception_valueChanged(int value) {
    ui->angle_2->setText(QString("%1").arg(value));
    image_se = adjust::light_adjust(image,value);
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

//曝光调整
void mainwindow::on_exposure_valueChanged(int value) {
    ui->angle_4->setText(QString("%1").arg(value));
    image_se = adjust::exposure_adjust(image,value);
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

//对比度调整
void mainwindow::on_contrast_ratio_valueChanged(int value) {
    ui->angle_5->setText(QString("%1").arg(value));
    image_se = adjust::contrast_adjust(image,value);
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

//曲线调整

//直方图均衡化
void mainwindow::on_Equalize_clicked() {
    // 对图像进行y轴对称操作
    image_se = adjust::equalization(image);
    // 显示对称后的图像
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}
//饱和度调整
//曲线调色
//HSL
//锐化
void mainwindow::on_sharpening_valueChanged(int value) {
    ui->angle_6->setText(QString("%1").arg(value));
    image_se = adjust::sharpen_adjust(image,value);
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

//色温
void mainwindow::on_color_temperature_valueChanged(int value) {
    ui->angle_7->setText(QString("%1").arg(value));
    image_se = adjust::cot_adjust(image,value);
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}

//色调
void mainwindow::on_tone_valueChanged(int value) {
    ui->angle_8->setText(QString("%1").arg(value));
    image_se = adjust::tone_adjust(image,value);
    QImage qImage = QImage(image_se.data, image_se.cols, image_se.rows, image_se.step, QImage::Format_BGR888);
    QImage processImage = Image_Processing((qImage));
    ui->label_show->setPixmap(QPixmap::fromImage(processImage));
}