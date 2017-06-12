#pragma once

#include "LuaFunctions.h"
#include "Button.h"

class BattleRenderer
{
public:
	Battle* mBattle;

	Texture* mTilesetTexture;

	Texture* mPokemonMap;
	Texture* mPokemonSide;
	Texture* mPokemonSelect;

	Pokemon* mSelectedPokemon;

	Button* mSideButtons[2][6];

	Timer mTimer;
	int mSideFrame;

	BattleRenderer();
	BattleRenderer(Battle* battle);
	~BattleRenderer();

	void render(SDL_Surface* surface);
	void update(Uint32 deltatime);
	void handleEvent(SDL_Event e);
};

