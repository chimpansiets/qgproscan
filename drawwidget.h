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
#include <QVector>

#define AMOUNT_OF_SOILTYPES 8

enum eMode {MODE_LIMITS, MODE_LINES};

typedef enum                s_soilType {
    AK, HV, BV, K1, K2, K3, Z1, Z3,
}                           e_soilType;

typedef struct              s_mouse_location {
    QPoint                  mousepoint;
    e_soilType              type_soil; //indicates what type of soil this line corresponds to, useless for now..
}                           t_mouse_location;

typedef struct              s_line {
    QList<QPoint>           locations;
    e_soilType              soilType;
}                           t_line;

typedef struct              s_soilList {
    QList<t_line>           lines;
    e_soilType              soilType;
}                           t_soilList;

class DrawWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit DrawWidget(QWidget *parent = nullptr);
        void setImageFromFile(const QString filename);
        void saveImageToFile(const QString filename);
        void setMode(eMode mode);
        void setSoil(int index);

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
        void deletePoint();
        void deleteAllLines();
        void setDrawMode(int mode);
    
    protected:
        QImage                  *m_img;
        QPoint                  m_topleft;
        QPoint                  m_bottomright;
        QPoint                  m_mouse_location;
        int                     m_left = 0;
        int                     m_right = 0;
        double                  m_top = 0.;
        double                  m_bottom = 0.;
        QList<t_mouse_location> locations2;
        QPoint                  points[1000];

    private:
        // void createActions();
        void initSoils();
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
        t_mouse_location        *locations = NULL;
        t_soilList              soils[8];
        e_soilType              current_soil = AK;
        int                     current_line = 0;
        QList<int>              last_inserted;
        QPoint                  m_mousedown_location;
        QPoint                  m_mousedown_location_first;
        QPoint                  m_mouserelease_location_first;
        QPoint                  m_mousedown_location_second;
        QPoint                  m_mouserelease_location_second;
        eMode                   m_mode;

        qreal scale = 1;
        int drawMode = 0;

        bool m_has_image;
};

#endif // DRAWWIDGET_H
