#ifndef MAINHERO_H
#define MAINHERO_H

#include "Creature.h"
#include "AbstractCreature.h"
#include "../../GlobalValues.h"
#include "AnimationData.h"


class MainHero : public Creature, public AbstractCreature
{
    public:
        MainHero(char *creatureNumber, SDL_Renderer *renderer);
        ~MainHero();

        int getImagePixellOffsetX();
        int getImagePixellOffsetY();
        int getNonBattleSpeed();


    private:
        int additionLife;
        int currLife;
        int additionPoints;

        int takePoints;
        int throwPoints;
        int changeWeaponPoints;
        int usePoints;
        int currPoints;

        // for drawing
        int imagePixellOffsetX;
        int imagePixellOffsetY;

        Direction direction;
};

#endif // MAINHERO_H
