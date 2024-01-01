#include <QImage>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Mat original_image,image_now; //初始图片和当前处理图像
int image_index = -1;
std::vector<cv::Mat> imageStates;
int ismark = 0;

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::mainwindow) {
    ui->setupUi(this);
    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    // 监控水印是否勾选进行动作
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &mainwindow::onCheckBoxStateChanged);
}
void outError()
{   // 错误提示
    if (image_now.empty())
    {
        // 没上传图片
        QMessageBox *messageBox = new QMessageBox();
        QMessageBox::information(nullptr, "错误提示", "您还没有上传图片，请点击加载图片进行上传");
        return;
    }
}
// 水印勾选
void mainwindow::onCheckBoxStateChanged(int state)
{
    outError();
    if (state == Qt::Checked)
    {  // 加水印
        ismark = 1;
        // 读取原始图像和水印图像
        cv::Mat originalImage = image_now;
        cv::Mat watermarkImage = cv::imread("./images/waterMark.png");

        // 检查图像是否成功加载
        if (originalImage.empty() || watermarkImage.empty())
        {
            std::cout << "Failed to load images." << std::endl;
            return;
        }

        // 调整水印图像的大小以适应原始图像的左下角
        cv::resize(watermarkImage, watermarkImage, cv::Size(originalImage.cols / 4, originalImage.rows / 4));

        // 将水印图像添加到原始图像的左下角
        cv::Mat imageWithWatermark = originalImage.clone();
        cv::Mat roi = imageWithWatermark(cv::Rect(0, imageWithWatermark.rows - watermarkImage.rows, watermarkImage.cols, watermarkImage.rows));
        cv::addWeighted(roi, 1.0, watermarkImage, 0.5, 0, roi);

        image_now = imageWithWatermark;
        updateState();
    }
    else if (state == Qt::Unchecked && ismark)
    { // 若上一次动作是有加水印的，则现在回退到未加状态
        ismark = 0;
        image_now = imageStates[--image_index];
        updateState();
    }
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
// 每当对图像进行一次操作，将其更新在存储数组中，并重新显示
void mainwindow::updateState() {
    // 当进行一个新操作时，删除当前图片位置以后所有图片状态，然后再更新当前图片进去
    if(image_index != -1)
        imageStates.erase(imageStates.begin()+image_index+1, imageStates.end());
    image_index++;
    imageStates.push_back(image_now);

    // 显示当前图像
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
// 撤销操作
void mainwindow::on_Withdraw_clicked() {
    outError();
    if(image_index > 0){
        image_index--;
        image_now = imageStates[image_index];
        // 显示当前图像
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }
}
// 重做操作
void mainwindow::on_Remake_clicked() {
    outError();
    if(image_index < imageStates.size() - 1)
    {
        image_index++;
        image_now = imageStates[image_index];
        // 显示当前图像
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }
}

//图像对比
//通过调用全局变量实现图像处理前后对比
void mainwindow::on_Contrast_pressed() {
    outError();
    QImage qImage(original_image.data, original_image.cols, original_image.rows, original_image.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
void mainwindow::on_Contrast_released() {
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}

//加载图片
void mainwindow::on_Load_Image_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"), "./images/testImage",
                                                    tr("Images (*.png *.jpg *.bmp *.tif)"));
    if (filePath.isEmpty()) {
        return;
    }
    // 更新初始图片、当前图片和图片状态存储
    original_image = imread(filePath.toStdString());
    if (original_image.empty()) {
        QMessageBox::warning(this, tr("警告"), tr("图片加载失败，请选择一个有效的图片文件。"));
        return;
    }
    imageStates.clear();
    image_index = -1;
    image_now = original_image;
    updateState();
}

// 保存图片
void mainwindow::on_Save_Image_clicked()
{
    outError();
    QString savePath = QFileDialog::getSaveFileName(nullptr, "保存图像", "", "图像文件 (*.png *.jpg *.bmp)");

    if (!savePath.isEmpty()) {
        // 将QString转换为std::string
        std::string savePathStr = savePath.toStdString();

        // 保存图像
        bool success = cv::imwrite(savePathStr, image_now);

        // 显示保存结果弹窗
        if (success) {
            QMessageBox::information(nullptr, "保存结果", "保存成功");
        }
        else {
            QMessageBox::critical(nullptr, "保存结果", "保存失败");
        }
    }
}

// 裁剪图片
// 声明一个新的槽函数，用于处理裁剪结果的信号
void mainwindow::handleCropResult(const cv::Mat& result) {
    // 处理接收到的 result 的值
    image_now = result;
    updateState();
}
void mainwindow::on_Crop_Image_clicked() {
    outError();
    ImageLabel* label = new ImageLabel(ui->label_show);

    // 将 cropResultAvailable 信号连接到 handleCropResult 槽函数
    connect(label, &ImageLabel::cropResultAvailable, this, &mainwindow::handleCropResult);

    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    label->setImage(QPixmap::fromImage(Image_Processing(qImage)));
    label->show();
}

//角度滑动条变化，实时显示角度值
void mainwindow::on_horizontalSlider_valueChanged(int value) {
    outError();
    ui->angle->setText(QString("%1").arg(value));
    image_now = adjust::rotateImage(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_horizontalSlider_sliderReleased() {
    updateState();
}
// 向右旋转90°
void mainwindow::on_pushButton1_clicked() {
    outError();
    image_now = Revolve90::left90(image_now);
    // 显示当前图像
    updateState();
}
// 向左旋转90°
void mainwindow::on_pushButton2_clicked() {
    outError();
    image_now = Revolve90::right90(image_now);
    // 显示当前图像
    updateState();
}

// x轴对称
void mainwindow::on_pushButton3_clicked() {
    outError();
    // 对图像进行x轴对称操作
    image_now = Symmetry::xSymmetry(image_now);
    // 显示当前图像
    updateState();
}

// y轴对称
void mainwindow::on_pushButton4_clicked() {
    outError();
    // 对图像进行y轴对称操作
    image_now = Symmetry::ySymmetry(image_now);
    // 显示当前图像
    updateState();
}

// 直方图均衡化
void mainwindow::on_Equalize_clicked() {
    outError();
    // 对图像进行y轴对称操作
    image_now = adjust::equalization(image_now);
    // 显示当前图像
    updateState();
}

// 添加文字
void mainwindow::on_addText_clicked() {
    outError();
    QString inText = ui->textEdit->toPlainText();
    QMessageBox *messageBox = new QMessageBox();
    messageBox->information(nullptr, "用户输入", "您输入的文字是：" + inText);
    image_now = adjust::addTextToImage(image_now, inText);
    updateState();
}

// 高斯滤波实现图像平滑处理
void mainwindow::on_smoothing_valueChanged(int value) {
    outError();
    ui->angle_2->setText(QString("%1").arg(value));
    image_now = adjust::smoothing(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
void mainwindow::on_smoothing_sliderReleased() {
    updateState();
}

//光感调整
void mainwindow::on_light_perception_valueChanged(int value) {
    outError();
    ui->angle_2->setText(QString("%1").arg(value));
    image_now = adjust::light_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
// 通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_light_perception_sliderReleased() {
    updateState();
}

// 曝光调整
void mainwindow::on_exposure_valueChanged(int value) {
    outError();
    ui->angle_4->setText(QString("%1").arg(value));
    image_now = adjust::exposure_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
// 通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_exposure_sliderReleased() {
    updateState();
}

// 对比度调整
void mainwindow::on_contrast_ratio_valueChanged(int value) {
    outError();
    ui->angle_5->setText(QString("%1").arg(value));
    image_now = adjust::contrast_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
// 通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_contrast_ratio_sliderReleased() {
    updateState();
}

//锐化
void mainwindow::on_sharpening_valueChanged(int value) {
    outError();
    ui->angle_6->setText(QString("%1").arg(value));
    image_now = adjust::sharpen_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_sharpening_sliderReleased() {
    updateState();
}

//色温
void mainwindow::on_color_temperature_valueChanged(int value) {
    outError();
    ui->angle_7->setText(QString("%1").arg(value));
    image_now = adjust::cot_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_color_temperature_sliderReleased() {
    updateState();
}

//色调
void mainwindow::on_tone_valueChanged(int value) {
    outError();
    ui->angle_8->setText(QString("%1").arg(value));
    image_now = adjust::cot_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_tone_sliderReleased() {
    updateState();
}

//饱和度
void mainwindow::on_saturation_valueChanged(int value) {
    outError();
    ui->angle_9->setText(QString("%1").arg(value));
    image_now = adjust::cot_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    qImage = qImage.convertToFormat(QImage::Format_ARGB32);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_saturation_sliderReleased() {
    updateState();
}

//图层合并
void mainwindow::on_merge_clicked() {
    outError();
    original_image = image_now;
    image_index = -1;
    imageStates.clear();
    updateState();
}

void mainwindow::on_Grayscale_clicked() {
    outError();
    image_now = adjust::grayscale(image_now);
    updateState();
}

void mainwindow::on_edge_detection_clicked() {
    outError();
    image_now = adjust::edge_detection(image_now);
    updateState();
}