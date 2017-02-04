#pragma once

#include "Timer.h"
#include <string>

extern SDL_Window* gWindow;
extern SDL_Surface* gScreenSurface;
extern SDL_Renderer* gRenderer;

SDL_Surface* loadSurface(std::string path);
