#pragma once

#include "AbilityData.h"

extern lua_State* LuaPokemon;

enum Stat { STAT_HP, STAT_ATK, STAT_DEF, STAT_SPATK, STAT_SPDEF, STAT_SPEED, STAT_NUM };

enum Type {TYPE_NORMAL, TYPE_FIGHTING, TYPE_FLYING, TYPE_POISON, TYPE_GROUND, TYPE_ROCK, TYPE_BUG, TYPE_GHOST, TYPE_STEEL, TYPE_FIRE,
TYPE_WATER, TYPE_GRASS, TYPE_ELECTRIC, TYPE_PSYCHIC, TYPE_ICE, TYPE_DRAGON, TYPE_DARK, TYPE_FAIRY, TYPE_NUM};

class PokemonData
{
public:
	std::string Name;

	int Species;
	uint32_t Type;
	
	double BaseStats[STAT_NUM];
	double StatGains[STAT_NUM];

	PokemonData() {}
	~PokemonData() {}
};

int initPokemon();

extern std::vector<PokemonData> PokemonDatabase;

