#ifndef COORDSTRANFORMER_H
#define COORDSTRANFORMER_H

#include <SDL.h>
#include <math.h>

#include "Logger.h"
#include "../GlobalValues.h"



class CoordsTranformer
{
    public:
        // return cell to wich belongs pixel
        static SDL_Point pixelsToCells(int pixelX, int pixelY);

        // return cords of the center of the cell
        static SDL_Point cellsToPixels(int cellX, int cellY);

    private:
        static double getDistBetwPoints(int x1, int y1, int x2, int y2);
};

#endif // COORDSTRANFORMER_H
