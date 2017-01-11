#ifndef ENEMY_H
#define ENEMY_H

#include "Unit.h"
#include "AbstractEnemy.h"
#include "FileReader.h"

#include "Unit.h"
#include "Creature.h"
#include "AnimationData.h"
#include "AbstractDataHolder.h"
#include "Cell.h"
#include "Randomizer.h"
#include "TimerHolder.h"

enum MainHeroDetectionState {AGGRESS, FOLLOW, REST};

class Enemy;

/**
    In NonBattle Mode this timer will delay enemy's staying mode
*/
class EnemyStayTimer : public Timer
{
    public:
        EnemyStayTimer(int interval, Enemy *enemy);
        void execute();

    private:
        Enemy *enemy;
        int COEF = 3;
};


class Enemy : public Creature
{
    public:
        Enemy(FileReader *fileReader, AbstractDataHolder *dataHolder , LocationData *locationData, SDL_Renderer *renderer);
        ~Enemy();

        void load(FileReader *fileReader, AbstractDataHolder *dataHolder, LocationData *locationData, SDL_Renderer *renderer);

        void nonBattleActIfNeeded();

        Cell* getRandCellToGo();

        int getImagePixellOffsetX();
        int getImagePixellOffsetY();
        int getNonBattleSpeed();
        AbstractEnemy* getAbstractEnemy();
        LocationData* getLocationData();

    private:
        AbstractEnemy *abstractEnemy;

        MainHeroDetectionState mainHeroDetectionState;

        LocationData *locationData;

        EnemyStayTimer *stayTimer;

        int currLife;
        int currPoints;

        int xHomeCell;
        int yHomeCell;
        int xDestination;
        int yDestination;
        int secondsToWait;



};


#endif // ENEMY_H
