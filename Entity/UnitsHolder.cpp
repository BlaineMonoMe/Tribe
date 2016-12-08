#include "UnitsHolder.h"

UnitsHolder::UnitsHolder() {}

UnitsHolder::UnitsHolder(char *locationNumber)
{
    load(locationNumber);
}

void UnitsHolder::load(char *locationNumber)
{
    units = new std::vector<Unit*>();
    loadContainers(locationNumber);
    loadObstacles(locationNumber);
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


    delete units;
}

void UnitsHolder::loadContainers(char *locationNumber)
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
        Container *container = new Container(fileReader);
        containers->push_back(container);
        units->push_back(container);
    }

    delete fileReader;
}

void UnitsHolder::loadObstacles(char *locationNumber)
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
        obstacles->push_back(obstacle);
        units->push_back(obstacle);
    }

    delete fileReader;
}




Container* UnitsHolder::getContainer(int index) { return containers->at(index); }

Obstacle* UnitsHolder::getObstacle(int index) { return obstacles->at(index); }

