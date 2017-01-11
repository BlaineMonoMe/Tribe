#include "Cursor.h"

Cursor::Cursor(SDL_Renderer *renderer)
{
    init(renderer);
}

void Cursor::setHexGreenCursor()
{
    currImage = hexGreen;
    isHexCursor = true;
}

void Cursor::setHexBlackCursor()
{
    currImage = hexBlack;
    isHexCursor = true;
}

void Cursor::setHexBlueCursor()
{
    currImage = hexBlue;
    isHexCursor = true;
}

void Cursor::setHexRedCursor()
{
    currImage = hexRed;
    isHexCursor = true;
}

void Cursor::setXPixelCoord(int x) {this->xPixelCoord = x;}
void Cursor::setYPixelCoord(int y) {this->yPixelCoord = y;}

void Cursor::setLocation(Location *location) {this->location = location;}

void Cursor::updateCoords()
{
    int globalPixelX = xPixelCoord + location->getLocationScreen()->getXOffset();
    int globalPixelY = yPixelCoord + location->getLocationScreen()->getYOffset();

    SDL_Point cell = CoordsTranformer::pixelsToCells(globalPixelX, globalPixelY);

    xCell = cell.x;
    yCell = cell.y;
}

void Cursor::updateType()
{
    if(location != NULL)
    {
        int globalPixelX = xPixelCoord + location->getLocationScreen()->getXOffset();
        int globalPixelY = yPixelCoord + location->getLocationScreen()->getYOffset();

        SDL_Point cell = CoordsTranformer::pixelsToCells(globalPixelX, globalPixelY);
        if(location->getLocationData()->isFreeToGo(cell.x, cell.y))
        {
            setHexGreenCursor();
        }
        else
        {
            setHexBlackCursor();
        }
        if(location->getUnitsHolder()->isContainerOnCell(cell.x, cell.y))
        {
            setHexBlueCursor();
        }
        if(location->getUnitsHolder()->isEnemyOnCell(cell.x, cell.y))
        {
            setHexRedCursor();
        }
        if(location->getLocationData()->isWater(cell.x, cell.y))
        {
            setHexBlueCursor();
        }
        if(location->getLocationData()->isOtherLocation(cell.x, cell.y))
        {
            setHexBlueCursor();
        }
    }
}


void Cursor::init(SDL_Renderer *renderer)
{
    hexGreen = new Image((char*)HEX_GREEN_IMAGE_PATH, renderer);
    hexBlack = new Image((char*)HEX_BLACK_IMAGE_PATH, renderer);
    hexBlue = new Image((char*)HEX_BLUE_IMAGE_PATH, renderer);
    hexRed = new Image((char*)HEX_RED_IMAGE_PATH, renderer);

    currImage = hexGreen;
    isHexCursor = true;
}

void Cursor::draw(int xPixellScreenOffset, int yPixelScreenOffset)
{
    if(isHexCursor)
    {
        int globalPixelX = xPixelCoord + location->getLocationScreen()->getXOffset();
        int globalPixelY = yPixelCoord + location->getLocationScreen()->getYOffset();

        SDL_Point cell = CoordsTranformer::pixelsToCells(globalPixelX, globalPixelY);
        SDL_Point pixel = CoordsTranformer::cellsToPixels(cell.x, cell.y);

        int pixelX = pixel.x - location->getLocationScreen()->getXOffset();
        int pixelY = pixel.y - location->getLocationScreen()->getYOffset();

        currImage->draw(pixelX - GlobalValues::CELL_WIDTH / 2, pixelY - GlobalValues::CELL_HEIGHT / 2);
    }
}


