#ifndef DLGCANNY_H
#define DLGCANNY_H

#include <QDialog>
#include "modification/canny.h"
#include "modifierentry.h"

namespace Ui {
class DlgCanny;
}

class DlgCanny : public QDialog
{
    Q_OBJECT

public:
    explicit DlgCanny(QWidget *parent = 0);
    ~DlgCanny();

     void accept();

private:
    Ui::DlgCanny *ui;
};

#endif // DLGCANNY_H
