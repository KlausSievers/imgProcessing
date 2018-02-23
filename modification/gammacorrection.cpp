#include "gammacorrection.h"
#include <math.h>

GammaCorrection::GammaCorrection()
{
    gamma = 1;
}

cv::Mat GammaCorrection::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    cv::Mat result;
    result.create(rows,cols,img.type());

    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            dataOut[j] = pow(1/(double)255 * dataIn[j], gamma) * 255;
        }
    }

    return result;

}

void GammaCorrection::setGamma(double gamma){
    this->gamma = gamma;
}

double GammaCorrection::getGamma(){
    return gamma;
}
