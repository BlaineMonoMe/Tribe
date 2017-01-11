#include "MainHero.h"

MainHero::MainHero(char *creatureNumber, SDL_Renderer *renderer) : Creature(creatureNumber, renderer)
{
    xCell = 4;
    yCell = 50;

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

    state = STAY;
    direction = RIGHT;
}

MainHero::~MainHero() {}

int MainHero::getImagePixellOffsetX() {return imagePixellOffsetX;}
int MainHero::getImagePixellOffsetY() {return imagePixellOffsetY;}
int MainHero::getNonBattleSpeed() {return nonBattleSpeed;}



