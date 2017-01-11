#include "UnitsHolder.h"

UnitsHolder::UnitsHolder() {}

UnitsHolder::UnitsHolder(char *locationNumber, AbstractDataHolder *dataHolder, LocationData *locationData, Image *obstaclesImage, SDL_Renderer *renderer)
{
    load(locationNumber, dataHolder, locationData, obstaclesImage, renderer);
}

void UnitsHolder::load(char *locationNumber, AbstractDataHolder *dataHolder, LocationData *locationData, Image *obstaclesImage, SDL_Renderer *renderer)
{
    units = new std::vector<Unit*>();
    loadContainers(locationNumber, renderer);
    loadObstacles(locationNumber, obstaclesImage);
    loadEnemies(locationNumber, dataHolder, locationData, renderer);
}

UnitsHolder::~UnitsHolder()
{
    if(containers != NULL)
    {
        for(int i = 0; i < containers->size(); i++)
        {
            delete containers->at(i);
        }
        delete containers;
    }

    if(obstacles != NULL)
    {
        for(int i = 0; i < obstacles->size(); i++)
        {
            delete obstacles->at(i);
        }
        delete obstacles;
    }

    if(enemies != NULL)
    {
        for(int i = 0; i < enemies->size(); i++)
        {
            delete enemies->at(i);
        }
        delete enemies;
    }


    delete units;
}

void UnitsHolder::nonBattleEnemiesAct()
{
    for(int i = 0; i < enemies->size(); i++)
    {
        enemies->at(i)->nonBattleActIfNeeded();
    }
}

void UnitsHolder::addMainHero(Unit *mainHero)
{
    units->push_back(mainHero);
}

void UnitsHolder::addCursor(Unit *cursor)
{
    this->cursor = cursor;
}

void UnitsHolder::sortUnits()
{
    std::sort(units->begin(), units->end(), unitComp);
}

void UnitsHolder::loadContainers(char *locationNumber, SDL_Renderer *renderer)
{

    char dataFilePath[80] = {0};
    strcat(dataFilePath, GlobalValues::LOCATIONS_DIR);
    strcat(dataFilePath, locationNumber);
    strcat(dataFilePath, GlobalValues::ITEMS_DIR_FILE);

    FileReader *fileReader = new FileReader(dataFilePath);

    int containersCount = fileReader->readInt();
    containers = new std::vector<Container*>();

    for(int i = 0; i < containersCount; i++)
    {
        Container *container = new Container(fileReader, renderer);
        containers->push_back(container);
    }

    delete fileReader;
}

void UnitsHolder::loadObstacles(char *locationNumber, Image *obstacleImage)
{

    char dataFilePath[80] = {0};
    strcat(dataFilePath, GlobalValues::LOCATIONS_DIR);
    strcat(dataFilePath, locationNumber);
    strcat(dataFilePath, GlobalValues::OBSTACLES_DIR_FILE);

    FileReader *fileReader = new FileReader(dataFilePath);

    int obstaclesCount = fileReader->readInt();
    obstacles = new std::vector<Obstacle*>();

    for(int i = 0; i < obstaclesCount; i++)
    {
        Obstacle *obstacle = new Obstacle(fileReader);
        obstacle->setObstaclesImage(obstacleImage);
        obstacles->push_back(obstacle);
        units->push_back(obstacle);
    }

    delete fileReader;
}

void UnitsHolder::loadEnemies(char *locationNumber, AbstractDataHolder *dataHolder, LocationData *locationData, SDL_Renderer *renderer)
{

    char dataFilePath[80] = {0};
    strcat(dataFilePath, GlobalValues::LOCATIONS_DIR);
    strcat(dataFilePath, locationNumber);
    strcat(dataFilePath, GlobalValues::ENEMIES_DIR_FILE);

    FileReader *fileReader = new FileReader(dataFilePath);

    int enemiesCount = fileReader->readInt();
    enemies = new std::vector<Enemy*>();

    for(int i = 0; i < enemiesCount; i++)
    {
        Enemy *enemy = new Enemy(fileReader, dataHolder, locationData, renderer);
        enemies->push_back(enemy);
        units->push_back(enemy);
    }

    delete fileReader;
}

void UnitsHolder::draw(LocationScreen *locationScreen)
{

    cursor->draw(0, 0);

    for(int i = 0; i < containers->size(); i++)
    {
        containers->at(i)->draw(locationScreen->getXOffset(), locationScreen->getYOffset());
    }

    sortUnits();
    for(int i = 0; i < units->size(); i++)
    {
        units->at(i)->draw(locationScreen->getXOffset(), locationScreen->getYOffset());
    }

}

bool UnitsHolder::isEnemyOnCell(int xCell, int yCell)
{
    for(int i = 0; i < enemies->size(); i++)
    {
        if(enemies->at(i)->getXCell() == xCell && enemies->at(i)->getYCell() == yCell)
        {
            return true;
        }
    }
    return false;
}

bool UnitsHolder::isContainerOnCell(int xCell, int yCell)
{
    for(int i = 0; i < containers->size(); i++)
    {
        if(containers->at(i)->getXCell() == xCell && containers->at(i)->getYCell() == yCell)
        {
            return true;
        }
    }
    return false;
}

std::vector<Enemy*>* UnitsHolder::getEnemies() {return enemies;}

Container* UnitsHolder::getContainer(int index) {return containers->at(index);}

Obstacle* UnitsHolder::getObstacle(int index) {return obstacles->at(index);}


