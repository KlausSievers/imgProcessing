#ifndef EQUALDENSITY_H
#define EQUALDENSITY_H

#include <opencv2/opencv.hpp>
#include "lookuptable.h"
#include "modifier.h"

class EqualDensity : public Modifier
{
public:
    EqualDensity(LookupTable* lookup);

    cv::Mat modify(const cv::Mat &img);

private:
    LookupTable* lookup;
};

#endif // EQUALDENSITY_H
