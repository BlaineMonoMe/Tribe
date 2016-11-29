#ifndef LOCATION_H
#define LOCATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Image.h"
#include "../GlobalValues.h"


class Location
{
    public:
        Location();
        Location(char* loctionNumber, SDL_Surface *screen);
        ~Location();

        void load(char* locationNumber, SDL_Surface *screen);
        bool isLoaded();
        void draw(int xOffset, int yOffset);

    private:
        Image *image = NULL;

};

#endif // LOCATION_H
