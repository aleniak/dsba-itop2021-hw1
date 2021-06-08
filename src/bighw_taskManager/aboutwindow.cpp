#include "aboutwindow.h"
#include "ui_aboutwindow.h"

AboutWindow::AboutWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutWindow)
{
    ui->setupUi(this);
    logo_of_the_app = new RenderArea(ui->frame);
    ui->gridLayout->addWidget(logo_of_the_app);
}

AboutWindow::~AboutWindow()
{
    delete ui;
    delete logo_of_the_app;
}
