#ifndef DELETECONFIRMATION_H
#define DELETECONFIRMATION_H

#include <QDialog>

namespace Ui {
class deleteConfirmation;
}

class deleteConfirmation : public QDialog
{
    Q_OBJECT

public:
    explicit deleteConfirmation(QWidget *parent = nullptr);
    ~deleteConfirmation();
    bool if_not_canceled();

private slots:
    void onYesButtonClicked();
    void onNoButtonClicked();

private:
    Ui::deleteConfirmation *ui;
    bool yes_or_no = false;
};

#endif // DELETECONFIRMATION_H
