
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

void DrawWidget::deleteLine()
{
    if (!locations2.isEmpty())
        locations2.removeAt(last_inserted.takeLast());
    set_points_to_null(points);
    if (locations2.count() == 1)
        locations2.removeLast();
    init_points();
    update();
}

void DrawWidget::deleteAllLines()
{
    locations2.clear();
    set_points_to_null(points);
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
