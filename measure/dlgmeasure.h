#ifndef DLGMEASURE_H
#define DLGMEASURE_H

#include <QDialog>
#include <opencv2/opencv.hpp>


namespace Ui {
class DlgMeasure;
}

class DlgMeasure : public QDialog
{
    Q_OBJECT

public:
    explicit DlgMeasure(cv::Mat &img,QWidget *parent = 0);
    ~DlgMeasure();

private:
    Ui::DlgMeasure *ui;
};

#endif // DLGMEASURE_H
