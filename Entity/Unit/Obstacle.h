#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>

#include "Unit.h"
#include "FileReader.h"
#include "Image.h"


class Obstacle : public Unit
{
    public:
        Obstacle();
        Obstacle(FileReader *fileReader);
        ~Obstacle();
        void load(FileReader *fileReader);

        void setObstaclesImage(Image *obstaclesImage);

        void draw(int xPixellScreenOffset, int yPixelScreenOffset);

    private:
        SDL_Rect *rectToDrawFrom = NULL;
        Image *obstaclesImage = NULL;


};

#endif // OBSTACKLE_H
