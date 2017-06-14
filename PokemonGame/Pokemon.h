#pragma once

#include "Ability.h"

enum Facing { FACING_UP, FACING_DOWN, FACING_LEFT, FACING_RIGHT };

class Pokemon
{
public:
	int mSpecies;

	std::string mName;

	int mPrimaryType;
	int mSecondaryType;

	int mLevel;
	int mMovement;
	float mStats[STAT_NUM];
	float mStatGains[STAT_NUM];

	std::vector<Attack> mAttacks;

	float mCurrentHP;
	int mAccuracy;
	int mEvasion;
	int mX;
	int mY;
	int mFacing;

	int mHasMoved;
	int mHasAttacked;
	int mIsDead;

	std::vector<StatusEffect> mStatusEffects;

	Pokemon(int species, int lvl);
	~Pokemon();
};

