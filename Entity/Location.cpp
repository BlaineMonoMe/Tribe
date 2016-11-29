#include "Location.h"

Location::Location(){}

Location::Location(char* locationNumber, SDL_Surface *screen)
{
    load(locationNumber, screen);
}

Location::~Location()
{
    //dtor
}

void Location::load(char* locationNumber, SDL_Surface *screen)
{
    char imageFilePath[80];
    strcat(imageFilePath, GlobalValues::LOCATIONS_DIR);
    strcat(imageFilePath, locationNumber);
    strcat(imageFilePath, GlobalValues::IMG_EXTENTION);
    Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", imageFilePath);

    image = new Image(imageFilePath, screen);
}

bool Location::isLoaded()
{
    return !(image->isEmpty());
}

void Location::draw(int xOffset, int yOffset)
{

}
