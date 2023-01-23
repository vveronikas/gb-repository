#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList list {"C++", "Python", "Java", "C#", "PHP", "JavaScript"};
    model = new QStandardItemModel(list.size(), 1, this);

    for(int i=0; i<model->rowCount(); ++i)
    {
        QModelIndex index = model->index(i, 0);
        QString str = list[i];
        model->setData(index, str, Qt::DisplayRole);
        model->setData(index, str, Qt::ToolTipRole);
        model->setData(index, QIcon("./Icons/" + str + ".png"), Qt::DecorationRole);
    }

    ui->listView->setViewMode(QListView::ListMode);
    ui->listView->setModel(model);
    ui->listView->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked);
    ui->listView->setDragDropMode(QAbstractItemView::InternalMove);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    model->insertRow(model->rowCount());
    QModelIndex index = model->index(model->rowCount()-1, 0);
    model->setData(index, QIcon("./Icons/default.png"), Qt::DecorationRole);
}


void MainWindow::on_deleteButton_clicked()
{
    int row = ui->listView->currentIndex().row();
    model->removeRow(row);
}


void MainWindow::on_iconMode_stateChanged(int arg1)
{
    if (arg1)
    {
        ui->listView->setViewMode(QListView::IconMode);
    }
    else
    {
        ui->listView->setViewMode(QListView::ListMode);
    }
    ui->listView->setDragDropMode(QAbstractItemView::InternalMove);
}

