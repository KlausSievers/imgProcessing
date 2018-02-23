#ifndef CANNY_H
#define CANNY_H

#include "modifier.h"
#include "filter.h"
#include "morphology.h"
#include <opencv2/opencv.hpp>

class CannyMod : public Modifier
{
public:
    CannyMod(int lowerThreshold, int higherThreshold);

    cv::Mat modify(const cv::Mat &img);

private:
    cv::Mat nonMaximumCompression(const cv::Mat &gradient, const cv::Mat &direction);
    cv::Mat doubleTreshold(const cv::Mat &img);
    cv::Mat hysterese(const cv::Mat &img);

    Filter* gaussFilter;
    Filter* sobelXFilter;
    Filter* sobelYFilter;

    SetProvider* providerHyst;
    SetFunction* maxFunc;

    int lowerThreshold;
    int higherThreshold;
};

#endif // CANNY_H
