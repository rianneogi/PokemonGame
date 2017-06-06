#include "Texture.h"

Texture::Texture() : mTexture(NULL), mWidth(900), mHeight(900)
{
}

Texture::Texture(std::string path) : mTexture(NULL), mWidth(900), mHeight(900)
{
	loadFromFile(path);
}

Texture::Texture(std::string path, Uint32 r, Uint32 g, Uint32 b)
{
	loadFromFile(path, r, g, b);
}

Texture::~Texture()
{
	free();
}

void Texture::loadFromFile(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

void Texture::loadFromFile(std::string path, Uint32 r, Uint32 g, Uint32 b)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, r, g, b));

		//Create texture from surface pixels
		mTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (mTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of the good ol' loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}

void Texture::free()
{
	SDL_DestroyTexture(mTexture);
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

void Texture::render(int x, int y, SDL_Rect * clip)
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//SDL_BlitSurface(mTexture, clip, surface, &renderQuad);
	SDL_RenderCopy(gRenderer, mTexture, clip, &renderQuad);
}
