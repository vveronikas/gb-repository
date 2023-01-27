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

void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();
    int pos = 0;
    while (1)
    {
        int fnd = txt.indexOf("rub.", pos);
        if (fnd != -1)
        {
            txt.remove(fnd, 4);
            txt.insert(fnd, "₽");
            ui->plainTextEdit->setPlainText(txt);
        }

        fnd = txt.indexOf("eur.", pos);
        if (fnd != -1)
        {
            txt.remove(fnd, 4);
            txt.insert(fnd, "€");
            ui->plainTextEdit->setPlainText(txt);
        }

        fnd = txt.indexOf("R.", pos);
        if (fnd != -1)
        {
            txt.remove(fnd, 2);
            txt.insert(fnd, "®");
            ui->plainTextEdit->setPlainText(txt);
        }

        fnd = txt.indexOf("0/0o", pos);
        if (fnd != -1)
        {
            txt.remove(fnd, 4);
            txt.insert(fnd, "‰");
            ui->plainTextEdit->setPlainText(txt);
        }

        if (fnd == -1)
        {
            return;
        }
    }
}
