#ifndef CONTAINER_H
#define CONTAINER_H

#include <string>
#include <vector>

#include "AmmunitionItem.h"
#include "Unit.h"
#include "FileReader.h"
#include "../../GlobalValues.h";
#include "Logger.h"


class Container : public Unit
{
    public:
        Container();
        Container(FileReader *fileReader);
        ~Container();

        void draw();

        void load(FileReader *fileReader);

        std::string getPathToSmallImage();
        int getLitersOfWater();
        bool getWillStayAnyway();

        int getWeaponType(int index);
        int getWeaponTypesCount();

        int getStone(int index);
        int getStonesCount();

        AmmunitionItem* getAmmunition(int index);
        int getAmmunitionsCount();

        int getFood(int index);
        int getFoodsCount();

    private:
        bool willStayAnyway = false;
        std::string pathToSmallImage;
        int litersOfWater;
        std::vector<int> *weapons = NULL;
        std::vector<int> *stones = NULL;
        std::vector<AmmunitionItem*> *ammunitions = NULL;
        std::vector<int> *foods = NULL;

};

#endif // CONTAINER_H
