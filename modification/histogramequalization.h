#ifndef HISTOGRAMEQUALIZATION_H
#define HISTOGRAMEQUALIZATION_H

#include <opencv2/opencv.hpp>
#include <QString>
#include "../modifier.h"

class HistogramEqualization : public Modifier
{
public:
    HistogramEqualization();

    cv::Mat modify(const cv::Mat &img);

};

#endif // HISTOGRAMEQUALIZATION_H
