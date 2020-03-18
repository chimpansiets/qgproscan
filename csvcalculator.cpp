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

QPoint CSVCalculator::find_corresponding_point(QList<t_line> lines, int dx)
{
	foreach (t_line curr_line, lines) {
		for (int i = 0; i < curr_line.locations.count(); i++) {
			if (curr_line.locations.at(i).x() > dx) {
				return (curr_line.locations.at(i - 1));
			}
		}
	}
}

void slopeCalculator(int dy, int dx) {
	
}