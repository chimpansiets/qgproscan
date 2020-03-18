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
#include "csvcalculator.h"

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
    //Here the CSVCalculator class needs to be called and this
    //should calculate the limits and scale. After this,
    //it needs to assert the height of every layer every n meters.
    //the user can specify n in the ui by giving an interval.
    //still need to think strategies as to how I should get the
    //height values from every line. perhaps a slope calculator
    //function. This can then calculate the height at n-x from
    //the corresponding point in front of n-x.
    QString filename = QFileDialog::getSaveFileName(this, tr("Save"), QString());
    CSVCalculator calculator(m_view);
    int corr_index;
    int height = 0;
    double slope = 0.0;

    for (int dx = 0; dx < m_view->m_bottomright.x(); dx += m_view->interval)
    {
        for (int i = 0; i < AMOUNT_OF_SOILTYPES; i++)
        {
            corr_index = calculator.find_corresponding_index(m_view->soils[i].lines, dx);
            slope = calculator.slopeCalculator(m_view->soils[i].lines.loca);
            height = corr_point.y() + ((dx - corr_point.x()) * calculator.slope);
            cout << "Height at " << dx << " is " << height << "pix\n";
        }
    }
    if (filename.isEmpty())
    {
        cout << "bi ba bad gaan\n";
        return ;
    }
    else {
        QFile file(filename);
        if (!file.open(QFile::WriteOnly | QFile::Truncate))
        {
            // QMessageBox::informativeText(this, tr("Unable to open file"));
            //     file.errorString();
            return ;
        }
        QTextStream out(&file);
        out << "Zerg OP, pls nerf\n";
        out.flush();
        file.close();
    }
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
    QString         str = QString("Line %1").arg(ui->lineBox->count() + 1);

    m_view->addLineBackend(str, ui->lineBox->currentIndex());
    ui->lineBox->addItem(str);
    ui->lineBox->setCurrentIndex(ui->lineBox->count() - 1);
}

void MainWindow::on_lineBox_currentIndexChanged(int index)
{
    m_view->changeCurrentLine(index);
}

void MainWindow::on_intervalBox_valueChanged(double arg1)
{
    m_view->setInterval((int)arg1);
}
