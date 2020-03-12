
#include "drawwidget.h"

using namespace std;

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

void DrawWidget::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
        scale += 0.10;
    else if (event->key() == Qt::Key_Minus)
        scale -= 0.10;
    else if (event->key() == Qt::Key_Z && event->modifiers() == Qt::ControlModifier)
    {
        deletePoint();
        update();
    }
}

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

void DrawWidget::set_points_to_null(QPoint p[1000])
{
    for (int i = 0; i < 1000; i++)
    {
        p[i].setX(0);
        p[i].setY(0);
    }
}

void DrawWidget::deletePoint()
{
    t_line  temp_line;

    if (!soils[current_soil].lines.at(current_line).locations.isEmpty() && \
        !last_inserted.isEmpty())
    {
        temp_line = soils[current_soil].lines.at(current_line);
        temp_line.locations.removeAt(last_inserted.takeLast());
        if (temp_line.locations.count() == 1)
            temp_line.locations.removeLast();
        soils[current_soil].lines.replace(current_line, temp_line);
    }
    update();
}

void DrawWidget::deleteAllLines()
{
    for (int i = 0; i < AMOUNT_OF_SOILTYPES; i++)
        soils[i].lines.clear();
    update();
}

void DrawWidget::addLineBackend(QString str, int index)
{
    t_line  newLine;

    newLine.soilType = current_soil;
    soils[current_soil].lines.append(newLine);
    soils[current_soil].lines_combobox.append(str);
    if (index == -1)
        current_line = 0;
    else
        current_line = index;
}

void DrawWidget::changeCurrentLine(int index)
{
    current_line = index;
}

int  DrawWidget::countLines()
{
    return (soils[current_soil].lines.count());
}

void DrawWidget::initSoils()
{
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

void DrawWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() != Qt::RightButton && drawMode == 2)
    {
        QPoint                  point;
        int                     index_to_insert = 0;
        t_line                  temp_line;
        t_line                  line_to_compare;

        point = event->pos();
        if (soils[current_soil].lines.isEmpty())
        {
            t_line newLine;

            newLine.soilType = current_soil;
            soils[current_soil].lines.append(newLine);
        }

        line_to_compare = soils[current_soil].lines.at(current_line);

        foreach (QPoint p, line_to_compare.locations) {
            if (p.x() > event->pos().x())
                break ;
            index_to_insert++;
        }
        last_inserted.append(index_to_insert);

        temp_line = soils[current_soil].lines.at(current_line);
        temp_line.locations.insert(index_to_insert, point);
        soils[current_soil].lines.replace(current_line, temp_line);
    }
}

void DrawWidget::mouseReleaseEvent(QMouseEvent *event)
{
    update();
}

void DrawWidget::mouseMoveEvent(QMouseEvent *event)
{
    m_mouse_location = event->pos();
    update();
}


void DrawWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // LineDrawer ld;

    // ld.drawCursorFollow(painter);
    if (m_img) painter.drawImage(0,0,*m_img);
        painter.drawLine(m_mouse_location.x(), 0, m_mouse_location.x(),height());
        painter.drawLine(0, m_mouse_location.y(), width(), m_mouse_location.y());

    if(m_topleft.x()!=-1){
        painter.drawLine(m_topleft.x() - 5, m_topleft.y(), m_topleft.x() + 5, m_topleft.y());
        painter.drawLine(m_topleft.x(), m_topleft.y() - 5, m_topleft.x(), m_topleft.y() + 5);
    }
    if(m_bottomright.x()!=-1){
        painter.drawLine(m_bottomright.x() - 5, m_bottomright.y(), m_bottomright.x() + 5, m_bottomright.y());
        painter.drawLine(m_bottomright.x(), m_bottomright.y() - 5, m_bottomright.x(), m_bottomright.y() + 5);
    }

    QString xtxt = QString("%1").arg(m_mouse_location.x());
    QString ytxt = QString("%1").arg(m_mouse_location.y());
    if(m_topleft.x()!=-1 && m_bottomright.x()!=-1){
        if((m_right - m_left) > 0){
            int x = int(m_left + (float(m_mouse_location.x() - m_topleft.x())) / (m_bottomright.x() - m_topleft.x()) * (m_right - m_left));
            xtxt = QString("%1").arg(x);
        }
    }
    if(m_topleft.y()!=-1 && m_bottomright.y()!=-1){
        if((m_top - m_bottom) > 0){
            double y = m_top - double(m_mouse_location.y() - m_topleft.y()) / (m_bottomright.y() - m_topleft.y()) * (m_top - m_bottom);
            ytxt = QString("%1").arg(y,2,'f',2,0);
        }
    }
    QString msg = xtxt + "," + ytxt;
    QFontMetrics fm = painter.fontMetrics();
    int tw = fm.width(msg);
    painter.drawText(m_mouse_location.x()-tw, m_mouse_location.y(), msg);

    QPen linePen(Qt::black);
    linePen.setWidth(2);

    QVector<QPoint> vector_points;
    QPoint          *data_pointer;

    for (int i = 0; i < AMOUNT_OF_SOILTYPES; i++) {
        linePen.setColor(setColor(soils[i].soilType));
        painter.setPen(linePen);
        foreach (t_line line, soils[i].lines) {
            vector_points = line.locations.toVector();
            data_pointer = vector_points.data();
            painter.drawPolyline(data_pointer, line.locations.count());
        }
    }
}

void DrawWidget::setMode(eMode mode)
{
    m_mode = mode;
    if(m_mode == eMode::MODE_LIMITS){
        disconnect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLines(const QPoint &)));
        connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLimits(const QPoint &)));
    }else{
        disconnect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLimits(const QPoint &)));
        connect(this, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(showPopupMenuLines(const QPoint &)));
    }
}

void DrawWidget::showPopupMenuLimits(const QPoint &pos)
{
    QMenu *menu = new QMenu;
    menu->addAction("Linksboven", this, SLOT(setTopLeft()));
    menu->addAction("Rechtsonder", this, SLOT(setBottomRight()));
    menu->exec(this->mapToGlobal(pos));
}

void DrawWidget::showPopupMenuLines(const QPoint &pos)
{
    QMenu *menu = new QMenu;
    menu->addAction("Wissen", this, SLOT(deletePoint()));
    menu->addAction("Alles wissen", this, SLOT(deleteAllLines()));
    menu->exec(this->mapToGlobal(pos));
}

QStringList soil_colors = QStringList() << "darkgray" << "chocolate" << "saddlebrown" << "palegreen" << "lime" << "darkgreen" << "khaki" << "yellow";

QColor DrawWidget::setColor(e_soilType soil_type)
{
    QColor	ret_color;

    ret_color.setNamedColor(soil_colors[soil_type]);
    return (ret_color);
}

void DrawWidget::setSoil(int index)
{
    current_soil = (e_soilType)index;
    cout << "current_soil: " << current_soil << "\n";
    if (!last_inserted.isEmpty())
        last_inserted.clear();
    current_line = soils[current_soil].lines.count() - 1;
}
