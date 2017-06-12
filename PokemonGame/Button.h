#pragma once

#include "Texture.h"

class Button
{
public:
	SDL_Rect mRect;
	std::vector<SDL_Rect> mClip;
	Texture* mTexture;

	Timer mTimer;
	int mCurrentFrame;
	int mFrameInterval;

	Button(Texture* tex, SDL_Rect r, SDL_Rect clip);
	Button(Texture* tex, SDL_Rect r, std::vector<SDL_Rect> clip, int frame_interval);
	~Button();

	bool checkCollision(int mouseX, int mouseY);
	void render();
};

