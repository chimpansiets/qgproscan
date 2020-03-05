
#include "drawwidget.h"

void DrawWidget::setImageFromFile(const QString filename)
{
    if (m_img) delete(m_img);
    m_img = new QImage(filename);
    setMinimumSize(m_img->width(), m_img->height());
//    resize(m_img->width(), m_img->height());
    resize(100, 100);
    update();
}

void DrawWidget::saveImageToFile(const QString filename)
{
    m_img->save(filename, 0, -1);
}
