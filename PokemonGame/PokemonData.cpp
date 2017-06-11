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
		lua_getfield(LuaPokemon, -1, std::to_string(i + 1).c_str());

		lua_getfield(LuaPokemon, -1, "Name");
		name = lua_tostring(LuaPokemon, -1);
		lua_pop(LuaPokemon, 2);

		printf("Loading %s\n", name);

		PokemonData d;
		d.Name = name;
		PokemonDatabase.push_back(d);
	}

	return 0;
}
