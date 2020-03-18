#ifndef CSVCALCULATOR_H
#define CSVCALCULATOR_H

#include "drawwidget.h"
#include <QObject>
#include <QWidget>

class CSVCalculator : public DrawWidget
{
    Q_OBJECT
    public:
        explicit CSVCalculator(DrawWidget *parent);
        int find_corresponding_point(QList<t_line> lines, int dx);
        double slopeCalculator(QPoint p1, QPoint p2);
        double slope;

    private:
        double calculateXScale(int x_begin, int x_end);
        double calculateYScale(int y_begin, int y_end);
        int getHeightAtX(int y_start, double slope, int x);
        void measureIntervalHeights();

		int x_scale_meters;
		int x_scale_pixels;
        int y_scale_meters;
        int y_scale_pixels;
        int x_scale;
        int y_scale;


signals:

};

#endif // CSVCALCULATOR_H
