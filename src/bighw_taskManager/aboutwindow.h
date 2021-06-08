#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>
#include "renderarea.h"

namespace Ui {
class AboutWindow;
}

class AboutWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = nullptr);
    ~AboutWindow();

private:
    Ui::AboutWindow *ui;
    RenderArea* logo_of_the_app;
};

#endif // ABOUTWINDOW_H
