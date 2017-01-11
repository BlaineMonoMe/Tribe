#ifndef LOCATION_H
#define LOCATION_H


#include "LocationScreenMover.h"
#include "TimerHolder.h"
#include "LocationData.h"
#include "UnitsHolder.h"
#include "AbstractDataHolder.h"
#include "Cursor.h"

class Cursor;

class Location
{
    public:
        Location(char *number, AbstractDataHolder *abstractData, SDL_Renderer *renderer);
        ~Location();

        void draw();

        void doEnable();
        void doDiable();

        char* getLocationNumber();
        LocationScreen* getLocationScreen();
        LocationScreenMover* getLocationScreenMover();
        LocationData* getLocationData();
        UnitsHolder* getUnitsHolder();

        void updateLocationData();

        void addMainHero(Unit *mainHero);
        void addCursor(Cursor *cursor);

    private:
        char locationNumber[5] = {0};

        Cursor *cursor;

        LocationData *locationData;
        LocationScreen *locationScreen;
        LocationScreenMover *locationScreenMover;

        UnitsHolder *unitsHolder;

};

#endif // LOCATION_H
