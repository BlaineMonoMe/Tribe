#ifndef AMMUNITIONITEM_H
#define AMMUNITIONITEM_H


class AmmunitionItem
{
    public:
        AmmunitionItem();
        AmmunitionItem(int ammCount, int weponType);
        ~AmmunitionItem();

    int ammCount;
    int weaponType;
};

#endif // AMMUNITIONITEM_H
