#include "LocationScreen.h"

LocationScreen::LocationScreen(char* locationNumber, SDL_Renderer *renderer)
{
    char imageFilePath[80] = {0};
    char imageObstacleFilePath[80] = {0};

    strcat(imageFilePath, GlobalValues::LOCATIONS_DIR);
    strcat(imageFilePath, locationNumber);

    strcpy(imageObstacleFilePath, imageFilePath);

    strcat(imageFilePath, GlobalValues::LOCATION_IMG_FILENAME);
    strcat(imageObstacleFilePath, GlobalValues::LOCATION_IMG_OBSTACLE_FILENAME);

    Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", imageObstacleFilePath);

    screenRect = new SDL_Rect();
    screenRect->x = 0;
    screenRect->y = 0;
    screenRect->w = GlobalValues::SCREEN_WIDTH;
    screenRect->h = GlobalValues::SCREEN_HEIGHT;

    locationRect = new SDL_Rect();
    locationRect->x = 0;
    locationRect->y = 0;
    locationRect->w = GlobalValues::SCREEN_WIDTH;
    locationRect->h = GlobalValues::SCREEN_HEIGHT;

    image = new Image(imageFilePath, renderer);
    obstaclesImage = new Image(imageObstacleFilePath, renderer);
}

LocationScreen::~LocationScreen()
{
    delete image;
    delete screenRect;
    delete locationRect;
}

int LocationScreen::getXOffset() {return xOffset;}
int LocationScreen::getYOffset() {return yOffset;}
Image* LocationScreen::getObstaclesImage() {return obstaclesImage;}

void LocationScreen::draw()
{
    locationRect->x = xOffset;
    locationRect->y = yOffset;
    locationRect->w = GlobalValues::SCREEN_WIDTH;
    locationRect->h = GlobalValues::SCREEN_HEIGHT;

    image->draw(locationRect, screenRect);
}

void LocationScreen::move(Direction direction, int delta)
{
    switch(direction)
    {
        case LEFT_UP:
        {
            yOffset -= delta;
            xOffset -= delta;
            break;
        }
        case UP:
        {
            yOffset -= delta;
            break;
        }
        case RIGHT_UP:
        {
            yOffset -= delta;
            xOffset += delta;
            break;
        }
        case RIGHT:
        {
            xOffset += delta;
            break;
        }
        case RIGHT_DOWN:
        {
            xOffset += delta;
            yOffset += delta;
            break;
        }
        case DOWN:
        {
            yOffset += delta;
            break;
        }
        case LEFT_DOWN:
        {
            yOffset += delta;
            xOffset -= delta;
            break;
        }
        case LEFT:
        {
            xOffset -= delta;
            break;
        }
    }

    if(yOffset < 0) yOffset = 0;
    if(xOffset + GlobalValues::SCREEN_WIDTH > image->getWidth()) xOffset = image->getWidth() - GlobalValues::SCREEN_WIDTH;
    if(yOffset + GlobalValues::SCREEN_HEIGHT > image->getHeight()) {yOffset = image->getHeight() - GlobalValues::SCREEN_HEIGHT;}
    if(xOffset < 0) xOffset = 0;
}






