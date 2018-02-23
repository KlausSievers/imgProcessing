#pragma once
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include "cvimagewidget.h"


QSize CVImageWidget::sizeHint() const {
    return _qimage.size();
}

QSize CVImageWidget::minimumSizeHint() const {
    return _qimage.size();
}

void CVImageWidget::showImage(const cv::Mat &image) {
    // Convert the image to the RGB888 format
    switch (image.type()) {
    case CV_8UC1:
        cvtColor(image, cvImage, CV_GRAY2RGB);
        break;
    case CV_8UC3:
        cvtColor(image, cvImage, CV_BGR2RGB);
        break;
    }

    // QImage needs the data to be stored continuously in memory
    assert(cvImage.isContinuous());
    // Assign OpenCV's image buffer to the QImage. Note that the bytesPerLine parameter
    // (http://qt-project.org/doc/qt-4.8/qimage.html#QImage-6) is 3*width because each pixel
    // has three bytes.
    _qimage = QImage(cvImage.data, cvImage.cols, cvImage.rows, cvImage.cols*3, QImage::Format_RGB888);

    this->setFixedSize(image.cols, image.rows);

    repaint();
}

void CVImageWidget::paintEvent(QPaintEvent* /*event*/) {
    // Display the image
    QPainter painter(this);
    painter.drawImage(QPoint(0,0), _qimage);
    painter.end();
}

cv::Mat& CVImageWidget::getImg(){
    return cvImage;
}

