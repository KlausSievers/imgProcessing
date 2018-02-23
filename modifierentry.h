#ifndef MODIFIERENTRY_H
#define MODIFIERENTRY_H

#include "modifier.h"
#include <opencv2/opencv.hpp>
#include <QString>

class ModifierEntry
{
public:
    ModifierEntry(Modifier* mod, QString strTitle, QString strProp);
    ModifierEntry();
    ~ModifierEntry();

    Modifier* getModifier();
    QString getTitle();
    void setPropStr(QString strProp);
    QString getPropStr();
    cv::Mat getImg();
    cv::Mat getImgScaled();

    void setImg(cv::Mat &img);

private:
    Modifier* mod;
    QString strTitle;
    QString strProp;
    cv::Mat img;
    //100x100
    cv::Mat imgScaled;
};

Q_DECLARE_METATYPE(ModifierEntry)
Q_DECLARE_METATYPE(ModifierEntry *)

#endif // MODIFIERENTRY_H
