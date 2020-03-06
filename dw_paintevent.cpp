
#include "linedrawer.h"

using namespace std;

void DrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // LineDrawer ld;

    // ld.drawCursorFollow(painter);
    if (m_img) painter.drawImage(0,0,*m_img);
        painter.drawLine(m_mouse_location.x(), 0, m_mouse_location.x(),height());
        painter.drawLine(0, m_mouse_location.y(), width(), m_mouse_location.y());

    if(m_topleft.x()!=-1){
        painter.drawLine(m_topleft.x() - 5, m_topleft.y(), m_topleft.x() + 5, m_topleft.y());
        painter.drawLine(m_topleft.x(), m_topleft.y() - 5, m_topleft.x(), m_topleft.y() + 5);
    }
    if(m_bottomright.x()!=-1){
        painter.drawLine(m_bottomright.x() - 5, m_bottomright.y(), m_bottomright.x() + 5, m_bottomright.y());
        painter.drawLine(m_bottomright.x(), m_bottomright.y() - 5, m_bottomright.x(), m_bottomright.y() + 5);
    }

    QString xtxt = QString("%1").arg(m_mouse_location.x());
    QString ytxt = QString("%1").arg(m_mouse_location.y());
    if(m_topleft.x()!=-1 && m_bottomright.x()!=-1){
        if((m_right - m_left) > 0){
            int x = int(m_left + (float(m_mouse_location.x() - m_topleft.x())) / (m_bottomright.x() - m_topleft.x()) * (m_right - m_left));
            xtxt = QString("%1").arg(x);
        }
    }
    if(m_topleft.y()!=-1 && m_bottomright.y()!=-1){
        if((m_top - m_bottom) > 0){
            double y = m_top - double(m_mouse_location.y() - m_topleft.y()) / (m_bottomright.y() - m_topleft.y()) * (m_top - m_bottom);
            ytxt = QString("%1").arg(y,2,'f',2,0);
        }
    }
    QString msg = xtxt + "," + ytxt;
    QFontMetrics fm = painter.fontMetrics();
    int tw = fm.width(msg);
    painter.drawText(m_mouse_location.x()-tw, m_mouse_location.y(), msg);

    QPen linePen(Qt::black);
    linePen.setWidth(2);

    painter.setPen(linePen);
    if (locations2.count() > 1)
        painter.drawPolyline(points, locations2.count());
    // LineDrawer  ld;

    // ld.drawCursorFollow(this);
}
