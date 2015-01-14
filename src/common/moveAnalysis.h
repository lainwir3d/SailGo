#pragma once

#include <vector>

#include "boardmodel.h"
#include "common.h"

class BoardModel;

class MoveAnalysis
{
	public:
	bool isCorrect;

	MoveAnalysis(BoardModel *b);
	void move(player_t p, int i);
	bool moveCorrect(player_t p, int i);

	private:
	struct NeighB {
		unsigned int nb;
		unsigned int pos;
		unsigned int idx[4];
		void possibles(unsigned int pos_, unsigned int nbCol, unsigned int nbPos);
	};

	static int dirs[4][2];
	BoardModel *board;
	std::vector<int> captives;

	void reset();
};
