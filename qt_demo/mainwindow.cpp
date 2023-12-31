#include "mainwindow.h"
#include "ui_mainwindow.h"


Mat original_image,image_now; //初始图片和当前处理图像
int image_index = -1;
std::vector<cv::Mat> imageStates;

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
// 每当对图像进行一次操作，将其更新在存储数组中，并重新显示
void mainwindow::updateState() {
    // 当进行一个新操作时，删除当前图片位置以后所有图片状态，然后再更新当前图片进去
    if(image_index != -1)
    imageStates.erase(imageStates.begin()+image_index+1, imageStates.end());
    image_index++;
    imageStates.push_back(image_now);

    // 显示当前图像
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
// 撤销操作
void mainwindow::on_Withdraw_clicked() {
    if(image_index > 0){
        image_index--;
        image_now = imageStates[image_index];
        // 显示当前图像
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }
}
// 重做操作
void mainwindow::on_Remake_clicked() {
    if(image_index < imageStates.size() - 1)
    {
        image_index++;
        image_now = imageStates[image_index];
        // 显示当前图像
        QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
        QImage processed_image = Image_Processing(qImage);
        ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
    }
}

//图像对比
//通过调用全局变量实现图像处理前后对比
void mainwindow::on_Contrast_pressed() {
    QImage qImage(original_image.data, original_image.cols, original_image.rows, original_image.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
void mainwindow::on_Contrast_released() {
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}

//加载图片
void mainwindow::on_Load_Image_clicked() {
    QString filePath = QFileDialog::getOpenFileName(this, tr("选择图片"), "./",
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
    ImageLabel* label = new ImageLabel(ui->label_show);

    // 将 cropResultAvailable 信号连接到 handleCropResult 槽函数
    connect(label, &ImageLabel::cropResultAvailable, this, &mainwindow::handleCropResult);

    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    label->setImage(QPixmap::fromImage(Image_Processing(qImage)));
    label->show();
}

//角度滑动条变化，实时显示角度值
void mainwindow::on_horizontalSlider_valueChanged(int value) {
    ui->angle->setText(QString("%1").arg(value));
}
// 向右旋转90°
void mainwindow::on_pushButton1_clicked() {
    image_now = Revolve90::left90(image_now);
    // 显示当前图像
    updateState();
}
// 向左旋转90°
void mainwindow::on_pushButton2_clicked() {
    image_now = Revolve90::right90(image_now);
    // 显示当前图像
    updateState();
}

// x轴对称
void mainwindow::on_pushButton3_clicked() {
    // 对图像进行x轴对称操作
    image_now = Symmetry::xSymmetry(image_now);
    // 显示当前图像
    updateState();
}

// y轴对称
void mainwindow::on_pushButton4_clicked() {
    // 对图像进行y轴对称操作
    image_now = Symmetry::ySymmetry(image_now);
    // 显示当前图像
    updateState();
}

//光感调整
void mainwindow::on_light_perception_valueChanged(int value) {
    ui->angle_2->setText(QString("%1").arg(value));
    image_now = adjust::light_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_light_perception_sliderReleased() {
    updateState();
}

//曝光调整
void mainwindow::on_exposure_valueChanged(int value) {
    ui->angle_4->setText(QString("%1").arg(value));
    image_now = adjust::exposure_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_exposure_sliderReleased() {
    updateState();
}

//对比度调整
void mainwindow::on_contrast_ratio_valueChanged(int value) {
    ui->angle_5->setText(QString("%1").arg(value));
    image_now = adjust::contrast_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_contrast_ratio_sliderReleased() {
    updateState();
}

//曲线调整

//直方图均衡化
void mainwindow::on_Equalize_clicked() {
    // 对图像进行y轴对称操作
    image_now = adjust::equalization(image_now);
    // 显示当前图像
    updateState();
}
//饱和度调整
//曲线调色
//HSL
//锐化
void mainwindow::on_sharpening_valueChanged(int value) {
    ui->angle_6->setText(QString("%1").arg(value));
    image_now = adjust::sharpen_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_sharpening_sliderReleased() {
    test
    updateState();
}

//色温
void mainwindow::on_color_temperature_valueChanged(int value) {
    ui->angle_7->setText(QString("%1").arg(value));
    image_now = adjust::cot_adjust(original_image,value);
    QImage qImage(image_now.data, image_now.cols, image_now.rows, image_now.step, QImage::Format_BGR888);
    QImage processed_image = Image_Processing(qImage);
    ui->label_show->setPixmap(QPixmap::fromImage(processed_image));
}
//通过检测滑动条释放时刻的状态来更新全局图像数组的内容
void mainwindow::on_color_temperature_sliderReleased() {
    updateState();
}

//色调
void mainwindow::on_tone_valueChanged(int value) {
    ui->angle_8->setText(QString("%1").arg(value));
    image_now = adjust::tone_adjust(image_now,value);
    // 显示当前图像
    updateState();
}