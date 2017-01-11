#include "Path.h"

Path::Path()
{
    cellsSequence = new std::vector<Cell*>();
}

Path::~Path()
{
    if(cellsSequence->size() > 0)
    {
        for(int i = 0; i < cellsSequence->size(); i++)
        {
            delete cellsSequence->at(i);
        }
    }

    delete cellsSequence;
}

void Path::addCell(Cell *cell)
{
    cellsSequence->push_back(new Cell(cell->getX(), cell->getY()));
}

Cell* Path::takeCell()
{
    if(cellsSequence->empty() == false)
    {
        Cell *cellToReturn = cellsSequence->at(0);
        cellsSequence->erase(cellsSequence->begin());
        return cellToReturn;
    }
    return NULL;
}

bool Path::isEmpty()
{
    cellsSequence->empty();
}
