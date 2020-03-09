
#include "drawwidget.h"

void DrawWidget::setMode(eMode mode)
{
    m_mode = mode;
    if(m_mode == eMode::MODE_LIMITS){
        disconnect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLines(const QPoint &)));
        connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLimits(const QPoint &)));
    }else{
        disconnect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLimits(const QPoint &)));
        connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLines(const QPoint &)));
    }
}

void DrawWidget::showPopupMenuLimits(const QPoint &pos)
{
    QMenu *menu = new QMenu;
    menu->addAction("Linksboven", this, SLOT(setTopLeft()));
    menu->addAction("Rechtsonder", this, SLOT(setBottomRight()));
    menu->exec(this->mapToGlobal(pos));
}

void DrawWidget::showPopupMenuLines(const QPoint &pos)
{
    QMenu *menu = new QMenu;
    menu->addAction("Wissen", this, SLOT(deletePoint()));
    menu->addAction("Alles wissen", this, SLOT(deleteAllLines()));
    menu->exec(this->mapToGlobal(pos));
}
