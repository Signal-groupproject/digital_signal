#include <QImage>
#include "mainwindow.h"
#include "ui_mainwindow.h"

Mat image_now, slider_image; //当前处理图像、滑块处理图像
int image_index = -1;
std::vector<cv::Mat> imageStates;
int ismark = 0, hslCho = 0; // HSL默认红色处理

mainwindow::mainwindow(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::mainwindow) {
    ui->setupUi(this);
    this->setWindowIcon(QIcon(".\\images\\images\\icon.png"));
    this->setWindowTitle("图片处理工具");
    QPixmap backgroundImage(".\\images\\images\\bg.png");
    QSize windowSize = this->size();

    // 调整背景图片大小以填充窗口
    QPixmap scaledBackground = backgroundImage.scaledToWidth(windowSize.width(), Qt::SmoothTransformation);
    QPalette palette;
    palette.setBrush(QPalette::Window, scaledBackground);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    //设置按钮Icon以及窗口Icon
    ui->pushButton1->setIcon(QIcon(".\\images\\images\\left.png"));
    ui->pushButton1->setIconSize(QSize(50, 50));

    ui->pushButton2->setIcon(QIcon(".\\images\\images\\right.png"));
    ui->pushButton2->setIconSize(QSize(50, 50));

    ui->pushButton3->setIcon(QIcon(".\\images\\images\\X.png"));
    ui->pushButton3->setIconSize(QSize(50, 50));

    ui->pushButton4->setIcon(QIcon(".\\images\\images\\Y.png"));
    ui->pushButton4->setIconSize(QSize(50, 50));

    ui->Withdraw->setIcon(QIcon(".\\images\\images\\withdraw.png"));
    ui->Remake->setIcon(QIcon(".\\images\\images\\remake.png"));
    ui->merge->setIcon(QIcon(".\\images\\images\\merge.png"));
    ui->Contrast->setIcon(QIcon(".\\images\\images\\contrast.png"));

    ui->dockWidget->setFeatures(QDockWidget::NoDockWidgetFeatures);//隐藏工具栏的放大和关闭按钮

    setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);    // 禁止最大化按钮
    setFixedSize(this->width(),this->height());                     // 禁止拖动窗口大小
    // 监控水印是否勾选进行动作
    connect(ui->checkBox, &QCheckBox::stateChanged, this, &mainwindow::onCheckBoxStateChanged);
}

void outError()
{   // 错误提示
    // 没上传图片
    QMessageBox *messageBox = new QMessageBox();
    QMessageBox::information(nullptr, "错误提示", "您还没有上传图片，请点击加载图片进行上传");
}

// 水印勾选
void mainwindow::onCheckBoxStateChanged(int state) {
    if (!image_now.empty()) {
        if (state == Qt::Checked) {  // 加水印
            ismark = 1;
            // 读取原始图像和水印图像
            cv::Mat originalImage = image_now;
            cv::Mat watermarkImage = cv::imread("./images/images/waterMark.png");

            // 检查图像是否成功加载
            if (originalImage.empty() || watermarkImage.empty()) {
                std::cout << "Failed to load images." << std::endl;
                return;
            }

            // 调整水印图像的大小以适应原始图像的左下角
            cv::resize(watermarkImage, watermarkImage, cv::Size(originalImage.cols / 4, originalImage.rows / 4));

            // 将水印图像添加到原始图像的左下角
            cv::Mat imageWithWatermark = originalImage.clone();
            cv::Mat roi = imageWithWatermark(
                    cv::Rect(0, imageWithWatermark.rows - watermarkImage.rows, watermarkImage.cols,
                             watermarkImage.rows));
            cv::addWeighted(roi, 1.0, watermarkImage, 0.5, 0, roi);

            image_now = imageWithWatermark;
            slider_image = image_now;   // 同时更新滑块处理图像
            updateState();
        } else if (state == Qt::Unchecked && ismark) { // 若上一次动作是有加水印的，则现在回退到未加状态
            ismark = 0;
            image_now = imageStates[--image_index];
            slider_image = image_now;   // 同时更新滑块处理图像
            updateState();
        }
    }else{
        outError();
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
    if (!image_now.empty()) {
        if (image_index > 0) {
            image_index--;
            image_now = imageStates[image_index];
            slider_image = image_now;   // 同时更新滑块处理图像
            // 显示当前图像
            QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
            qImage = qImage.convertToFormat(QImage::Format_ARGB32);
            QImage processed_image = Image_Processing(qImage);
            ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
        }
    }else{
        outError();
    }
}

// 重做操作
void mainwindow::on_Remake_clicked() {
    if (!image_now.empty()) {
        if (image_index < imageStates.size() - 1) {
            image_index++;
            image_now = imageStates[image_index];
            slider_image = image_now;   // 同时更新滑块处理图像
            // 显示当前图像
            QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
            qImage = qImage.convertToFormat(QImage::Format_ARGB32);
            QImage processed_image = Image_Processing(qImage);
            ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
        }
    }else{
        outError();
    }
}

//图像对比，通过调用全局变量实现图像处理前后对比
void mainwindow::on_Contrast_pressed() {
    if (!imageStates.empty()) {
        QImage qImage(imageStates[0].data,imageStates[0].cols, imageStates[0].rows, imageStates[0].step,
                      QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
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
    image_now = imread(filePath.toStdString());
    if (image_now.empty()) {
        QMessageBox::warning(this, tr("警告"), tr("图片加载失败，请选择一个有效的图片文件。"));
        return;
    }
    imageStates.clear();
    image_index = -1;
    slider_image = image_now;
    updateState();
}

// 保存图片
void mainwindow::on_Save_Image_clicked() {
    if (!image_now.empty()) {
        QString savePath = QFileDialog::getSaveFileName(nullptr, "保存图像", "", "图像文件 (*.png *.jpg *.bmp)");

        if (!savePath.isEmpty()) {
            // 将QString转换为std::string
            std::string savePathStr = savePath.toStdString();

            // 保存图像
            bool success = cv::imwrite(savePathStr, image_now);

            // 显示保存结果弹窗
            if (success) {
                QMessageBox::information(nullptr, "保存结果", "保存成功");
            } else {
                QMessageBox::critical(nullptr, "保存结果", "保存失败");
            }
        }
    }else{
        outError();
    }
}

// HSL处理
// 红色部分
void mainwindow::on_redHSL_clicked() {
    hslCho = 0;
}
// 绿色部分
void mainwindow::on_greenHSL_clicked() {
    hslCho = 1;
}
// 蓝色部分
void mainwindow::on_blueHSL_clicked() {
    hslCho = 2;
}
// 色相处理
void mainwindow::on_colorationHSL_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_11->setText(QString("%1").arg(value));
        image_now = HSL::changeHue(slider_image, value, hslCho);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
void mainwindow::on_colorationHSL_sliderReleased() {
    updateState();
}

// 饱和度处理
void mainwindow::on_saturationHSL_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_12->setText(QString("%1").arg(value));
        image_now = HSL::changeSaturation(slider_image, value, hslCho);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
void mainwindow::on_saturationHSL_sliderReleased() {
    updateState();
}

// 明度处理
void mainwindow::on_brightnessHSL_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_13->setText(QString("%1").arg(value));
        image_now = HSL::changeBrightness(slider_image, value, hslCho);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
void mainwindow::on_brightnessHSL_sliderReleased() {
    updateState();
}

// 裁剪图片
// 声明一个新的槽函数，用于处理裁剪结果的信号
void mainwindow::handleCropResult(const cv::Mat& result) {
    // 处理接收到的 result 的值
    image_now = result;
    slider_image = image_now;   // 同时更新滑块处理图像
    updateState();
}
void mainwindow::on_Crop_Image_clicked() {
    if (!image_now.empty()) {
        ImageLabel *label = new ImageLabel(ui->label_show);

        // 将 cropResultAvailable 信号连接到 handleCropResult 槽函数
        connect(label, &ImageLabel::cropResultAvailable, this, &mainwindow::handleCropResult);

        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        label->setImage(QPixmap::fromImage(Image_Processing(qImage)));
        label->show();
    }else{
        outError();
    }
}

//角度滑动条变化，实时显示角度值
void mainwindow::on_horizontalSlider_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle->setText(QString("%1").arg(value));
        image_now = adjust::rotateImage(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_horizontalSlider_sliderReleased() {
    updateState();
}

// 向左旋转90°
void mainwindow::on_pushButton1_clicked() {
    if (!image_now.empty()) {
        image_now = Revolve90::left90(image_now);
        slider_image = image_now;   // 同时更新滑块处理图像
        // 显示当前图像
        updateState();
    }else{
        outError();
    }
}

// 向右旋转90°
void mainwindow::on_pushButton2_clicked() {
    if(!image_now.empty()){
    image_now = Revolve90::right90(image_now);
    slider_image = image_now;   // 同时更新滑块处理图像
    // 显示当前图像
    updateState();
    }else{
        outError();
    }
}

// x轴对称
void mainwindow::on_pushButton3_clicked() {
    if (!image_now.empty()) {
        // 对图像进行x轴对称操作
        image_now = Symmetry::xSymmetry(image_now);
        slider_image = image_now;   // 同时更新滑块处理图像
        // 显示当前图像
        updateState();
    }else{
        outError();
    }
}

// y轴对称
void mainwindow::on_pushButton4_clicked() {
    if (!image_now.empty()) {
        // 对图像进行y轴对称操作
        image_now = Symmetry::ySymmetry(image_now);
        slider_image = image_now;   // 同时更新滑块处理图像
        // 显示当前图像
        updateState();
    }else{
        outError();
    }
}

// 直方图均衡化
void mainwindow::on_Equalize_clicked() {
    if (!image_now.empty()) {
        // 对图像进行y轴对称操作
        image_now = adjust::equalization(image_now);
        slider_image = image_now;   // 同时更新滑块处理图像
        // 显示当前图像
        updateState();
    }else{
        outError();
    }
}

// 添加文字
void mainwindow::on_addText_clicked() {
    if(!image_now.empty()){
        QString inText = ui->textEdit->toPlainText();
        QMessageBox *messageBox = new QMessageBox();
        messageBox->information(nullptr, "用户输入", "您输入的文字是：" + inText);

        image_now = adjust::addTextToImage(image_now, inText);
        slider_image = image_now;   // 同时更新滑块处理图像
        updateState();
    }else{
        outError();
    }

}

// 高斯滤波实现图像平滑处理
void mainwindow::on_smoothing_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_10->setText(QString("%1").arg(value));
        image_now = adjust::smoothing(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
void mainwindow::on_smoothing_sliderReleased() {
    updateState();
}

//光感调整
void mainwindow::on_light_perception_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_2->setText(QString("%1").arg(value));
        image_now = adjust::light_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
// 通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_light_perception_sliderReleased() {
    updateState();
}

// 曝光调整
void mainwindow::on_exposure_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_4->setText(QString("%1").arg(value));
        image_now = adjust::exposure_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
// 通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_exposure_sliderReleased() {
    updateState();
}

// 对比度调整
void mainwindow::on_contrast_ratio_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_5->setText(QString("%1").arg(value));
        image_now = adjust::contrast_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
// 通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_contrast_ratio_sliderReleased() {
    updateState();
}

//锐化
void mainwindow::on_sharpening_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_6->setText(QString("%1").arg(value));
        image_now = adjust::sharpen_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_sharpening_sliderReleased() {
    updateState();
}

//色温
void mainwindow::on_color_temperature_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_7->setText(QString("%1").arg(value));
        image_now = adjust::cot_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_color_temperature_sliderReleased() {
    updateState();
}

//色调
void mainwindow::on_tone_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_8->setText(QString("%1").arg(value));
        image_now = adjust::tone_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_tone_sliderReleased() {
    updateState();
}

//饱和度
void mainwindow::on_saturation_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_9->setText(QString("%1").arg(value));
        image_now = adjust::saturation_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_saturation_sliderReleased() {
    updateState();
}

//图层合并
void mainwindow::on_merge_clicked() {
    if (!image_now.empty()) {
        slider_image = image_now;
        updateState();
    }else{
        outError();
    }
}

//灰度化
void mainwindow::on_Grayscale_clicked() {
    if (!image_now.empty()) {
        image_now = adjust::grayscale(image_now);
        slider_image = image_now;   // 同时更新滑块处理图像
        updateState();
    }else{
        outError();
    }
}

//边缘检测
void mainwindow::on_edge_detection_clicked() {
    if(!image_now.empty()){
        image_now = adjust::edge_detection(image_now);
        slider_image = image_now;   // 同时更新滑块处理图像
        updateState();
    }else{
        outError();
    }
}

// 人像美颜
void mainwindow::on_beautiful_clicked() {
    if(!image_now.empty()){
        image_now = adjust::processFace(image_now); // 人脸识别
        slider_image = image_now;   // 同时更新滑块处理图像
        updateState();
    }else{
        outError();
    }
}

// 去雾
void mainwindow::on_defog_clicked() {
    if(!image_now.empty()){
        image_now = adjust::defog(image_now); // 去雾
        slider_image = image_now;   // 同时更新滑块处理图像
        updateState();
    }else{
        outError();
    }
}

//颗粒感
void mainwindow::on_particle_valueChanged(int value) {
    if (!image_now.empty()) {
        ui->angle_14->setText(QString("%1").arg(value));
        image_now = adjust::particle_adjust(slider_image, value);
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        qImage = qImage.convertToFormat(QImage::Format_ARGB32);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }else{
        outError();
    }
}
void mainwindow::on_particle_sliderReleased() {
    updateState();
}
