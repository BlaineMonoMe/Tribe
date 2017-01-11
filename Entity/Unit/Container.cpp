#include "Container.h"

Container::Container() {}

Container::Container(FileReader *fileReader, SDL_Renderer *renderer)
{
    load(fileReader, renderer);
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

void Container::draw(int xPixellScreenOffset, int yPixellScreenOffset)
{
    SDL_Point point = CoordsTranformer::cellsToPixels(xCell, yCell);

    int pixellXOffset = point.x - smallImage->getWidth() / 2;
    int pixellYOffset = point.y - smallImage->getHeight() / 2;

    int resultXCoord = pixellXOffset - xPixellScreenOffset;
    int resultYCoord = pixellYOffset - yPixellScreenOffset;

    smallImage->draw(resultXCoord, resultYCoord);
}

void Container::load(FileReader *fileReader, SDL_Renderer *renderer)
{
    fileReader->readLine(); // read service data - it is not used
    willStayAnyway = fileReader->readInt();
    xCell = fileReader->readInt();
    yCell = fileReader->readInt();
    smallImage = new Image((char*)(fileReader->readLine().c_str()), renderer);
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
bool Container::getWillStayAnyway() {return willStayAnyway;}

int Container::getWeaponType(int index) {return weapons->at(index);}
int Container::getWeaponTypesCount() {return weapons->size();}

int Container::getStone(int index) {return stones->at(index);}
int Container::getStonesCount() {return stones->size();}

AmmunitionItem* Container::getAmmunition(int index) {return ammunitions->at(index);}
int Container::getAmmunitionsCount() {return ammunitions->size();}

int Container::getFood(int index) {return foods->at(index);}
int Container::getFoodsCount() {return foods->size();}

