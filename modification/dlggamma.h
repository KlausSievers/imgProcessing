#ifndef DLGGAMMA_H
#define DLGGAMMA_H

#include <QDialog>

namespace Ui {
class DlgGamma;
}

class DlgGamma : public QDialog
{
    Q_OBJECT

public:
    explicit DlgGamma(QWidget *parent = 0);
    ~DlgGamma();

private slots:
    void gammaChanged(int spValue);
    void accept();

private:
    void calcYValues(double gamma);

    double gamma;

    Ui::DlgGamma *ui;
    QVector<double> xData;
    QVector<double> yData;
};

#endif // DLGGAMMA_H
