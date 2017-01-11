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
        static char *ITEMS_DIR_FILE;
        static char *OBSTACLES_DIR_FILE;
        static char *ENEMIES_DIR_FILE;
        static char *LOCATION_IMG_FILENAME;
        static char *LOCATION_IMG_OBSTACLE_FILENAME;
        static char *LOCATION_TXT_FILENAME;
        static char *ABSTRACT_WEAPON_DIR_FILE;
        static char *ABSTRACT_ENEMY_DIR_FILE;
        static char *IMAGES_CREATURES_DIR;
        static char *INFO_FILE_TXT;
        //TODO: add static SCREEN_RECT and init it

        static float CELL_WIDTH;
        static float CELL_HEIGHT;
        static int CELLS_PER_SCREEN_X;
        static int CELLS_PER_SCREEN_Y;

        static int SCREEN_EDGE_WIDTH;
        static int SCREEN_MOVE_SPEED;
};

enum Direction {LEFT_UP, UP, RIGHT_UP, RIGHT, RIGHT_DOWN, DOWN, LEFT_DOWN, LEFT, NONE};

enum GameState {WALK, BATTLE};

#endif // GLOBALVALUES_H
