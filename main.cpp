#include <SDL.h>
#include <stdio.h>
#include "Image.h"
#include "LocationData.h"
#include "LocationScreen.h"
#include "GlobalValues.h"
#include "CoordsTranformer.h"
#include "AnimationData.h"
#include "Animation.h"
#include "LocationScreenMover.h"
#include "Container.h"
#include "UnitsHolder.h"
#include "FileReader.h"
#include "AbstractWeapon.h"
#include "AbstractDataHolder.h"

SDL_Window *window = NULL;
SDL_Surface *screen = NULL;

int main(int argc, char** args)
{

    //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "zzz");

    bool quit = false;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
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


    AbstractDataHolder *adh = new AbstractDataHolder();

    AbstractEnemy *ae = adh->getAbstractEnemyByType(1);
    AbstractWeapon *aw = adh->getAbstractWeaponByType(1);

    int z = aw->getPower();

    Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", z);

    delete adh;

    UnitsHolder *uh = new UnitsHolder("0");

    delete uh;








    LocationScreen *ls = new LocationScreen("0", renderer);
    ls->draw();

    LocationScreenMover *lsm = new LocationScreenMover(ls, 30);



    AnimationData *ad = new AnimationData("workImages/Animation4Frames.png", 4, renderer);


    class AnimationMover : public Timer
    {
    public:
        Animation *a;
        int beginX;
        SDL_Rect *rect;
        AnimationMover(int interval, Animation *a, SDL_Rect *rect) : Timer(interval)
        {
            this->a = a;
            this->rect = rect;
            beginX = rect->x;
        }

        void execute()
        {
            if(rect->x == beginX + (42 * 20))
            {
                stop();
                a->stop();
                Image *ii;
                beginX += 38;
                return;
                //ii = new Image("workImages/right_stand.png", renderer);

            }
            rect->x += 2;
            a->setScreenRect(rect);
        }
    };

    Animation *a = new Animation(ad, 300);
    SDL_Rect *r = new SDL_Rect();
            r->x = 120;
            r->y = 27;
            r->w = 120;
            r->h = 120;
            a->setScreenRect(r);
    //a->start();

    AnimationMover *am = new AnimationMover(50, a, r);
    //am->start();

    SDL_RenderPresent(renderer);

    while(quit == false)
    {

        //SDL_Delay(1);
        int currTime = SDL_GetTicks();

        if(a->isTime(currTime) && a->getIsStarted())
        {
            ls->draw();
            a->execute();
            SDL_RenderPresent(renderer);
        }


        if(am->isTime(currTime) && am->getIsStarted())
        {
            am->execute();
            ls->draw();
            a->draw();
            SDL_RenderPresent(renderer);
        }


        if(lsm->getIsStarted() && lsm->isTime(currTime))
        {
            lsm->execute();
            ls->draw();
            SDL_RenderPresent(renderer);
        }




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

                lsm->checkNeedToMove(x, y);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                a->start();
                am->start();
            }
        }
    }


    delete ad;
    delete ls;
    delete lsm;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
