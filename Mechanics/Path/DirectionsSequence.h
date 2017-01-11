#ifndef DIRECTIONSSEQUENCE_H
#define DIRECTIONSSEQUENCE_H

#include <vector>
#include <stdlib.h>

#include "../../GlobalValues.h"
#include "Path.h"
#include "Cell.h"

// TO REMOVE!!

class DirectionsSequence
{
    public:
        DirectionsSequence();
        ~DirectionsSequence();

        void addDirection(Direction direction);
        Direction takeDirection();
        bool isEmpty();

    private:
        std::vector<Direction> *directionSequence = NULL;
};

#endif // DIRECTIONSSEQUENCE_H
