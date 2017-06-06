#include "BattleRenderer.h"

BattleRenderer::BattleRenderer() : mBattle(NULL)
{
	printf("WARNING: default contructor for battle renderer called\n");
}

BattleRenderer::BattleRenderer(Battle* battle) : mBattle(battle)
{
	mBackgroundSprite = new Texture("Game Data/Sprites/Platinum/Battle-Backgrounds.png");
	mPokemonFrontSprite = new Texture("Game Data/Sprites/RubySapphire/Gen.-1-Pokemon.png", 255, 200, 106);
	mPokemonBackSprite = new Texture("Game Data/Sprites/RubySapphire/Gen.-1-Pokemon.png", 255, 200, 106);
}

BattleRenderer::~BattleRenderer()
{
	delete mBackgroundSprite;
	delete mPokemonBackSprite;
	delete mPokemonFrontSprite;
}

void BattleRenderer::render(SDL_Surface* surface)
{
	SDL_Rect r;
	r.x = 1;
	r.y = 1;
	r.w = 256;
	r.h = 144;
	mBackgroundSprite->render(0, 0, &r);

	SDL_Rect r2;
	r2.x = 8;
	r2.y = 24;
	r2.w = 62;
	r2.h = 62;

	SDL_Rect r3;
	r3.x = 152;
	r3.y = 24;
	r3.w = 62;
	r3.h = 62;
	mPokemonFrontSprite->render(160, 40, &r2);

	mPokemonBackSprite->render(40, 82, &r3);
}

void BattleRenderer::update(Uint32 deltatime)
{
}

void BattleRenderer::handleEvent(SDL_Event e)
{
}
