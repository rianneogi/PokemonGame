#pragma once

#include "Trainer.h"

class Battle
{
public:
	Trainer* mTrainers[2];

	unsigned int mSelf;
	unsigned int mTarget;

	std::vector<Pokemon*> mPokemon;

	std::vector<Pokemon*> mPlayer1Pokemon;
	std::vector<Pokemon*> mPlayer2Pokemon;

	unsigned int mNumPokemonInBattle;
	std::vector<unsigned int> mPlayer1InBattle;
	std::vector<unsigned int> mPlayer2InBattle;

	int* mTiles;

	Battle(Trainer* t1, Trainer* t2);
	~Battle();


	Pokemon* getPokemon(int trainer, int num);
	int& getTile(int i, int j);
};

