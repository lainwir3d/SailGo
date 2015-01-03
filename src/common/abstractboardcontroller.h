#ifndef ABSTRACTBOARDCONTROLLER_H
#define ABSTRACTBOARDCONTROLLER_H

#include <QObject>
#include "boardmodel.h"

class AbstractBoardController : public QObject
{
    Q_OBJECT
public:
    explicit AbstractBoardController(BoardModel * model, QObject *parent = 0);

    Q_INVOKABLE void playMove(int linearIndex);
    Q_INVOKABLE void playMove(int line, int column);

    QString nextPlayer();
    void switchPlayer();

signals:
    QString moveForbidden();
    int playerPassed();

public slots:

private:
    enum Player {
        WhitePlayer = 1,
        BlackPlayer = 2
    };
    int nextPlayer_;
    BoardModel * model_;

};

#endif // ABSTRACTBOARDCONTROLLER_H
