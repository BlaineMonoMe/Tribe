#ifndef GLOBALVALUES_H
#define GLOBALVALUES_H

#include <SDL.h>


class GlobalValues
{
    public:
        static int SCREEN_WIDTH;
        static int SCREEN_HEIGHT;
        static char *PROJECT_NAME;
        static char *LOCATIONS_DIR;
        static char *LOCATION_IMG_FILENAME;
        static char *LOCATION_TXT_FILENAME;
        //TODO: add static SCREEN_RECT and init it

        static float CELL_WIDTH;
        static float CELL_HEIGHT;
        static int CELLS_PER_SCREEN_X;
        static int CELLS_PER_SCREEN_Y;
};

enum Direction {LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN, LEFT};

#endif // GLOBALVALUES_H
