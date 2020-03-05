#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QPainter>

#include "drawwidget.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    signals:
        void  on_drawMode_stateChanged(int arg1);

    private slots:
        void on_actionOpenen_triggered();
        void on_actionOpslaan_triggered();
        void on_actionAfsluiten_triggered();
        void changeClickMode();

        void on_pbLimits_clicked();

        void on_pbLines_clicked();
        // void zoomIn();
        // void zoomOut();


private:
        Ui::MainWindow *ui;
        DrawWidget *m_view;
        QGraphicsScene *m_scene;
        // QAction *zoomInAct;
        // QAction *zoomOutAct;
};

#endif // MAINWINDOW_H
