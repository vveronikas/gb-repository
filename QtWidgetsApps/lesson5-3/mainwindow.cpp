#include "mainwindow.h"
#include "firstmyqtwidget.h"

MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
{
    FirstMyQtWidget* fmqw= new FirstMyQtWidget(this);
}

MainWindow::~MainWindow()
{
}

