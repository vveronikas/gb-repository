#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QMdiArea>
#include <QPlainTextEdit>
#include <QMdiSubWindow>
#include <QPrinter>
#include <QPrintDialog>
#include <QMessageBox>
#include <QToolBar>
#include <QFont>
#include <QFontDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    font = new QFont;
    translator = new QTranslator;
    translator->load(":/ts/QtLanguage_ru.qm");
    ui->setupUi(this);
    open_new_file();
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);

    QMenu* fileMenu = menuBar()->addMenu(tr("File"));

    QAction* newFile = fileMenu->addAction(tr("New"));
    connect(newFile, SIGNAL(triggered()), this, SLOT(open_new_file()));

    QAction* open = fileMenu->addAction(tr("Open"));
    connect(open, SIGNAL(triggered()), this, SLOT(open_file()));

    QAction* openRO = fileMenu->addAction(tr("Open (Read only)"));
    connect(openRO, SIGNAL(triggered()), this, SLOT(open_file_read_only()));

    QAction* save = fileMenu->addAction(tr("Save as"));
    connect(save, SIGNAL(triggered()), this, SLOT(on_saveButton_clicked()));

    QAction* print = fileMenu->addAction(tr("Print"));
    connect(print, SIGNAL(triggered()), this, SLOT(print_file()));

    fileMenu = menuBar()->addMenu("About");

    QAction* readMe = fileMenu->addAction(tr("Read me"));
    connect(readMe, SIGNAL(triggered()), this, SLOT(on_readMeButton_clicked()));

    QToolBar* toolBar = new QToolBar;
    QAction* setFront = toolBar->addAction(tr("Set font"));
    connect(setFront, SIGNAL(triggered()), this, SLOT(set_font()));

    QAction* leftAlign = toolBar->addAction(tr("Left align"));
    connect(leftAlign, SIGNAL(triggered()), this, SLOT(left_align()));

    QAction* centerAlign = toolBar->addAction(tr("Center align"));
    connect(centerAlign, SIGNAL(triggered()), this, SLOT(center_align()));

    QAction* rightAlign = toolBar->addAction(tr("Right align"));
    connect(rightAlign, SIGNAL(triggered()), this, SLOT(right_align()));

    QAction* copyFont = toolBar->addAction(tr("Copy font"));
    connect(copyFont, SIGNAL(triggered()), this, SLOT(copy_font()));

    QAction* pasteFont = toolBar->addAction(tr("Paste font"));
    connect(pasteFont, SIGNAL(triggered()), this, SLOT(paste_font()));

    ui->gridLayout->addWidget(toolBar);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete translator;
    delete font;
}

void MainWindow::on_readMeButton_clicked()
{
    QTextEdit* textEdit = new QTextEdit;
    QMdiSubWindow*  subWindow = ui->mdiArea->addSubWindow(textEdit);
    QFile file(":/files/readme");
    subWindow->setWindowTitle(tr("Read me"));
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        textEdit->setPlainText(text);
    }
    textEdit->setReadOnly(true);
    subWindow->show();
}
void MainWindow::open_file()
{
    QTextEdit* textEdit = new QTextEdit;
    QMdiSubWindow*  subWindow = ui->mdiArea->addSubWindow(textEdit);
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) { return; };
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        textEdit->setPlainText(text);
    }
    textEdit->setReadOnly(false);
    subWindow->setWindowTitle(file.fileName());
    subWindow->show();
}

void MainWindow::open_file_read_only()
{
    QTextEdit* textEdit = new QTextEdit;
    QMdiSubWindow*  subWindow = ui->mdiArea->addSubWindow(textEdit);
    QString path = QFileDialog::getOpenFileName();
    if (path.isEmpty()) { return; };
    QFile file(path);
    if (file.open(QIODevice::ReadOnly))
    {
        QByteArray ba = file.readAll();
        QString text(ba);
        textEdit->setPlainText(text);
    }
    textEdit->setReadOnly(true);
    subWindow->setWindowTitle(file.fileName());
    subWindow->show();
}

void MainWindow::open_new_file()
{
    QMdiSubWindow* subWindow = ui->mdiArea->addSubWindow(new QTextEdit);
    subWindow->setWindowTitle(tr("New document"));
    subWindow->show();
}

void MainWindow::on_saveButton_clicked()
{
    QString path = QFileDialog::getSaveFileName();
    if (path.isEmpty()) { return; };
    QFile file(path);
    QMdiSubWindow* subWindow = ui->mdiArea->currentSubWindow();
    QWidget* widget = subWindow->widget();
    QTextEdit* textEdit = (QTextEdit*)widget;
    if (file.open(QIODevice::WriteOnly))
    {
        QString text = textEdit->toPlainText();
        QByteArray ba = text.toUtf8();
        file.write(ba, ba.length());
    }
    subWindow->setWindowTitle(file.fileName());
}

void MainWindow::on_ru_toggled(bool checked)
{
    if (checked)
    {
       QCoreApplication::installTranslator(translator);
       QApplication::installTranslator(translator);
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
        open_file();
    }

    if ((event->key() == Qt::Key_S) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
    {
        on_saveButton_clicked();
    }

    if ((event->key() == Qt::Key_N) && (QApplication::keyboardModifiers() & Qt::ControlModifier))
    {
        QTextEdit* textEdit = (QTextEdit*)(ui->mdiArea->currentSubWindow()->widget());
        textEdit->clear();
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
                      "QTextEdit { background-color: Snow; color: black; border-color: white }"
                      "QComboBox {background-color: white; color: black; }"
                      "QCheckBox {color: black; }");
    }
    else if(arg1 == "black")
    {
        setStyleSheet("QMainWindow { background-color: gray; }"
                      "QPushButton { background-color: DimGrey; color: white; }"
                      "QRadioButton { color: white; selection-background-color: DimGrey; }"
                      "QTextEdit { background-color: DimGrey; color: white; }"
                      "QComboBox {background-color: DimGrey; color: white; "
                      "selection-background-color: DimGrey; }"
                      "QCheckBox {color: white; }"
                      "QMdiSubWindow:title { background: DimGrey }");
    }
}

 void MainWindow::print_file()
 {
    QTextEdit* textEdit = (QTextEdit*)(ui->mdiArea->currentSubWindow()->widget());
    QPrinter printer;
    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle("Print");
    if (dlg.exec() != QDialog::Accepted) return;
    textEdit->print(&printer);
 }

 void MainWindow::closeEvent(QCloseEvent *event)
 {
     while (ui->mdiArea->currentSubWindow() != nullptr)
     {
        QMdiSubWindow* subWindow = ui->mdiArea->currentSubWindow();
        QTextEdit* textEdit =  (QTextEdit*)subWindow->widget();
        if (textEdit->isReadOnly())
        {
            ui->mdiArea->currentSubWindow()->close();
        }
        else
        {
            QMessageBox msgBox(this);
            QString str = "Do you want to save " + subWindow->windowTitle() + " before exit?";;
            msgBox.setText((str));
            msgBox.addButton("Yes", QMessageBox::YesRole);
            msgBox.addButton("No", QMessageBox::NoRole);
            msgBox.addButton("Cancel", QMessageBox::RejectRole);

            int result = msgBox.exec();
            if (result == 0)
            {
                on_saveButton_clicked();
                ui->mdiArea->currentSubWindow()->close();
            }
            else if (result == 1)
            {
                ui->mdiArea->currentSubWindow()->close();
            }
            else
            {
                event->ignore();
                break;
            }
        }
        event->accept();
    }
 }

 void MainWindow::set_font()
 {
    QTextEdit* textEdit = (QTextEdit*)ui->mdiArea->currentSubWindow()->widget();
    if (textEdit->isReadOnly()) return;
    QFont font = textEdit->textCursor().charFormat().font();
    QFontDialog fntDlg(font,this);
    bool b[] = {true};
    font = fntDlg.getFont(b);
    if (b[0])
    {
        QTextCharFormat fmt;
        fmt.setFont(font);
        textEdit->textCursor().setCharFormat(fmt);
    }
 }

 void MainWindow::right_align()
 {
    QTextEdit* textEdit = (QTextEdit*)ui->mdiArea->currentSubWindow()->widget();
    textEdit->setAlignment(Qt::AlignRight);
 }

 void MainWindow::left_align()
 {
    QTextEdit* textEdit = (QTextEdit*)ui->mdiArea->currentSubWindow()->widget();
    textEdit->setAlignment(Qt::AlignLeft);
 }

 void MainWindow::center_align()
 {
    QTextEdit* textEdit = (QTextEdit*)ui->mdiArea->currentSubWindow()->widget();
    textEdit->setAlignment(Qt::AlignCenter);
 }

 void MainWindow::copy_font()
 {
    QTextEdit* textEdit = (QTextEdit*)ui->mdiArea->currentSubWindow()->widget();
    if (textEdit->isReadOnly()) return;
    *font = textEdit->textCursor().charFormat().font();
    isFontSet = true;
 }

 void MainWindow::paste_font()
 {
    if (!isFontSet) return;
    QTextEdit* textEdit = (QTextEdit*)ui->mdiArea->currentSubWindow()->widget();
    if (textEdit->isReadOnly()) return;
    QTextCharFormat fmt;
    fmt.setFont(*font);
    textEdit->textCursor().setCharFormat(fmt);
 }

