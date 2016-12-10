#include "AbstractWeapon.h"

AbstractWeapon::AbstractWeapon() {}

AbstractWeapon::AbstractWeapon(FileReader *fileReader)
{
    load(fileReader);
}


void AbstractWeapon::load(FileReader *fileReader)
{
    fileReader->readLine(); // delimiter
    fileReader->readLine(); // service data
    type = fileReader->readInt();
    minAttack = fileReader->readInt();
    maxAttack = fileReader->readInt();
    attackRange = fileReader->readInt();
    maxPercission = fileReader->readInt();
    percissionCoef = fileReader->readInt();
    aimCoef = fileReader->readInt();
    power = fileReader->readInt();
    holderMaxSize = fileReader->readInt();
    attackPoints = fileReader->readInt();
    rechargePoints = fileReader->readInt();
    aimPoints = fileReader->readInt();
}

AbstractWeapon::~AbstractWeapon(){}


int AbstractWeapon::getType() {return type;}
float AbstractWeapon::getAimCoef() {return aimCoef;}
int AbstractWeapon::getPower() {return power;}
int AbstractWeapon::getHolderMaxSize() {return holderMaxSize;}
int AbstractWeapon::getRechargePoints() {return rechargePoints;}
int AbstractWeapon::getAimPoints() {return aimPoints;}
