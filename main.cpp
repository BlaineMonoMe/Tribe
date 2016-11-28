#include <SDL.h>
#include <stdio.h>

//The window we'll be rendering to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;


int main(int argc, char** args)
{

    bool quit = false;
    SDL_Event e;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tribal", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1366, 768, SDL_WINDOW_FULLSCREEN);
    screenSurface = SDL_GetWindowSurface(window);


    while(quit == false)
    {
        while(SDL_PollEvent(&e) != 0)
        {
            if(e.type == SDL_KEYDOWN)
            {
                if(e.key.keysym.sym = SDLK_ESCAPE)
                {
                    quit = true;
                }
            }
        }
    }


	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;

	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();

	return 0;
}
