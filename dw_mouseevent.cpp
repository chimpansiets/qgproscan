
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
        last_inserted.append(index_to_insert);

        temp_line = soils[current_soil].lines.at(current_line);
        temp_line.locations.insert(index_to_insert, point);
        soils[current_soil].lines.replace(current_line, temp_line);
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
