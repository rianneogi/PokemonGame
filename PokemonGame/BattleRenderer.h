#pragma once

#include "LuaFunctions.h"
#include "Texture.h"

class BattleRenderer
{
public:
	Battle* mBattle;
	SDL_Surface* mBackgroundSprite;
	SDL_Surface* mPokemonFrontSprite;
	SDL_Surface* mPokemonBackSprite;

	BattleRenderer();
	BattleRenderer(Battle* battle);
	~BattleRenderer();

	void render(SDL_Surface* surface);
	void update(Uint32 deltatime);
	void handleEvent(SDL_Event e);
};

