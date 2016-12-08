#include "Container.h"

Container::Container() {}

Container::Container(FileReader *fileReader)
{
    load(fileReader);
}

Container::~Container()
{
    if(weapons != NULL) delete weapons;
    if(stones != NULL) delete stones;
    if(ammunitions != NULL)
    {
        for(int i = 0; i < ammunitions->size(); i++)
        {
            delete ammunitions->at(i);
        }
        delete ammunitions;
    }
    if(foods != NULL) delete foods;
}

void Container::draw()
{

}

void Container::load(FileReader *fileReader)
{
    fileReader->readLine(); // read service data - it is not used
    xCell = fileReader->readInt();
    yCell = fileReader->readInt();
    pathToSmallImage = fileReader->readLine();
    litersOfWater = fileReader->readInt();

    int weaponsCount = fileReader->readInt();
    weapons = new std::vector<int>();
    for(int j = 0; j < weaponsCount; j++)
    {
        weapons->push_back(fileReader->readInt());
    }

    int stonesCount = fileReader->readInt();
    stones = new std::vector<int>();
    for(int j = 0; j < stonesCount; j++)
    {
        stones->push_back(fileReader->readInt());
    }

    int ammunitionsCount = fileReader->readInt();
    ammunitions = new std::vector<AmmunitionItem*>();
    for(int j = 0; j < ammunitionsCount; j++)
    {
        ammunitions->push_back(new AmmunitionItem(fileReader->readInt(), fileReader->readInt()));
    }

    int foodsCount = fileReader->readInt();
    foods = new std::vector<int>();
    for(int j = 0; j < foodsCount; j++)
    {
        foods->push_back(fileReader->readInt());
    }
}

int Container::getLitersOfWater() {return litersOfWater;}
std::string Container::getPathToSmallImage() {return pathToSmallImage;}

int Container::getWeaponType(int index) {return weapons->at(index);}
int Container::getWeaponTypesCount() {return weapons->size();}

int Container::getStone(int index) {return stones->at(index);}
int Container::getStonesCount() {return stones->size();}

AmmunitionItem* Container::getAmmunition(int index) {return ammunitions->at(index);}
int Container::getAmmunitionsCount() {return ammunitions->size();}

int Container::getFood(int index) {return foods->at(index);}
int Container::getFoodsCount() {return foods->size();}

