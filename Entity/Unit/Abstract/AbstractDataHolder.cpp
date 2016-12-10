#include "AbstractDataHolder.h"

AbstractDataHolder::AbstractDataHolder()
{
    abstractWeapons = new std::vector<AbstractWeapon*>();
    abstractEnemies = new std::vector<AbstractEnemy*>();

    load();
}

AbstractDataHolder::~AbstractDataHolder()
{
    if(abstractWeapons != NULL)
    {
        for(int i = 0; i < abstractWeapons->size(); i++)
        {
            delete abstractWeapons->at(i);
        }
        delete abstractWeapons;
    }
    if(abstractEnemies != NULL)
    {
        for(int i = 0; i < abstractEnemies->size(); i++)
        {
            delete abstractEnemies->at(i);
        }
        delete abstractEnemies;
    }
}

void AbstractDataHolder::load()
{
    FileReader *fileReader = new FileReader(GlobalValues::ABSTRACT_WEAPON_DIR_FILE);

    int abstractWeaponsCount = fileReader->readInt();
    for(int i = 0; i < abstractWeaponsCount; i++)
    {
        abstractWeapons->push_back(new AbstractWeapon(fileReader));
    }

    delete fileReader;

    fileReader = new FileReader(GlobalValues::ABSTRACT_ENEMY_DIR_FILE);
    int abstractEnemiesCount = fileReader->readInt();
    for(int i = 0; i < abstractEnemiesCount; i++)
    {
        abstractEnemies->push_back(new AbstractEnemy(fileReader));
    }

    delete fileReader;
}

AbstractWeapon* AbstractDataHolder::getAbstractWeaponByType(int type)
{
    if(abstractWeapons == NULL) return NULL;

    for(int i = 0; i < abstractWeapons->size(); i++)
    {
        if(abstractWeapons->at(i)->getType() == type)
        {
            return abstractWeapons->at(i);
        }
    }

    return NULL;
}

AbstractEnemy* AbstractDataHolder::getAbstractEnemyByType(int type)
{
    if(abstractEnemies == NULL) return NULL;

    for(int i = 0; i < abstractEnemies->size(); i++)
    {
        if(abstractEnemies->at(i)->getType() == type)
        {
            return abstractEnemies->at(i);
        }
    }

    return NULL;
}
