#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_calculateButton_clicked()
{
    double angle = ui->angle->text().toDouble();
    double c = ui->c->text().toDouble();
    double b = ui->b->text().toDouble();
    if (ui->degreesButton->isChecked())
    {
        angle = angle*3.141592653589793/180;
    }
    double a = qSqrt(qPow(b, 2) + qPow(c, 2) - 2*b*c*qCos(angle));
    ui->a->setText(QString::number(a));
}

