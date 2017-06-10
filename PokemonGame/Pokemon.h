#pragma once

#include <vector>

#include "Ability.h"

enum Facing { FACING_UP, FACING_DOWN, FACING_LEFT, FACING_RIGHT };

class Pokemon
{
public:
	int mSpecies;

	std::string mName;

	int mLevel;

	int mLife;
	int mAttack;
	int mSpecialAttack;
	int mDefense;
	int mSpecialDefense;
	int mSpeed;

	int mAccuracy;
	int mEvasion;

	int mX;
	int mY;
	int mFacing;

	std::vector<Ability> mAbilities;
	std::vector<StatusEffect> mStatusEffects;

	Pokemon(int species, int lvl);
	~Pokemon();
};

