#include "abstractboardcontroller.h"

AbstractBoardController::AbstractBoardController(QObject *parent) :
    QObject(parent)
{
    this->nextPlayer = WhitePlayer;
}
