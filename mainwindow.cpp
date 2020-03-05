#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QSaveFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>
#include <QGraphicsPixmapItem>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <iostream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_view = new DrawWidget();

    ui->scrollArea->setWidget(m_view);

    connect(ui->dspTop, SIGNAL(valueChanged(double)), m_view, SLOT(setTop(double)));
    connect(ui->dspBottom, SIGNAL(valueChanged(double)), m_view, SLOT(setBottom(double)));
    connect(ui->dspLeft, SIGNAL(valueChanged(double)), m_view, SLOT(setLeft(double)));
    connect(ui->dspRight, SIGNAL(valueChanged(double)), m_view, SLOT(setRight(double)));
    connect(ui->drawMode, SIGNAL(stateChanged(int)), m_view, SLOT(setDrawMode(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete m_view;
}

void MainWindow::on_actionOpenen_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());
    if(!filename.isEmpty())
    {
        m_view->setImageFromFile(filename);
    }
}

void MainWindow::on_actionOpslaan_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Save"), QString());

    m_view->saveImageToFile(filename);

    // if (filename.isEmpty())
    // {
    //     cout << "bi ba bad gaan\n";
    //     return ;
    // }
    // else {
    //     QFile file(filename);
    //     if (!file.open(QFile::WriteOnly | QFile::Truncate))
    //         // QMessageBox::informativeText(this, tr("Unable to open file"));
    //         //     file.errorString();
    //         return ;
    //     QTextStream out(&file);
    //     out << "Zerg OP, pls nerf\n";
    //     out.flush();
    //     file.close();
    // }
}


void MainWindow::on_actionAfsluiten_triggered()
{
    QCoreApplication::quit();
}

void MainWindow::changeClickMode()
{
    if(ui->pbLimits->isChecked()){
        m_view->setMode(eMode::MODE_LIMITS);
    }else{
        m_view->setMode(eMode::MODE_LINES);
    }
}

void MainWindow::on_pbLimits_clicked()
{
    changeClickMode();
}

void MainWindow::on_pbLines_clicked()
{
    changeClickMode();
}

// void MainWindow::zoomIn()
// {
//     m_view->scaleImage(1.25);
// }

// void MainWindow::zoomOut()
// {
//     m_view->scaleImage(0.75);
// }


// void MainWindow::createActions()
// {
//     zoomInAct = new QAction(tr("Zoom &In (25%)"), this);
//     zoomInAct->setShortcut(tr("Ctrl++"));
//     zoomInAct->setEnabled(false);
//     connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

//     zoomOutAct = new QAction(tr("Zoom &Out (25%)"), this);
//     zoomOutAct->setShortcut(tr("Ctrl+-"));
//     zoomOutAct->setEnabled(false);
//     connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));
// }


// void MainWindow::scaleImage(double factor)
// {
//     Q_ASSERT(pixmap());
//     scaleFactor *= factor;
//     resize(scaleFactor * pixmap()->size());

//     adjustScrollBar(ui->scrollArea->horizontalScrollBar(), factor);
//     adjustScrollBar(ui->scrollArea->verticalScrollBar(), factor);

//     zoomInAct->setEnabled(scaleFactor < 3.0);
//     zoomOutAct->setEnabled(scaleFactor > 0.333);
// }
