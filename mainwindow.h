#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void openDlgMeasure();
    void openDlgGreyvalueMatrix();
    void openDlgHistogramm();

    void openDlgGamma();
    void openDlgLinearScaling();
    void openDlgEqualDensity();
    void startHistEqual();
    void startCanny();
    void startGauss();
    void startSobelX();
    void startSobelY();
    void startLaplace();
    void startDiffX();
    void startDiffY();
    void startDiffBoth();
    void startNorth();
    void startNorthEast();
    void startEast();
    void startSouthEast();
    void startSouth();
    void startSouthWest();
    void startWest();
    void startNorthWest();
    void startDilatation();
    void startErosion();
    void startMedian();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
