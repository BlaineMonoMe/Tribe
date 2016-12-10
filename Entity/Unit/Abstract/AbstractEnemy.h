#ifndef ABSTRACTENEMY_H
#define ABSTRACTENEMY_H

#include "AbstractAttack.h"
#include "AbstractCreature.h"
#include "FileReader.h"

class AbstractEnemy : public AbstractAttack, public AbstractCreature
{
    public:
        AbstractEnemy();
        AbstractEnemy(FileReader *fileReader);
        void load(FileReader *fileReader);
        ~AbstractEnemy();

        int getType();
        bool getIsTwooCells();
        int getEnemyNoticeRange();
        int getFriendMoodNoticeRange();
        int getFreeWill();

    private:
        int type;
        bool isTwooCells;
        int enemyNoticeRange;
        int friendMoodNoticeRange;
        int freeWill;
};

#endif // ABSTRACTENEMY_H
