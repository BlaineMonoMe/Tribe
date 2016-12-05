#ifndef IMAGE_H
#define IMAGE_H

#include <SDL.h>
#include <SDL_image.h>
#include "Logger.h"


class Image
{
    public:
        Image();
        Image(char *filename, SDL_Renderer *renderer);
        ~Image();
        void load(char *filename, SDL_Renderer *renderer);
        void draw(SDL_Rect *imageRect, SDL_Rect *screenRect);

        int getWidth();
        int getHeight();

    private:
        SDL_Renderer *renderer;
        SDL_Texture *texture;
        SDL_Surface *surface;
        int height;
        int width;
};

#endif // IMAGE_H
