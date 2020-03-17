#include "csvcalculator.h"

CSVCalculator::CSVCalculator(DrawWidget *parent)
{
    x_scale = calculateXScale(left_x_scale.x(), right_x_scale.x());
    y_scale = calculateYScale(left_y_scale.y(), right_y_scale.y());

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
