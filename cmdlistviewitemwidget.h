#ifndef CMDLISTVIEWITEMWIDGET_H
#define CMDLISTVIEWITEMWIDGET_H

#include <QWidget>
#include <opencv2/opencv.hpp>
#include <QMouseEvent>

namespace Ui {
class CmdListViewItemWidget;
}

class CmdListViewItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CmdListViewItemWidget(QWidget *parent = 0);
    ~CmdListViewItemWidget();

    void mouseDoubleClickEvent(QMouseEvent* event);

signals:
    void showImg(const cv::Mat img);

public slots:
    void setTitle(const QString title);
    void setProperties(const QString prop);
    void setImg(const cv::Mat img);

private:
    Ui::CmdListViewItemWidget *ui;
    cv::Mat img;
};

#endif // CMDLISTVIEWITEMWIDGET_H
