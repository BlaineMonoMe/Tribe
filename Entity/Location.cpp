#include "Location.h"

Location::Location(char *number, AbstractDataHolder *abstractData, SDL_Renderer *renderer)
{
    strcpy(this->locationNumber, number);

    locationData = new LocationData(number);
    locationScreen = new LocationScreen(number, renderer);
    locationScreenMover = new LocationScreenMover(locationScreen, 30);

    unitsHolder = new UnitsHolder(number, abstractData, locationData, locationScreen->getObstaclesImage(), renderer);
}

void Location::doEnable()
{
    locationScreen->draw();
    locationScreenMover->start();
    TimerHolder::getInstance().addTimer(locationScreenMover);
}

void Location::doDiable()
{
    locationScreenMover->stop();
}

Location::~Location()
{
    delete locationData;
    delete locationScreen;
    delete locationScreenMover;
}

void Location::addMainHero(Unit *mainHero)
{
    unitsHolder->addMainHero(mainHero);
}

void Location::addCursor(Cursor *cursor)
{
    unitsHolder->addCursor(cursor);
}

void Location::draw()
{
    locationScreen->draw();
    unitsHolder->draw(locationScreen);
}

void Location::updateLocationData()
{
    locationData->reinitActualData();
    for(int i = 0; i < unitsHolder->getEnemies()->size(); i++)
    {
        locationData->setEnemyOnCell(unitsHolder->getEnemies()->at(i)->getXCell(), unitsHolder->getEnemies()->at(i)->getYCell());
    }
}

char* Location::getLocationNumber() {return locationNumber;}
LocationScreen* Location::getLocationScreen() {return locationScreen;}
LocationScreenMover* Location::getLocationScreenMover() {return locationScreenMover;}
LocationData* Location::getLocationData() {return locationData;}
UnitsHolder* Location::getUnitsHolder() {return unitsHolder;}
