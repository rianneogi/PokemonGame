#pragma once

#include "Timer.h"
#include <string>

extern SDL_Window* gWindow;
extern SDL_Surface* gScreenSurface;

SDL_Surface* loadSurface(std::string path);
