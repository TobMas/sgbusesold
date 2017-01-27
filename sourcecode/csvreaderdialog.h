#ifndef CSVREADERDIALOG_H
#define CSVREADERDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui
{
class CSVReaderDialog;
}

class CSVReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CSVReaderDialog(QWidget *parent = 0);
    ~CSVReaderDialog();

private slots:
    void on_buttonBox_accepted();

    void on_browseButton_clicked();

private:
    void done(int);

    Ui::CSVReaderDialog *ui;
    QString defaultDir;

signals:
    void readCSVFiles(const QString &, const QString &);

};

#endif // CSVREADERDIALOG_H
