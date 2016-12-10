#include "AbstractEnemy.h"

AbstractEnemy::AbstractEnemy() {}

AbstractEnemy::AbstractEnemy(FileReader *fileReader)
{
    load(fileReader);
}

void AbstractEnemy::load(FileReader *fileReader)
{
    fileReader->readLine(); // service data
    fileReader->readLine(); // delimiter
    type = fileReader->readInt();
    isTwooCells = fileReader->readInt();
    maxLife = fileReader->readInt();
    resistance = fileReader->readInt();
    minAttack = fileReader->readInt();
    maxAttack = fileReader->readInt();
    attackRange = fileReader->readInt();
    strength = fileReader->readDouble();
    maxPercission = fileReader->readInt();
    percissionCoef = fileReader->readInt();
    enemyNoticeRange = fileReader->readInt();
    friendMoodNoticeRange = fileReader->readInt();
    nonBattleSpeed = fileReader->readInt();
    pointsPerTurn = fileReader->readInt();
    movePoints = fileReader->readInt();
    attackPoints = fileReader->readInt();
    freeWill = fileReader->readInt();

}

AbstractEnemy::~AbstractEnemy() {}

int AbstractEnemy::getType() {return type;}
bool AbstractEnemy::getIsTwooCells() {return isTwooCells;}
int AbstractEnemy::getEnemyNoticeRange() {return enemyNoticeRange;}
int AbstractEnemy::getFriendMoodNoticeRange() {return friendMoodNoticeRange;}
int AbstractEnemy::getFreeWill() {return freeWill;}
