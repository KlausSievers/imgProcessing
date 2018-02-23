#ifndef MORPHOLOGY_H
#define MORPHOLOGY_H

#include "modifier.h"
#include <opencv2/opencv.hpp>
#include <QSet>
#include <QPoint>

class SetProvider
{
public:
    virtual QSet<uchar> getPixelSet(const cv::Mat &img, int x, int y) = 0;
};

class SetFunction
{
public:
    virtual uchar getNewPixelValue(const QSet<uchar> set) = 0;
};


class Morphology : public Modifier
{
public:
    Morphology();
    ~Morphology(){
        delete setProvider;
        delete setFunction;
    }

    cv::Mat modify(const cv::Mat &img);

    void setSetProvider(SetProvider* setProvider);
    void setSetFunction(SetFunction* setFunction);

private:
    SetProvider *setProvider;
    SetFunction *setFunction;

};


//Set Provider
class SqareSetProvider : public SetProvider
{

public:
    SqareSetProvider(int length){
        Q_ASSERT(length % 2 != 0);
        this->length = length;
    }

    QSet<uchar> getPixelSet(const cv::Mat &img, int x, int y){
        QSet<uchar> result;

        QPoint toAdd;
        for(int i = -1 * (length / 2); i <= (length / 2); i++){
            for(int j =  -1 * (length / 2); j <=  (length / 2); j++){
                toAdd.setX(x + i);
                toAdd.setY(y + j);

                if(toAdd.x() >= 0 && toAdd.x() < img.cols && toAdd.y() >= 0 && toAdd.y() < img.rows){
                      result.insert(img.at<uchar>(toAdd.x(), toAdd.y()));
                }
            }
        }

        return result;
    }

private:
    int length;
};

//Function
class Erosion : public SetFunction
{
    uchar getNewPixelValue(QSet<uchar> set){
        QSet<uchar>::iterator i;
        uchar min = (uchar)255;
        for (i = set.begin(); i != set.end(); ++i){
            uchar value = *i;
            if(value < min){
                min = value;
            }
        }
        return min;
    }
};

class Dilatation : public SetFunction
{
    uchar getNewPixelValue(QSet<uchar> set){
        QSet<uchar>::iterator i;
        uchar max = (uchar)0;
        for (i = set.begin(); i != set.end(); ++i){
            uchar value = *i;
            if(value > max){
                max = value;
            }
        }
        return max;
    }
};

class Median : public SetFunction
{
    uchar getNewPixelValue(QSet<uchar> set){
        QList<uchar> list = set.toList();
        qSort(list);

        if(list.size() % 2 == 0){
           uchar a = list.at(list.size() / 2);
           uchar b = list.at(list.size() / 2)+1;

           return (a + b) / 2;
        } else {
            return list.at(list.size() / 2);
        }
    }
};

#endif // MORPHOLOGY_H
