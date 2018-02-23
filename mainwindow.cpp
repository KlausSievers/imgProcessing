#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>

#include "modification/dlggamma.h"
#include "modification/dlglinearscaling.h"
#include "commandline.h"
#include "modification/filter.h"
#include "measure/dlgmeasure.h"
#include "measure/dlghistogram.h"
#include "modification/dlgequaldensity.h"
#include "modification/histogramequalization.h"
#include "modification/morphology.h"
#include "modification/dlgcanny.h"
#include "modifierentry.h"
#include "cmdlistviewitemdelegate.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->cmdListView->setItemDelegate(new CmdListViewItemDelegate());
    ui->cmdListView->setModel(CommandLine::getInstance());

    connect(ui->wgtFile, SIGNAL(loadImage(cv::Mat)), ui->wgtImg, SLOT(showImage(cv::Mat)));
    connect(ui->wgtFile, SIGNAL(loadImage(cv::Mat)), CommandLine::getInstance(), SLOT(setStartImage(cv::Mat)));    
    connect(ui->wgtFile, SIGNAL(reset()), CommandLine::getInstance(), SLOT(clear()));

    connect(ui->actionNumbers,SIGNAL(triggered()), this, SLOT(openDlgMeasure()));
    connect(ui->actionGreyvalue_Matrix,SIGNAL(triggered()), this, SLOT(openDlgGreyvalueMatrix()));
    connect(ui->actionHistogramm,SIGNAL(triggered()), this, SLOT(openDlgHistogramm()));

    connect(ui->actionGamma, SIGNAL(triggered()), this, SLOT(openDlgGamma()));
    connect(ui->actionLinear_Scaling, SIGNAL(triggered()), this, SLOT(openDlgLinearScaling()));
    connect(ui->actionEqualDensity, SIGNAL(triggered()), this, SLOT(openDlgEqualDensity()));
    connect(ui->actionHistogram_Equalization, SIGNAL(triggered()), this, SLOT(startHistEqual()));

    connect(ui->actionCanny, SIGNAL(triggered()), this, SLOT(startCanny()));

    connect(ui->actionGau,SIGNAL(triggered()), this, SLOT(startGauss()));
    connect(ui->actionSobel_X,SIGNAL(triggered()), this, SLOT(startSobelX()));
    connect(ui->actionSobel_Y,SIGNAL(triggered()), this, SLOT(startSobelY()));
    connect(ui->actionLaplace,SIGNAL(triggered()), this, SLOT(startLaplace()));

    //Diff
    connect(ui->actionX ,SIGNAL(triggered()), this, SLOT(startDiffX()));
    connect(ui->actionY,SIGNAL(triggered()), this, SLOT(startDiffY()));
    connect(ui->actionBoth,SIGNAL(triggered()), this, SLOT(startDiffBoth()));

    //Compass
    connect(ui->actionNorth,SIGNAL(triggered()), this, SLOT(startNorth()));
    connect(ui->actionNorthWest,SIGNAL(triggered()), this, SLOT(startNorthWest()));
    connect(ui->actionNorthEast,SIGNAL(triggered()), this, SLOT(startNorthEast()));
    connect(ui->actionSouth,SIGNAL(triggered()), this, SLOT(startSouth()));
    connect(ui->actionSouthWest,SIGNAL(triggered()), this, SLOT(startSouthWest()));
    connect(ui->actionSouthEast,SIGNAL(triggered()), this, SLOT(startSouthEast()));
    connect(ui->actionEast,SIGNAL(triggered()), this, SLOT(startEast()));
    connect(ui->actionWest,SIGNAL(triggered()), this, SLOT(startWest()));

    //Morphology
    connect(ui->actionDilatation,SIGNAL(triggered()), this, SLOT(startDilatation()));
    connect(ui->actionErosion,SIGNAL(triggered()), this, SLOT(startErosion()));
    connect(ui->actionMedian,SIGNAL(triggered()), this, SLOT(startMedian()));


    connect(CommandLine::getInstance(), SIGNAL(imgModified(cv::Mat)), ui->wgtImg, SLOT(showImage(cv::Mat)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openDlgMeasure(){
    DlgMeasure dlgMeasure(ui->wgtImg->getImg(), this);
    dlgMeasure.exec();
}

void MainWindow::openDlgGreyvalueMatrix(){

}

void MainWindow::openDlgHistogramm(){
    DlgHistogram dlgHist(ui->wgtImg->getImg(),this);
    dlgHist.exec();
}

void MainWindow::openDlgGamma(){
    DlgGamma dlgGamma(this);
    dlgGamma.exec();
}

void MainWindow::openDlgLinearScaling(){
    DlgLinearScaling dlgLinScale(this);
    dlgLinScale.exec();
}

void MainWindow::openDlgEqualDensity(){
    DlgEqualDensity dlgEqualDensity(this);
    dlgEqualDensity.exec();
}


void MainWindow::startHistEqual(){
    CommandLine::getInstance()->addModifier(new ModifierEntry(new HistogramEqualization(), "Histogramm Equalization", ""));
}

void MainWindow::startCanny(){
    DlgCanny dlgCanny(this);
    dlgCanny.exec();
}

void MainWindow::startGauss() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getGaussFilterMask3()), "Gauß Filter", ""));
}

void MainWindow::startSobelX() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getSobelXFilterMask(), false), "Sobel Filter", "X"));
}

void MainWindow::startSobelY() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getSobelYFilterMask(), false), "Sobel Filter", "Y"));
}

void MainWindow::startLaplace() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getLaplaceFilterMask()), "Laplace Filter", ""));
}

void MainWindow::startDiffX() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getDiffXFilterMask()), "Difference Filter", "X"));
}

void MainWindow::startDiffY() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getDiffYFilterMask()), "Difference Filter", "Y"));
}

void MainWindow::startDiffBoth() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getDiffFilterMask()), "Difference Filter", "Both"));
}

void MainWindow::startNorth() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getNorthFilterMask()), "Compass Filter", "North"));
}

void MainWindow::startNorthEast() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getNorthEastFilterMask()), "Compass Filter", "North East"));
}

void MainWindow::startEast() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getEastFilterMask()), "Compass Filter", "East"));
}

void MainWindow::startSouthEast() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getSouthEastFilterMask()), "Compass Filter", "South East"));
}

void MainWindow::startSouth() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getSouthFilterMask()), "Compass Filter", "South"));
}

void MainWindow::startSouthWest() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getSouthWestFilterMask()), "Compass Filter", "South West"));
}

void MainWindow::startWest() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getWestFilterMask()), "Compass Filter", "West"));
}

void MainWindow::startNorthWest() {
    CommandLine::getInstance()->addModifier(new ModifierEntry(new Filter(Filter::getNorthWestFilterMask()), "Compass Filter", "North West"));
}

void MainWindow::startDilatation() {
    Morphology *dilatation = new Morphology();
    dilatation->setSetFunction(new Dilatation());
    dilatation->setSetProvider(new SqareSetProvider(3));

    CommandLine::getInstance()->addModifier(new ModifierEntry(dilatation, "Dilatation", ""));
}

void MainWindow::startErosion() {
    Morphology *erosion = new Morphology();
    erosion->setSetFunction(new Erosion());
    erosion->setSetProvider(new SqareSetProvider(3));

    CommandLine::getInstance()->addModifier(new ModifierEntry(erosion, "Erosion", ""));
}

void MainWindow::startMedian() {
    Morphology *median = new Morphology();
    median->setSetFunction(new Median());
    median->setSetProvider(new SqareSetProvider(3));

    CommandLine::getInstance()->addModifier(new ModifierEntry(median, "Median", ""));
}
