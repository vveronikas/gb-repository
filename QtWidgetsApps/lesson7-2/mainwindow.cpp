#include "mainwindow.h"
#include <QMessageBox>
#include <QCursor>
#include <QMouseEvent>
#include <QGraphicsItem>

MainWindow::MainWindow(QWidget *parent)
: QGraphicsView(parent)
{
    srand(clock());
    scence = new QGraphicsScene(this);
    setScene(scence);
}

MainWindow::~MainWindow()
{
}

void MainWindow::draw()
{
    auto [x, y] = QCursor::pos();
    QBrush brush(QColor(rand() % 256, rand() % 256, rand() % 256));
    if (geometry == ELLIPS)
    {
        scence->addEllipse(x, y, 200, 100, QPen(), brush);
        geometry = RECTANGLE;
    }
    else if (geometry == RECTANGLE)
    {
        scence->addRect(x, y, 200, 100, QPen(), brush);
        geometry = ELLIPS;
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
       draw();
    }
}
