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

        void on_soilBox_currentIndexChanged(int index);
        void on_lineBox_currentIndexChanged(int index);

        void on_lineButton_clicked();

protected:
        DrawWidget *m_view;

    private:
        Ui::MainWindow *ui;
        QGraphicsScene *m_scene;
        void print_lines_combobox(QList<QString> lst);
        // QAction *zoomInAct;
        // QAction *zoomOutAct;
};

#endif // MAINWINDOW_H
