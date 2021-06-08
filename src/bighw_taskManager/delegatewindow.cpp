#include "delegatewindow.h"
#include "ui_delegatewindow.h"

delegateWindow::delegateWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delegateWindow)
{
    ui->setupUi(this);
}

delegateWindow::~delegateWindow()
{
    delete ui;
}

void delegateWindow::give_to_another()
{
    QVariant inp = ui->lineEdit->text();
    newinf[0] = inp;
    inp = ui->lineEdit_2->text();
    newinf[1] = inp;
}

void delegateWindow::onDonePushed()
{
    give_to_another();
    closed = true;
    this->close();
}

void delegateWindow::onCancelPushed()
{
    closed = false;
    this->close();
}

QList<QVariant> delegateWindow::getName()
{
    return newinf;
}

bool delegateWindow::if_can()
{
    return closed;
}
