#ifndef ABSTRACTATTACK_H
#define ABSTRACTATTACK_H


class AbstractAttack
{
    public:
        int getMinAttack();
        int getMaxAttack();
        int getAttackRange();
        int getMaxPercission();
        int getPercissionCoef();
        int getAttackPoints();

    protected:
        int minAttack;
        int maxAttack;
        int attackRange;
        int maxPercission;
        int percissionCoef;
        int attackPoints;
};

#endif // ABSTRACTATTACK_H
