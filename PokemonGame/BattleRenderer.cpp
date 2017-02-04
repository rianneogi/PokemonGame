#include "BattleRenderer.h"

BattleRenderer::BattleRenderer() : mBattle(NULL)
{
	printf("WARNING: default contructor for battle renderer called\n");
}

BattleRenderer::BattleRenderer(Battle* battle) : mBattle(battle)
{
	
}

BattleRenderer::~BattleRenderer()
{
}

void BattleRenderer::render(SDL_Window* window)
{
}

void BattleRenderer::update(Uint32 deltatime)
{
}

void BattleRenderer::handleEvent(SDL_Event e)
{
}
