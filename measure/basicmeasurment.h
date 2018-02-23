#ifndef BASICMEASURMENT_H
#define BASICMEASURMENT_H

#include <opencv2/opencv.hpp>
#include <QVector>

class BasicMeasurment
{
public:
    BasicMeasurment();

    static double getAverage(const cv::Mat &img);

    static int getMedian(const cv::Mat &img);

    static double getSquareDeviation(const cv::Mat &img);

    static double getStandardDeviation(const cv::Mat &img);

    static QVector<double>* getRelativeFrequency(const cv::Mat &img);

    static QVector<double>* getCumulatedRelativeFrequency(const cv::Mat &img);

    static double getEntropy(const cv::Mat &img);

};

#endif // BASICMEASURMENT_H
