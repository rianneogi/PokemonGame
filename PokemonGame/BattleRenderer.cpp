#include "BattleRenderer.h"

BattleRenderer::BattleRenderer() : mBattle(NULL)
{
	printf("WARNING: default contructor for battle renderer called\n");
}

BattleRenderer::BattleRenderer(Battle* battle) : mBattle(battle)
{
	mTilesetTexture = new Texture("Graphics/Tilesets/Outside_A2.png");

	mPokemonMap = new Texture("Game Data/Sprites/HeartGoldSoulSilver/Kanto-Pokemon.png");
	mPokemonSide = new Texture("Game Data/Sprites/RubySapphire/Gen.-1-Pokemon.png", 255, 200, 106);
	mPokemonSelect = new Texture("Game Data/front first frame.png");

	mSelectedPokemon = NULL;

	mTimer = Timer();
	mSideFrame = 0;

	SDL_Rect r;
	std::vector<SDL_Rect> v;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Pokemon* p = mBattle->mTrainers[i]->mPokemon[j];
			r = createSDLRect(425, 35 * j + 250 * i, 32, 32);

			v.clear();
			v.push_back(createSDLRect(296 + ((p->mSpecies - 1) % 3) * 328, 24 + ((p->mSpecies - 1) / 3) * 72, 32, 32));
			v.push_back(createSDLRect(296 + ((p->mSpecies - 1) % 3) * 328, 32 + 24 + ((p->mSpecies - 1) / 3) * 72, 32, 32));
			mSideButtons[i][j] = new Button(mPokemonSide, r, v, 250);
		}
	}
}

BattleRenderer::~BattleRenderer()
{
	delete mTilesetTexture;
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
			r.w = 32;
			r.h = 32;

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

			mPokemonMap->render(32 * p->mX, 32 * p->mY, &r);

			/*r.x = 296 + ((p->mSpecies - 1) % 3) * 328;
			r.y = 24 + ((p->mSpecies - 1) / 3) * 72;
			if (mSideFrame)
			{
				r.y += 32;
			}
			r.w = 32;
			r.h = 32;
			mPokemonSide->render(425, 35*j + 250*i, &r);*/
			mSideButtons[i][j]->render();
		}
	}

	if (mSelectedPokemon)
	{
		r.x = ((mSelectedPokemon->mSpecies - 1) % 25) * 80;
		r.y = ((mSelectedPokemon->mSpecies - 1) / 25) * 80;
		r.w = 80;
		r.h = 80;
		mPokemonSelect->render(20, 425, &r);
	}
}

void BattleRenderer::update(Uint32 deltatime)
{
	if (mTimer.getElaspedTime() >= 250)
	{
		mSideFrame = (mSideFrame + 1) % 2;
		mTimer.restart();
	}
}

void BattleRenderer::handleEvent(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (mSideButtons[i][j]->checkCollision(e.button.x, e.button.y))
				{
					mSelectedPokemon = mBattle->getPokemon(i, j);
				}
			}
		}
	}
}
