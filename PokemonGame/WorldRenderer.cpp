#include "WorldRenderer.h"

WorldRenderer::WorldRenderer(World* w) : mWorld(w)
{
	mTerrainTexture = new Texture("Graphics\\Tilesets\\Outside_A2.png");
}

WorldRenderer::~WorldRenderer()
{
}

void WorldRenderer::render(SDL_Surface* surface)
{
	SDL_Rect r;
	for (int i = 0; i < 64; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			r.x = 32*i;
			r.y = 32*j;
			r.w = 32;
			r.h = 32;
			mTerrainTexture->render(0, 0, &r);
		}
	}
	
}

void WorldRenderer::update(Uint32 deltatime)
{
}

void WorldRenderer::handleEvent(SDL_Event e)
{
}
