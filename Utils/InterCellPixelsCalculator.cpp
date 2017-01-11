#include "InterCellPixelsCalculator.h"

SDL_Point InterCellPixelsCalculator::getInterCellPixel(Direction direction, int currTime, int maxTime)
{
    const int paralelDistance = GlobalValues::CELL_WIDTH;
    const int diagonalDistanceX = 21;
    const int diagonalDistanceY = 19;


    float coef = 1.0;
    if(currTime != maxTime)
    {
        coef = currTime / float(maxTime);
    }

    SDL_Point result;
    result.x = 0;
    result.y = 0;

    switch (direction)
    {
        case LEFT:
            result.x = -1 * (coef * paralelDistance);
            result.y = 0;
            break;
        case RIGHT:
            result.x = coef * paralelDistance;
            result.y = 0;
            break;
        case RIGHT_UP:
            result.x = coef * diagonalDistanceX;
            result.y = -1 * (coef * diagonalDistanceY);
            break;
        case RIGHT_DOWN:
            result.x = coef * diagonalDistanceX;
            result.y = coef * diagonalDistanceY;
            break;
        case LEFT_DOWN:
            result.x = -1 * (coef * diagonalDistanceX);
            result.y = coef * diagonalDistanceY;
            break;
        case LEFT_UP:
            result.x = -1 * (coef * diagonalDistanceX);
            result.y = -1 * (coef * diagonalDistanceX);
            break;
    }

    return result;
}
