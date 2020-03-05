
#include "drawwidget.h"

void DrawWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
        scale += 0.10;
    else if (event->key() == Qt::Key_Minus)
        scale -= 0.10;
    else if (event->key() == Qt::Key_Z && event->modifiers() == Qt::ControlModifier)
    {
        deleteLine();
        update();
    }
}
