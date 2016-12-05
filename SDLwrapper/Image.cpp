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
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
}

void Image::load(char *filename, SDL_Renderer *renderer)
{
    this->renderer = renderer;

    surface = IMG_Load(filename);
    this->width = surface->w;
    this->height = surface->h;

    texture = SDL_CreateTextureFromSurface(renderer, surface);
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
    if(surface != NULL)
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
    if(surface != NULL)
    {
        return height;
    }
    else
    {
        return 0;
    }
}




