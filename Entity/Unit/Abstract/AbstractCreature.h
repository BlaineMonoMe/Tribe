#ifndef ABSTRACTCREATURE_H
#define ABSTRACTCREATURE_H


class AbstractCreature
{
    public:
        int getMaxLife();
        int getResistance();
        int getStrength();
        int getNonBattleSpeed();
        int getPointsPerTurn();
        int getMovePoints();

    protected:
        int maxLife;
        int resistance;
        int strength;
        int nonBattleSpeed;
        int pointsPerTurn;
        int movePoints;
};

#endif // ABSTRACTCREATURE_H
