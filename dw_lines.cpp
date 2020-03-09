
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

    if (!soils[current_soil].lines.at(current_line).locations.isEmpty())
    {
        temp_line = soils[current_soil].lines.at(current_line);
        temp_line.locations.removeAt(last_inserted.takeLast());
    }
    if (temp_line.locations.count() == 1)
        temp_line.locations.removeLast();
    soils[current_soil].lines.replace(current_line, temp_line);
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

void DrawWidget::init_points()
{
    t_mouse_location    tmp;

    for (int i = 0; i < locations2.count(); i++)
    {
        tmp = locations2.at(i);
        points[i] = tmp.mousepoint;
    }
}

void DrawWidget::printPoints(QPoint p[1000])
{
    cout << "Points: \n";
    for (int i = 0; i < locations2.count(); i++)
        cout << p[i].x() << " " << p[i].y() << " | ";
    cout << "\n";
}
