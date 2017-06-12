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
	Texture(std::string path, Uint32 r, Uint32 g, Uint32 b);
	Texture(TTF_Font* font, std::string path, SDL_Color color);
	~Texture();

	void loadFromFile(std::string path);
	void loadFromFile(std::string path, Uint32 r, Uint32 g, Uint32 b);
	bool loadFromText(TTF_Font* font, std::string path, SDL_Color color);
	void free();

	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setBlendMode(SDL_BlendMode blending);
	void setAlpha(Uint8 alpha);
	void render(int x, int y, SDL_Rect* clip = NULL);
};

