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
	mMenuSprite = new Texture("Game Data/Sprites/RubySapphire/Fonts-and-Menus.png", 255, 255, 255);
	mTilesetTexture = new Texture("Graphics/Tilesets/Outside_A2.png");
	mPokemonOverworld = new Texture("Game Data/Sprites/HeartGoldSoulSilver/Kanto-Pokemon.png");
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
	r.x = 0;
	r.y = 0;
	r.w = 32;
	r.h = 32;
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			mTilesetTexture->render(i * 32, j * 32, &r);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < mBattle->mTrainers[i]->mPokemon.size(); j++)
		{
			Pokemon* p = mBattle->mTrainers[i]->mPokemon[j];

			r.x = ((p->mSpecies - 1) % 15) * 65;
			r.y = ((p->mSpecies - 1) / 15) * 129;

			if (p->mFacing == FACING_LEFT)
			{
				r.x += 32;
			}
			if (p->mFacing == FACING_DOWN)
			{
				r.y += 64;
			}
			if (p->mFacing == FACING_RIGHT)
			{
				r.x += 32;
				r.y += 64;
			}

			mPokemonOverworld->render(32 * p->mX, 32 * p->mY, &r);
		}
	}
}

void BattleRenderer::update(Uint32 deltatime)
{
}

void BattleRenderer::handleEvent(SDL_Event e)
{
}
