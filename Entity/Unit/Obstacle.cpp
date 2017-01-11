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

    rectToDrawFrom = new SDL_Rect();
    rectToDrawFrom->x = fileReader->readInt();
    rectToDrawFrom->y = fileReader->readInt();
    rectToDrawFrom->w = fileReader->readInt();
    rectToDrawFrom->h = fileReader->readInt();
}

Obstacle::~Obstacle()
{
    delete rectToDrawFrom;
}

void Obstacle::setObstaclesImage(Image *obstaclesImage) {this->obstaclesImage = obstaclesImage;}

void Obstacle::draw(int xPixellScreenOffset, int yPixellScreenOffset)
{
    SDL_Rect *rectDrawTo = new SDL_Rect();
    rectDrawTo->x = rectToDrawFrom->x - xPixellScreenOffset;
    rectDrawTo->y = rectToDrawFrom->y - yPixellScreenOffset;
    rectDrawTo->w = rectToDrawFrom->w;
    rectDrawTo->h = rectToDrawFrom->h;

    obstaclesImage->draw(rectToDrawFrom, rectDrawTo);

    delete rectDrawTo;
}

