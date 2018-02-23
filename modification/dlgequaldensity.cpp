#include "dlgequaldensity.h"
#include "ui_dlgequaldensity.h"
#include "lookuptable.h"
#include "equaldensity.h"
#include "commandline.h"

DlgEqualDensity::DlgEqualDensity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgEqualDensity)
{
    ui->setupUi(this);
}

DlgEqualDensity::~DlgEqualDensity()
{
    delete ui;
}

void DlgEqualDensity::accept(){
    Modifier* modifier = NULL;
    QString properties = "";
    if(ui->cb2Order->isChecked()){
        modifier = getSecondOrder();
        properties = "2. Ordnung";
    } else {
        modifier = getFirstOrder();
        properties = "1. Ordnung";
    }

    CommandLine::getInstance()->addModifier(new ModifierEntry(modifier, "Äquidensiten", properties));

     QDialog::accept();
}

LookupTable* DlgEqualDensity::getFirstOrder(){
    QAbstractItemModel* model = ui->tableWidget->model();
    int row = 0;
    QModelIndex idxStart = model->index(row,0);
    QModelIndex idxEnd = model->index(row,1);
    QModelIndex idxValue = model->index(row,2);

    LookupTable* lookup = new LookupTable();
    QString end = model->data(idxEnd).toString() ;
    while(end != ""){
        lookup->setRange(model->data(idxStart).toString().toInt(), end.toInt(), model->data(idxValue).toString().toInt());

        row++;

        idxStart = model->index(row,0);
        idxEnd = model->index(row,1);
        idxValue = model->index(row,2);

        end = model->data(idxEnd).toString() ;
    }

    return lookup;
}

EqualDensity* DlgEqualDensity:: getSecondOrder(){
    return new EqualDensity(getFirstOrder());
}
