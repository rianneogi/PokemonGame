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

	for (int i = 0; i < t1->mPokemon.size(); i++)
	{
		t1->mPokemon[i]->mFacing = FACING_DOWN;
		t1->mPokemon[i]->mX = 1 + i * 2;
		t1->mPokemon[i]->mY = 1;
	}
	for (int i = 0; i < t2->mPokemon.size(); i++)
	{
		t2->mPokemon[i]->mFacing = FACING_UP;
		t2->mPokemon[i]->mX = 1 + i * 2;
		t2->mPokemon[i]->mY = 11;
	}
}

Battle::~Battle()
{
	delete[] mTiles;
}

Pokemon* Battle::getPokemon(int id)
{
	return mTrainers[id/6]->mPokemon[id%6];
}

Pokemon* Battle::getPokemon(int trainer, int num)
{
	return mTrainers[trainer]->mPokemon[num];
}

int& Battle::getTile(int i, int j)
{
	return mTiles[i * 13 + j];
}

bool Battle::move(int trainer, int num, int x, int y)
{
	Pokemon* p = getPokemon(trainer, num);

	if (trainer != mTurn) //not your turn
	{
		return false;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (getPokemon(i, j)->mX == x && getPokemon(i, j)->mY == y) //target location is occupied
			{
				return false;
			}
		}
	}

	if (abs(p->mX - x) <= p->mMovement && abs(p->mY - y) <= p->mMovement)
	{
		p->mX = x;
		p->mY = y;
		return true;
	}
	return false;
}

