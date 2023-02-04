#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTranslator>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void on_readMeButton_clicked();

    void open_file();

    void open_file_read_only();

    void on_saveButton_clicked();

    void on_ru_toggled(bool checked);

    void on_en_toggled(bool checked);

    void on_theme_currentTextChanged(const QString &arg1);

    void open_new_file();

    void print_file();

    void closeEvent(QCloseEvent *Event) override;

private:
    Ui::MainWindow *ui;
    QTranslator* translator;
};
#endif // MAINWINDOW_H
