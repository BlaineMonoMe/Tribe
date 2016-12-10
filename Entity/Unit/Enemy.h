#ifndef ENEMY_H
#define ENEMY_H

#include "Unit.h"
#include "AbstractEnemy.h"
#include "FileReader.h"

enum Mode {ATTACK, FOLLOW, REST};

class Enemy : public Unit
{
    public:
        Enemy();
        Enemy(FileReader *fileReader);
        ~Enemy();

        void load(FileReader *fileReader);

        void draw();

    private:
        AbstractEnemy *abstractEnemy;

        Mode mode;

        int currLife;
        int currPoints;

        int xHomeCell;
        int yHomeCell;
        int xDestination;
        int yDestination;
        int secondsToWait;

};

#endif // ENEMY_H
