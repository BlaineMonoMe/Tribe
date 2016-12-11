#ifndef INTERCELLPIXELSCALCULATOR_H
#define INTERCELLPIXELSCALCULATOR_H

#include <SDL.h>

#include "../GlobalValues.h"
#include "Logger.h"

class InterCellPixelsCalculator
{
    public:
        static SDL_Point getInterCellPixel(Direction direction, int currTime, int maxTime);
};

#endif // INTERCELLPIXELSCALCULATOR_H
