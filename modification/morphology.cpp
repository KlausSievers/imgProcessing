#include "morphology.h"

Morphology::Morphology() : Modifier()
{
}


cv::Mat Morphology::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    cv::Mat result(rows, cols, img.type());

    for(int i = 0; i < rows; i++){
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){

            dataOut[j] = this->setFunction->getNewPixelValue(this->setProvider->getPixelSet(img, i, j));

        }
    }

    return result;
}

void Morphology::setSetProvider(SetProvider* setProvider){
    this->setProvider = setProvider;
}

void Morphology::setSetFunction(SetFunction* setFunction){
    this->setFunction = setFunction;
}
