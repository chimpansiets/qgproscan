#ifndef CSVCALCULATOR_H
#define CSVCALCULATOR_H

#include <QObject>
#include <QWidget>

class CSVCalculator : public QWidget
{
    Q_OBJECT
    public:
        explicit CSVCalculator(QWidget *parent = nullptr);
    private:
		int scale_meters;
		int scale_pixels;


signals:

};

#endif // CSVCALCULATOR_H
