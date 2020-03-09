
#include "drawwidget.h"

using namespace std;

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::RightButton && drawMode == 2)
    {
        QPoint                  point;
        int                     index_to_insert = 0;
        t_line                  temp_line;
        t_line                  line_to_compare;

        point = event->pos();
        if (soils[current_soil].lines.isEmpty())
        {
            t_line newLine;

            newLine.soilType = current_soil;
            soils[current_soil].lines.append(newLine);
        }

        line_to_compare = soils[current_soil].lines.at(current_line);

        foreach (QPoint p, line_to_compare.locations) {
            if (p.x() > event->pos().x())
                break ;
            index_to_insert++;
        }
        // foreach (t_line line, soils[current_soil].lines) {
        //     cout << line.locations.at(current_line).x() << " > " << event->pos().x() << "\n";
        //     if (line.locations.at(current_line).x() > event->pos().x()) {
        //         break ;
        //     }
        //     index_to_insert++;
        // }
        // foreach (t_mouse_location tmp, locations2) {
        //     if (tmp.mousepoint.x() > new_loc.mousepoint.x())
        //         break ;
        //     index_to_insert++;
        // }
        last_inserted.append(index_to_insert);

        // locations2.insert(index_to_insert, new_loc);

        temp_line = soils[current_soil].lines.at(current_line);
        temp_line.locations.insert(index_to_insert, point);
        soils[current_soil].lines.replace(current_line, temp_line);
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
