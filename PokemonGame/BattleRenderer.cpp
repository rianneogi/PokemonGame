#include "BattleRenderer.h"

TTF_Font* gFont; 
TTF_Font* gFontSmall;

std::string gStatNames[STAT_NUM] = { "MaxHP", "ATK", "DEF", "SPATK", "SPDEF", "SPEED" };

BattleRenderer::BattleRenderer() : mBattle(NULL)
{
	printf("WARNING: default contructor for battle renderer called\n");
}

BattleRenderer::BattleRenderer(Battle* battle) : mBattle(battle)
{
	mDebug = 0;

	mTilesetTexture = new Texture("Graphics/Tilesets/Outside_A2.png");

	mPokemonMap = new Texture("Game Data/Sprites/HeartGoldSoulSilver/Kanto-Pokemon.png", 160, 176, 128);
	mPokemonSide = new Texture("Game Data/Sprites/RubySapphire/Gen.-1-Pokemon.png", 255, 200, 106);
	mPokemonSelect = new Texture("Game Data/front first frame.png");
	mPokemonSelect2 = new Texture("Game Data/front second frame.png");
	mTypeTexture = new Texture("Graphics/typesheet.png");
	mHPText = new Texture(gFontSmall, "HP: ", createSDLColor(255, 255, 255));

	mSkipTexture = new Texture(gFont, "End Turn", createSDLColor(255, 255, 255));
	printf("sk, %d %d\n", mSkipTexture->mWidth, mSkipTexture->mHeight);
	mSkipButton = new Button(mSkipTexture, 
		createSDLRect(425, 35 * 1 + 250 * 2, mSkipTexture->mWidth, mSkipTexture->mHeight),
		createSDLRect(0, 0, mSkipTexture->mWidth, mSkipTexture->mHeight));

	mSelectedPokemonTrainer = -1;
	mSelectedPokemonNum = -1;
	mSelectedAbility = -1;

	mTimer = Timer();
	mSelectFrame = 0;

	SDL_Rect r;
	std::vector<SDL_Rect> v;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Pokemon* p = mBattle->mTrainers[i]->mPokemon[j];

			v.clear();
			v.push_back(createSDLRect(296 + ((p->mSpecies) % 3) * 328, 24 + ((p->mSpecies) / 3) * 72, 32, 32));
			v.push_back(createSDLRect(296 + ((p->mSpecies) % 3) * 328, 32 + 24 + ((p->mSpecies) / 3) * 72, 32, 32));
			mSideButtons[i][j] = new Button(mPokemonSide, createSDLRect(425, 35 * j + 250 * i, 32, 32), v, 250);
		}
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Pokemon* p = mBattle->getPokemon(i, j);

			mPokemonNames[i][j] = new Texture(gFont, p->mName, createSDLColor(255, 255, 255));
			mPokemonLvlText[i][j] = new Texture(gFontSmall, "Lv." + std::to_string(p->mLevel), createSDLColor(255, 255, 255));
			for (int k = 0; k < STAT_NUM; k++)
			{
				mPokemonStatText[i][j][k] = new Texture();
			}
			for (int k = 0; k < 4; k++)
			{
				mMoveTextures[i][j][k] = new Texture(gFont, p->mAttacks[k].mName, createSDLColor(255, 255, 255));

				mMoveButtons[i][j][k] = new Button(mMoveTextures[i][j][k], 
					createSDLRect(100, 475 + 20 * k, mMoveTextures[i][j][k]->mWidth, mMoveTextures[i][j][k]->mHeight),
					createSDLRect(0, 0, mMoveTextures[i][j][k]->mWidth, mMoveTextures[i][j][k]->mHeight));
			}
		}
	}

	updateSprites();
}

BattleRenderer::~BattleRenderer()
{
	delete mTilesetTexture;
	delete mPokemonMap;
	delete mPokemonSelect;
	delete mPokemonSelect2;
	delete mPokemonSide;
	delete mHPText;
	delete mTypeTexture;

	delete mSkipTexture;
	delete mSkipButton;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			delete mSideButtons[i][j];
			delete mPokemonNames[i][j];
			delete mPokemonLvlText[i][j];

			for (int k = 0; k < STAT_NUM; k++)
			{
				delete mPokemonStatText[i][j][k];
			}
		}
	}
}

void BattleRenderer::updateSprites()
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			Pokemon* p = mBattle->getPokemon(i, j);

			std::string hp_string = "HP:" + std::to_string(int(p->mCurrentHP)) + "/" + std::to_string(int(p->mStats[STAT_HP]));
			mPokemonStatText[i][j][STAT_HP]->loadFromText(gFontSmall, hp_string, createSDLColor(255, 255, 255));

			for (int k = 1; k < STAT_NUM; k++)
			{
				std::string stat_string = gStatNames[k];
				for (int x = 0; x < 6 - gStatNames[k].length(); x++)
				{
					stat_string += " ";
				}
				stat_string += ": " + std::to_string(int(p->mStats[k]));
				mPokemonStatText[i][j][k]->loadFromText(gFontSmall, stat_string, createSDLColor(255, 255, 255));
			}
		}
	}
}

void BattleRenderer::render(SDL_Surface* surface)
{
	printf("stack size attacks: %d\n", lua_gettop(LuaAttacks));
	printf("stack size pokemon: %d\n", lua_gettop(LuaPokemon));
	mSkipButton->render();

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

			if (p->mSpecies >= 25)
			{
				r.x = ((p->mSpecies + 2) % 15) * 65;
				r.y = ((p->mSpecies + 2) / 15) * 129;
			}
			else if (p->mSpecies >= 3)
			{
				r.x = ((p->mSpecies + 1) % 15) * 65;
				r.y = ((p->mSpecies + 1) / 15) * 129;
			}
			else
			{
				r.x = ((p->mSpecies) % 15) * 65;
				r.y = ((p->mSpecies) / 15) * 129;
			}
			
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

			//Picture
			mSideButtons[i][j]->render();
			mPokemonNames[i][j]->render(460, 35 * j + 250 * i);
			
			//HP
			mPokemonStatText[i][j][STAT_HP]->render(515, 35 * j + 250 * i + 15);

			//Lvl
			mPokemonLvlText[i][j]->render(460, 35 * j + 250 * i + 15);
		}
	}

	if (mSelectedPokemonNum != -1)
	{
		Pokemon* p = mBattle->getPokemon(mSelectedPokemonTrainer, mSelectedPokemonNum);

		//Picture
		r.x = ((p->mSpecies) % 25) * 80;
		r.y = ((p->mSpecies) / 25) * 80;
		r.w = 80;
		r.h = 80;
		if (mSelectFrame == 1)
		{
			mPokemonSelect2->render(20, 425, &r);
		}
		else
		{
			mPokemonSelect->render(20, 425, &r);
		}
		
		//Name and HP
		mPokemonNames[mSelectedPokemonTrainer][mSelectedPokemonNum]->render(100, 425);
		//mHPText->render(100, 442);
		mPokemonStatText[mSelectedPokemonTrainer][mSelectedPokemonNum][STAT_HP]->render(100, 442);

		//Types
		r.x = 32 * p->mPrimaryType;
		r.y = 0;
		r.w = 32;
		r.h = 14;
		mTypeTexture->render(200, 442, &r);

		if (p->mSecondaryType != -1)
		{
			r.x = 32 * p->mSecondaryType;
			r.y = 0;
			r.w = 32;
			r.h = 14;
			mTypeTexture->render(233, 442, &r);
		}

		//Other Stats
		for (int i = 1; i < STAT_NUM; i++)
		{
			mPokemonStatText[mSelectedPokemonTrainer][mSelectedPokemonNum][i]->render(200, 439 + 20*i);
		}

		//Abilities
		for (int i = 0; i < 4; i++)
		{
			mMoveButtons[mSelectedPokemonTrainer][mSelectedPokemonNum][i]->render();
		}
	}
}

void BattleRenderer::update(Uint32 deltatime)
{
	if (mTimer.getElaspedTime() >= 250 && mSelectFrame < 2)
	{
		mSelectFrame++;
		mTimer.restart();
	}
}

void BattleRenderer::handleEvent(SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		//End Turn
		if (mSkipButton->checkCollision(e.button.x, e.button.y))
		{
			mBattle->endTurn();
			updateSprites();
		}

		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				if (mSideButtons[i][j]->checkCollision(e.button.x, e.button.y)) //Select pokemon from side menu
				{
					mSelectedPokemonTrainer = i;
					mSelectedPokemonNum = j;
					mSelectFrame = 0;
					mSelectedAbility = -1;
					mTimer.restart();
				}
			}
		}

		if (e.button.x >= 0 && e.button.x <= 32 * 13 && e.button.y >= 0 && e.button.y <= 32 * 13)
		{
			int tx = e.button.x / 32;
			int ty = e.button.y / 32;

			if (mSelectedAbility != -1) //Attack
			{
				if (mBattle->attemptAttack(mSelectedPokemonTrainer, mSelectedPokemonNum, mSelectedAbility, tx, ty))
				{
					printf("%d %d attacked %d %d with %d!\n", mSelectedPokemonTrainer, mSelectedPokemonNum, tx, ty, mSelectedAbility);
					updateSprites();
				}
				else
					printf("attacked failed\n");
				mSelectedAbility = -1;
			}
			else
			{
				int flag = 0;
				for (int i = 0; i < 2; i++)
				{
					for (int j = 0; j < 6; j++)
					{
						if (mBattle->getPokemon(i, j)->mX == tx && mBattle->getPokemon(i, j)->mY == ty) //Select pokemon from board
						{
							mSelectedPokemonNum = j;
							mSelectedPokemonTrainer = i;
							mSelectFrame = 0;
							mSelectedAbility = -1;
							mTimer.restart();
							flag = 1;
						}
					}
				}

				if (flag == 0 && mSelectedPokemonNum != -1) //Move
				{
					if(mBattle->attemptMove(mSelectedPokemonTrainer, mSelectedPokemonNum, tx, ty))
						updateSprites();
				}
			}
		}

		if (mSelectedPokemonNum != -1)
		{
			for (int i = 0; i < 4; i++)
			{
				//Select Attack
				if (mMoveButtons[mSelectedPokemonTrainer][mSelectedPokemonNum][i]->checkCollision(e.button.x, e.button.y))
				{
					mSelectedAbility = i;

					for (int j = 0; j < 13; j++)
					{
						for (int k = 0; k < 13; k++)
						{
							printf("check target %d %d %d %d %d\n", mSelectedPokemonTrainer, mSelectedPokemonNum, i, j, k);
							if (mBattle->checkAttackTarget(mSelectedPokemonTrainer, mSelectedPokemonNum, i, j, k))
							{
								mTargetMap[j][k] = 1;
							}
							else
							{
								mTargetMap[j][k] = 0;
							}
						}
					}
					//mDebug = 1;
				}
			}
		}
	}
}
