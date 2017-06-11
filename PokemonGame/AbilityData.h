#pragma once

#include "Include.h"

enum TargetType { TARGET_NONE, TARGET_UNIT, TARGET_GROUND, TARGET_NUM };

void registerLua(lua_State* L);

class AbilityData
{
public:
	std::string Name;
	int ID;

	int TargetType;
	std::string Description;

	AbilityData() {}
	~AbilityData() {}
};

int initAbilities();

extern std::vector<AbilityData> AbilityDatabase;