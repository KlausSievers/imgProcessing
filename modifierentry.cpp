#include "modifierentry.h"

ModifierEntry::ModifierEntry(Modifier* mod, QString strTitle, QString strProp) :
    mod(mod), strTitle(strTitle), strProp(strProp)
{
}

ModifierEntry::~ModifierEntry()
{
    delete mod;
}

ModifierEntry::ModifierEntry(){}

Modifier* ModifierEntry::getModifier(){
    return mod;
}

QString ModifierEntry::getTitle(){
    return strTitle;
}

void ModifierEntry::setPropStr(QString strProp){
    this->strProp = strProp;
}

QString ModifierEntry::getPropStr(){
    return strProp;
}

cv::Mat ModifierEntry::getImg(){
    return img;
}

cv::Mat ModifierEntry::getImgScaled(){
    return imgScaled;
}

void ModifierEntry::setImg(cv::Mat &img){
    this->img = img;
    cv::resize(img, imgScaled, cv::Size(100,100));
}
