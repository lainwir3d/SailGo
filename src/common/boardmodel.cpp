#include "boardmodel.h"

BoardModel::BoardModel(int rows, int columns, QObject *parent) :
    QAbstractTableModel(parent)
{
    this->nrows_ = rows;
    this->ncolumns_ = columns;
}

QHash<int, QByteArray> BoardModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[GridRole] = "squareState";
    roles[PieceRole] = "pieceState";
    roles[TerritoryRole] = "territory";
    roles[NoteRole] = "note";
    return roles;
}

int BoardModel::rowCount(const QModelIndex & parent) const
{
    return this->nrows_;
}


int BoardModel::columnCount(const QModelIndex & parent) const
{
    return this->ncolumns_;
}

QVariant BoardModel::data(const QModelIndex & index, int role) const
{
    QString state;	// grid state

    int row = index.row();
    int column = index.column();

    switch(role){
            case GridRole:
                if((row == 0) && (column == 0)){
                    state = "TopLeft";
                }else if((row == 0) && (column < columnCount()-1)){
                    state = "Top";
                }else if((row == 0) && (column == columnCount()-1)){
                    state = "TopRight";
                }else if((row == rowCount()-1) && (column == 0)){
                    state = "BottomLeft";
                }else if((row == rowCount()-1) && (column == columnCount()-1)){
                    state = "BottomRight";
                }else if(column == 0){
                    state = "Left";
                }else if(column == columnCount()-1){
                    state = "Right";
                }else if(row == rowCount()-1){
                    state = "Bottom";
                }else{
                    state = "Normal";
                }

                return state;
            case PieceRole:
                return QString("black");
            case TerritoryRole:
                return QString("neutral");
            case NoteRole:
                return QString("");
            default:
                return QVariant();
        }

    return QVariant();
}

