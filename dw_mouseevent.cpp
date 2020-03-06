
#include "drawwidget.h"

using namespace std;

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::RightButton && drawMode == 2)
    {
        t_mouse_location        new_loc;
        int                     index_to_insert = 0;

        new_loc.mousepoint = event->pos();

//        if (soils[current_soil].lines.isEmpty())
//        {
//            t_line newLine;

//            newLine.soilType = current_soil;
//            soils[current_soil].lines.append(newLine);
//        }

//        foreach (t_line line, soils[current_soil].lines) {
//            cout << "Hello\n";
//            if (line.locations.at(current_line).mousepoint.x() > new_loc.mousepoint.x())
//                break ;
//            index_to_insert++;
//        }
        foreach (t_mouse_location tmp, locations2) {
            if (tmp.mousepoint.x() > new_loc.mousepoint.x())
                break ;
            index_to_insert++;
        }
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
