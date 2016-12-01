#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <SDL_image.h>
#include "Logger.h"


class Image
{
    public:
        Image();
        Image(char *filename, SDL_Surface *screen);
        ~Image();
        bool isEmpty();
        void load(char *filename, SDL_Surface *screen);
        void draw(SDL_Rect *imageRect, SDL_Rect *screenRect);

        int getWidth();
        int getHeight();

    private:
        SDL_Surface *surface = NULL;
        SDL_Surface *screen = NULL;
};

#endif // IMAGE_H
