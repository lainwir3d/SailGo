#include "abstractboardcontroller.h"

AbstractBoardController::AbstractBoardController(BoardModel * model, QObject *parent) :
    QObject(parent)
{
    this->model_ = model;
    this->nextPlayer = WhitePlayer;
}

void AbstractBoardController::playMove(int linearIndex)
{
    if(model_->isEmpty(linearIndex)){
        this->model_->setPiece(linearIndex, this->nextPlayer == WhitePlayer ? model_->WhitePiece : model_->BlackPiece);
        this->nextPlayer = this->nextPlayer == WhitePlayer ? BlackPlayer : WhitePlayer;
    }else{
        qDebug("Not playable.");
    }
}

void AbstractBoardController::playMove(int line, int column)
{
    if(model_->isEmpty(line, column)){
        this->model_->setPiece(line, column, this->nextPlayer == WhitePlayer ? model_->WhitePiece : model_->BlackPiece);
        this->nextPlayer = this->nextPlayer == WhitePlayer ? BlackPlayer : WhitePlayer;
    }else{
        qDebug("Not playable.");
    }
}
