#pragma once

#include "AttackData.h"

extern lua_State* LuaAbility;

class AbilityData
{
public:
	std::string Name;
	int ID;

	std::string Description;

	AbilityData() {}
	~AbilityData() {}
};

int initAbilities();

extern std::vector<AbilityData> AbilityDatabase;