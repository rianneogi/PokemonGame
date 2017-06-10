#include "LuaFunctions.h"

Battle* gCurrentBattle;

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
	int pid = lua_tointeger(L, 1);
	int dmg = lua_tointeger(L, 2);
	gCurrentBattle->mPokemon[pid]->mLife -= dmg;
	return 0;
}

static int heal(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int amt = lua_tointeger(L, 2);
	gCurrentBattle->mPokemon[pid]->mLife += amt;
	return 0;
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
