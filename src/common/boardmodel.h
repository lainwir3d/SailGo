#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QAbstractTableModel>

class BoardModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit BoardModel(int rows = 13, int columns = 13, QObject *parent = 0);

    enum BoardRoles {
        GridRole = Qt::UserRole+1,
        PieceRole,
        TerritoryRole,
        NoteRole
    };

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    QHash<int, QByteArray> roleNames() const;
signals:

public slots:

private:
    int nrows_;
    int ncolumns_;

};

#endif // BOARDMODEL_H
