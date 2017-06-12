#pragma once

#include "Timer.h"
#include <string>
#include <vector>

extern SDL_Window* gWindow;
extern SDL_Surface* gScreenSurface;
extern SDL_Renderer* gRenderer;

SDL_Rect createSDLRect(int x, int y, int w, int h);
SDL_Color createSDLColor(int r, int g, int b);
SDL_Color createSDLColor(int r, int g, int b, int a);
SDL_Surface* loadSurface(std::string path);