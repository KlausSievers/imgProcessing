#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <QObject>
#include <QAbstractListModel>
#include <QVector>
#include <opencv2/opencv.hpp>
#include "modifierentry.h"

class CommandLine : public QAbstractListModel
{
    Q_OBJECT

public:
    static CommandLine *getInstance();

    void addModifier(ModifierEntry* modifier);

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;


signals:
    void imgModified(const cv::Mat&);

public slots:
    void setStartImage(const cv::Mat &img);
    void clear();
    void exectueAll();
    void activeImgChanged(cv::Mat img);

protected:
    CommandLine();

private:
    static CommandLine *instance;

    QVector<ModifierEntry*> modifiers;
    cv::Mat startImage;

};

#endif // COMMANDLINE_H
