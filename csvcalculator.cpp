#include "csvcalculator.h"

CSVCalculator::CSVCalculator(DrawWidget *parent)
{
    x_scale = calculateXScale(left_x_scale.x(), right_x_scale.x());
    y_scale = calculateYScale(top_y_scale.y(), bottom_y_scale.y());

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
	int index;

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