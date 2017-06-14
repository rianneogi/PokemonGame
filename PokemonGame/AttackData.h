#pragma once

#include "Include.h"

enum TargetMode { TARGET_NONE, TARGET_UNIT, TARGET_GROUND, TARGET_NUM };

extern lua_State* LuaAttacks;

void registerLua(lua_State* L);

class AttackData
{
public:
	std::string Name;
	int ID;
	int Type;

	int TargetCount;
	std::string Description;

	AttackData() {}
	~AttackData() {}
};

int initAttacks();

extern std::vector<AttackData> AttackDatabase;