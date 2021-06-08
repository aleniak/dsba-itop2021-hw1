#ifndef CHANGEWINDOW_H
#define CHANGEWINDOW_H

#include <QDialog>

namespace Ui {
class ChangeWindow;
}

class ChangeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ChangeWindow(QWidget *parent = nullptr);
    ~ChangeWindow();
    bool not_closed();
    QVariant get_new_status();

private slots:
        virtual void onInProgressPushed();
        virtual void onCompletedPushed();
        virtual void onNotCompletedPushed();
        virtual void on_CancelPushed();

private:
    Ui::ChangeWindow *ui;
    bool canceled = false;
    QVariant *status_new;
};

#endif // CHANGEWINDOW_H
