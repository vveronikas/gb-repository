#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QDirIterator>
#include <searcher.h>
#include <QThread>
#include <thread.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete th;
    delete s;
}

void MainWindow::on_searchButton_pressed()
{
    ui->result->clear();
    if (ui->path->text().isEmpty()) return;
    if (ui->fileName->text().isEmpty()) return;

    QString targetStr = ui->fileName->text();
    QString directory = ui->path->text() ;

    s = new Searcher();
    th = new MyThread();
    connect(s, SIGNAL(finished()), th, SLOT(quit()));

    s->moveToThread(th);
    QFileInfoList hitList = s->search(targetStr, directory);

    foreach (QFileInfo hit, hitList) {
        ui->result->append(hit.absoluteFilePath());
    }
}

