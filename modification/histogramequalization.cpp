#include "histogramequalization.h"
#include "../measure/basicmeasurment.h"
#include <QVector>

HistogramEqualization::HistogramEqualization()
{
}

cv::Mat HistogramEqualization::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    QVector<double> *hist = BasicMeasurment::getCumulatedRelativeFrequency(img);

    for(int i = 0; i < 256; i++){
       hist->replace(i, hist->at(i) * 255);
    }

    cv::Mat result;
    result.create(rows,cols,img.type());

    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            dataOut[j] = hist->at(dataIn[j]);
        }
    }

    return result;

}
