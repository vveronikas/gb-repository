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


void MainWindow::on_copyButton_clicked()
{
    ui->text2->setPlainText(ui->text1->toPlainText());
}


void MainWindow::on_changeButton_clicked()
{
    QString text1 = ui->text1->toPlainText();
    ui->text1->setPlainText(ui->text2->toPlainText());
    ui->text2->setPlainText(text1);
}


void MainWindow::on_addHtmlButton_clicked()
{
   ui->text1->appendHtml("<font color='red'>Hello</font>");
}

