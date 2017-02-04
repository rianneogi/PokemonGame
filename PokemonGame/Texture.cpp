#include "Texture.h"

Texture::Texture() : mTexture(NULL)
{
}

Texture::Texture(std::string path) : mTexture(NULL)
{
	loadFromFile(path);
}

Texture::~Texture()
{
	free();
}

bool Texture::loadFromFile(std::string path)
{
	//The final optimized image
	SDL_Surface* optimizedSurface = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Convert surface to screen format
		mTexture = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (mTexture == NULL)
		{
			printf("Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return true;
}

void Texture::free()
{
	SDL_FreeSurface(mTexture);
	mTexture = NULL;
}

void Texture::setColor(Uint8 red, Uint8 green, Uint8 blue)
{
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	//SDL_SetTextureBlendMode(mTexture, blending);
}

void Texture::setAlpha(Uint8 alpha)
{
	//SDL_SetTextureAlphaMod(mTexture, alpha);
}

void Texture::render(SDL_Surface* surface, int x, int y, SDL_Rect * clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, 900, 900 };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_BlitSurface(mTexture, clip, surface, &renderQuad);
	//SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}
