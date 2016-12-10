#include "Enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(FileReader *fileReader)
{
    load(fileReader);
}

void Enemy::load(FileReader *fileReader)
{
    fileReader->readLine(); // delimiter
    fileReader->readLine(); // read service data
    int enemyType = fileReader->readInt(); // TODO: get href to AbstractEnemy
    xCell = fileReader->readInt();
    xHomeCell = xCell;
    yCell = fileReader->readInt();
    yHomeCell = yCell;

    mode = REST;

    // TODO - INIT MORE

}

Enemy::~Enemy() {}

void Enemy::draw()
{

}
