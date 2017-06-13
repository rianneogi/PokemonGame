#pragma once

#include "Trainer.h"

enum Tile { TILE_GRASS };

class Battle
{
public:
	Trainer* mTrainers[2];

	int mTurn;

	int mSelf;
	int mTarget;

	int* mTiles;

	Battle(Trainer* t1, Trainer* t2);
	~Battle();

	Pokemon* getPokemon(int id);
	Pokemon* getPokemon(int trainer, int num);
	int& getTile(int i, int j);

	bool attemptMove(int trainer, int num, int x, int y);
	bool attemptAttack(int trainer, int num, int attack_id, int target);

	void checkTurn();
	void resetPokemon();
};

