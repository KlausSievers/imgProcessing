#include "equaldensity.h"

EqualDensity::EqualDensity(LookupTable* lookup) :
    Modifier(),
    lookup(lookup)
{

}


cv::Mat EqualDensity::modify(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;

    cv::Mat result, firstOrder;
    result.create(rows,cols,img.type());

    firstOrder = lookup->modify(img);

    for(int i = 0; i < rows; i++){
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
         int diff = 0;
         int faktor = 0;

          if(j > 0){
              diff -= firstOrder.at<uchar>(i,j-1);
              faktor++;
          }

          if(j < cols - 1){
              diff -= firstOrder.at<uchar>(i,j+1);
              faktor++;
          }

          if(i > 0){
              diff -= firstOrder.at<uchar>(i-1,j);
              faktor++;
          }

          if(i < rows - 1){
              diff -= firstOrder.at<uchar>(i+1,j);
              faktor++;
          }

          diff += faktor * firstOrder.at<uchar>(i,j);

          if(diff == 0){
              dataOut[j] = (uchar) 255;
          } else {
              dataOut[j] = (uchar) 0;
          }

        }
    }

    return result;

}
