#include "csvcalculator.h"

using namespace std;

CSVCalculator::CSVCalculator(DrawWidget *parent)
{
	x_scale_meters = parent->x_scale_meters;
	y_scale_meters = parent->y_scale_meters;

    x_scale = calculateXScale(parent->left_x_scale.x(), parent->right_x_scale.x());
    y_scale = calculateYScale(parent->top_y_scale.y(), parent->bottom_y_scale.y());
	// measureIntervalHeights();
}

double CSVCalculator::calculateXScale(int x_begin, int x_end)
{
	int	x_delta = x_end - x_begin;

	return ((double) x_delta / x_scale_meters);
}

double CSVCalculator::calculateYScale(int y_begin, int y_end)
{
	int	y_delta = y_end - y_begin;

	return ((double) y_delta / y_scale_meters);
}

int CSVCalculator::find_corresponding_point(t_line curr_line, int dx)
{
	for (int i = 0; i < curr_line.locations.count(); i++) {
		if (curr_line.locations.at(i).x() > dx) {
			return (i - 1);
			// return (curr_line.locations.at(i - 1));
			// Qindex_lst.append(i - 1);
		}
	}
}

double CSVCalculator::slopeCalculator(QPoint p1, QPoint p2) {
	double dy = p2.y() - p1.y();
	double dx = p2.x() - p1.x();

	return ((double)dy / dx);
}

QString CSVCalculator::select_soil(int i)
{
	QList<QString> soils = {"AK", "HV", "BV", "K1", "K2", "K3", "Z1", "Z3"};

	return (soils[i]);
}