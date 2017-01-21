#pragma once

#include "StatusEffect.h"

class Ability
{
public:
	unsigned int mAbilityID;

	int mPP;

	Ability();
	Ability(unsigned int id);
	~Ability();

	void use();
};

