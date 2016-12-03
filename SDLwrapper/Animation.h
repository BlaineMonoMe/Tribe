#ifndef ANIMATION_H
#define ANIMATION_H

#include <SDL.h>
#include "AnimationData.h"
#include "Timer.h"


class Animation : public Timer
{
    public:
        Animation(AnimationData *animationData, int interval);
        ~Animation();

        void execute();
        void reset();

        void setScreenRect(SDL_Rect *screenRect);
        void draw();

    private:
        AnimationData *animationData;
        int currentFrameNumber;
        SDL_Rect *screenRect;
};

#endif // ANIMATION_H
