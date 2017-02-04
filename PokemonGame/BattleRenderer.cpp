#include "BattleRenderer.h"

BattleRenderer::BattleRenderer() : mBattle(NULL)
{
	printf("WARNING: default contructor for battle renderer called\n");
}

BattleRenderer::BattleRenderer(Battle* battle) : mBattle(battle)
{
	mBackgroundSprite = loadSurface("Game Data/Sprites/Platinum/Battle-Backgrounds.png");
	//mPokemonFrontSprite = loadSurface("Game Data/Sprites/Emerald/Generation-1-Pokemon.png");
	mPokemonFrontSprite = loadSurface("Game Data/Sprites/HeartGoldSoulSilver/Pokemon-Fronts-(Male).png");
	mPokemonBackSprite = loadSurface("Game Data/Sprites/Emerald/Generation-1-Pokemon.png");
}

BattleRenderer::~BattleRenderer()
{
}

void BattleRenderer::render(SDL_Surface* surface)
{
	SDL_Rect r;
	r.x = 1;
	r.y = 1;
	r.w = 256;
	r.h = 144;
	SDL_BlitSurface(mBackgroundSprite, &r, surface, NULL);
	//mBackgroundSprite.render(surface, 0, 0, &r);

	SDL_Rect r2;
	r2.x = 6;
	r2.y = 6;
	r2.w = 62;
	r2.h = 62;

	SDL_Rect r3;
	r3.x = 160;
	r3.y = 30;
	r2.w = 62;
	r2.h = 62;
	SDL_BlitSurface(mPokemonFrontSprite, &r2, surface, &r3);
	//mPokemonFrontSprite.render(surface, 160, 30, &r2);
}

void BattleRenderer::update(Uint32 deltatime)
{
}

void BattleRenderer::handleEvent(SDL_Event e)
{
}
