#include "AnimationData.h"

AnimationData::AnimationData(char *filename, int framesCount, SDL_Renderer *renderer)
{
    load(filename, framesCount, renderer);
}

void AnimationData::load(char *filename, int framesCount, SDL_Renderer *renderer)
{
    spritesheet = new Image(filename, renderer);
    this->framesCount = framesCount;
}

AnimationData::~AnimationData()
{
    if(spritesheet != NULL)
    {
        delete spritesheet;
    }
}

int AnimationData::getFramesCount()
{
    return framesCount;
}

Image* AnimationData::getSpritesheet()
{
    return spritesheet;
}

int AnimationData::getFrameWidth()
{
    return spritesheet->getWidth() / framesCount;
}

int AnimationData::getFrameHeight()
{
    return spritesheet->getHeight();
}

SDL_Rect* AnimationData::getFrameRect(int frameNumber)
{
    SDL_Rect *result = new SDL_Rect();
    result->x = spritesheet->getWidth() / framesCount * frameNumber;
    result->y = 0;
    result->w = spritesheet->getWidth() / framesCount;
    result->h = spritesheet->getHeight();

    return result;
}


