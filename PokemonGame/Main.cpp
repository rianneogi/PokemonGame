#include "Timer.h"
#include "LuaFunctions.h"

SDL_Window* gWindow = NULL;
const unsigned int MAX_FPS = 30;

void handleEvent(SDL_Event e, Uint32 deltatime)
{

}

void update(Uint32 deltatime)
{

}

void render()
{

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

		// draw...
		render();

		// end the current frame (internally swaps the front and back buffers)
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

int main(int argc, char* args[])
{
	gWindow = SDL_CreateWindow("Pokemon", 0, 0, 800, 600, SDL_WINDOW_SHOWN);

	mainLoop();

	return 0;
}