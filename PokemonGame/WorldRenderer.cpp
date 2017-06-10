#include "WorldRenderer.h"

WorldRenderer::WorldRenderer(World* w) : mWorld(w)
{
	mTerrainTexture = new Texture("Graphics\\Tilesets\\Outside_A2.png");
}

WorldRenderer::~WorldRenderer()
{
}

float getRand() {
	int x = rand();
	float ret = (float)(x % 100);
	return ret;
}

void WorldRenderer::render(SDL_Surface* surface)
{
	SDL_Rect r;
    r.x = 32;
    r.y = 32;
    r.w = 32;
    r.h = 32;


    
    const int SEED = 3;
    const int ROWS = 10;
    const int COLS = 10;
    const int CELL_SIZE = 10;


    srand(SEED);

    const int PIXEL_ROWS = ROWS * CELL_SIZE;
    const int PIXEL_COLS = COLS * CELL_SIZE;

    Vector2 lattice[ROWS][COLS];
    float radius;
    float angle;

    float pixels[PIXEL_ROWS][PIXEL_COLS];

    Vector2 tempVector;
    for (int latticeRow = 0; latticeRow < ROWS; latticeRow++) {
        for (int latticeCol = 0; latticeCol < COLS; latticeCol++) {
			tempVector.x = getRand();
			tempVector.y = getRand();
            tempVector.normalize();
            lattice[latticeRow][latticeCol] = tempVector;
        }
    }


	int lx;
	int ly;
    for (int pixelRow = 0; pixelRow < PIXEL_ROWS; pixelRow++) {
        for (int pixelCol = 0; pixelCol < PIXEL_COLS; pixelCol++) {
            lx = pixelRow / ROWS;
            ly = pixelCol / COLS;
            // pixels[pixelRow][pixelCol]
        }
    }

}

void WorldRenderer::update(Uint32 deltatime)
{
}

void WorldRenderer::handleEvent(SDL_Event e)
{
}
