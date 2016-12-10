#ifndef UNITSHOLDER_H
#define UNITSHOLDER_H

#include <vector>

#include "Container.h"
#include "Obstacle.h"
#include "FileReader.h"
#include "Enemy.h"
#include "Logger.h"


class UnitsHolder
{
    public:
        UnitsHolder();
        UnitsHolder(char *locationNumber);
        ~UnitsHolder();
        void load(char *locationNumber);

        Container* getContainer(int index);
        Obstacle* getObstacle(int index);
        Enemy* getEnemy(int index);

    private:
        void loadContainers(char *locationNumber);
        void loadObstacles(char *locationNumber);
        void loadEnemies(char *locationNumber);

        std::vector<Obstacle*> *obstacles = NULL;
        std::vector<Container*> *containers = NULL;
        std::vector<Enemy*> *enemies = NULL;

        std::vector<Unit*> *units = NULL;


};

#endif // UNITSHOLDER_H
