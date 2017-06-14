#include "AttackData.h"

lua_State* LuaAttacks;
std::vector<AttackData> AttackDatabase;

int ATTACK_NUM = 4;

int initAttacks()
{
	LuaAttacks = luaL_newstate();
	luaL_openlibs(LuaAttacks);

	registerLua(LuaAttacks);

	if (luaL_loadfile(LuaAttacks, "Lua\\Attacks.lua") || lua_pcall(LuaAttacks, 0, 0, 0))
	{
		std::cout << "Error: failed to load Attacks.lua" << std::endl;
		std::cout << lua_tostring(LuaAttacks, -1) << "\n";
		//_getch();
		return -1;
	}

	lua_getglobal(LuaAttacks, "Attacks");

	for (int i = 0; i < ATTACK_NUM; i++)
	{
		AttackData d;

		lua_rawgeti(LuaAttacks, -1, i + 1);

		//Name
		lua_getfield(LuaAttacks, -1, "Name");
		d.Name = lua_tostring(LuaAttacks, -1);
		lua_pop(LuaAttacks, 1);

		printf("Loading Attack: %s\n", d.Name);

		//Type
		lua_getfield(LuaAttacks, -1, "Type");
		d.Type = lua_tointeger(LuaAttacks, -1);
		lua_pop(LuaAttacks, 1);

		//Target Mode
		lua_getfield(LuaAttacks, -1, "TargetMode");
		d.TargetCount = lua_tointeger(LuaAttacks, -1);
		lua_pop(LuaAttacks, 1);

		//Description
		lua_getfield(LuaAttacks, -1, "Description");
		d.Description = lua_tointeger(LuaAttacks, -1);
		lua_pop(LuaAttacks, 1);

		lua_pop(LuaAttacks, 1);

		AttackDatabase.push_back(d);
	}

	return 0;
}
