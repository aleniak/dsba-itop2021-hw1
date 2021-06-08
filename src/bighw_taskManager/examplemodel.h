#ifndef EXAMPLEMODEL_H
#define EXAMPLEMODEL_H

#include <QAbstractTableModel>
#include <QList>


class ExampleModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ExampleModel(QObject *parent = nullptr);

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    void appendRow(QList<QVariant> newRow);

    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void fillModelWithData(QString path);
    void saveModelAsFile(QString path);

    void deleteRow(int idx);
    void deleteAll();

    int give_num_of_rows();
    int size_of_table();

    QList<QVariant> getRow(int n);
    void change_status(int n);

    void changed_status_by_window(QVariant st, int num_r);

    void delegated1(QVariant per, int row);
    void delegated2(QVariant per, int row);

private:
    QList<QList<QVariant> > exampleData;
    QList<QString> headerList;
    int overall_num_of_rows = exampleData.size();
};

#endif // EXAMPLEMODEL_H
