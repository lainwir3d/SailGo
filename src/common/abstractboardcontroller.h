#ifndef ABSTRACTBOARDCONTROLLER_H
#define ABSTRACTBOARDCONTROLLER_H

#include <QObject>

class AbstractBoardController : public QObject
{
    Q_OBJECT
public:
    explicit AbstractBoardController(QObject *parent = 0);

    void playMove();

signals:
    QString moveForbidden();
    int playerPassed();

public slots:

private:
    enum Player {
        WhitePlayer = 1,
        BlackPlayer = 2
    };
    int nextPlayer;

};

#endif // ABSTRACTBOARDCONTROLLER_H
