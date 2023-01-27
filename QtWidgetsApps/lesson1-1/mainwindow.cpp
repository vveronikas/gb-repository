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


void MainWindow::on_claculateButton_clicked()
{
    if (ui->a->text().toInt() <= 0) ui->a->setText("1");
    else
    {
        double a = ui->a->text().toDouble();
        double b = ui->b->text().toDouble();
        double c = ui->c->text().toDouble();
        double d = qPow(b, 2) - 4*a*c;

        if (d < 0)
        {
            ui->x1->setText("no roots");
            ui->x2->setText("no roots");
        }
        else
        {
            double x = (-b + qSqrt(d))/(2*a);
            ui->x1->setText(QString::number(x));

            if (d == 0)
            {
                ui->x2->setText(QString::number(x));
            }
            else
            {
                double x2 = (-b - qSqrt(d))/(2*a);
                ui->x2->setText(QString::number(x2));
            }
        }
    }
}

