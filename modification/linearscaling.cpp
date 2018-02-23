#include "linearscaling.h"

LinearScaling::LinearScaling()
{
    setBrightness(0);
    setContrast(1);
}

cv::Mat LinearScaling::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    cv::Mat result;
    result.create(rows,cols,img.type());

    int offset = contrast * brightness;
    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            int pixel = contrast*dataIn[j] + offset;
            if(pixel < 0){
                pixel = 0;
            } else if(pixel > 255){
                pixel = 255;
            }

            dataOut[j] = (uchar) pixel;
        }
    }

    return result;

}

void LinearScaling::setBrightness(int brightness){
    this->brightness = brightness;
}

void LinearScaling::setContrast(int contrast){
    this->contrast = contrast;
}

int LinearScaling::getBrightness(){
    return brightness;
}

int LinearScaling::getContrast(){
    return contrast;
}
