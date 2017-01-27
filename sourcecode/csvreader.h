#ifndef CSVREADER_H
#define CSVREADER_H

#include <QObject>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

#define DEBUGMODE 1

class CSVReader : public QObject
{
    Q_OBJECT
public:
    explicit CSVReader(QObject *parent = 0);

signals:

public slots:
    bool receiveDirInformation(const QString &, const QString &);

private:
    bool parseCSVFile(const QString &);

};

#endif // CSVREADER_H
