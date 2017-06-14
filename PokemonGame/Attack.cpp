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

void Attack::onCast()
{
	lua_getglobal(LuaAttacks, "Attacks");
	lua_rawgeti(LuaAttacks, -1, mID + 1);
	lua_getfield(LuaAttaks, -1, "OnUse");
	lua_pcall(LuaAttacks, 0, 0, 0);
}
