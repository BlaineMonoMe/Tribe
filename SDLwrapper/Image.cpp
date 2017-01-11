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

void Image::draw(SDL_Rect *screenRect)
{
    SDL_Rect *imageRect = new SDL_Rect;
    imageRect->x = 0;
    imageRect->y = 0;
    imageRect->w = width;
    imageRect->h = height;

    draw(imageRect, screenRect);

    delete imageRect;
}

void Image::draw(int x, int y)
{
    SDL_Rect *screeRect = new SDL_Rect;
    screeRect->x = x;
    screeRect->y = y;
    screeRect->w = width;
    screeRect->h = height;

    draw(screeRect);

    delete screeRect;
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




