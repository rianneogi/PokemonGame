#pragma once

#include "BattleRenderer.h"
#include "Vector2.h"

class WorldRenderer
{
public:
	World* mWorld;

	Texture* mTerrainTexture;

	WorldRenderer(World* w);
	~WorldRenderer();

	void render(SDL_Surface* surface);
	void update(Uint32 deltatime);
	void handleEvent(SDL_Event e);
};

