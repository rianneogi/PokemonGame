#include "Battle.h"

Battle::Battle(Trainer* t1, Trainer* t2)
{
	mTiles = new int[13 * 13];
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			getTile(i, j) = TILE_GRASS;
		}
	}
	mTrainers[0] = t1;
	mTrainers[1] = t2;

	for (int i = 0; i < t1->mPokemon.size(); i++)
	{
		t1->mPokemon[i]->mFacing = FACING_DOWN;
		t1->mPokemon[i]->mX = 1 + i * 2;
		t1->mPokemon[i]->mY = 1;
		t1->mPokemon[i]->mHasMoved = 0;
	}
	for (int i = 0; i < t2->mPokemon.size(); i++)
	{
		t2->mPokemon[i]->mFacing = FACING_UP;
		t2->mPokemon[i]->mX = 1 + i * 2;
		t2->mPokemon[i]->mY = 11;
		t1->mPokemon[i]->mHasMoved = 0;
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

bool Battle::attemptMove(int trainer, int num, int x, int y)
{
	Pokemon* p = getPokemon(trainer, num);

	if (trainer != mTurn || p->mHasMoved == 1)
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
		p->mHasMoved = 1;
		checkTurn();
		return true;
	}
	return false;
}

bool Battle::attemptAttack(int trainer, int num, int attack_id, int target)
{
	return false;
}

void Battle::checkTurn()
{
	int flag = 0;
	for (int j = 0; j < 6; j++)
	{
		if (getPokemon(mTurn, j)->mHasMoved == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		mTurn = (mTurn + 1) % 2;
		resetPokemon();
	}
}

void Battle::resetPokemon()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			getPokemon(i, j)->mHasMoved = 0;
		}
	}
}

