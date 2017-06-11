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
    r.x = 32;
    r.y = 32;
    r.w = 32;
    r.h = 32;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
			mTerrainTexture->render(32 * i, 32 * j, &r);
        }
    }
	getchar();

}

double lerp(double a, double b, double t) {
    return a + (b - a) * t;
}

float WorldRenderer::getRand() {
    int x = rand();
    float ret = (float) (x % 100);
    return ret;
}

void WorldRenderer::update(Uint32 deltatime)
{
}

void WorldRenderer::handleEvent(SDL_Event e)
{
}


