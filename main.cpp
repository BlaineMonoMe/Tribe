#include <SDL.h>
#include <stdio.h>
#include <ctime>

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
#include "InterCellPixelsCalculator.h"
#include "Path.h"
#include "Cell.h"
#include "PathGenerator.h"
#include "MainHero.h"
#include "DirectionsSequence.h"
#include "AbstractCreature.h"
#include "TimerHolder.h"
#include "Location.h"
#include "Randomizer.h"
#include "Cursor.h"


SDL_Window *window = NULL;
SDL_Surface *screen = NULL;


int main(int argc, char** args)
{
    //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", "zzz");


    srand(time(0));

    bool quit = false;

    SDL_Event event;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER);
    window = SDL_CreateWindow(GlobalValues::PROJECT_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              GlobalValues::SCREEN_WIDTH, GlobalValues::SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG;
    IMG_Init(imgFlags);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);

    SDL_ShowCursor(SDL_DISABLE);



    //==========================


    Cursor *cursor = new Cursor(renderer);

    AbstractDataHolder *abstractData = new AbstractDataHolder();

    MainHero *mh = new MainHero("0", renderer);

    Location *location = new Location("0", abstractData, renderer);
    location->addMainHero(mh);
    location->addCursor(cursor);
    location->doEnable();

    cursor->setLocation(location);


    DirectionsSequence *dd = new DirectionsSequence();
    //PathGenerator::generatePathAStar(new Cell(31, 25), new Cell(33, 27), location->getLocationData(), dd);


    //mh->draw(location->getLocationScreen()->getXOffset(), location->getLocationScreen()->getYOffset());
    //mh->setDetstinationAndGo(4, 26, location->getLocationData());







    //mh->image = new Image("workImages\\redPoint.jpg", renderer);




   /* AbstractDataHolder *adh = new AbstractDataHolder();

    AbstractEnemy *ae = adh->getAbstractEnemyByType(1);
    AbstractWeapon *aw = adh->getAbstractWeaponByType(1);

    int z = aw->getPower();*/

    //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", z);

   /* delete adh;

    UnitsHolder *uh = new UnitsHolder("0");

    delete uh;*/



    //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", cc->getY());






   // AnimationData *ad = new AnimationData("workImages/Animation4Frames.png", 4, renderer);


    /*class AnimationMover : public Timer
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
    };*/

    /*Animation *a = new Animation(ad, 300);
    SDL_Rect *r = new SDL_Rect();
            r->x = 120;
            r->y = 27;
            r->w = 120;
            r->h = 120;
            a->setScreenRect(r);*/
    //a->start();

    //AnimationMover *am = new AnimationMover(50, a, r);
    //am->start();



    /*bool isSetBeginCell = false;
    Cell *begCell = NULL;
    Cell *mainHeroDestCell = NULL;*/

    int last = 0;

    while(quit == false)
    {

        int currTime = SDL_GetTicks();

        TimerHolder::getInstance().updateTimers(currTime);




        //if(currTime > last + 100)
        {

        last = currTime;

        location->draw();
        cursor->updateType();
        //cursor->draw(0, 0); /// zeros - because cursor already contains this data
        location->getUnitsHolder()->nonBattleEnemiesAct();
        location->updateLocationData();



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

                cursor->setXPixelCoord(x);
                cursor->setYPixelCoord(y);
                cursor->updateCoords();

                location->getLocationScreenMover()->checkNeedToMove(x, y);
            }
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                int x, y;
                SDL_GetMouseState(&x, &y);

                int screenOffsetX = location->getLocationScreen()->getXOffset();
                int screenOffsetY = location->getLocationScreen()->getYOffset();

                SDL_Point p = CoordsTranformer::pixelsToCells(x + screenOffsetX,
                                                              y + screenOffsetY);

                mh->setDetstinationAndGo(p.x, p.y, location->getLocationData());
            }
        }
    }


    delete location;
    delete abstractData;
    delete mh;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();

	return 0;
}
