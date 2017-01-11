#ifndef CREATURE_H
#define CREATURE_H

#include <stdlib.h>
#include <string>
#include <SDL.h>

#include "Unit.h"
#include "AbstractCreature.h"
#include "../../GlobalValues.h"
#include "Cell.h"
#include "DirectionsSequence.h"
#include "PathGenerator.h"
#include "LocationData.h"
#include "CreatureMover.h"
#include "Image.h"
#include "CoordsTranformer.h"
#include "AnimationData.h"
#include "Animation.h"
#include "AbstractCreatureGraphics.h"
#include "TimerHolder.h"


class CreatureMover;

class Creature : public Unit, public AbstractCreatureGraphics
{
    public:
        Creature(char *creatureNumber, SDL_Renderer *renderer);
        Creature();
        ~Creature();

        void init(char *creatureNumber, SDL_Renderer *renderer);

        void draw(int xPixellScreenOffset, int yPixellScreenOffset);

        State getState();
        Direction getDirection();
        void setState(State state);
        void setDirection (Direction direction);

        int getCurrPixellOffsetX();
        int getCurrPixellOffsetY();
        void setCurrPixellOffsetX(int x);
        void setCurrPixellOffsetY(int y);


        // Main Hero and Enemy gets this value from different places
        virtual int getImagePixellOffsetX() = 0;
        virtual int getImagePixellOffsetY() = 0;
        virtual int getNonBattleSpeed() = 0;


        // this function will be call to activate CreatureMover - Creature will go...
        void setDetstinationAndGo(int destX, int destY, LocationData *locationData);

        void setNewAnimationAndStart(State state, Direction direction);
        void setNewAnimationAndStart(State states);

    protected:
        char creatureNumber[5] = {0};

        State state;
        Direction direction;

        CreatureMover *creatureMover = NULL;

        /// this data is needed to draw creature in certain place (betw cells)
        int currPixellOffsetX = 0;
        int currPixellOffsetY = 0;

        Animation *currAnimation = NULL;
};

#endif // CREATURE_H
