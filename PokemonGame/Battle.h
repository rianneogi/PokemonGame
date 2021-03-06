#pragma once

#include "Trainer.h"

enum Tile { TILE_GRASS };

class Battle
{
public:
	Trainer* mTrainers[2];

	int mTurn;

	int mAttackerID;
	int mTargetX;
	int mTargetY;

	int* mTiles;

	Battle(Trainer* t1, Trainer* t2);
	~Battle();

	Pokemon* getPokemon(int id);
	Pokemon* getPokemon(int trainer, int num);
	int getPokemonID(int trainer, int num);
	int getPokemonAt(int x, int y);
	int& getTile(int i, int j);

	bool attemptMove(int trainer, int num, int x, int y);
	bool attemptAttack(int trainer, int num, int attack_id, int targetx, int targety);
	void forceAttack(int trainer, int num, int attack_id, int targetx, int targety);
	bool checkAttackTarget(int trainer, int num, int attack_id, int targetx, int targety);

	void checkTurn();
	void endTurn();
	void checkDead();
	void resetPokemon();
};

