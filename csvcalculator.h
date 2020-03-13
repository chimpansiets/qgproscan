#ifndef CSVCALCULATOR_H
#define CSVCALCULATOR_H

#include <QObject>
#include <QWidget>

class CSVCalculator : public DrawWidget
{
    Q_OBJECT
    public:
        explicit CSVCalculator();
    private:
        double calculateXScale(int x_begin, int x_end);
        double calculateYScale(int y_begin, int y_end);
        double slopeCalculator(int dy, int dx);
        int getHeightAtX(int y_start, double slope, int x);

		int x_scale_meters;
		int x_scale_pixels;
        int y_scale_meters;
        int y_scale_pixels;


signals:

};

#endif // CSVCALCULATOR_H
