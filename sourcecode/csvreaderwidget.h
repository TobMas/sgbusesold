#ifndef CSVREADERWIDGET_H
#define CSVREADERWIDGET_H

#include <QWidget>

namespace Ui
{
class CSVReaderWidget;
}

class CSVReaderWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CSVReaderWidget(QWidget *parent = 0);
    ~CSVReaderWidget();

private:
    Ui::CSVReaderWidget *ui;
};

#endif // CSVREADERWIDGET_H
