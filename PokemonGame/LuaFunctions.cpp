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

static int dealDamage(lua_State* L)
{
	int atker_id = lua_tointeger(L, 1);
	int dfnder_id = lua_tointeger(L, 2);
	int pow = lua_tointeger(L, 3);
	int type = lua_tointeger(L, 4);

	Pokemon* attacker = gCurrentBattle->getPokemon(atker_id);
	Pokemon* defender = gCurrentBattle->getPokemon(dfnder_id);

	printf("Pow: %d\n", pow);

	float dmg = pow * (attacker->mStats[STAT_ATK] / defender->mStats[STAT_DEF]);
	printf("first pass: %f\n", dmg);
	dmg *= gTypeEffectiveness[type][defender->mPrimaryType];
	if (defender->mSecondaryType != -1)
	{
		dmg *= gTypeEffectiveness[type][defender->mSecondaryType];
	}
	printf("scnd pass: %f\n", dmg);
	if (type == attacker->mPrimaryType || type == attacker->mSecondaryType)
	{
		dmg *= 1.33; //STAB bonus
	}
	printf("dmg dealt: %f\n", dmg);
	defender->mCurrentHP -= dmg;
	return 0;
}

static int applyStatus(lua_State* L)
{
	int atker_id = lua_tointeger(L, 1);
	int dfnder_id = lua_tointeger(L, 2);
	int status_name = lua_tointeger(L, 3);
	int pow = lua_tointeger(L, 4);
	int type = lua_tointeger(L, 5);

	Pokemon* attacker = gCurrentBattle->getPokemon(atker_id);
	Pokemon* defender = gCurrentBattle->getPokemon(dfnder_id);

	float strength = pow * (attacker->mStats[STAT_SPATK] / defender->mStats[STAT_SPDEF]);
	strength *= gTypeEffectiveness[type][defender->mPrimaryType] * gTypeEffectiveness[type][defender->mSecondaryType];
	if (type == attacker->mPrimaryType || type == attacker->mSecondaryType)
	{
		strength *= 1.33; //STAB bonus
	}

	if (strength >= 10)
	{
		defender->mStatusEffects.push_back(StatusEffect());
	}
	return 0;
}

static int move(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int x = lua_tointeger(L, 2);
	int y = lua_tointeger(L, 3);

	gCurrentBattle->getPokemon(pid)->mX = x;
	gCurrentBattle->getPokemon(pid)->mY = y;

	return 0;
}

static int heal(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int amt = lua_tointeger(L, 2);
	gCurrentBattle->getPokemon(pid)->mCurrentHP += amt;
	return -1;
}


static int getAttacker(lua_State* L)
{
	lua_pushinteger(L, gCurrentBattle->mAttackerID);
	return 1;
}

static int getAttackTarget(lua_State* L)
{
	lua_pushinteger(L, gCurrentBattle->mTargetX);
	lua_pushinteger(L, gCurrentBattle->mTargetY);
	return 2;
}

static int isTileOccupied(lua_State* L)
{
	int x = lua_tointeger(L, 1);
	int y = lua_tointeger(L, 2);

	if (gCurrentBattle->getPokemonAt(x, y) == -1)
	{
		lua_pushinteger(L, 0);
	}
	else
	{
		lua_pushinteger(L, 1);
	}

	return 1;
}

static int getPokemonPos(lua_State* L)
{
	int pid = lua_tointeger(L, 1);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mX);
	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mY);

	return 2;
}

static int getPokemonAt(lua_State* L)
{
	int x = lua_tointeger(L, 1);
	int y = lua_tointeger(L, 2);

	lua_pushinteger(L, gCurrentBattle->getPokemonAt(x, y));

	return 1;
}

static int getPokemonSpecies(lua_State* L)
{
	int pid = lua_tointeger(L, 1);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mSpecies);

	return 1;
}

static int getPokemonCurrentHP(lua_State* L)
{
	int pid = lua_tointeger(L, 1);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mCurrentHP);

	return 1;
}

static int getPokemonStat(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int stat_id = lua_tointeger(L, 2);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mStats[stat_id]);

	return 1;
}

static int getPokemonStatGain(lua_State* L)
{
	int pid = lua_tointeger(L, 1);
	int stat_id = lua_tointeger(L, 2);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mStatGains[stat_id]);

	return 1;
}

static int getPokemonHasMoved(lua_State* L)
{
	int pid = lua_tointeger(L, 1);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mHasMoved);

	return 1;
}

static int getPokemonHasAttacked(lua_State* L)
{
	int pid = lua_tointeger(L, 1);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mHasAttacked);

	return 1;
}

static int getPokemonIsDead(lua_State* L)
{
	int pid = lua_tointeger(L, 1);

	lua_pushinteger(L, gCurrentBattle->getPokemon(pid)->mIsDead);

	return 1;
}

void registerLua(lua_State* L)
{
	lua_register(L, "printstr", printstr);
	lua_register(L, "printint", printint);

	lua_register(L, "dealDamage", dealDamage);
	lua_register(L, "applyStatus", applyStatus);
	lua_register(L, "move", move);
	lua_register(L, "heal", heal);

	lua_register(L, "getAttacker", getAttacker);
	lua_register(L, "getAttackTarget", getAttackTarget);
	lua_register(L, "isTileOccupied", isTileOccupied);
	lua_register(L, "getPokemonPos", getPokemonPos);
	lua_register(L, "getPokemonAt", getPokemonAt);
	lua_register(L, "getPokemonCurrentHP", getPokemonCurrentHP);
	lua_register(L, "getPokemonStat", getPokemonStat);
	lua_register(L, "getPokemonStatGain", getPokemonStatGain);
	lua_register(L, "getPokemonHasMoved", getPokemonHasMoved);
	lua_register(L, "getPokemonHasAttacked", getPokemonHasAttacked);
	lua_register(L, "getPokemonIsDead", getPokemonIsDead);
}
