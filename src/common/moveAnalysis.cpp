#include "moveAnalysis.h"

int MoveAnalysis::dirs[4][2] = {{ -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 }};

MoveAnalysis::MoveAnalysis(BoardModel *b)
{
	board = b;
}

void MoveAnalysis::move(player_t p, int pos)
{
	isCorrect = true;
}

void MoveAnalysis::reset()
{
	isCorrect = false;
	captives.clear();
}

bool MoveAnalysis::moveCorrect(player_t p, int pos)
{
	reset();
	move(p, pos);
	return isCorrect;
}

void MoveAnalysis::NeighB::possibles(unsigned int pos_, unsigned int nbCol, unsigned int nbPos)
{
	pos = pos_;
	nb = 0;

	if (pos >= nbCol) idx[nb++] = pos - nbCol;
	if (pos + nbCol < nbPos) idx[nb++] = pos + nbCol;
	if (pos % nbCol < nbCol - 1) idx[nb++] = pos + 1;
	if (pos > 0) idx[nb++] = pos - 1;
}
