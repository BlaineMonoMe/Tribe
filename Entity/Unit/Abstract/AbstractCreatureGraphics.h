#ifndef ABSTRACTCREATUREGRAPHICS_H
#define ABSTRACTCREATUREGRAPHICS_H

#include <SDL.h>
#include <cstring>

#include "Animation.h"
#include "AnimationData.h"
#include "Logger.h"
#include "../../../GlobalValues.h"
#include "FileReader.h"
#include "AbstractCreature.h"



class AbstractCreatureGraphics
{
    public:
        AbstractCreatureGraphics();
        ~AbstractCreatureGraphics();

        void loadGraphics(char* creatureNumber, SDL_Renderer *renderer);

        AnimationData* getAnimationData(State state, Direction direction);

        int getStaticOffsetX();
        int getStaticOffsetY();
        int getAnimationInterval();


    protected:
        int staticOffsetX;
        int staticOffsetY;
        int animationInterval;

    private:

        AnimationData *goRightUp = NULL;
        AnimationData *goRight = NULL;
        AnimationData *goRightDown = NULL;
        AnimationData *goLeftDown = NULL;
        AnimationData *goLeft = NULL;
        AnimationData *goLeftUp = NULL;

        AnimationData *standRightUp = NULL;
        AnimationData *standRight = NULL;
        AnimationData *standRightDown = NULL;
        AnimationData *standLeftDown = NULL;
        AnimationData *standLeft = NULL;
        AnimationData *standLeftUp = NULL;
};

#endif // ABSTRACTCREATUREGRAPHICS_H
