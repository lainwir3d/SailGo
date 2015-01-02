#include "boardlistmodelwrapper.h"

BoardListModelWrapper::BoardListModelWrapper(BoardModel * model, QObject *parent) :
    QAbstractListModel(parent)
{
    this->model_ = model;
}

QHash<int, QByteArray> BoardListModelWrapper::roleNames() const
{
    return this->model_->roleNames();
}

int BoardListModelWrapper::rowCount(const QModelIndex & parent) const
{
    return this->model_->rowCount() * this->model_->columnCount();
}

const QModelIndex BoardListModelWrapper::rowToTableIndex(const QModelIndex &idx) const
{
    int tableRow = 0;
    int tableColumn = 0;

    tableRow = idx.row() / this->model_->columnCount();
    tableColumn = idx.row() % this->model_->columnCount();

    QModelIndex tableIdx = this->createIndex(tableRow, tableColumn);

    return tableIdx;
}

QVariant BoardListModelWrapper::data(const QModelIndex & index, int role) const
{
    QModelIndex tableIdx = rowToTableIndex(index);

    return this->model_->data(tableIdx, role);
}

