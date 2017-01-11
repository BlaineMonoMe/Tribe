#ifndef CURSOR_H
#define CURSOR_H

#include <SDL.h>

#include "Image.h"
#include "CoordsTranformer.h"
#include "../GlobalValues.h"
#include "Logger.h"
#include "Location.h"
#include "Unit.h"

class Location;

class Cursor : public Unit
{
    public:
        Cursor(SDL_Renderer *renderer);

        void init(SDL_Renderer *renderer);

        void updateType();
        void updateCoords();

        void draw(int xPixellScreenOffset, int yPixelScreenOffset);

        void setXPixelCoord(int x);
        void setYPixelCoord(int y);

        void setLocation(Location *location);

    private:
        void setHexGreenCursor();
        void setHexBlackCursor();
        void setHexBlueCursor();
        void setHexRedCursor();

        int xPixelCoord = 0;
        int yPixelCoord = 0;

        Image *hexGreen;
        Image *hexBlack;
        Image *hexBlue;
        Image *hexRed;
        Image *pointer;
        Image *clock;

        bool isHexCursor;

        Image *currImage;

        Location *location = NULL;

        const char *HEX_GREEN_IMAGE_PATH = "resources\\images\\cursors\\hex_green.png";
        const char *HEX_BLACK_IMAGE_PATH = "resources\\images\\cursors\\hex_black.png";
        const char *HEX_BLUE_IMAGE_PATH = "resources\\images\\cursors\\hex_blue.png";
        const char *HEX_RED_IMAGE_PATH = "resources\\images\\cursors\\hex_red.png";
};

#endif // CUROR_H
