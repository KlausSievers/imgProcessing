#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>

namespace Ui {
class FileWidget;
}

class FileWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileWidget(QWidget *parent = 0);
    ~FileWidget();

signals:
    void loadImage(cv::Mat);
    void reset();

private slots:
    void loadFile();
    void saveFile();
private:
    Ui::FileWidget *ui;
};

#endif // FILEWIDGET_H
