#include "abstractboardcontroller.h"

AbstractBoardController::AbstractBoardController(BoardModel * model, QObject *parent) :
    QObject(parent)
{
    this->model_ = model;
    this->nextPlayer_ = WhitePlayer;
	 this->analysis = new MoveAnalysis(model);
}

AbstractBoardController::~AbstractBoardController()
{
	delete analysis;
}

void AbstractBoardController::playMove(int linearIndex)
{
    if(model_->isEmpty(linearIndex) && analysis->moveCorrect(this->nextPlayer_, linearIndex)) {
        this->model_->setPiece(linearIndex, this->nextPlayer_ == WhitePlayer ? model_->WhitePiece : model_->BlackPiece);
        switchPlayer();
    }else{
        qDebug("Not playable.");
    }
}

void AbstractBoardController::playMove(int line, int column)
{
	 playMove(model_->gridToLinearIndex(line, column));
}

QString AbstractBoardController::nextPlayer()
{
    QString player;

    player = nextPlayer_ == WhitePlayer ? "white" : "black";

    return player;
}

player_t AbstractBoardController::nextPlayerIndex()
{
	return nextPlayer_;
}

void AbstractBoardController::switchPlayer()
{
    this->nextPlayer_ = this->nextPlayer_ == WhitePlayer ? BlackPlayer : WhitePlayer;
    emit nextPlayerChanged();
}
