#ifndef SEARCHER_H
#define SEARCHER_H

#include <QObject>
#include <QFileInfoList>

class Searcher : public QObject
{
    Q_OBJECT
public:
    explicit Searcher(QObject *parent = nullptr);

    QFileInfoList search(const QString &targetStr, const QString &directory);

signals:
    void finished();

};

#endif // SEARCHER_H
