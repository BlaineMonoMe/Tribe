#ifndef PATHGENERATOR_H
#define PATHGENERATOR_H

#include <vector>
#include <set>
#include <cstdlib>
#include <algorithm>

#include "Path.h"
#include "Cell.h"
#include "LocationData.h"
#include "../../GlobalValues.h"
#include "Logger.h"
#include "DirectionsSequence.h"

class Node : public Cell
{
    public:
        Node() {}
        Node(int x, int y) : Cell(x, y) {}
        Node(Cell *cell) : Cell(cell) {}

        Node(int x, int y, Node *prev, int g, int h, int f) : Cell(x, y)
        {
            this->g = g;
            this->h = h;
            this->f = f;
            this->prev = prev;
        }

        int g;
        int h;
        int f;
        Node *prev = NULL;
};



class PathGenerator
{
    public:

        static Path* generatePath(Cell *beginCell, Cell* endCell, LocationData *location,
                                  DirectionsSequence *directionsSequence);
        static Path* generatePathAStar(Cell *beginCell, Cell* endCell, LocationData *location,
                                  DirectionsSequence *directionsSequence);

        static Cell* getAdjacentCell(Cell *currCell, Direction direction);
        static std::vector<Cell*>* getAvaliableAdjacentCells(Cell *currCell, LocationData *locationData);

    private:
        static bool isCellInLeftRow(Cell *cell);

        static int getDistance(Node *beginNode, Node *endNode);

        static Direction getDirection(Node *currNode, Node *nextNode);


};

#endif // PATHGENERATOR_H
