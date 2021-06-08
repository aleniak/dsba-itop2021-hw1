#ifndef DELEGATEWINDOW_H
#define DELEGATEWINDOW_H

#include <QDialog>
#include "examplemodel.h"

namespace Ui {
class delegateWindow;
}

class delegateWindow : public QDialog
{
    Q_OBJECT

public:
    explicit delegateWindow(QWidget *parent = nullptr);
    ~delegateWindow();
    QList<QVariant> getName();
    bool if_can();
    void give_to_another();

private slots:
    virtual void onDonePushed();
    void onCancelPushed();

private:
    Ui::delegateWindow *ui;
    QList<QVariant> newinf = {"",""};
    bool closed = false;
    ExampleModel *Model;

};

#endif // DELEGATEWINDOW_H
