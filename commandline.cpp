#include "commandline.h"
#include <QDebug>

CommandLine* CommandLine::instance = 0;

CommandLine::CommandLine() : QAbstractListModel(NULL){

}

CommandLine* CommandLine::getInstance(){
    if(instance == 0){
        instance = new CommandLine();
    }

    return instance;
}

void CommandLine::activeImgChanged(cv::Mat img){
    emit imgModified(img);
}

void CommandLine::setStartImage(const cv::Mat &img){
    startImage = img;
}

void CommandLine::clear(){
    beginRemoveRows(QModelIndex(), 0, this->modifiers.size());
    for(int i = 0; i < modifiers.size(); i++){
        delete modifiers.at(i);
    }

    modifiers.clear();

    endRemoveRows();

    emit imgModified(startImage);
}

void CommandLine::addModifier(ModifierEntry* modifier){
    beginInsertRows(QModelIndex(), this->modifiers.size(), this->modifiers.size());
        this->modifiers.append(modifier);


    cv::Mat img;
    if(this->modifiers.size() == 1){
        img = startImage;
    } else {
        img = this->modifiers.at(modifiers.size() - 2)->getImg();
    }

    cv::Mat modImg = modifier->getModifier()->modify(img);
    modifier->setImg(modImg);

    endInsertRows();
    emit imgModified(modImg);
}

void CommandLine::exectueAll(){
    cv::Mat img = startImage;
    for(int i = 0; i < modifiers.size(); i++){
        cv::Mat modImg = modifiers.at(i)->getModifier()->modify(img);
        modifiers.at(i)->setImg(modImg);
        img = modifiers.at(i)->getImg();
    }

    cv::Mat modImg = this->modifiers.last()->getImg();
    emit imgModified(modImg);
}

int CommandLine::rowCount(const QModelIndex &parent) const{
    return modifiers.size();
}


QVariant CommandLine::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        qDebug() << "index not valid";
        return QVariant();
    }

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        QVariant v;
        v.setValue<ModifierEntry *>(modifiers.at(index.row()));
        return v;
    }

    return QVariant();
}
