#ifndef LINEARSCALING_H
#define LINEARSCALING_H

#include <opencv2/opencv.hpp>
#include <QString>
#include "../modifier.h"

class LinearScaling : public Modifier
{
public:
    LinearScaling();

    cv::Mat modify(const cv::Mat &img);

    void setBrightness(int brightness);
    void setContrast(int contrast);

    int getBrightness();
    int getContrast();

private:
    int brightness;
    int contrast;
};

#endif // LINEARSCALING_H
