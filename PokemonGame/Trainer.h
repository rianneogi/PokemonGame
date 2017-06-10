#pragma once

#include "Pokemon.h"

class Trainer
{
public:
	uint64_t mID;

	std::vector<Pokemon*> mPokemon;

	Trainer(uint64_t id);
	~Trainer();
};

