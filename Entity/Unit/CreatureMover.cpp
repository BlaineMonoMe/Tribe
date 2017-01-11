#include "CreatureMover.h"

CreatureMover::CreatureMover(Creature *creature, int interval) : Timer(interval)
{
    init(creature);
}

void CreatureMover::init(Creature *creature)
{
    this->creature = creature;
}

void CreatureMover::updateCell(Cell *cell)
{
    creature->setXCell(cell->getX());
    creature->setYCell(cell->getY());
}
void CreatureMover::updateCurrPixellOffset(int x, int y)
{
    creature->setCurrPixellOffsetX(x);
    creature->setCurrPixellOffsetY(y);
}
void CreatureMover::updateDirection(Direction direction)
{
    creature->setDirection(direction);
    creature->setNewAnimationAndStart(GO, direction);
}
void CreatureMover::setStateStop()
{
    creature->setState(STAY);
    creature->setNewAnimationAndStart(STAY);
}

void CreatureMover::generatePath(Cell *currCell, Cell *destCell, LocationData *locationData)
{
    directionSequence = new DirectionsSequence();
    PathGenerator::generatePathAStar(currCell, destCell, locationData, directionSequence);
}

void CreatureMover::initMove(Cell *currCell)
{
    this->currCell = new Cell(currCell);
    currStepPerCellMove = 0;
    currDirection = directionSequence->takeDirection();
    if(currDirection != NONE)
    {
        updateDirection(currDirection);
    }
}


void CreatureMover::execute()
{
    if(currDirection == NONE)
    {
        setStateStop();
        stop();
        return;
    }

    ++currStepPerCellMove;

    SDL_Point currOffsetPoint = InterCellPixelsCalculator::getInterCellPixel(currDirection,
                                                                             currStepPerCellMove, stepsPerCellMoveCount);

    updateCurrPixellOffset(currOffsetPoint.x, currOffsetPoint.y);


    if(currStepPerCellMove >= stepsPerCellMoveCount)
    {
        currStepPerCellMove = 0;

        currCell = PathGenerator::getAdjacentCell(currCell, currDirection);
        updateCell(currCell);

        updateCurrPixellOffset(0, 0);

        currDirection = directionSequence->takeDirection();
        if(currDirection != NONE)
        {
            updateDirection(currDirection);
        }
        else
        {
            setStateStop();
            stop();
        }
    }
}

