#include "Enemy.h"


Enemy::Enemy(FileReader *fileReader, AbstractDataHolder *dataHolder, LocationData *locationData, SDL_Renderer *renderer)
{
    load(fileReader, dataHolder, locationData, renderer);
}

void Enemy::load(FileReader *fileReader, AbstractDataHolder *dataHolder, LocationData *locationData, SDL_Renderer *renderer)
{
    this->locationData = locationData;

    fileReader->readLine(); // delimiter
    fileReader->readLine(); // read service data
    char enemyType[5] = {0};
    strcpy(enemyType, fileReader->readLine().c_str()); // TODO: get href to AbstractEnemy
    xCell = fileReader->readInt();
    xHomeCell = xCell;
    yCell = fileReader->readInt();
    yHomeCell = yCell;

    mainHeroDetectionState = REST;
    state = STAY;
    direction = LEFT;

    /// graphics init
    init(enemyType, renderer);

    abstractEnemy = dataHolder->getAbstractEnemyByType(atoi(enemyType));

    stayTimer = new EnemyStayTimer(1000, this);
    TimerHolder::getInstance().addTimer(stayTimer);

}

Enemy::~Enemy() {}

int Enemy::getImagePixellOffsetX() {return abstractEnemy->getImagePixellOffsetX();}
int Enemy::getImagePixellOffsetY() {return abstractEnemy->getImagePixellOffsetY();}
int Enemy::getNonBattleSpeed() {return abstractEnemy->getNonBattleSpeed();}
AbstractEnemy* Enemy::getAbstractEnemy() {return abstractEnemy;}
LocationData* Enemy::getLocationData() {return locationData;}

void Enemy::nonBattleActIfNeeded()
{
    if(state == STAY && stayTimer->getIsStarted() == false)
    {
        if(Randomizer::isEvent(50))
        {
            stayTimer->start();
        }
        else
        {
            Cell *destCell = getRandCellToGo();
            setDetstinationAndGo(destCell->getX(), destCell->getY(), locationData);
        }
    }
}

Cell* Enemy::getRandCellToGo()
{
    bool goUp = Randomizer::isEvent(50);
    bool goLeft = Randomizer::isEvent(50);

    int xDestination = Randomizer::getRandom(1, abstractEnemy->getFreeWill());
    int yDestination = Randomizer::getRandom(1, abstractEnemy->getFreeWill());

    if(goLeft) {xDestination *= -1;}
    if(goUp) {yDestination *= -1;}

    return new Cell(xHomeCell + xDestination, yHomeCell + yDestination);
}



EnemyStayTimer::EnemyStayTimer(int interval, Enemy *enemy) : Timer(interval)
{
    this->enemy = enemy;
}

void EnemyStayTimer::execute()
{
    if(Randomizer::isEvent(enemy->getAbstractEnemy()->getFreeWill() * COEF) == true)
    {
        stop();
        Cell *destCell = enemy->getRandCellToGo();
        enemy->setDetstinationAndGo(destCell->getX(), destCell->getY(), enemy->getLocationData());
    }
}


