#include <SDL.h>
#include <stdio.h>
#include "Image.h"
#include "Location.h"
#include "GlobalValues.h"


SDL_Window *window = NULL;
SDL_Surface *screen = NULL;

int main(int argc, char** args)
{

    bool quit = false;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(GlobalValues::PROJECT_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              GlobalValues::SCREEN_WIDTH, GlobalValues::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    int imgFlags = IMG_INIT_JPG;
    IMG_Init(imgFlags);

    screen = SDL_GetWindowSurface(window);

    Image *fon = new Image("example1.jpg", screen);
    fon->draw(NULL, NULL, screen);
    delete fon;

    Location *l = new Location("0", screen);

    SDL_UpdateWindowSurface(window);




    while(quit == false)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    quit = true;
                }
            }
        }
    }


	SDL_FreeSurface(screen);
	screen = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	IMG_Quit();
	SDL_Quit();

	return 0;
}
