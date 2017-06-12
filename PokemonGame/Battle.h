#pragma once

#include "Trainer.h"

enum Tile { TILE_GRASS };

class Battle
{
public:
	Trainer* mTrainers[2];

	unsigned int mSelf;
	unsigned int mTarget;

	int* mTiles;

	Battle(Trainer* t1, Trainer* t2);
	~Battle();

	Pokemon* getPokemon(int id);
	Pokemon* getPokemon(int trainer, int num);
	int& getTile(int i, int j);

	bool move(int trainer, int num, int x, int y);
};

