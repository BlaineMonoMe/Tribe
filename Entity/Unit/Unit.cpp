#include "Unit.h"

Unit::Unit() {}

Unit::Unit(int xCell, int yCell)
{
    this->xCell = xCell;
    this->yCell = yCell;
}

Unit::~Unit() {}

int Unit::getXCell() { return xCell; }
void Unit::setXCell(int xCell) { this->xCell = xCell; }
int Unit::getYCell() { return yCell; }
void Unit::setYCell(int yCell) { this->yCell = yCell; }
