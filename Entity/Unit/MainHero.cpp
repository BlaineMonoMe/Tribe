#include "MainHero.h"

MainHero::MainHero()
{
    xCell = 3;
    yCell = 25;

    maxLife = 150;
    currLife = maxLife;

    resistance = 5;
    strength = 0.8;
    nonBattleSpeed = 4;

    additionLife = 0;
    additionPoints = 0;

    pointsPerTurn = 25;
    currPoints = pointsPerTurn;
    movePoints = 3;
    takePoints = 5;
    throwPoints = 2;
    changeWeaponPoints = 7;
    usePoints = 7;
}

MainHero::~MainHero() {}

void MainHero::draw()
{

}
