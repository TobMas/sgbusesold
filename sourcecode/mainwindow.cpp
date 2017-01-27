#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connect signals and slots
   connect(&readerDiag, SIGNAL(readCSVFiles(const QString &, const QString &)), &reader, SLOT(receiveDirInformation(const QString &, const QString &)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

void MainWindow::on_actionRead_CSV_Files_triggered()
{
    readerDiag.exec();
}
