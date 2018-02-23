#ifndef DLGLINEARSCALING_H
#define DLGLINEARSCALING_H

#include <QDialog>

namespace Ui {
class DlgLinearScaling;
}

class DlgLinearScaling : public QDialog
{
    Q_OBJECT

public:
    explicit DlgLinearScaling(QWidget *parent = 0);
    ~DlgLinearScaling();

    void accept();

private:
    Ui::DlgLinearScaling *ui;
};

#endif // DLGLINEARSCALING_H
