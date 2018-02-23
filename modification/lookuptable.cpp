#include "lookuptable.h"

LookupTable::LookupTable()
{
}

cv::Mat LookupTable::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    cv::Mat result;
    result.create(rows,cols,img.type());

    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            dataOut[j] = table[dataIn[j]];
        }
    }

    return result;
}

void LookupTable::setPair(int key, int value){
    if(value < 0) {
        value = 0;
    } else if(value > 255){
        value = 255;
    }

    table[key] = value;
}

void LookupTable::setRange(int begin, int end, int value){
    if(end >= begin){
        for(int i = begin; i <= end; i++){
            setPair(i, value);
        }
    }
}

int LookupTable::getValue(int key){
    return table[key];
}
