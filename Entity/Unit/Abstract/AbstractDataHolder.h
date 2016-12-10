#ifndef ABSTRACTDATAHOLDER_H
#define ABSTRACTDATAHOLDER_H

#include <vector>

#include "FileReader.h"
#include "AbstractWeapon.h"
#include "AbstractEnemy.h"
#include "../../../GlobalValues.h"

class AbstractDataHolder
{
    public:
        AbstractDataHolder();
        ~AbstractDataHolder();

        void load();

        AbstractWeapon* getAbstractWeaponByType(int type);
        AbstractEnemy* getAbstractEnemyByType(int type);

    private:
        std::vector<AbstractWeapon*> *abstractWeapons = NULL;
        std::vector<AbstractEnemy*> *abstractEnemies = NULL;
};

#endif // ABSTRACTDATAHOLDER_H
