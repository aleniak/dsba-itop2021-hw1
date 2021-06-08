#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "examplemodel.h"
#include <QSortFilterProxyModel>
#include <QTransposeProxyModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onLoadButtonPushed();
    void onSaveButtonPushed();
    void on_actionAbout_triggered();
    void onAddButtonPushed();
    void onDeleteButtonClicked();
    void onChangeButtonClicked();
    void on_tableView_clicked(const QModelIndex &index);
    void setListViewColumn(int value);
    void onCurrentDatePushed();
    void onSortInfoPushed();
    void onDelegatePushed();

private:
    Ui::MainWindow *ui;
    ExampleModel *Model;
    QSortFilterProxyModel *sortModel;
    QTransposeProxyModel *tmodel;
    QSortFilterProxyModel *sort;
};
#endif // MAINWINDOW_H
