#pragma once

#include "LuaFunctions.h"
#include "GraphicsFunctions.h"

class BattleRenderer
{
public:
	Battle* mBattle;
	SDL_Surface* mImage;

	BattleRenderer();
	BattleRenderer(Battle* battle);
	~BattleRenderer();

	void render(SDL_Window* window);
	void update(Uint32 deltatime);
	void handleEvent(SDL_Event e);
};

