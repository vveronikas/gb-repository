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
        html = text;
    }
}

QString MainWindow::getData(const QString& tmp)
{
    int n = html.indexOf(tmp);
    QString str;
    if (n != -1)
    {
        n = n + tmp.length();
        str = html.mid(n, html.indexOf("\"", n) - n);
    }

    if (str[str.length() - 1] == ',')
    {
        str.truncate(str.length() - 1);
    }
    return str;
}

void MainWindow::on_getButton_clicked()
{
    if (html.isEmpty()) { return; };
    ui->eur->setText(getData("\"EUR\",\"rate\":"));
    ui->usd->setText(getData("\"USD\",\"rate\":"));
    ui->temp->setText(getData("\"temp\":\""));
    ui->tempFeels->setText(getData("\"tempFeelsLike\":\""));
    ui->description->setText(getData("\"descriptionShort\":\""));
    ui->wind->setText(getData("\"wind\":\""));
    ui->windDesc->setText(getData("\"wind_description\":\""));
    ui->pressue->setText(getData("\"pressure\":\""));
    ui->pressueDesc->setText(getData("\"pressure_description\":\""));
    ui->humidity->setText(getData("\"humidity\":\""));
    ui->humidityDesc->setText(getData("\"humidity_description\":\""));
}
