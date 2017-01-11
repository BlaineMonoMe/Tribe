#include "DirectionsSequence.h"

DirectionsSequence::DirectionsSequence()
{
    directionSequence = new std::vector<Direction>();
}


DirectionsSequence::~DirectionsSequence()
{
    if(directionSequence != NULL)
    {
        delete directionSequence;
    }
}

void DirectionsSequence::addDirection(Direction direction)
{
    directionSequence->push_back(direction);
}

Direction DirectionsSequence::takeDirection()
{
    if(directionSequence->empty() == false)
    {
        Direction toReturn = directionSequence->at(0);
        directionSequence->erase(directionSequence->begin());
        return toReturn;
    }
}

bool DirectionsSequence::isEmpty()
{
    directionSequence->empty();
}
