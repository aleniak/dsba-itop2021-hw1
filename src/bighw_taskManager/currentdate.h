#ifndef CURRENTDATE_H
#define CURRENTDATE_H

#include <QDialog>

namespace Ui {
class currentDate;
}

class currentDate : public QDialog
{
    Q_OBJECT

public:
    explicit currentDate(QWidget *parent = nullptr);
    ~currentDate();
    bool if_closed();
    QVariant date_fin();

private slots:
    void onEdit_Pushed();
    void onCancel_Pushed();

private:
    Ui::currentDate *ui;
    bool if_can = false;
    QVariant *input;
};

#endif // CURRENTDATE_H
