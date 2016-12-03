#include "Animation.h"

Animation::Animation(AnimationData *animationData, int interval): Timer(interval)
{
    this->animationData = animationData;
    this->currentFrameNumber = 1;
    this->screenRect = new SDL_Rect();
}

Animation::~Animation()
{
    delete animationData;
    delete screenRect;
}

void Animation::setScreenRect(SDL_Rect *screenRect)
{
    this->screenRect->x = screenRect->x;
    this->screenRect->y = screenRect->y;
    this->screenRect->w = screenRect->w;
    this->screenRect->h = screenRect->h;
}

void Animation::reset()
{
    currentFrameNumber = 0;
}

void Animation::execute()
{
    draw();
    ++currentFrameNumber;
    if(currentFrameNumber >= animationData->getFramesCount() )
    {
        currentFrameNumber = 0;
    }
}

void Animation::draw()
{
    SDL_Rect *animationFrame = animationData->getFrameRect(currentFrameNumber);
    animationData->getSpritesheet()->draw(animationFrame, screenRect);
}
