#ifndef LOCATION_H
#define LOCATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>

#include "Image.h"
#include "Logger.h"
#include "../GlobalValues.h"
#include "LocationScreen.h"


/**
    Represents location (location data)
*/
class Location
{
    public:
        Location(char* loctionNumber);
        ~Location();

        int getWidth();
        int getHeight();
        int getCell(int x, int y);

    private:
        char locationNumber[5] = {0};

        int cellsInRowCount;
        int cellsInColCount;
        int **matrix;

};

#endif // LOCATION_H
