#include <SDL.h>
#include <stdio.h>
#include "Image.h"
#include "Location.h"
#include "LocationScreen.h"
#include "GlobalValues.h"
#include "CoordsTranformer.h"


SDL_Window *window = NULL;
SDL_Surface *screen = NULL;

int main(int argc, char** args)
{

    //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "zzz");

    bool quit = false;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(GlobalValues::PROJECT_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              GlobalValues::SCREEN_WIDTH, GlobalValues::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    IMG_Init(imgFlags);

    SDL_Renderer* renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);


    /*SDL_Surface* loadedSurface = IMG_Load("point.png");
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
    SDL_RenderClear( renderer );
    SDL_RenderCopy( renderer, gTexture, NULL, NULL );
    SDL_RenderPresent( renderer );*/



    LocationScreen *ls = new LocationScreen("0", renderer);
    ls->draw();

    Image *img = new Image("point.png", renderer);
    img->draw(NULL, NULL);



    SDL_RenderPresent(renderer);





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
            if(event.type == SDL_MOUSEMOTION)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                SDL_Point p = CoordsTranformer::pixelsToCells(x, y);

                SDL_Point p2 = CoordsTranformer::cellsToPixels(p.x, p.y);

                SDL_Rect imgRect; imgRect.x = 77; imgRect.y = 19; imgRect.w = 7; imgRect.h = 7;
                SDL_Rect scrRect; scrRect.x = p2.x; scrRect.y = p2.y; scrRect.w = 7; scrRect.h = 7;

                ls->draw();

                img->draw(&imgRect, &scrRect);

                SDL_RenderPresent(renderer);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                /*int x, y;

                SDL_GetMouseState( &x, &y );


                char xx[10] = {0};
                char yy[10] = {0};

                SDL_Point p = CoordsTranformer::pixelsToCells(x, y);

                itoa(p.x, xx, 10);
                itoa(p.y, yy, 10);

                Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", xx);
                Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", yy);
                Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "----");*/
            }
        }
    }


    delete img;
    delete ls;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
