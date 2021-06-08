#include "addwindow.h"
#include "ui_addwindow.h"
#include "examplemodel.h"
#include "mainwindow.h"

addWindow::addWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addWindow)
{
    ui->setupUi(this);
}

addWindow::~addWindow()
{
    delete ui;
}

QList<QVariant> addWindow::newinf(int num_of_rows)
{
    gotinf.append(num_of_rows+1);
    number_row = num_of_rows+1;

    QVariant input = ui->lineEdit_4->text();
    gotinf.append(input);

    input = ui->lineEdit_3->text();
    gotinf.append(input);

    input = ui->lineEdit_2->text();
    gotinf.append(input);

    input = ui->dateEdit->date();
    gotinf.append(input);

    gotinf.append("In progress");
    return gotinf;
}

void addWindow::result_saved()
{
    closed = true;
    this->close();
}

void addWindow::to_close()
{
    closed = false;
    this->close();
}

bool addWindow::if_closed()
{
    return closed;
}
