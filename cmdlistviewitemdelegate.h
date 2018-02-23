#ifndef CMDLISTVIEWITEMDELEGATE_H
#define CMDLISTVIEWITEMDELEGATE_H

#include <QStyledItemDelegate>
#include "cmdlistviewitemwidget.h"
#include <QPainter>

class CmdListViewItemDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit CmdListViewItemDelegate(QObject *parent = 0);
    ~CmdListViewItemDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    protected:
        CmdListViewItemWidget *m_itemWidget;

private:
    void mouseDoubleClickEvent(QMouseEvent * e );

signals:

public slots:

};

#endif // CMDLISTVIEWITEMDELEGATE_H
