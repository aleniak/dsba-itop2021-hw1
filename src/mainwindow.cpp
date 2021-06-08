#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "aboutwindow.h"
#include "addwindow.h"
#include "changewindow.h"
#include "deleteconfirmation.h"
#include "currentdate.h"
#include "sortinstruction.h"
#include "delegatewindow.h"

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QFileDialog>

#include <iostream>
#include <fstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    tmodel(new QTransposeProxyModel)
    , sort(new QSortFilterProxyModel)
{
    ui->setupUi(this);
    ui->menubar->setNativeMenuBar(false);
    Model = new ExampleModel(this);

    ui->listView->setModelColumn(0);
    tmodel->setSourceModel(Model);
    ui->listView->setModel(tmodel);

    ui->tableView->setModel(Model);

    sortModel = new QSortFilterProxyModel(this);
        sortModel->setSourceModel(Model);
        ui->tableView->setModel(sortModel);
        ui->tableView->setSortingEnabled(true);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete Model;
}

void MainWindow::onLoadButtonPushed()
{
    QString path = QFileDialog::getOpenFileName(this);
    Model->fillModelWithData(path);
}

void MainWindow::onSaveButtonPushed()
{
    QString path = QFileDialog::getSaveFileName(this);
    Model->saveModelAsFile(path);
}

void MainWindow::on_actionAbout_triggered()
{
    AboutWindow dialog;
    dialog.exec();
}

void MainWindow::onAddButtonPushed()
{
    addWindow to_get_data;
    to_get_data.exec();
    QList<QVariant> got_this_info;
    int num_of_rows = Model->give_num_of_rows();
    got_this_info = to_get_data.newinf(num_of_rows);
    if (to_get_data.if_closed())
    {
        Model->appendRow(got_this_info);
    }
}

void MainWindow::onDeleteButtonClicked()
{
    QModelIndex idx = ui->tableView->currentIndex();
    int row = idx.row();
    deleteConfirmation are_you_sure;
    are_you_sure.exec();
    if (are_you_sure.if_not_canceled())
    {
        Model->deleteRow(row);
    }
}

void MainWindow::onChangeButtonClicked()
{
    ChangeWindow new_status;
    new_status.exec();
    QModelIndex idx = ui->tableView->currentIndex();
    int row = idx.row();
    QVariant status = new_status.get_new_status();
    if (new_status.not_closed())
    {
        Model->changed_status_by_window(status, row);
    }
}

void MainWindow::setListViewColumn(int value)
{
    ui->listView->setModelColumn(value);
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    int row = sortModel->mapToSource(index).row();
    ui->listView->setModelColumn(row);
}

void MainWindow::onCurrentDatePushed()
{
    currentDate today;
    today.exec();
    QVariant date_today = today.date_fin();
    if (today.if_closed())
    {
        for (int i = 0; i < Model->size_of_table(); i++)
        {
            QList<QVariant> row = Model->getRow(i);
            if (row[4] < date_today && row[5]!= "Completed")
            {
                Model->change_status(i);
            }
        }
    }
}

void MainWindow::onSortInfoPushed()
{
    sortInstruction instr;
    instr.exec();
}

void MainWindow::onDelegatePushed()
{
    delegateWindow to_another;
    to_another.exec();
    QList<QVariant> new_p = to_another.getName();
    QModelIndex idx = ui->tableView->currentIndex();
    int row = idx.row();
    if (to_another.if_can())
    {
        Model->delegated1(new_p[1], row);
    }
    if (to_another.if_can())
    {
        Model->delegated2(new_p[0], row);
    }

}
