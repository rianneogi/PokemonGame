#pragma once

#include "Pokemon.h"

class Battle
{
public:
	std::vector<Pokemon*> mPlayer1Pokemon;
	std::vector<Pokemon*> mPlayer2Pokemon;

	unsigned int mNumPokemonInBattle;
	std::vector<unsigned int> mPlayer1InBattle;
	std::vector<unsigned int> mPlayer2InBattle;

	Battle();
	~Battle();
};

