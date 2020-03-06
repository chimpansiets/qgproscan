
#include "drawwidget.h"

using namespace std;

void DrawWidget::setSoil(int index)
{
    current_soil = (e_soilType)index;
    cout << "current_soil: " << current_soil << "\n";
}
