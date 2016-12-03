#ifndef ANIMATIONDATA_H
#define ANIMATIONDATA_H

#include <SDL.h>
#include "Image.h"


class AnimationData
{
    public:
        AnimationData(char *filename, int framesCount, SDL_Renderer *renderer);
        ~AnimationData();
        void load(char *filename, int framesCount, SDL_Renderer *renderer);

        int getFramesCount();
        SDL_Rect* getFrameRect(int frameNumber);
        Image* getSpritesheet();

    private:
        Image *spritesheet;
        int framesCount;
};

#endif // ANIMATIONDATA_H
