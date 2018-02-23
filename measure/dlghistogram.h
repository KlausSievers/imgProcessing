#ifndef DLGHISTOGRAM_H
#define DLGHISTOGRAM_H

#include <QDialog>
#include <QVector>
#include <opencv2/opencv.hpp>

namespace Ui {
class DlgHistogram;
}

class DlgHistogram : public QDialog
{
    Q_OBJECT

public:
    explicit DlgHistogram(cv::Mat &img, QWidget *parent = 0);
    ~DlgHistogram();

private:
    Ui::DlgHistogram *ui;
    QVector<double> xData;
    QVector<double> *yData;
};

#endif // DLGHISTOGRAM_H
