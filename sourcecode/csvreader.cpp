#include "csvreader.h"

CSVReader::CSVReader(QObject *parent) : QObject(parent)
{

}

bool CSVReader::receiveDirInformation(const QString &dirName, const QString &extension)
{

    QDir dir(dirName);
    QStringList entries;
    QMessageBox qm;
    uint numberOfFiles = 0, i = 0;
    bool success = false;

    if(dir.exists())
    {
        if(extension.isEmpty())
        {
            qm.setIcon(QMessageBox::Critical);
            qm.setWindowTitle("No extension specified");
            qm.setText("No extension has been specified.");
            qm.exec();

            return false;
        }

//        extension = "*." + extension;
        entries << "*." + extension;

        dir.setNameFilters(entries);
        dir.setSorting(QDir::Name);

        numberOfFiles = dir.count();

#ifdef DEBUGMODE
        numberOfFiles = 1; //DEBUG ONLY
#endif

        for (i = 0; i < numberOfFiles; ++i)
        {
 //           qDebug () << QString::number(i + 1) + ": " + dirName + "/" + dir.entryList().at(i);
            success = parseCSVFile(dirName + "/" + dir.entryList().at(i));
        }


        return success;
    }

    // else (dir does not exist)
    qm.setIcon(QMessageBox::Critical);
    qm.setWindowTitle("Directory does not exist");
    qm.setText("The specified directory " + dirName + " does not exist.");
    qm.exec();

    return false;

}

bool CSVReader::parseCSVFile(const QString &fileName)
{
    QFile CSVFile(fileName);
    QStringList entries;
    QString value;
    QByteArray line;
    QList<QByteArray> arrayLine;
    quint32 i = 0;
    quint8 j = 0, numberOfEntries = 0;
    QMessageBox qm;

    if(!CSVFile.open(QIODevice::ReadOnly))
    {
        qm.setIcon(QMessageBox::Critical);
        qm.setWindowTitle("Couldn't open file");
        qm.setText("The file " + fileName + " could not be opened.\nThe following error has been reported: " + CSVFile.errorString() + ".");
        qm.exec();

        return false;
    }

    //else
    while (!CSVFile.atEnd())
    {
        //entries.clear();
        line = CSVFile.readLine();
        //entries.append(line.split(','));
        arrayLine = line.split(',');

        numberOfEntries = arrayLine.size();

        for (j = 0; j < numberOfEntries; ++j)
        {

            qDebug() << "Entry " + QString::number(j + 1) + ": " + arrayLine.at(j).trimmed();
        }

        ++i;

        if (i > 100)
            break;

    }

    return true;
}
