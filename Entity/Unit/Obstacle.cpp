#include "Obstacle.h"

Obstacle::Obstacle() {}

Obstacle::Obstacle(FileReader *fileReader)
{
    load(fileReader);
}

void Obstacle::load(FileReader *fileReader)
{
    fileReader->readLine(); // read service data - it is not used
    xCell = fileReader->readInt();
    yCell = fileReader->readInt();

    rectToDrawTo = new SDL_Rect();
    rectToDrawTo->x = fileReader->readInt();
    rectToDrawTo->y = fileReader->readInt();
    rectToDrawTo->w = fileReader->readInt();
    rectToDrawTo->h = fileReader->readInt();
}

Obstacle::~Obstacle()
{
    delete rectToDrawTo;
}

void Obstacle::draw()
{

}

SDL_Rect* Obstacle::getRectToDrawTo()
{
    return rectToDrawTo;
}
