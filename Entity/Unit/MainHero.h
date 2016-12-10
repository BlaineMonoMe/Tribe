#ifndef MAINHERO_H
#define MAINHERO_H

#include "AbstractCreature.h"
#include "Unit.h"
#include "../../GlobalValues.h"


class MainHero : public AbstractCreature, public Unit
{
    public:
        MainHero();
        ~MainHero();

    void draw();

    private:
        int additionLife;
        int currLife;
        int additionPoints;

        int takePoints;
        int throwPoints;
        int changeWeaponPoints;
        int usePoints;
        int currPoints;

        Direction direction;
};

#endif // MAINHERO_H
