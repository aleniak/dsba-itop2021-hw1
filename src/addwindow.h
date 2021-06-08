#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include <QDialog>
#include "examplemodel.h"

namespace Ui {
class addWindow;
}

class addWindow : public QDialog
{
    Q_OBJECT

public:
    explicit addWindow(QWidget *parent = nullptr);
    ~addWindow();
    QList<QVariant> newinf(int n);
    bool if_closed();

public slots:
    virtual void result_saved();
    void to_close();

private:
    Ui::addWindow *ui;
    QList<QVariant> gotinf;
    ExampleModel *Model;
    int number_row;
    bool closed = false;
};

#endif // ADDWINDOW_H
