#ifndef CREATUREMOVER_H
#define CREATUREMOVER_H

#include <SDL.h>
// TODO - remove include sdl

#include "Creature.h"
#include "Timer.h"
#include "../../GlobalValues.h"
#include "DirectionsSequence.h"
#include "LocationData.h"
#include "Cell.h"
#include "PathGenerator.h"
#include "InterCellPixelsCalculator.h"

class Creature;

class CreatureMover : public Timer
{
    public:
        CreatureMover(Creature *creature, int interval);
        void init(Creature *creature);

        void generatePath(Cell *curr, Cell *dest, LocationData *locationData);
        void initMove(Cell *currCell);

        void execute();

    private:
        const int stepsPerCellMoveCount = 7;
        int currStepPerCellMove = 0;

        Creature *creature;
        DirectionsSequence *directionSequence;

        Direction currDirection;
        Cell *currCell;

        // this methods do update data in Creature object
        void updateCell(Cell *cell);
        void updateCurrPixellOffset(int x, int y);
        void updateDirection(Direction direction);
        void setStateStop();
};

#endif // CREATUREMOVER_H
