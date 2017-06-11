#include "PokemonData.h"

lua_State* LuaPokemon;
std::vector<PokemonData> PokemonDatabase;

int initPokemon()
{
	LuaPokemon = luaL_newstate();
	luaL_openlibs(LuaPokemon);

	registerLua(LuaPokemon);

	if (luaL_loadfile(LuaPokemon, "Lua\\Pokemon.lua") || lua_pcall(LuaPokemon, 0, 0, 0))
	{
		std::cout << "Error: failed to load Cards.lua" << std::endl;
		std::cout << lua_tostring(LuaPokemon, -1) << "\n";
		//_getch();
		return -1;
	}

	lua_getglobal(LuaPokemon, "Pokemon");

	std::string name;

	for (int i = 0; i < 1; i++)
	{
		PokemonData d;

		lua_pushinteger(LuaPokemon, i + 1);
		lua_gettable(LuaPokemon, -2);

		lua_getfield(LuaPokemon, -1, "Name");
		d.Name = lua_tostring(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		printf("Loading %s\n", name);

		lua_getfield(LuaPokemon, -1, "BaseHP");
		d.BaseStats[STAT_HP] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "BaseAtk");
		d.BaseStats[STAT_ATK] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "BaseDef");
		d.BaseStats[STAT_DEF] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "BaseSpAtk");
		d.BaseStats[STAT_SPATK] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "BaseSpDef");
		d.BaseStats[STAT_SPDEF] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "BaseSpeed");
		d.BaseStats[STAT_SPEED] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "HPGain");
		d.StatGains[STAT_HP] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "AtkGain");
		d.StatGains[STAT_ATK] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "DefGain");
		d.StatGains[STAT_DEF] = lua_tonumber(LuaPokemon, -1); 
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "SpAtkGain");
		d.StatGains[STAT_SPATK] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "SpAtkGain");
		d.StatGains[STAT_SPDEF] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_getfield(LuaPokemon, -1, "SpeedGain");
		d.StatGains[STAT_SPEED] = lua_tonumber(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		lua_pop(LuaPokemon, 1);
		
		PokemonDatabase.push_back(d);
	}

	return 0;
}
