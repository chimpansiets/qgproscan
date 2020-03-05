
#include "drawwidget.h"

void DrawWidget::setTop(double top)
{
    m_top = top;
    update();
}

void DrawWidget::setBottom(double bottom)
{
    m_bottom = bottom;
    update();
}

void DrawWidget::setLeft(double left)
{
    m_left = int(left);
    update();
}

void DrawWidget::setRight(double right)
{
    m_right = int(right);
    update();
}

void DrawWidget::setTopLeft()
{
    m_topleft = m_mouse_location;
}

void DrawWidget::setBottomRight()
{
    m_bottomright = m_mouse_location;
}
