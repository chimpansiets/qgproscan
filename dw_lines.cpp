
#include "drawwidget.h"

using namespace std;

void DrawWidget::set_points_to_null(QPoint p[1000])
{
    for (int i = 0; i < 1000; i++)
    {
        p[i].setX(0);
        p[i].setY(0);
    }
}

void DrawWidget::deletePoint()
{
    t_line  temp_line;

    if (!soils[current_soil].lines.at(current_line).locations.isEmpty() && \
        !last_inserted.isEmpty())
    {
        temp_line = soils[current_soil].lines.at(current_line);
        temp_line.locations.removeAt(last_inserted.takeLast());
        if (temp_line.locations.count() == 1)
            temp_line.locations.removeLast();
        soils[current_soil].lines.replace(current_line, temp_line);
    }
    update();
}

void DrawWidget::deleteAllLines()
{

    for (int i = 0; i < AMOUNT_OF_SOILTYPES; i++)
    {
        foreach (t_line temp_line, soils[i].lines) {
            temp_line.locations.clear();
            soils[i].lines.replace(0, temp_line);
        }
    }
    update();
}

void DrawWidget::addLineBackend(QString str, int index)
{
    t_line  newLine;

    newLine.soilType = current_soil;
    soils[current_soil].lines.append(newLine);
    soils[current_soil].lines_combobox.append(str);
    current_line = index;
}
