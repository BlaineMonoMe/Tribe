#include <SDL.h>
#include <stdio.h>


const int SCREEN_WIDTH = 1366;
const int SCREEN_HEIGHT = 768;
const char *PROJECT_NAME = "Tibe";

SDL_Window *window = NULL;
SDL_Surface *screen = NULL;


int main(int argc, char** args)
{

    bool quit = false;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(PROJECT_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
    screen = SDL_GetWindowSurface(window);


    while(quit == false)
    {
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym = SDLK_ESCAPE)
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

	SDL_Quit();

	return 0;
}
