#include "filter.h"
#include <math.h>

Filter::Filter(QVector<QVector<double> > *mask, bool useOffset) : Modifier()
{
    this->mask = mask;
    this->useOffset = useOffset;
}


Filter::~Filter()
{
    delete mask;
}

//just for square matrix (k = (m-1) / 2)
cv::Mat Filter::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    cv::Mat result(rows, cols, img.type());

    int offset = 0;
    int max = 0;
    int value = 0;
    double norm = 0;
    if(useOffset) {
          for(int i = 0; i < mask->length(); i++){
            for(int j = 0; j <mask->at(i).length(); j++){
                value = mask->at(i).at(j);
                if( value < 0){
                    offset += qAbs(value);
                } else {
                    max += value;
                }
            }
        }

        norm = (double) 1 / (max+ offset);
        offset *= 255;
        offset = qRound(offset * norm);
    }

    for(int i = 1; i < rows-1; i++){
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 1; j < cols-1; j++){

            //calc new value for s(i,j)
            int sum = 0;
            int k = (mask->length()-1) / 2;
            for(int u = 0; u < mask->length(); u++){
                for(int v = 0; v < mask->at(u).length(); v++){
                    int p = img.at<uchar>(i + k - u, j +k - v);
                    int f = mask->at(u).at(v);
                    int plus = p*f;
                    sum +=  plus;
                }
            }

            double pixel =  0;
            if(useOffset){
                pixel =  norm * sum + offset;
            } else {
                 pixel =  qAbs(sum);
            }

            dataOut[j] = (uchar) pixel;

        }
    }

    return result;
}
