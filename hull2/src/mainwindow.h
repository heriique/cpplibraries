#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <time.h>
#include <math.h>
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QValidator>
#include <QMouseEvent>
#include <QResizeEvent>
#include "hullfinder.h"
#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<Point> points;
    QGraphicsScene scene;
    QRegExpValidator validator;

    void DrawPoints();

private slots:
    void btnGenerate_clicked(bool checked);
    void btnFind_clicked(bool checked);
    void btnClear_clicked(bool checked);
    void mousePressEvent(QMouseEvent * e);
    void resizeEvent(QResizeEvent * event);
};

#endif // MAINWINDOW_H
