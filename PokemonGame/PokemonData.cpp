#include "PokemonData.h"

lua_State* LuaPokemon;
std::vector<PokemonData> PokemonDatabase;

int POKEMON_COUNT = 22;

float gTypeEffectiveness[TYPE_NUM][TYPE_NUM] =
{   //NOR FIG FLY POI GRO ROC BUG GHO STE FIR WAT GRA ELE PSY ICE DRA DAR FAI
	{ 1,  1,  1,  1,  1, .5,  1,  0, .5,  1,  1,  1,  1,  1,  1,  1,  1,  1 }, //NOR
	{ 2,  1, .5, .5,  1,  2, .5,  0,  2,  1,  1,  1,  1, .5,  2,  1,  2, .5 }, //FIG
	{ 1,  2,  1,  1,  1, .5,  2,  1, .5,  1,  1,  2, .5,  1,  1,  1,  1,  1 }, //FLY
	{ 1,  1,  1, .5, .5, .5,  1, .5,  0,  1,  1,  2,  1,  1,  1,  1,  1,  2 }, //POI
	{ 1,  1,  0,  2,  1,  2, .5,  1,  2,  2,  1, .5,  2,  1,  1,  1,  1,  1 }, //GRO
	{ 1, .5,  2,  1, .5,  1,  2,  1, .5,  2,  1,  1,  1,  1,  2,  1,  1,  1 }, //ROC
	{ 1, .5, .5, .5,  1,  1,  1, .5, .5, .5,  1,  2,  1,  2,  1,  1,  2, .5 }, //BUG
	{ 0,  1,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  1,  1, .5,  1 }, //GHO
	{ 1,  1,  1,  1,  1,  2,  1,  1, .5, .5, .5,  1, .5,  1,  2,  1,  1,  2 }, //STE
	{ 1,  1,  1,  1,  1, .5,  2,  1,  2, .5, .5,  2,  1,  1,  2, .5,  1,  1 }, //FIR
	{ 1,  1,  1,  1,  2,  2,  1,  1,  1,  2, .5, .5,  1,  1,  1, .5,  1,  1 }, //WAT
	{ 1,  1, .5, .5,  2,  2, .5,  1, .5, .5,  2, .5,  1,  1,  1, .5,  1,  1 }, //GRA
	{ 1,  1,  2,  1,  0,  1,  1,  1,  1,  1,  2, .5, .5,  1,  1, .5,  1,  1 }, //ELE
	{ 1,  2,  1,  2,  1,  1,  1,  1, .5,  1,  1,  1,  1, .5,  1,  1,  0,  1 }, //PSY
	{ 1,  1,  2,  1,  2,  1,  1,  1, .5, .5, .5,  2,  1,  1, .5,  2,  1,  1 }, //ICE
	{ 1,  1,  1,  1,  1,  1,  1,  1, .5,  1,  1,  1,  1,  1,  1,  2,  1,  0 }, //DRA
	{ 1, .5,  1,  1,  1,  1,  1,  2,  1,  1,  1,  1,  1,  2,  1,  1, .5, .5 }, //DAR
	{ 1,  2,  1, .5,  1,  1,  1,  1, .5, .5,  1,  1,  1,  1,  1,  2,  2,  1 }  //FAI
};

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

	for (int i = 0; i < POKEMON_COUNT; i++)
	{
		PokemonData d;

		lua_rawgeti(LuaPokemon, -1, i+1);

		//Name
		lua_getfield(LuaPokemon, -1, "Name");
		d.Name = lua_tostring(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);

		printf("Loading %s\n", d.Name);

		//Type
		lua_getfield(LuaPokemon, -1, "Types");
		lua_rawgeti(LuaPokemon, -1, 1);
		d.PrimaryType = lua_tointeger(LuaPokemon, -1);
		lua_pop(LuaPokemon, 1);
		lua_len(LuaPokemon, -1);
		if (luaL_checkinteger(LuaPokemon, -1) > 1)
		{
			lua_pop(LuaPokemon, 1);
			lua_rawgeti(LuaPokemon, -1, 2);
			d.SecondaryType = lua_tointeger(LuaPokemon, -1);
			lua_pop(LuaPokemon, 1);
		}
		else
		{
			lua_pop(LuaPokemon, 1);
			d.SecondaryType = -1;
		}
		lua_pop(LuaPokemon, 1);


		//Stats
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
