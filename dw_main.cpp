#include "drawwidget.h"

using namespace std;

DrawWidget::DrawWidget(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setFocus();
    setFocusPolicy(Qt::ClickFocus);
    m_img = nullptr;
    m_topleft = QPoint(-1,-1);
    m_bottomright = QPoint(-1, -1);
    
    // createActions();
    setContextMenuPolicy(Qt::CustomContextMenu);
    setMode(eMode::MODE_LIMITS);
}

void DrawWidget::setDrawMode(int mode)
{
    drawMode = mode;
    update();
}
