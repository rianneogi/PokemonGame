#pragma once

#include <vector>

#include "Ability.h"

class Pokemon
{
public:
	int mLevel;

	int mLife;
	int mAttack;
	int mSpecialAttack;
	int mDefense;
	int mSpecialDefense;
	int mSpeed;

	int mAccuracy;
	int mEvasion;

	std::vector<Ability> mAbilities;
	std::vector<StatusEffect> mStatusEffects;

	Pokemon();
	~Pokemon();
};

