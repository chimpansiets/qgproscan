
#include "drawwidget.h"

char soil_colors[8][20] = {"darkgray", "chocolate", \
        "saddlebrown", "palegreen", "lime", \
        "darkgreen", "khaki", "yellow"};

QColor DrawWidget::setColor(e_soilType soil_type)
{
	QColor	ret_color;

	ret_color.setNamedColor(soil_colors[soil_type]);
	return (ret_color);
}
