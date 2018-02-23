#ifndef DLGEQUALDENSITY_H
#define DLGEQUALDENSITY_H

#include <QDialog>
#include "lookuptable.h"3
#include "equaldensity.h"

namespace Ui {
class DlgEqualDensity;
}

class DlgEqualDensity : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEqualDensity(QWidget *parent = 0);
    ~DlgEqualDensity();


    void accept();

private:
    Ui::DlgEqualDensity *ui;

    LookupTable* getFirstOrder();
    EqualDensity* getSecondOrder();
};

#endif // DLGEQUALDENSITY_H
