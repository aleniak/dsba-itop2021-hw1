#include "currentdate.h"
#include "ui_currentdate.h"

currentDate::currentDate(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::currentDate)
{
    ui->setupUi(this);
}

currentDate::~currentDate()
{
    delete ui;
}

void currentDate::onEdit_Pushed()
{
    *input = ui->dateEdit->date();
    if_can = true;
    this->close();
}

void currentDate::onCancel_Pushed()
{
    if_can = false;
    this->close();
}

bool currentDate::if_closed()
{
    return if_can;
}

QVariant currentDate::date_fin()
{
    return *input;
}
