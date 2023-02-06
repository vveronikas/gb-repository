#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QGraphicsScene>
#include <QGraphicsView>

class MainWindow : public QGraphicsView
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    QGraphicsScene *scence;
    enum Geometry {RECTANGLE, ELLIPS};
    Geometry geometry = RECTANGLE;
protected:
    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void draw();
};

#endif // MAINWINDOW_H

