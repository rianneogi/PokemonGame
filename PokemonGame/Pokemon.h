#pragma once

#include "Ability.h"

extern lua_State* LuaPokemon;

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

	int mLifePerLvl;
	int mAttackPerLvl;
	int mSpecialAttackPerLvl;
	int mDefensePerLvl;
	int mSpecialDefensePerLvl;
	int mSpeedPerLvl;

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

