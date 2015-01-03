#include "abstractboardcontroller.h"

AbstractBoardController::AbstractBoardController(BoardModel * model, QObject *parent) :
    QObject(parent)
{
    this->model_ = model;
    this->nextPlayer_ = WhitePlayer;
}

void AbstractBoardController::playMove(int linearIndex)
{
    if(model_->isEmpty(linearIndex)){
        this->model_->setPiece(linearIndex, this->nextPlayer_ == WhitePlayer ? model_->WhitePiece : model_->BlackPiece);
        switchPlayer();
    }else{
        qDebug("Not playable.");
    }
}

void AbstractBoardController::playMove(int line, int column)
{
    if(model_->isEmpty(line, column)){
        this->model_->setPiece(line, column, this->nextPlayer_ == WhitePlayer ? model_->WhitePiece : model_->BlackPiece);
        switchPlayer();
    }else{
        qDebug("Not playable.");
    }
}

QString AbstractBoardController::nextPlayer()
{
    QString player;

    player = nextPlayer_ == WhitePlayer ? "white" : "black";

    return player;
}

void AbstractBoardController::switchPlayer()
{
    this->nextPlayer_ = this->nextPlayer_ == WhitePlayer ? BlackPlayer : WhitePlayer;
    emit nextPlayerChanged();
}
