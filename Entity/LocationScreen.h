#ifndef LOCATIONSCREEN_H
#define LOCATIONSCREEN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL.h>
#include "../GlobalValues.h"
#include "Image.h"



/**
    Represent location screen - drawing the location
*/
class LocationScreen
{
    public:
        LocationScreen(char* locationNumber, SDL_Renderer *renderer);
        ~LocationScreen();

        void draw();
        void move(Direction direction, int delta);

        int getXOffset();
        int getYOffset();

        Image* getObstaclesImage();

    private:
        int xOffset = 0;
        int yOffset = 0;

        SDL_Rect *screenRect;
        SDL_Rect *locationRect;

        Image *image = NULL;
        Image *obstaclesImage = NULL;

};

#endif // LOCATIONSCREEN_H
