#include "Battle.h"

Battle::Battle(Trainer* t1, Trainer* t2)
{
	mTiles = new int[13 * 13];
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			getTile(i, j) = 0;
		}
	}
	mTrainers[0] = t1;
	mTrainers[1] = t2;
}

Battle::~Battle()
{
	delete[] mTiles;
}

Pokemon* Battle::getPokemon(int trainer, int num)
{
	return mTrainers[trainer]->mPokemon[num];
}

int& Battle::getTile(int i, int j)
{
	return mTiles[i * 13 + j];
}

