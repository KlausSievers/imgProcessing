#include "canny.h"
#include "filter.h"
#include "commandline.h"

CannyMod::CannyMod(int lowerThreshold, int higherThreshold) : Modifier(),
    lowerThreshold(lowerThreshold), higherThreshold(higherThreshold),
    providerHyst(new SqareSetProvider(3)), maxFunc(new Dilatation()),
    gaussFilter(new Filter(Filter::getGaussFilterMask5())),
    sobelXFilter(new Filter(Filter::getSobelXFilterMask(),false)), sobelYFilter(new Filter(Filter::getSobelYFilterMask(),false))
{

}


cv::Mat CannyMod::modify(const cv::Mat &img)
{
    cv::Mat gauss = gaussFilter->modify(img);
     cv::Mat sobelX = sobelXFilter->modify(gauss);
     cv::Mat sobelY = sobelYFilter->modify(gauss);

    int rows = img.rows;
    int cols = img.cols;

    cv::Mat gradient(rows, cols, img.type());
    cv::Mat direction(rows, cols, img.type());

    for(int i = 0; i < rows; i++){
        const uchar* dataInX =sobelX.ptr<uchar>(i);
        const uchar* dataInY =sobelY.ptr<uchar>(i);

        uchar* dataOutGradient = gradient.ptr<uchar>(i);
        uchar* dataOutDirection = direction.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            double y = (double)dataInY[j];
            double x = (double)dataInX[j];
            dataOutGradient[j] = (uchar)sqrt(pow(x,2) + pow(y,2));
            double dir = atan2(y, x)*(180 / M_PI);
            //std::cout << dir << std::endl;

            int rounded = 0;

            if(dir >= 0 && dir <= 22.5 || dir > 157.5 && dir <= 180 ){
                rounded = 0;
            } else if(dir > 22.5 && dir <= 67.5){
                rounded = 45;
            } else if(dir > 67.5 && dir < 112.5){
                rounded = 90;
            } else{
                rounded = 135;
            }

            dataOutDirection[j] = (uchar) rounded;
        }
    }

    //cv::imshow("Gradient",gradient);
    //cv::imshow("Direction",direction);
    cv::Mat nmc = nonMaximumCompression(gradient, direction);
    //cv::imshow("nonMaximumCompression",nmc);
    cv::Mat dblThresh = doubleTreshold(nmc);
    //cv::imshow("Double Threshold", dblThresh);
   // cv::Mat hyst = hysterese(dblThresh);
    //cv::imshow("Hysterese", hyst);

    //cv::Mat cannyImg;
    //cv::Canny(img, cannyImg, 20, 80, 5);
    //cv::imshow("cv Canny", cannyImg);
   return dblThresh;

}

cv::Mat CannyMod::nonMaximumCompression(const cv::Mat &gradient, const cv::Mat &direction){
    int rows = gradient.rows;
    int cols = gradient.cols;

    cv::Mat nmc(rows, cols, gradient.type());;
    for(int i = 0; i < rows; i++){
        const uchar* dataInGradient =gradient.ptr<uchar>(i);
        const uchar* dataInDirection =direction.ptr<uchar>(i);

        uchar* dataOutNMC = nmc.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            int dir = (int) dataInDirection[j];
            uchar value = dataInGradient[j];
            uchar p1 = 0;
            uchar p2 = 0;

            switch(dir){
            case 0:
                if(j > 0){
                    p1 = dataInGradient[j-1];
                }
                if(j < cols - 1) {
                    p2 = dataInGradient[j+1];
                }
                break;
            case 45:
                if(i > 0 && j < cols - 1) {
                    p1 = gradient.at<uchar>(i-1,j+1);
                }
                if(i < rows - 1 && j > 0){
                    p2 = gradient.at<uchar>(i+1,j-1);
                }
                break;
            case 90:
                if(i > 0){
                    p1 = gradient.at<uchar>(i-1,j);
                }
                if(i < rows - i){
                    p2 = gradient.at<uchar>(i+1,j);
                }
                break;
            case 135:
                if(i < rows - 1 && j < cols -1){
                    p1 = gradient.at<uchar>(i+1,j+1);
                }
                if(i > 0 && j > 0){
                    p2 = gradient.at<uchar>(i-1,j-1);
                }
                break;
            }

            if(value > p1 && value > p2){
                dataOutNMC[j] = value;
            } else {
                dataOutNMC[j] = 0;
            }

        }
    }

    return nmc;
}

cv::Mat CannyMod::doubleTreshold(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;
    cv::Mat result(rows, cols, img.type());;
    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            int value = (int) dataIn[j];
            if(value < lowerThreshold){
                dataOut[j] = (uchar) 0;
            }  else if(value > higherThreshold){
                dataOut[j] = (uchar) 255;
            } else {
                QSet<uchar> set = providerHyst->getPixelSet(img, i,j);
                if(maxFunc->getNewPixelValue(set) == (uchar) 255) {
                    dataOut[j] = (uchar)255;
                } else {
                    dataOut[j] = (uchar) 0;
                }

                //dataOut[j] = (uchar) 128;
            }

        }


    }
    return result;
}

cv::Mat CannyMod::hysterese(const cv::Mat &img){
    int rows = img.rows;
    int cols = img.cols;
    cv::Mat result(rows, cols, img.type());;
    for(int i = 0; i < rows; i++){
        const uchar* dataIn =img.ptr<uchar>(i);
        uchar* dataOut = result.ptr<uchar>(i);

        for(int j = 0; j < cols; j++){
            if(dataIn[i] == (uchar) 128){
                QSet<uchar> set = providerHyst->getPixelSet(img, i,j);
                if(maxFunc->getNewPixelValue(set) == (uchar) 255) {
                    dataOut[j] = (uchar)255;
                } else {
                    dataOut[j] = (uchar) 0;
                }

            }

        }
    }

    return result;
}
