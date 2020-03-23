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

typedef enum s_soilType {
    AK, HV, BV, K1, K2, K3, Z1, Z3,
} e_soilType;

typedef struct s_line {
    QList<QPoint> locations;
    e_soilType soilType;
} t_line;

typedef struct s_soilList {
    QList<t_line> lines;
    QList<QString> lines_combobox;
    e_soilType soilType;
} t_soilList;

class DrawWidget : public QWidget
{
    Q_OBJECT

    public:
        explicit DrawWidget(QWidget *parent = nullptr);
        void setImageFromFile(const QString filename);
        void saveImageToFile(const QString filename);
        void setMode(eMode mode);
        void setSoil(int index);
        void addLineBackend(QString str, int index);
        void changeCurrentLine(int index);
        int  countLines();
        void setInterval(int arg);

        QPoint m_topleft;
        QPoint m_bottomright;
        int interval;
        QPoint left_x_scale = QPoint(-1, -1);
        QPoint right_x_scale = QPoint(-1, -1);
        QPoint top_y_scale = QPoint(-1, -1);
        QPoint bottom_y_scale = QPoint(-1, -1);
        t_soilList soils[8];
        int x_scale_meters;
        int y_scale_meters;

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
        void setLeftXScale();
        void setRightXScale();
        void setLeftYScale();
        void setRightYScale();
    
    protected:
        QImage *m_img;
        QPoint m_mouse_location;
        int m_left = 0;
        int m_right = 0;
        double m_top = 0.;
        double m_bottom = 0.;

    private:
        // void createActions();
        void initSoils();
        void paintEvent(QPaintEvent *event);
        void keyPressEvent(QKeyEvent *event);
        void mouseMoveEvent(QMouseEvent* event);
        void mousePressEvent(QMouseEvent *event);
        void mouseReleaseEvent(QMouseEvent *event);
        QColor setColor(e_soilType soil_type);
        // void scaleImage(double factor);

        // double scaleFactor;
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
