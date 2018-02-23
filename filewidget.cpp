#include "filewidget.h"
#include "ui_filewidget.h"
#include <QFileDialog>

FileWidget::FileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileWidget)
{
    ui->setupUi(this);

    connect(ui->btnLoad, SIGNAL(pressed()), this, SLOT(loadFile()));
    connect(ui->btnReset, SIGNAL(pressed()), this, SIGNAL(reset()));
 }

FileWidget::~FileWidget()
{
    delete ui;
}

void FileWidget::loadFile(){
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home", tr("Image Files (*.png *.jpg *.bmp)"));

    if(fileName.count() > 0){
        cv::Mat image = cv::imread(fileName.toStdString(), CV_LOAD_IMAGE_COLOR);
        cv::cvtColor(image, image, CV_BGR2GRAY);

        emit loadImage(image);
    }
}

void FileWidget::saveFile(){

}
