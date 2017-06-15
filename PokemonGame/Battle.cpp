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
	}
	for (int i = 0; i < t2->mPokemon.size(); i++)
	{
		t2->mPokemon[i]->mFacing = FACING_UP;
		t2->mPokemon[i]->mX = 1 + i * 2;
		t2->mPokemon[i]->mY = 11;
	}

	resetPokemon();
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

int Battle::getPokemonID(int trainer, int num)
{
	return (6*trainer + num);
}

int Battle::getPokemonAt(int x, int y)
{
	for (int i = 0; i < 12; i++)
	{
		Pokemon* p = getPokemon(i);
		if (p->mX == x && p->mY == y)
		{
			return i;
		}
	}
	return -1;
}

int& Battle::getTile(int i, int j)
{
	return mTiles[i * 13 + j];
}

bool Battle::attemptMove(int trainer, int num, int x, int y)
{
	Pokemon* p = getPokemon(trainer, num);

	if (trainer != mTurn || p->mHasMoved == 1 || p->mIsDead == 1)
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

bool Battle::attemptAttack(int trainer, int num, int attack_id, int targetx, int targety)
{
	Pokemon* p = getPokemon(trainer, num);

	if (mTurn != trainer || p->mHasAttacked == 1 || p->mIsDead == 1)
	{
		return false;
	}

	if (checkAttackTarget(trainer, num, attack_id, targetx, targety))
	{
		p->mAttacks[attack_id].onUse();
		p->mHasAttacked = 1;
		return true;
	}

	return false;
}

void Battle::forceAttack(int trainer, int num, int attack_id, int targetx, int targety)
{
	mAttackerID = getPokemonID(trainer, num);
	mTargetX = targetx;
	mTargetY = targety;
	getPokemon(trainer, num)->mAttacks[attack_id].onUse();
	getPokemon(trainer, num)->mHasAttacked = 1;
}

bool Battle::checkAttackTarget(int trainer, int num, int attack_id, int targetx, int targety)
{
	mAttackerID = getPokemonID(trainer, num);
	mTargetX = targetx;
	mTargetY = targety;

	return getPokemon(trainer, num)->mAttacks[attack_id].checkTarget();
}

void Battle::checkTurn()
{
	int flag = 0;
	for (int j = 0; j < 6; j++)
	{
		Pokemon* p = getPokemon(mTurn, j);
		if (p->mIsDead==0 && (p->mHasMoved == 0 || p->mHasAttacked == 0))
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		endTurn();
	}
}

void Battle::endTurn()
{
	mTurn = (mTurn + 1) % 2;
	resetPokemon();
}

void Battle::checkDead()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (getPokemon(i, j)->mCurrentHP <= 0)
			{
				getPokemon(i, j)->mIsDead = 1;
				getPokemon(i, j)->mCurrentHP = 0;
			}
		}
	}
}

void Battle::resetPokemon()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			getPokemon(i, j)->mHasMoved = 0;
			getPokemon(i, j)->mHasAttacked = 0;
		}
	}
}

