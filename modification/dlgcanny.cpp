#include "dlgcanny.h"
#include "ui_dlgcanny.h"
#include "commandline.h"
#include "canny.h"

DlgCanny::DlgCanny(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgCanny)
{
    ui->setupUi(this);
}

DlgCanny::~DlgCanny()
{
    delete ui;
}

void DlgCanny::accept() {
    int low = ui->slLow->value();
    int high = ui->slHigh->value();
    CommandLine::getInstance()->addModifier(new ModifierEntry(new CannyMod(low, high), "Canny", "Low: "+QString::number(low)+" / High: "+QString::number(high)));
    QDialog::accept();
}



