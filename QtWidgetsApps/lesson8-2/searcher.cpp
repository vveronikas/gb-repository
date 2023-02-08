#include "searcher.h"
#include <QDirIterator>

Searcher::Searcher(QObject *parent)
    : QObject{parent}
{

}

QFileInfoList Searcher::search(const QString &targetStr, const QString &directory)
{
    QFileInfoList hitList;
    QDirIterator it(directory, QDirIterator::Subdirectories);

    while (it.hasNext()) {
        QString filename = it.next();
        QFileInfo file(filename);

        if (file.isDir()) {
            continue;
        }

        if (file.fileName().contains(targetStr, Qt::CaseInsensitive)) {
            hitList.append(file);
        }
    }

    emit finished();
    return hitList;
}
