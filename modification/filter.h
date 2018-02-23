#ifndef FILTER_H
#define FILTER_H

#include <opencv2/opencv.hpp>
#include <QVector>
#include <QString>
#include <qmath.h>
#include "../modifier.h"

class Filter : public Modifier
{
public:    
    Filter(QVector<QVector<double> > *mask, bool useOffset = true);
    ~Filter();

    cv::Mat modify(const cv::Mat &img);

    static  QVector<QVector<double> > *getGaussFilterMask3() {
       QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,2,1});
        QVector<double> row2({2,4,2});
        QVector<double> row3({1,2,1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getGaussFilterMask5() {
       QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({2,4,5,4,2});
        QVector<double> row2({4,9,12,9,4});
        QVector<double> row3({5,12,15,12,5});
        QVector<double> row4({2,4,5,4,2});
        QVector<double> row5({4,9,12,9,4});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);
        mask->push_back(row4);
        mask->push_back(row5);

        return mask;
     }

    static  QVector<QVector<double> > *getSobelXFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,2,1});
        QVector<double> row2({0,0,0});
        QVector<double> row3({-1,-2,-1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getSobelYFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,0,-1});
        QVector<double> row2({2,0,-2});
        QVector<double> row3({1,0,-1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getLaplaceFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({0,-1,0});
        QVector<double> row2({-1,4,-1});
        QVector<double> row3({0,-1,0});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getDiffXFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({0,0,0});
        QVector<double> row2({0,-1,1});
        QVector<double> row3({0,0,0});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getDiffYFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({0,0,0});
        QVector<double> row2({0,-1,0});
        QVector<double> row3({0,1,0});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getDiffFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({0,0,0});
        QVector<double> row2({0,-2,1});
        QVector<double> row3({0,1,0});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getEastFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({-1,1,1});
        QVector<double> row2({-1,-2,1});
        QVector<double> row3({-1,1,1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getNorthEastFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,1,1});
        QVector<double> row2({-1,-2,1});
        QVector<double> row3({-1,-1,1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getNorthFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,1,1});
        QVector<double> row2({1,-2,1});
        QVector<double> row3({-1,-1,-1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getNorthWestFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,1,1});
        QVector<double> row2({1,-2,-1});
        QVector<double> row3({1,-1,-1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getWestFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,1,-1});
        QVector<double> row2({1,-2,-1});
        QVector<double> row3({1,1,-1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getSouthWestFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({1,-1,-1});
        QVector<double> row2({1,-2,-1});
        QVector<double> row3({1,1,1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getSouthFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({-1,-1,-1});
        QVector<double> row2({1,-2,1});
        QVector<double> row3({1,1,1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }

    static  QVector<QVector<double> > *getSouthEastFilterMask() {
        QVector<QVector<double> > *mask = new QVector<QVector<double> >();

        QVector<double> row1({-1,-1,1});
        QVector<double> row2({-1,-2,1});
        QVector<double> row3({1,1,1});

        mask->push_back(row1);
        mask->push_back(row2);
        mask->push_back(row3);

        return mask;
     }


private:
    QVector<QVector<double> > *mask;
    bool useOffset;
};

#endif // FILTER_H
