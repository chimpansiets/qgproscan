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
    ui->lineBox->addItem(QString("Line 1"));
    m_view->addLineBackend(QString("Line 1"), ui->lineBox->currentIndex());

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

void MainWindow::initializeLineBox()
{
    // here the lines of the corresponding soiltype
    // are loaded into the lineBox.
    if (m_view->countLines() == 0)
    {
        ui->lineBox->addItem(QString("Line 1"));
        m_view->addLineBackend(QString("Line 1"), ui->lineBox->currentIndex());
    }
    else {
        for (int i = 0; i < m_view->countLines(); i++) {
            ui->lineBox->addItem(QString("Line %1").arg(i + 1));
        }
    }
}

void MainWindow::on_soilBox_currentIndexChanged(int index)
{
    m_view->setSoil(index);
    // m_view->changeCurrentLine(0)
    // whenever soil type changes, lineBox needs to be cleared and filled
    // with corresponding lines, perhaps previously made
    // for now im just clearing, going to set up lists that save
    // these lines per soil.
    ui->lineBox->clear();
    initializeLineBox();
}

void MainWindow::on_lineButton_clicked()
{
    QString         str;

    str = QString("Line %1").arg(ui->lineBox->count() + 1);
    m_view->addLineBackend(str, ui->lineBox->currentIndex());
    ui->lineBox->addItem(str);
    ui->lineBox->setCurrentIndex(ui->lineBox->count() - 1);
}

void MainWindow::on_lineBox_currentIndexChanged(int index)
{
    m_view->changeCurrentLine(index);
}
