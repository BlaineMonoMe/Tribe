#include <stdio.h>
#include "Image.h"

Image::Image(){}

Image::Image(char *filename, SDL_Renderer *renderer)
{
    load(filename, renderer);
}

Image::~Image()
{
    if(texture != NULL)
    {
        SDL_DestroyTexture(texture);
    }
}

void Image::load(char *filename, SDL_Renderer *renderer)
{
    this->renderer = renderer;

    SDL_Surface* loadedSurface = IMG_Load(filename);
    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);

    width = loadedSurface->w;
    height = loadedSurface->h;

    SDL_FreeSurface(loadedSurface);

}

void Image::draw(SDL_Rect *imageRect, SDL_Rect *screenRect)
{
    if(texture != NULL)
    {
        SDL_RenderCopy(renderer, texture, imageRect, screenRect);
    }
}

int Image::getWidth()
{
    if(texture != NULL)
    {
        return width;
    }
    else
    {
        return 0;
    }
}

int Image::getHeight()
{
    if(texture != NULL)
    {
        return height;
    }
    else
    {
        return 0;
    }
}




