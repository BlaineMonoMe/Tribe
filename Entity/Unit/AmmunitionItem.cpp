#include "AmmunitionItem.h"

AmmunitionItem::AmmunitionItem() {}

AmmunitionItem::AmmunitionItem(int ammCount, int weaponType)
{
    this->ammCount = ammCount;
    this->weaponType = weaponType;
}

AmmunitionItem::~AmmunitionItem() {}
