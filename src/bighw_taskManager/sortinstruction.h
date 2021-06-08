#ifndef SORTINSTRUCTION_H
#define SORTINSTRUCTION_H

#include <QDialog>

namespace Ui {
class sortInstruction;
}

class sortInstruction : public QDialog
{
    Q_OBJECT

public:
    explicit sortInstruction(QWidget *parent = nullptr);
    ~sortInstruction();

private slots:
    void onGotItPushed();

private:
    Ui::sortInstruction *ui;
};

#endif // SORTINSTRUCTION_H
