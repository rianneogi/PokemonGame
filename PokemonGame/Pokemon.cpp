#include "Pokemon.h"

lua_State* LuaPokemon;

Pokemon::Pokemon(int species, int level) : mSpecies(species), mLevel(level)
{
	lua_getglobal(LuaPokemon, "Pokemon");
	lua_getfield(LuaPokemon, -1, CardNames.at(cid).c_str());

	lua_getfield(LuaPokemon, -1, "name");
	Name = lua_tostring(LuaPokemon, -1);
	lua_pop(LuaPokemon, 1);
}

Pokemon::~Pokemon()
{
}


