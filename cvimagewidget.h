#pragma once
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <opencv2/opencv.hpp>

class CVImageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CVImageWidget(QWidget *parent = 0) : QWidget(parent) {}

    QSize sizeHint() const;
    QSize minimumSizeHint() const;
    cv::Mat& getImg();

public slots:
    void showImage(const cv::Mat &image);


protected:
    void paintEvent(QPaintEvent* /*event*/);

private:
    QImage _qimage;
    cv::Mat cvImage;
};
