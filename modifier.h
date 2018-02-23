#ifndef MODIFIER_H
#define MODIFIER_H

#include <opencv2/opencv.hpp>
#include <QString>
#include <QMetaType>
#include <QObject>

class Modifier
{

public:
    Modifier();
    virtual cv::Mat modify(const cv::Mat &img) = 0;

};

#endif // MODIFIER_H
