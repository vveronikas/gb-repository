#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>

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

void MainWindow::on_readMeButton_clicked()
{
    QFile file(":/files/readme");
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        ui-> docTextEdit->setPlainText(text);
    }
}
void MainWindow::on_openButton_clicked()
{
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) { return; };
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        ui->docTextEdit->setPlainText(text);
    }
}


void MainWindow::on_saveButton_clicked()
{
    QString path = QFileDialog::getSaveFileName();
    if (path.isEmpty()) { return; };
    QFile file(path);
    if (file.open(QIODevice::WriteOnly))
    {
        QString text = ui->docTextEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.length());
    }
}

