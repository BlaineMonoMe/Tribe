#ifndef ABSTRACTWEAPON_H
#define ABSTRACTWEAPON_H

#include "AbstractAttack.h"
#include "FileReader.h"


class AbstractWeapon : public AbstractAttack
{
    public:
        AbstractWeapon();
        AbstractWeapon(FileReader *fileReader);
        void load(FileReader *fileReader);
        ~AbstractWeapon();

        int getType();
        float getAimCoef();
        int getPower();
        int getHolderMaxSize();
        int getRechargePoints();
        int getAimPoints();

    private:
        int type;
        float aimCoef;
        int power;
        int holderMaxSize;
        int rechargePoints;
        int aimPoints;
};

#endif // ABSTRACTWEAPON_H
