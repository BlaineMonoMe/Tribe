#ifndef UNITSHOLDER_H
#define UNITSHOLDER_H

#include <vector>
#include <algorithm>

#include "Container.h"
#include "Obstacle.h"
#include "FileReader.h"
#include "Enemy.h"
#include "Logger.h"
#include "AbstractDataHolder.h"
#include "LocationData.h"
#include "MainHero.h"
#include "Unit.h"

class UnitsHolder
{
    public:
        UnitsHolder();
        UnitsHolder(char *locationNumber, AbstractDataHolder *dataHolder, LocationData *locationData, Image *obstaclesImage, SDL_Renderer *renderer);
        ~UnitsHolder();
        void load(char *locationNumber, AbstractDataHolder *dataHolder, LocationData *locationData, Image *obstaclesImage, SDL_Renderer *renderer);

        void draw(LocationScreen *locationScreen);

        void nonBattleEnemiesAct();

        void addMainHero(Unit *mainHero);
        void addCursor(Unit *cursor);

        void sortUnits();

        bool isEnemyOnCell(int xCell, int yCell);
        bool isContainerOnCell(int xCell, int yCell);

        Container* getContainer(int index);
        Obstacle* getObstacle(int index);
        Enemy* getEnemy(int index);

        std::vector<Enemy*>* getEnemies();

    private:
        void loadContainers(char *locationNumber, SDL_Renderer *renderer);
        void loadObstacles(char *locationNumber, Image *obstaclesImage);
        void loadEnemies(char *locationNumber, AbstractDataHolder *dataHolder, LocationData *locationData, SDL_Renderer *renderer);

        std::vector<Obstacle*> *obstacles = NULL;
        std::vector<Container*> *containers = NULL;
        std::vector<Enemy*> *enemies = NULL;

        std::vector<Unit*> *units = NULL;

        Unit *cursor;

};

#endif // UNITSHOLDER_H
