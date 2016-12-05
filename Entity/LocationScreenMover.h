#ifndef LOCATIONSCREENMOVER_H
#define LOCATIONSCREENMOVER_H

#include "Timer.h"
#include "LocationScreen.h"


class LocationScreenMover : public Timer
{
    public:
        LocationScreenMover(LocationScreen *locationScreen, int interval);
        ~LocationScreenMover();

        void setDirection(Direction direction);
        void checkNeedToMove(int cursorX, int cursorY);

        void execute();

    private:
        LocationScreen *locationScreen;
        Direction direction;
};

#endif // LOCATIONSCREENMOVER_H
