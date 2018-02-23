#include "basicmeasurment.h"
#include <QVector>
#include <math.h>

BasicMeasurment::BasicMeasurment()
{
}

double BasicMeasurment::getAverage(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    double sum = 0;
    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            sum += dataIn[j];
        }
    }

    return sum / (rows * cols);
}

int BasicMeasurment::getMedian(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    QVector<uchar> values;
    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            values.append(dataIn[j]);
        }
    }

    qSort(values);

    int size = values.size();
    if(size % 2 == 0){
        return values[size / 2];
    } else {
        return (values[size / 2 - 1] + values[size / 2]) / 2;
    }
}

double BasicMeasurment::getSquareDeviation(const cv::Mat &img){
    double avg = getAverage(img);

    int rows = img.rows;
    int cols = img.cols;

    double sum = 0;
    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            sum += pow(dataIn[j] - avg,2);
        }
    }

    return sum / (rows * cols);

}

double BasicMeasurment::getStandardDeviation(const cv::Mat &img) {
    return sqrt(getSquareDeviation(img));
}

QVector<double>* BasicMeasurment::getRelativeFrequency(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;
    int pix = rows * cols;


    QVector<double> *hist = new QVector<double>();
    for(int i = 0; i < 256; i++){
        hist->append(0);
    }

    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            int value = (int) dataIn[j];
            hist->replace(value, hist->at(value) + 1);
        }
    }

    //norm
    for(int i = 0; i < 256; i++){
        hist->replace(i, hist->at(i) / pix);
    }

    return hist;
}

QVector<double>* BasicMeasurment::getCumulatedRelativeFrequency(const cv::Mat &img){
    QVector<double>*  relFreq = getRelativeFrequency(img);

    for(int i = 1; i < 256; i++){
        relFreq->replace(i, relFreq->at(i) + relFreq->at(i-1));
    }

    return relFreq;
}

double BasicMeasurment::getEntropy(const cv::Mat &img){
    QVector<double>* relFreq = getRelativeFrequency(img);

    double sum = 0;
    for(int i = 0; i <= 255; i++){
        double n = relFreq->at(i);
        if(n != 0){
            sum += n * log2(n);
        }
    }

    delete relFreq;

    return -1*sum;
}
