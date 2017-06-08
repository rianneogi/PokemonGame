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
}

static int getOpponent(lua_State* L)
{
	lua_pushinteger(L, gCurrentBattle->mOpponent);
}

static int dealDamage(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int dmg = lua_tointeger(L, 2);
	gCurrentBattle->mPokemon[pid]->mLife -= dmg;
}

static int heal(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int amt = lua_tointeger(L, 2);
	gCurrentBattle->mPokemon[pid]->mLife += amt;
}

void registerLua(lua_State* L)
{
	lua_register(L, "printstr", printstr);
	lua_register(L, "printint", printint);

	lua_register(L, "getSelf", getSelf);
	lua_register(L, "getOpponent", getSelf);
	lua_register(L, "dealDamage", dealDamage);
	lua_register(L, "heal", heal);
}
