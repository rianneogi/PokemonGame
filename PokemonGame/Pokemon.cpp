#include "Pokemon.h"

Pokemon::Pokemon(int species, int level) : mSpecies(species), mLevel(level)
{
	mName = PokemonDatabase[species].Name;

	for (int i = 0; i < STAT_NUM; i++)
	{
		mStats[i] = PokemonDatabase[species].BaseStats[i];
		mStatGains[i] = PokemonDatabase[species].StatGains[i];
	}

	for (int i = 0; i < STAT_NUM; i++)
	{
		mStats[i] += (level-1)*mStatGains[i];
	}

	mCurrentHP = mStats[STAT_HP];
	mMovement = 2;

	mPrimaryType = PokemonDatabase[species].PrimaryType;
	mSecondaryType = PokemonDatabase[species].SecondaryType;
}

Pokemon::~Pokemon()
{
}


