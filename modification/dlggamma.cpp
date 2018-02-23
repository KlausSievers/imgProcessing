#include "dlggamma.h"
#include "ui_dlggamma.h"

#include <math.h>
#include <iostream>
#include "gammacorrection.h"
#include "../commandline.h"

DlgGamma::DlgGamma(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgGamma),
    gamma(1)
{
    ui->setupUi(this);

    connect(ui->spnGamma, SIGNAL(valueChanged(int)), this, SLOT(gammaChanged(int)));

    for(int i = 0; i < 256; i++){
        xData.append(i);
    }

    ui->graphGamma->addGraph();
    ui->graphGamma->xAxis->setRange(0,255);
    ui->graphGamma->yAxis->setRange(0,255);
    ui->graphGamma->repaint();
}

DlgGamma::~DlgGamma()
{
    delete ui;
}

void DlgGamma::gammaChanged(int spValue){
    if(spValue >= 257) {
        gamma = spValue - 256;
    } else {
        gamma = 1/ (double) 256 * spValue;
    }

    ui->tfGamma->setText(QString::number(gamma));


    calcYValues(gamma);
}

void DlgGamma::calcYValues(double gamma){
    yData.clear();
    for(int i = 0; i < 256; i++){
        yData.append(pow(1/ (double) 255 * i, gamma) * 255);
    }

    ui->graphGamma->graph(0)->setData(xData, yData);
    ui->graphGamma->replot();

}

void DlgGamma::accept(){
    GammaCorrection* gc = new GammaCorrection();
    gc->setGamma(gamma);

    CommandLine::getInstance()->addModifier(new ModifierEntry(gc, "Gamma Correction", "Gamma: "+QString::number(this->gamma)));

    QDialog::accept();
}
