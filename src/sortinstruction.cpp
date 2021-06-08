#include "sortinstruction.h"
#include "ui_sortinstruction.h"

sortInstruction::sortInstruction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sortInstruction)
{
    ui->setupUi(this);
}

sortInstruction::~sortInstruction()
{
    delete ui;
}

void sortInstruction::onGotItPushed()
{
    this->close();
}
