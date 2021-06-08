#include "changewindow.h"
#include "ui_changewindow.h"

ChangeWindow::ChangeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChangeWindow)
{
    ui->setupUi(this);
}

ChangeWindow::~ChangeWindow()
{
    delete ui;
}

void ChangeWindow::onInProgressPushed()
{
    canceled = true;
    *status_new = "In progress";
    this->close();
}

void ChangeWindow::onCompletedPushed()
{
    canceled = true;
    *status_new = "Completed";
    this->close();
}

void ChangeWindow::onNotCompletedPushed()
{
    canceled = true;
    *status_new = "Not completed";
    this->close();
}

void ChangeWindow::on_CancelPushed()
{
    canceled = false;
    this->close();
}

bool ChangeWindow::not_closed()
{
    return canceled;
}

QVariant ChangeWindow::get_new_status()
{
    return *status_new;
}
