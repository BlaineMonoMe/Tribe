#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H

#include <stdlib.h>
#include <SDL.h>

#include "Animation.h"
#include "AnimationData.h"
#include "Image.h"
#include "../../../GlobalValues.h"
#include "FileReader.h"
#include "Logger.h"

enum State {STAY, GO, ATTACK, GET_DAMAGE, DIE};

class AbstractCreature
{
    public:
        int getMaxLife();
        int getResistance();
        int getStrength();
        int getNonBattleSpeed();
        int getPointsPerTurn();
        int getMovePoints();
        int getImagePixellOffsetX();
        int getImagePixellOffsetY();

    protected:
        int maxLife;
        int resistance;
        int strength;
        int nonBattleSpeed;
        int pointsPerTurn;
        int movePoints;

        // for drawing
        int imagePixellOffsetX;
        int imagePixellOffsetY;

};

#endif // ABSTRACTCREATURE_H
