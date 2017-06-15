#include "Attack.h"

Attack::Attack()
{
	printf("WARNING: Ability init without id\n");
}

Attack::Attack(std::string name)
{
	int flag = 0;
	for (size_t i = 0; i < AttackDatabase.size(); i++)
	{
		if (AttackDatabase[i].Name == name)
		{
			mID = AttackDatabase[i].ID;
			mTargetCount = AttackDatabase[i].TargetCount;
			mDescription = AttackDatabase[i].Description;
			mType = AttackDatabase[i].Type;
			mName = name;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("ERROR: Cant find attack name: %s\n", name.c_str());
	}
}

Attack::~Attack()
{
}

void Attack::onUse()
{
	lua_getglobal(LuaAttacks, "Attacks");
	lua_rawgeti(LuaAttacks, -1, mID + 1);
	lua_getfield(LuaAttacks, -1, "OnUse");
	lua_pcall(LuaAttacks, 0, 0, 0);
	lua_pop(LuaAttacks, 3);
}

bool Attack::checkTarget()
{
	lua_getglobal(LuaAttacks, "Attacks");
	lua_rawgeti(LuaAttacks, -1, mID + 1);
	lua_getfield(LuaAttacks, -1, "CheckTarget");
	lua_pcall(LuaAttacks, 0, 1, 0);
	int r = lua_tointeger(LuaAttacks, -1);
	lua_pop(LuaAttacks, 3);
	return r;
}
