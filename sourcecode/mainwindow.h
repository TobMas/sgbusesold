#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "csvreaderdialog.h"
#include "csvreader.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();
    void on_actionRead_CSV_Files_triggered();

private:
    Ui::MainWindow *ui;

    CSVReaderDialog readerDiag;
    CSVReader reader;
};

#endif // MAINWINDOW_H
