#ifndef GAMMACORRECTION_H
#define GAMMACORRECTION_H

#include <opencv2/opencv.hpp>
#include <QString>
#include "../modifier.h"

class GammaCorrection : public Modifier
{
public:
    GammaCorrection();

    cv::Mat modify(const cv::Mat &img);

    void setGamma(double gamma);

    double getGamma();

 private:
    double gamma;
};

#endif // GAMMACORRECTION_H
