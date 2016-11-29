#include <stdio.h>
#include "Image.h"

Image::Image(){}

Image::Image(char *filename, SDL_Surface *screen)
{
    load(filename, screen);
}

Image::~Image()
{
    if(surface != NULL)
    {
        SDL_FreeSurface(surface);
    }
}

void Image::load(char *filename, SDL_Surface *screen)
{
    SDL_Surface* loadedSurface = IMG_Load(filename);
    if(loadedSurface == NULL)
    {
        //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "load surface failed");
    }
    else
    {
        surface = SDL_ConvertSurface(loadedSurface, screen->format, NULL);
        if(surface == NULL)
        {
            //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "load surface failed");
        }

        SDL_FreeSurface(loadedSurface);
        //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "load successfully ended");
    }
}

bool Image::isEmpty()
{
    if(surface == NULL) return true;
    else return false;
}

void Image::draw(SDL_Rect *imageRect, SDL_Rect *screenRect, SDL_Surface *screen)
{
    if(surface != NULL)
    {
        SDL_BlitScaled(surface, imageRect, screen, screenRect);
    }
}


