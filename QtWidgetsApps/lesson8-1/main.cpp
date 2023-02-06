#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    w.setStyleSheet(  "QMainWindow { background-color: white; }"
                      "QPushButton { background-color: Snow; color: black; }"
                      "QRadioButton { background-color: white; color: black; }"
                      "QTextEdit { background-color: Snow; color: black; border-color: white }"
                      "QComboBox {background-color: white; color: black; }"
                      "QCheckBox {color: black; }");
    return a.exec();
}
