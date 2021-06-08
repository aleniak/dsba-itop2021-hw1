#include "deleteconfirmation.h"
#include "ui_deleteconfirmation.h"

deleteConfirmation::deleteConfirmation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deleteConfirmation)
{
    ui->setupUi(this);
}

deleteConfirmation::~deleteConfirmation()
{
    delete ui;
}

void deleteConfirmation::onYesButtonClicked()
{
    yes_or_no = true;
    this->close();
}

void deleteConfirmation::onNoButtonClicked()
{
    yes_or_no = false;
    this->close();
}

bool deleteConfirmation::if_not_canceled()
{
    return yes_or_no;
}
