#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <opencv2/opencv.hpp>
#include <QString>
#include "../modifier.h"

class LookupTable : public Modifier
{
public:
    LookupTable();

    cv::Mat modify(const cv::Mat &img);

    void setPair(int key, int value);

    void setRange(int begin, int end, int value);

    int getValue(int key);

private:
    int table[256];
};

#endif // LOOKUPTABLE_H
