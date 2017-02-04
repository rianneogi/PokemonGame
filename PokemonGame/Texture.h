#pragma once

#include "GraphicsFunctions.h"

class Texture
{
public:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;

	Texture();
	Texture(std::string path);
	~Texture();

	void loadFromFile(std::string path);
	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL);
};

