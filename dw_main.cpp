#include "drawwidget.h"

using namespace std;

void DrawWidget::initSoils()
{
    t_soilList  soil_elem[8];

    soils[0].soilType = AK;
    soils[1].soilType = HV;
    soils[2].soilType = BV;
    soils[3].soilType = K1;
    soils[4].soilType = K2;
    soils[5].soilType = K3;
    soils[6].soilType = Z1;
    soils[7].soilType = Z3;
}

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setFocus();
    setFocusPolicy(Qt::ClickFocus);
    initSoils();
    m_img = nullptr;
    m_topleft = QPoint(-1,-1);
    m_bottomright = QPoint(-1, -1);

    setContextMenuPolicy(Qt::CustomContextMenu);
    setMode(eMode::MODE_LIMITS);
}

void DrawWidget::setDrawMode(int mode)
{
    drawMode = mode;
    update();
}
