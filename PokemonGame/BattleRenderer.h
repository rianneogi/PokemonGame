#pragma once

#include "LuaFunctions.h"
#include "Button.h"

extern TTF_Font* gFont;
extern TTF_Font* gFontSmall;

extern std::string gStatNames[STAT_NUM];

class BattleRenderer
{
public:
	Battle* mBattle;

	Texture* mTilesetTexture;

	Texture* mPokemonMap;
	Texture* mPokemonSide;
	Texture* mPokemonSelect;
	Texture* mPokemonSelect2;
	Texture* mTypeTexture;

	int mSelectedPokemonNum;
	int mSelectedPokemonTrainer;

	Button* mSideButtons[2][6];
	Texture* mPokemonNames[2][6];
	Texture* mPokemonStatText[2][6][STAT_NUM];
	Texture* mPokemonLvlText[2][6];
	Texture* mHPText;

	Timer mTimer;
	int mSelectFrame;

	BattleRenderer();
	BattleRenderer(Battle* battle);
	~BattleRenderer();

	void render(SDL_Surface* surface);
	void update(Uint32 deltatime);
	void handleEvent(SDL_Event e);
};

