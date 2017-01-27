#include "csvreaderwidget.h"
#include "ui_csvreaderwidget.h"

CSVReaderWidget::CSVReaderWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CSVReaderWidget)
{
    ui->setupUi(this);
}

CSVReaderWidget::~CSVReaderWidget()
{
    delete ui;
}
