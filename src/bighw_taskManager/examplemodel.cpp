#include "examplemodel.h"
#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QList>
#include <QFileDialog>
#include <QBrush>

ExampleModel::ExampleModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int ExampleModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return exampleData.size();
}

int ExampleModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    if (exampleData.empty())
    {
        return 0;
    }
    return exampleData[0].size();
}

QVariant ExampleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && !headerList.empty())
    {
        if (orientation == Qt::Orientation::Horizontal)
        {
            return headerList.at(section);
        }
        else
        {
            return section + 1;
        }
    }
    return QVariant();
}

QVariant ExampleModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole || role == Qt::EditRole)
    {
        int row = index.row();
        int column = index.column();

        return exampleData.at(row).at(column);
    }
    return QVariant();
}


bool ExampleModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {

        exampleData[index.row()][index.column()] = value.toString();

        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ExampleModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}


void ExampleModel::appendRow(QList<QVariant> newRow)
{
    bool columnFlag = false;
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    if (exampleData.isEmpty())
    {
        columnFlag = true;
        beginInsertColumns(QModelIndex(), 0, newRow.size() - 1);
        endInsertColumns();
    }
    exampleData.append(newRow);
    overall_num_of_rows += 1;
    endInsertRows();
}

void ExampleModel::fillModelWithData(QString path)
{
    deleteAll();
    QFile inputFile(path);
    inputFile.open(QFile::ReadOnly | QFile::Text);
    QTextStream inputStream(&inputFile);

    QString firstline = inputStream.readLine();
    headerList = firstline.split(";");

    while(!inputStream.atEnd())
    {
        QString line = inputStream.readLine();
        QList<QVariant> dataRow;
        for (QString& item : line.split(";")) {
            bool ok = false;
            QVariant itemnum = item.toInt(&ok);
            if (ok)
            {
                dataRow.append(itemnum);
                continue;
            }
            itemnum = item.toDouble(&ok);
            if (ok)
            {
                dataRow.append(itemnum);
                continue;
            }
            dataRow.append(item);
        }
        appendRow(dataRow);
    }
    inputFile.close();
}

void ExampleModel::saveModelAsFile(QString path)
{
    QFile outFile(path);
    outFile.open(QFile::WriteOnly | QFile::Text);
    QTextStream out(&outFile);

    for (int j = 0; j < columnCount(); ++j)
    {
        out << headerList.at(j);
        if (j != columnCount() - 1)
        {
            out << ";";
        }
    }
    out << "\n";

    for (int i = 0; i < rowCount(); ++i)
    {
        for (int j = 0; j < columnCount(); ++j)
        {
            QModelIndex idx = index(i, j);
            out << data(idx).toString();
            if (j != columnCount() - 1)
            {
                out << ";";
            }
        }
        out << "\n";
    }
    outFile.close();
}

void ExampleModel::deleteRow(int idx)
{
    beginRemoveRows(QModelIndex(), idx, idx);
    exampleData.removeAt(idx);
    endRemoveRows();
}

void ExampleModel::deleteAll()
{

    beginRemoveColumns(QModelIndex(), 0, columnCount() - 1);
    beginRemoveRows(QModelIndex(), 0, rowCount() - 1);
    exampleData.clear();
    endRemoveRows();
    endRemoveColumns();
}

int ExampleModel::give_num_of_rows()
{
    return overall_num_of_rows;
}

int ExampleModel::size_of_table()
{
    return exampleData.size();
}

QList<QVariant> ExampleModel::getRow(int n)
{
    return exampleData[n];
}

void ExampleModel::change_status(int n)
{
    exampleData[n][5] = "Not Completed";
}

void ExampleModel::changed_status_by_window(QVariant st, int num_r)
{
    exampleData[num_r][5] = st;
}

void ExampleModel::delegated1(QVariant per, int row)
{
    exampleData[row][1] = per;
}

void ExampleModel::delegated2(QVariant per, int row)
{
    exampleData[row][2] = per;
}
