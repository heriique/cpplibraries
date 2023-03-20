/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *labNumber;
    QLineEdit *leNumber;
    QLabel *labNumber_2;
    QLineEdit *leN;
    QPushButton *btnGenerate;
    QPushButton *btnClear;
    QPushButton *btnFind;
    QCheckBox *cbShowPositions;
    QGraphicsView *graphicsView;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1003, 630);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labNumber = new QLabel(centralWidget);
        labNumber->setObjectName(QStringLiteral("labNumber"));

        gridLayout->addWidget(labNumber, 0, 0, 1, 1);

        leNumber = new QLineEdit(centralWidget);
        leNumber->setObjectName(QStringLiteral("leNumber"));

        gridLayout->addWidget(leNumber, 0, 1, 1, 1);

        labNumber_2 = new QLabel(centralWidget);
        labNumber_2->setObjectName(QStringLiteral("labNumber_2"));

        gridLayout->addWidget(labNumber_2, 0, 2, 1, 1);

        leN = new QLineEdit(centralWidget);
        leN->setObjectName(QStringLiteral("leN"));

        gridLayout->addWidget(leN, 0, 3, 1, 1);

        btnGenerate = new QPushButton(centralWidget);
        btnGenerate->setObjectName(QStringLiteral("btnGenerate"));

        gridLayout->addWidget(btnGenerate, 0, 4, 1, 1);

        btnClear = new QPushButton(centralWidget);
        btnClear->setObjectName(QStringLiteral("btnClear"));

        gridLayout->addWidget(btnClear, 0, 5, 1, 1);

        btnFind = new QPushButton(centralWidget);
        btnFind->setObjectName(QStringLiteral("btnFind"));

        gridLayout->addWidget(btnFind, 0, 6, 1, 1);

        cbShowPositions = new QCheckBox(centralWidget);
        cbShowPositions->setObjectName(QStringLiteral("cbShowPositions"));

        gridLayout->addWidget(cbShowPositions, 0, 7, 1, 1);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 1, 0, 1, 8);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labNumber->setText(QApplication::translate("MainWindow", "Number of points", 0));
        leNumber->setText(QApplication::translate("MainWindow", "10", 0));
        labNumber_2->setText(QApplication::translate("MainWindow", "N:", 0));
        leN->setText(QApplication::translate("MainWindow", "1", 0));
        btnGenerate->setText(QApplication::translate("MainWindow", "Generate points", 0));
        btnClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        btnFind->setText(QApplication::translate("MainWindow", "Find concave hull", 0));
        cbShowPositions->setText(QApplication::translate("MainWindow", "Show positions", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
