#ifndef DRAWWIDGET_H
#define DRAWWIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QString>
#include <QMenu>
#include <QSizePolicy>
#include <iostream>

enum eMode {MODE_LIMITS, MODE_LINES};

typedef struct              s_mouse_location {
QPoint                      mousepoint;
int                         type_soil; //indicates what type of soil this line corresponds to, useless for now..
// struct s_mouse_location     *next;
}                           t_mouse_location;

class DrawWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit DrawWidget(QWidget *parent = nullptr);
        void setImageFromFile(const QString filename);
        void saveImageToFile(const QString filename);

        void setMode(eMode mode);

    signals:
        //void topLeftChanged();
        //void bottomRightChanged();

    private slots:
        void setTopLeft();
        void setBottomRight();
        void showPopupMenuLimits(const QPoint &pos);
        void showPopupMenuLines(const QPoint &pos);

        void setTop(double top);
        void setBottom(double bottom);
        void setLeft(double left);
        void setRight(double right);
        void deleteLine();
        void deleteAllLines();
        void setDrawMode(int mode);
    

    private:
        // void createActions();
        t_mouse_location location_dup(t_mouse_location *loc);
        void lstadd_location(t_mouse_location **head, t_mouse_location *toAdd);
        void init_points();
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void mouseMoveEvent(QMouseEvent* event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        void free_locations(t_mouse_location *locations);
        void set_points_to_null(QPoint p[1000]);
        void removeFirstElem(t_mouse_location **lst);
        void printPoints(QPoint p[1000]);
        // void scaleImage(double factor);

        // double scaleFactor;
        QPoint m_mouse_location;
        QPoint points[1000];
        t_mouse_location *locations = NULL;
        QList<t_mouse_location> locations2;
        QList<int> last_inserted;
        QPoint m_mousedown_location;
        QPoint m_mousedown_location_first;
        QPoint m_mouserelease_location_first;
        QPoint m_mousedown_location_second;
        QPoint m_mouserelease_location_second;
        QPoint m_topleft;
        QPoint m_bottomright;
        QImage *m_img;
        eMode m_mode;

        qreal scale = 1;
        int drawMode = 0;
        int m_left = 0;
        int m_right = 0;
        double m_top = 0.;
        double m_bottom = 0.;

        bool m_has_image;
};

#endif // DRAWWIDGET_H
