#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    validator.setRegExp(QRegExp("\\d+"));
    ui->leNumber->setValidator(&validator);
    connect(ui->btnGenerate, SIGNAL(clicked(bool)), this, SLOT(btnGenerate_clicked(bool)));
    connect(ui->btnFind, SIGNAL(clicked(bool)), this, SLOT(btnFind_clicked(bool)));
    connect(ui->btnClear, SIGNAL(clicked(bool)), this, SLOT(btnClear_clicked(bool)));
    ui->graphicsView->setScene(&scene);
    srand((unsigned int)time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DrawPoints()
{
    scene.clear();
    double dy = scene.height();
    bool showPositions = ui->cbShowPositions->isChecked();
    foreach (Point tmp, points) {
        scene.addEllipse(tmp.x - 2, dy - tmp.y - 2, 4, 4);
        if (showPositions) {
            QGraphicsTextItem * text = new QGraphicsTextItem;
            text->setPlainText(QString::number(tmp.x) + "," + QString::number(tmp.y));
            text->setPos(tmp.x + 2, dy - tmp.y + 2);
            scene.addItem(text);
        }
    }
}

void MainWindow::btnGenerate_clicked(bool checked)
{
    int cnt = ui->leNumber->text().toInt();
    if (cnt < 1)
    {
        return;
    }

    double dx = scene.width();
    double dy = scene.height();

    points.clear();
    for (int i = 0; i < cnt; i++)
    {
        Point tmp(25 + rand() % (int)dx, 25 + rand() % (int)dy);
        points.push_back(tmp);
    }
    /*points.push_back(Point(131,421));
    points.push_back(Point(96,344));
    points.push_back(Point(145,305));
    points.push_back(Point(186,382));
    points.push_back(Point(369,327));
    points.push_back(Point(373,225));
    points.push_back(Point(428,137));
    points.push_back(Point(407,39));
    points.push_back(Point(646,324));
    points.push_back(Point(543,378));
    points.push_back(Point(483,410));*/

    DrawPoints();
}

void MainWindow::btnFind_clicked(bool checked)
{
    if (points.size() < 3) {
        return;
    }

    double N = ui->leN->text().toDouble();

    QVector<Point> hull = HullFinder::FindConcaveHull(points, N);

    DrawPoints();

    double dy = scene.height();

    for (QVector<Point>::const_iterator iter = hull.constBegin(); iter != hull.constEnd() - 1; iter++)
    {
        QVector<Point>::const_iterator next = iter + 1;
        scene.addLine(iter->x, dy - iter->y, next->x, dy - next->y);
    }
}

void MainWindow::btnClear_clicked(bool checked)
{
    points.clear();
    DrawPoints();
}

void MainWindow::mousePressEvent(QMouseEvent * e)
{
    QRect widgetRect = ui->graphicsView->geometry();
    QPoint pos = e->pos();
    if (widgetRect.contains(pos)) {
        double dy = scene.height();
        pos -= ui->graphicsView->pos();
        points.append(Point(pos.x(), dy - pos.y()));
        DrawPoints();
    }
}

void MainWindow::resizeEvent(QResizeEvent * event)
{
    scene.setSceneRect(0, 0, ui->graphicsView->frameSize().width(), ui->graphicsView->frameSize().height());
}
