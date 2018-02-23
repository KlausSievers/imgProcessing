#include "dlgmeasure.h"
#include "ui_dlgmeasure.h"
#include "basicmeasurment.h"

DlgMeasure::DlgMeasure(cv::Mat &img, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgMeasure)
{
    ui->setupUi(this);

    ui->tfAvg->setText(QString::number(BasicMeasurment::getAverage(img)));
    ui->tfMedian->setText(QString::number(BasicMeasurment::getMedian(img)));
    ui->tfEtnropie->setText(QString::number(BasicMeasurment::getEntropy(img)));
    ui->tfVar->setText(QString::number(BasicMeasurment::getSquareDeviation(img)));
    ui->tfStandard->setText(QString::number(BasicMeasurment::getStandardDeviation(img)));
}

DlgMeasure::~DlgMeasure()
{
    delete ui;
}
