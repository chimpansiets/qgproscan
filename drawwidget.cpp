#include "drawwidget.h"
#include <QKeyEvent>
#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QString>
#include <QMenu>
#include <QSizePolicy>
#include <iostream>

using namespace std;

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setFocus();
    setFocusPolicy(Qt::ClickFocus);
    m_img = nullptr;
    m_topleft = QPoint(-1,-1);
    m_bottomright = QPoint(-1, -1);
    
    // createActions();
    setContextMenuPolicy(Qt::CustomContextMenu);
    setMode(eMode::MODE_LIMITS);
}

void DrawWidget::setImageFromFile(const QString filename)
{
    if (m_img) delete(m_img);
    m_img = new QImage(filename);
    setMinimumSize(m_img->width(), m_img->height());
//    resize(m_img->width(), m_img->height());
    resize(100, 100);
    update();
}

void DrawWidget::saveImageToFile(const QString filename)
{
    m_img->save(filename, 0, -1);
}

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

void DrawWidget::setTopLeft()
{
    m_topleft = m_mouse_location;
}

void DrawWidget::setBottomRight()
{
    m_bottomright = m_mouse_location;
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
    menu->addAction("Wissen", this, SLOT(deleteLine()));
    menu->addAction("Alles wissen", this, SLOT(deleteAllLines()));
    menu->exec(this->mapToGlobal(pos));
}

void DrawWidget::setTop(double top)
{
    m_top = top;
    update();
}

void DrawWidget::setBottom(double bottom)
{
    m_bottom = bottom;
    update();
}

void DrawWidget::setLeft(double left)
{
    m_left = int(left);
    update();
}

void DrawWidget::setRight(double right)
{
    m_right = int(right);
    update();
}

// void DrawWidget::removeFirstElem(t_mouse_location **lst)
// {
//     t_mouse_location *toFree = *lst;

//     if (*lst)
//     {
//         locations = (*lst)->next;
//         delete (toFree);
//     }
// }

void DrawWidget::deleteLine()
{
    // removeFirstElem(&locations);
    // removeFirstElem(&locations);
    if (!locations2.isEmpty())
        locations2.removeFirst();
    if (!locations2.isEmpty())
        locations2.removeFirst();
    set_points_to_null(points);
    init_points();
    if (location_count >= 2)
    {
        location_count -= 2;
        if (location_count == 1)
            locations2.removeFirst();
    }
    else
        location_count = 0;
    update();
}

// void DrawWidget::free_locations(t_mouse_location *locations)
// {
//     t_mouse_location *tmp = locations;

//     while (tmp)
//     {
//         free(tmp);
//         tmp = tmp->next;
//     }
// }

void DrawWidget::set_points_to_null(QPoint p[1000])
{
    for (int i = 0; i < 1000; i++)
    {
        p[i].setX(0);
        p[i].setY(0);
    }
}

void DrawWidget::deleteAllLines()
{
    // free_locations(locations);
    // locations = NULL;
    locations2.clear();
    set_points_to_null(points);
    location_count = 0;
    update();
}

void DrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

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
    // QPainter myLine(this);

    QPen linePen(Qt::black);
    linePen.setWidth(2);

    painter.setPen(linePen);
    if (location_count > 1)
        painter.drawLines(points, location_count);
    
    painter.scale(scale, scale);
}

void DrawWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
        scale += 0.10;
    else if (event->key() == Qt::Key_Minus)
        scale -= 0.10;
    else if (event->key() == Qt::Key_Z && event->modifiers() == Qt::ControlModifier)
    {
        deleteLine();
        update();
    }
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_mouse_location = event->pos();
    update();
}

// void DrawWidget::lstadd_location(t_mouse_location **head, t_mouse_location *toAdd)
// {
//     if (*head != NULL || toAdd != NULL)
//     {
//         toAdd->next = *head;
//         *head = toAdd;
//     }
// }

void DrawWidget::init_points()
{
//    t_mouse_location    *tmp = locations;
    int                 ctr = 0;

//    if (tmp)
//        tmp = tmp->next;
//    while (tmp)
//    {
//        points[ctr] = tmp->mousepoint;
//        tmp = tmp->next;
//        ctr++;
//    }

    foreach (t_mouse_location mLoc, locations2) {
        points[ctr++] = mLoc.mousepoint;
        cout << points[ctr].x() << "\n";
    }
}

// t_mouse_location DrawWidget::location_dup(t_mouse_location *loc)
// {
//     t_mouse_location loc_dup;

//     loc_dup.mousepoint = loc->mousepoint;
//     loc_dup.type_soil = 0; // kan anders zijn als je van soil_type switch, geen idee of dit handig is, vragen aan Rob.
//     loc_dup.next = NULL;
//     return (loc_dup);
// }

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::RightButton && drawMode == 2)
    {
//        t_mouse_location        *new_loc;
        t_mouse_location        new_loc;

//        new_loc = (t_mouse_location *)malloc(sizeof(t_mouse_location));
        new_loc.mousepoint = event->pos();
        new_loc.type_soil = 0;
        // new_loc.next = NULL;
        if (locations2.isEmpty())
        {
//            locations = new_loc;
            locations2.prepend(new_loc);
            location_count += 1;
        }
        else
        {
            locations2.prepend(new_loc);
//            lstadd_location(&locations, new_loc);

            // hier duplicate ik location omdat de drawLines() functie
            // 2 punten per lijn nodig heeft, dus bijv.
            // A, B, B, C, C, D en niet A, B, C, D
//            t_mouse_location *loc_dup = (t_mouse_location *)malloc(sizeof(t_mouse_location));
            t_mouse_location loc_dup;

            loc_dup.mousepoint = event->pos();
            loc_dup.type_soil = 0;
            // loc_dup.next = NULL;
//            lstadd_location(&locations, loc_dup);
            locations2.prepend(loc_dup);
            location_count += 2;

            init_points();
        }
    }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    update();
}

void DrawWidget::setDrawMode(int mode)
{
    drawMode = mode;
    update();
}
