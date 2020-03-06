
#include "drawwidget.h"

using namespace std;

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::RightButton && drawMode == 2)
    {
        t_mouse_location        new_loc;
        int                     index_to_insert = 0;

        new_loc.mousepoint = event->pos();
        new_loc.type_soil = 0;

        
        foreach (t_mouse_location tmp, locations2) {
            if (tmp.mousepoint.x() > new_loc.mousepoint.x())
                break ;
            index_to_insert++;
        }
        cout << "\n\n";
        last_inserted.append(index_to_insert);
        locations2.insert(index_to_insert, new_loc);

        init_points();
        // printPoints(points);
    }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    update();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_mouse_location = event->pos();
    update();
}
