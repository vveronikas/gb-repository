#ifndef FIRSTMYQTWIDGET_H
#define FIRSTMYQTWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QTreeView>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>

class FirstMyQtWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FirstMyQtWidget(QWidget *parent = nullptr);
    void clearTree();
    QStandardItemModel *getCurrentModel() const
    {
        return model;
    }
    void setNewModel(QStandardItemModel *newmodel);
    void rebuildModel(QString str);

private:
    QGridLayout *gridLay;
    QTreeView *tree;
    QPushButton *mainPath;
    QComboBox *disckSelBox;

private slots:
    void chgDisk(int index);
    void goMainPath();

private:
    QStandardItemModel *model;
    QString curretnPath;

public slots:
    void folderClicked(QTreeView* t);

signals:

};

#endif // FIRSTMYQTWIDGET_H
