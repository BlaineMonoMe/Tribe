#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <SDL.h>

#include "Unit.h"
#include "FileReader.h"


class Obstacle : public Unit
{
    public:
        Obstacle();
        Obstacle(FileReader *fileReader);
        ~Obstacle();
        void load(FileReader *fileReader);

        void draw();

        SDL_Rect* getRectToDrawTo();

    private:
        SDL_Rect *rectToDrawTo = NULL;


};

#endif // OBSTACKLE_H
