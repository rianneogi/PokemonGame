#include "BattleRenderer.h"

BattleRenderer* mRenderer = NULL;
const unsigned int MAX_FPS = 30;

void handleEvent(SDL_Event e, Uint32 deltatime)
{
	mRenderer->handleEvent(e);
}

void update(Uint32 deltatime)
{
	mRenderer->update(deltatime);
}

void render()
{
	mRenderer->render(gScreenSurface);
}

void mainLoop()
{
	bool running = true;
	SDL_Event e;

	Timer timer;
	unsigned int frameCount = 0;
	while (running)
	{
		Uint32 deltaTime = timer.getElaspedTime();

		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
			{
				// end the program
				running = false;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}
			//else if (e.type == SDL_WINDOWEVENT)
			//{
			//	// adjust the viewport when the window is resized
			//	SCREEN_WIDTH = event.size.width;
			//	SCREEN_HEIGHT = event.size.height;
			//	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
			//}
			handleEvent(e, deltaTime);
		}
		update(deltaTime);
		//gTimer.restart();

		//Clear screen
		//SDL_RenderClear(gRenderer);

		//Render texture to screen
		//render();
		//SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

		//Update screen
		//SDL_RenderPresent(gRenderer);

		//// draw...
		render();

		//// end the current frame (internally swaps the front and back buffers)
		SDL_UpdateWindowSurface(gWindow);
	
		//SDL_GL_SwapWindow(gWindow);

		frameCount++;
		Uint32 t = timer.getElaspedTime();
		if (t >= 1000)
		{
			timer.restart();
			printf("FPS: %d\n", frameCount);
			frameCount = 0;
		}
		while (frameCount*(1000.f / MAX_FPS) > t)
		{
			t = timer.getElaspedTime();
		}
	}
}

void init()
{
	gWindow = SDL_CreateWindow("Pokemon", 0, 0, 800, 600, SDL_WINDOW_SHOWN);
	gScreenSurface = SDL_GetWindowSurface(gWindow);

	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags))
	{
		printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}
	else
	{
		//Initialize renderer color
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	}
}

void cleanup()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gRenderer = NULL;
	gWindow = NULL;
}

int main(int argc, char* args[])
{
	init();

	Battle* b = new Battle();
	mRenderer = new BattleRenderer(b);

	mainLoop();

	cleanup();
	delete b;

	return 0;
}