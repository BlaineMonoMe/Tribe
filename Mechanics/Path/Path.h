#ifndef PATH_H
#define PATH_H

#include <vector>
#include <stdlib.h>

#include "Cell.h"
#include "../../GlobalValues.h"


class Path
{
    public:
        Path();
        ~Path();

        void addCell(Cell *cell);
        Cell* takeCell();
        bool isEmpty();

    private:
        std::vector<Cell*> *cellsSequence = NULL;
};

#endif // PATH_H
