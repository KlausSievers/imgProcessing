#include "dlghistogram.h"
#include "ui_dlghistogram.h"
#include "basicmeasurment.h"

DlgHistogram::DlgHistogram(cv::Mat &img, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgHistogram)
{
    ui->setupUi(this);

     double max = 0;
    yData= BasicMeasurment::getRelativeFrequency(img);
    for(int i = 0; i < 256; i++){
        xData.append(i);

        if(yData->at(i) > max){
            max = yData->at(i);
        }
    }

    ui->wgtHist->addGraph();
    ui->wgtHist->graph(0)->setData(xData, *yData);
    ui->wgtHist->xAxis->setRange(0, 255);
    ui->wgtHist->yAxis->setRange(0,max * 1.1);
    ui->wgtHist->replot();
}

DlgHistogram::~DlgHistogram()
{
    delete yData;
    delete ui;
}
