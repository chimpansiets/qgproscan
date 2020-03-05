/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpenen;
    QAction *actionOpslaan;
    QAction *actionAfsluiten;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lblScale;
    QDoubleSpinBox *dspLeft;
    QLabel *label;
    QDoubleSpinBox *dspRight;
    QLabel *label_2;
    QDoubleSpinBox *dspTop;
    QLabel *label_3;
    QDoubleSpinBox *dspBottom;
    QPushButton *pbLimits;
    QPushButton *pbLines;
    QCheckBox *drawMode;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QMenuBar *menuBar;
    QMenu *menuBestand;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(941, 554);
        actionOpenen = new QAction(MainWindow);
        actionOpenen->setObjectName(QStringLiteral("actionOpenen"));
        actionOpslaan = new QAction(MainWindow);
        actionOpslaan->setObjectName(QStringLiteral("actionOpslaan"));
        actionAfsluiten = new QAction(MainWindow);
        actionAfsluiten->setObjectName(QStringLiteral("actionAfsluiten"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblScale = new QLabel(centralWidget);
        lblScale->setObjectName(QStringLiteral("lblScale"));

        horizontalLayout->addWidget(lblScale);

        dspLeft = new QDoubleSpinBox(centralWidget);
        dspLeft->setObjectName(QStringLiteral("dspLeft"));
        dspLeft->setDecimals(0);
        dspLeft->setMaximum(100000);
        dspLeft->setSingleStep(100);

        horizontalLayout->addWidget(dspLeft);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        dspRight = new QDoubleSpinBox(centralWidget);
        dspRight->setObjectName(QStringLiteral("dspRight"));
        dspRight->setDecimals(0);
        dspRight->setMaximum(100000);
        dspRight->setSingleStep(100);

        horizontalLayout->addWidget(dspRight);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        dspTop = new QDoubleSpinBox(centralWidget);
        dspTop->setObjectName(QStringLiteral("dspTop"));
        dspTop->setDecimals(1);
        dspTop->setMinimum(-100);

        horizontalLayout->addWidget(dspTop);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        dspBottom = new QDoubleSpinBox(centralWidget);
        dspBottom->setObjectName(QStringLiteral("dspBottom"));
        dspBottom->setDecimals(1);
        dspBottom->setMinimum(-100);

        horizontalLayout->addWidget(dspBottom);

        pbLimits = new QPushButton(centralWidget);
        pbLimits->setObjectName(QStringLiteral("pbLimits"));
        pbLimits->setCheckable(true);
        pbLimits->setChecked(true);
        pbLimits->setAutoExclusive(true);

        horizontalLayout->addWidget(pbLimits);

        pbLines = new QPushButton(centralWidget);
        pbLines->setObjectName(QStringLiteral("pbLines"));
        pbLines->setCheckable(true);
        pbLines->setAutoExclusive(true);

        horizontalLayout->addWidget(pbLines);

        drawMode = new QCheckBox(centralWidget);
        drawMode->setObjectName(QStringLiteral("drawMode"));
        drawMode->setEnabled(true);

        horizontalLayout->addWidget(drawMode);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 919, 404));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 941, 22));
        menuBestand = new QMenu(menuBar);
        menuBestand->setObjectName(QStringLiteral("menuBestand"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuBestand->menuAction());
        menuBestand->addSeparator();
        menuBestand->addAction(actionOpenen);
        menuBestand->addAction(actionOpslaan);
        menuBestand->addSeparator();
        menuBestand->addAction(actionAfsluiten);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        actionOpenen->setText(QApplication::translate("MainWindow", "Openen", Q_NULLPTR));
        actionOpslaan->setText(QApplication::translate("MainWindow", "Opslaan", Q_NULLPTR));
        actionAfsluiten->setText(QApplication::translate("MainWindow", "Afsluiten", Q_NULLPTR));
        lblScale->setText(QApplication::translate("MainWindow", "metrering links:", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "metrering rechts:", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "y hoog:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "y laag:", Q_NULLPTR));
        pbLimits->setText(QApplication::translate("MainWindow", "Limieten", Q_NULLPTR));
        pbLines->setText(QApplication::translate("MainWindow", "Lijnen", Q_NULLPTR));
        drawMode->setText(QApplication::translate("MainWindow", "Snaptool", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "grondsoort:", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "AK", Q_NULLPTR)
         << QApplication::translate("MainWindow", "HV", Q_NULLPTR)
         << QApplication::translate("MainWindow", "BV", Q_NULLPTR)
         << QApplication::translate("MainWindow", "K1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "K2", Q_NULLPTR)
         << QApplication::translate("MainWindow", "K3", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Z1", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Z3", Q_NULLPTR)
        );
        menuBestand->setTitle(QApplication::translate("MainWindow", "Bestand", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
