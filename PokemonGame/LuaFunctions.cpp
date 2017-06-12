#include "LuaFunctions.h"

static int printstr(lua_State* L)
{
	std::cout << lua_tostring(L, 1);
	return 0;
}

static int printint(lua_State* L)
{
	std::cout << lua_tointeger(L, 1);
	return 0;
}

static int getSelf(lua_State* L)
{
	lua_pushinteger(L, gCurrentBattle->mSelf);
	return 1;
}

static int getTarget(lua_State* L)
{
	lua_pushinteger(L, gCurrentBattle->mTarget);
	return 1;
}

static int dealDamage(lua_State* L)
{
	int atker_id = lua_tointeger(L, 1);
	int dfnder_id = lua_tointeger(L, 2);
	int pow = lua_tointeger(L, 3);
	int type = lua_tointeger(L, 4);

	Pokemon* attacker = gCurrentBattle->getPokemon(atker_id);
	Pokemon* defender = gCurrentBattle->getPokemon(dfnder_id);

	float dmg = pow * attacker->mStats[STAT_ATK] / defender->mStats[STAT_DEF];
	dmg *= gTypeEffectiveness[type][defender->mPrimaryType] * gTypeEffectiveness[type][defender->mSecondaryType];
	if (type == attacker->mPrimaryType || type == attacker->mSecondaryType)
	{
		dmg *= 1.25; //STAB bonus
	}

	defender->mCurrentHP -= dmg;
	return 0;
}

static int heal(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int amt = lua_tointeger(L, 2);
	gCurrentBattle->getPokemon(pid)->mCurrentHP += amt;
	return -1;
}

void registerLua(lua_State* L)
{
	lua_register(L, "printstr", printstr);
	lua_register(L, "printint", printint);

	lua_register(L, "getSelf", getSelf);
	lua_register(L, "getTarget", getTarget);
	lua_register(L, "dealDamage", dealDamage);
	lua_register(L, "heal", heal);
}
