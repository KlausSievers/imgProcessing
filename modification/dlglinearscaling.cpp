#include "dlglinearscaling.h"
#include "ui_dlglinearscaling.h"

#include "linearscaling.h"
#include "../commandline.h"

DlgLinearScaling::DlgLinearScaling(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgLinearScaling)
{
    ui->setupUi(this);
}

DlgLinearScaling::~DlgLinearScaling()
{
    delete ui;
}

void DlgLinearScaling::accept(){
    LinearScaling* lc = new LinearScaling();
    lc->setBrightness(ui->slBrigtness->value());
    lc->setContrast(ui->slContrast->value());

    CommandLine::getInstance()->addModifier(new ModifierEntry(lc, "Linear Scaling", "Brigthness: "+QString::number(lc->getBrightness()) +" Contrast: "+QString::number(lc->getContrast())));

    QDialog::accept();
}
