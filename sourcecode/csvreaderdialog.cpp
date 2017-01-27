#include "csvreaderdialog.h"
#include "ui_csvreaderdialog.h"

CSVReaderDialog::CSVReaderDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CSVReaderDialog)
{
    defaultDir = "/home/tobias/Research/Buses/RRT Data/Line information boarding - alighting/";

    ui->setupUi(this);
}

CSVReaderDialog::~CSVReaderDialog()
{
    delete ui;
}

/*
 * When user clicks on OK, check whether the entered data are correct, i.e. both text fields are not empty.
 *
 */
void CSVReaderDialog::done(int r)
{
    if(QDialog::Accepted == r)  // ok was clicked
    {
        QMessageBox qm;

        if (ui->lineEditDirectoryName->text().isEmpty() || ui->lineEditFileExtension->text().isEmpty())
        {
            qm.setIcon(QMessageBox::Critical);
            qm.setWindowTitle("Directory or extension not defined");
            qm.setText("Please define both the directory and the file extension.");
            qm.exec();
        }
        else    // no error
        {
            emit readCSVFiles(ui->lineEditDirectoryName->text(), ui->lineEditFileExtension->text());

            QMessageBox qm(QMessageBox::Information,"Ok","success",QMessageBox::Ok);
            qm.exec();

            QDialog::done(r);
            return;
        }
    }
    else    // cancel, close or exc was pressed
    {
        QDialog::done(r);
        return;
    }
}


void CSVReaderDialog::on_buttonBox_accepted()
{

}


void CSVReaderDialog::on_browseButton_clicked()
{

    QFileDialog dir;
    QString dirName;

    dir.setOption(QFileDialog::ShowDirsOnly, true);
    dir.setFileMode(QFileDialog::Directory);
//    qDebug()<<dir.testOption(QFileDialog::ShowDirsOnly);

    dirName = dir.getExistingDirectory(this, tr("Select directory with CSV files to read"), defaultDir);

    ui->lineEditDirectoryName->setText(dirName);

}
