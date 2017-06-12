#include "Button.h"

Button::Button(Texture* tex, SDL_Rect r, SDL_Rect clip) : mRect(r), mTexture(tex), mCurrentFrame(0)
{
	mClip.push_back(clip);
}

Button::Button(Texture* tex, SDL_Rect r, std::vector<SDL_Rect> clip, int frame_interval) :
	mRect(r), mClip(clip), mTexture(tex), mCurrentFrame(0), mFrameInterval(frame_interval)
{
}

Button::~Button()
{
}

bool Button::checkCollision(int mouseX, int mouseY)
{
	if (mouseX >= mRect.x && mouseX <= mRect.x + mRect.w)
	{
		if (mouseY >= mRect.y && mouseY <= mRect.y + mRect.h)
		{
			return true;
		}
	}
	return false;
}

void Button::render()
{
	if (mTimer.getElaspedTime() >= mFrameInterval)
	{
		mCurrentFrame = (mCurrentFrame + 1) % mClip.size();
		mTimer.restart();
	}

	mTexture->render(mRect.x, mRect.y, &mClip[mCurrentFrame]);
}
