#include "Cell.h"

Cell::Cell()
{
    //ctor
}

Cell::Cell(Cell *cell)
{
    this->x = cell->x;
    this->y = cell->y;
}

Cell::Cell(int x, int y)
{
    this->x = x;
    this->y = y;
}

bool Cell::operator==(const Cell &other) {

    if(x == other.x && y == other.y)
    {
        return true;
    }

    return false;
}

int Cell::getX() const {return x;}
int Cell::getY() const {return y;}
void Cell::setX(int x) {this->x = x;}
void Cell::setY(int y) {this->y = y;}
