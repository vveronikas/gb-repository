#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    translator = new QTranslator;
    translator->load(":/ts/QtLanguage_ru.qm");
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
    ui->docTextEdit->setReadOnly(ui->readOnly->isChecked());
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


void MainWindow::on_readOnly_stateChanged(int arg1)
{
    ui->docTextEdit->setReadOnly(arg1);
}

void MainWindow::on_ru_toggled(bool checked)
{
    if (checked)
    {
        QCoreApplication::installTranslator(translator);
        ui->retranslateUi(this);
    }
}


void MainWindow::on_en_toggled(bool checked)
{
    if (checked)
    {
        QCoreApplication::removeTranslator(translator);
        ui->retranslateUi(this);
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if ((event->key() == Qt::Key_O) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
    {
        on_openButton_clicked();
    }

    if ((event->key() == Qt::Key_S) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
    {
        on_saveButton_clicked();
    }

    if ((event->key() == Qt::Key_N) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
    {
        ui->docTextEdit->clear();
    }

    if ((event->key() == Qt::Key_Q) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
    {
        QApplication::closeAllWindows();
    }
}

void MainWindow::on_theme_currentTextChanged(const QString &arg1)
{
    if(arg1 == "white")
    {
        setStyleSheet("QMainWindow { background-color: white; }"
                      "QPushButton { background-color: Snow; color: black; }"
                      "QRadioButton { background-color: white; color: black; }"
                      "QPlainTextEdit { background-color: Snow; color: black; border-color: white }"
                      "QComboBox {background-color: white; color: black; }"
                      "QCheckBox {color: black; }");
    }
    else if(arg1 == "black")
    {
        setStyleSheet("QMainWindow { background-color: gray; }"
                      "QPushButton { background-color: DimGrey; color: white; }"
                      "QRadioButton { color: white; selection-background-color: DimGrey; }"
                      "QPlainTextEdit { background-color: DimGrey; color: white; }"
                      "QComboBox {background-color: DimGrey; color: white; "
                      "selection-background-color: DimGrey; }"
                      "QCheckBox {color: white; }");
    }
}

