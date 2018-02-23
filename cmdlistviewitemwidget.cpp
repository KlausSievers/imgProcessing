#include "cmdlistviewitemwidget.h"
#include "ui_cmdlistviewitemwidget.h"
#include "commandline.h"

CmdListViewItemWidget::CmdListViewItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CmdListViewItemWidget)
{
    ui->setupUi(this);
    connect(this, SIGNAL(showImg(cv::Mat)), CommandLine::getInstance(), SLOT(activeImgChanged(cv::Mat)));
}

CmdListViewItemWidget::~CmdListViewItemWidget()
{
    delete ui;
}

void CmdListViewItemWidget::setTitle(const QString title){
    ui->lblTitle->setText(title);
}

void CmdListViewItemWidget::setProperties(const QString prop){
    ui->lblProp->setText(prop);
}

void CmdListViewItemWidget::setImg(const cv::Mat img){
    ui->wgtImg->showImage(img);
    this->img = img;
}

void CmdListViewItemWidget::mouseDoubleClickEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        emit showImg(img);
    }
}

