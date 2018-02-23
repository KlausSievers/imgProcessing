#include "cmdlistviewitemdelegate.h"
#include "modifierentry.h"


CmdListViewItemDelegate::CmdListViewItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent), m_itemWidget(new CmdListViewItemWidget)
{
}

CmdListViewItemDelegate::~CmdListViewItemDelegate()
{
    if(m_itemWidget) {
        delete m_itemWidget;
        m_itemWidget = NULL;
    }
}


void CmdListViewItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    m_itemWidget->resize(option.rect.size());

    // Update data of widget here.
    ModifierEntry *m = index.data().value<ModifierEntry *>();
    m_itemWidget->setTitle(m->getTitle());
    m_itemWidget->setProperties(m->getPropStr());
    m_itemWidget->setImg(m->getImgScaled());

    // Change the background color of the widget if it is selected.
    QPalette pal;
    if ((option.state & QStyle::State_Selected) == QStyle::State_Selected)
    {
        pal.setBrush(QPalette::Window, QBrush(QColor(Qt::lightGray)));
    }
    else
    {
        pal.setBrush(QPalette::Window, QBrush(QColor(Qt::transparent)));
    }
    m_itemWidget->setPalette(pal);

    // Paint the widget now.
    painter->save();
    painter->translate(option.rect.topLeft());
    m_itemWidget->render(painter);
    painter->restore();
}


QSize CmdListViewItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
  const int width = m_itemWidget->minimumWidth();
  const int height = m_itemWidget->minimumHeight();
  return QSize(width,height);
   // return QSize(200,200);
}
