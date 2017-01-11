#ifndef LOCATIONDATA_H
#define LOCATIONDATA_H

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
class LocationData
{
    public:
        LocationData(char* locationNumber);
        ~LocationData();

        int getWidth();
        int getHeight();
        int getCell(int x, int y);

        bool isWater(int x, int y);
        bool isOtherLocation(int x, int y);

        /// working with actual data (including enemies on location)
        bool isFreeToGo(int x, int y);
        void reinitActualData();
        void setEnemyOnCell(int x, int y);

    private:
        int cellsInRowCount;
        int cellsInColCount;
        int **matrix;

        /// same matrix with data + with enemies on location
        int **actualMatrix;

};

#endif // LOCATION_H
