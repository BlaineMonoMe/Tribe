#include "PathGenerator.h"

bool nodeComp(const Node &one, const Node &two)
{
    if(one.f < two.f) return true;
    /*if(one.f == two.f)
    {
        if(one.h > two.h) return true;
        return false;
    }*/
    return false;
}

Path* PathGenerator::generatePathAStar(Cell *beginCell, Cell* endCell,
                                  LocationData *locationData, DirectionsSequence *directionsSequence)
{
    //std::set<Node, NodeComparator> *openSet = new std::set<Node, NodeComparator>();
    //std::set<Node, NodeComparator> *closedSet = new std::set<Node, NodeComparator>();

    std::vector<Node*> *openSet = new std::vector<Node*>();
    std::vector<Node*> *closedSet = new std::vector<Node*>();


    Node *beginNode = new Node(beginCell);
    beginNode->g = 0;
    beginNode->h = getDistance(beginNode, new Node(endCell));
    beginNode->f = beginNode->g + beginNode->h;

    Node *endNode = new Node(endCell);

    openSet->push_back(beginNode);

    while(true)
    {

        /// getting node with min F
        Node *currNode = openSet->at(0);
        int currNodeIndex = 0;

        for (int j = 1; j < openSet->size(); j++)
        {
            if(openSet->at(j)->f <= currNode->f)
            {
                currNode = openSet->at(j);
                currNodeIndex = j;
            }

            if(openSet->at(j)->h == currNode->f)
            {
                if(openSet->at(j)->h <= currNode->h)
                {
                    currNode = openSet->at(j);
                    currNodeIndex = j;
                }
            }
        }

        Node *node = openSet->at(currNodeIndex);

        openSet->erase(openSet->begin() + currNodeIndex);
        closedSet->push_back(node);


        /// if curr node is dest node
        if(node->getX() == endNode->getX() && node->getY() == endNode->getY())
        {
            std::vector<Node*> *path = new std::vector<Node*>();

            Node *curr = node;

            while(curr != NULL)
            {
                path->push_back(curr);
                curr = curr->prev;
            }

            for(int i = path->size() - 1; i > 0; --i)
            {
                Direction direction = getDirection(path->at(i), path->at(i - 1));
                directionsSequence->addDirection(direction);
            }
            directionsSequence->addDirection(NONE);

            return NULL; ///TODO - return path;
        }

        std::vector<Cell*> *neighbours = getAvaliableAdjacentCells(new Cell(node->getX(), node->getY()), locationData);


        Node *neigh = new Node[neighbours->size()];
        for(int j = 0; j < neighbours->size(); j++)
        {
            neigh[j] = Node(neighbours->at(j));
        }

        /// iterating through neiggbours
        for(int j = 0; j < neighbours->size(); j++)
        {
            bool contain = false;
            for(int z = 0; z < closedSet->size(); ++z)
            {
                if(neigh[j].getX() == closedSet->at(z)->getX() &&
                   neigh[j].getY() == closedSet->at(z)->getY())
                        contain = true;
            }
            if(contain) continue;

            bool inOpen = false;
            for(int z = 0; z < openSet->size(); ++z)
            {
                if(neigh[j].getX() == openSet->at(z)->getX() &&
                   neigh[j].getY() == openSet->at(z)->getY())
                   inOpen = true;
            }

            if(!inOpen || neigh[j].g > node->g + 1)
            {
                neigh[j].g = node->g + 1;
                neigh[j].h = getDistance(&neigh[j], endNode);
                neigh[j].f = neigh[j].g + neigh[j].h;
                neigh[j].prev = node;
            }


            if(!inOpen)
            {
                openSet->push_back(&neigh[j]);
            }
        }
    }

    /// free memory
    delete openSet;
    delete closedSet;

}


Path* PathGenerator::generatePath(Cell *beginCell, Cell* endCell,
                                  LocationData *locationData, DirectionsSequence *directionsSequence)
{
    Path *path = new Path();
    Cell *currCell = beginCell;
    Direction direction;


    do {
        // simple diagonals
        if(currCell->getX() < endCell->getX() && currCell->getY() < endCell->getY())
        {
            direction = RIGHT_DOWN;
            Cell *nextCell = PathGenerator::getAdjacentCell(currCell, RIGHT_DOWN);
            if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                directionsSequence->addDirection(direction);
        }
        if(currCell->getX() > endCell->getX() && currCell->getY() > endCell->getY())
        {
            direction = LEFT_UP;
            Cell *nextCell = PathGenerator::getAdjacentCell(currCell, LEFT_UP);
            if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                directionsSequence->addDirection(direction);
        }
        if(currCell->getX() > endCell->getX() && currCell->getY() < endCell->getY())
        {
            direction = LEFT_DOWN;
            Cell *nextCell = PathGenerator::getAdjacentCell(currCell, LEFT_DOWN);
            if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                directionsSequence->addDirection(direction);
        }
        if(currCell->getX() < endCell->getX() && currCell->getY() > endCell->getY())
        {
            direction = RIGHT_UP;
            Cell *nextCell = PathGenerator::getAdjacentCell(currCell, RIGHT_UP);
            if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                directionsSequence->addDirection(direction);
        }

        // simple straight
        if(currCell->getX() < endCell->getX() && currCell->getY() == endCell->getY())
        {
            direction = RIGHT;
            Cell *nextCell = PathGenerator::getAdjacentCell(currCell, RIGHT);
            if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                directionsSequence->addDirection(direction);
        }
        if(currCell->getX() > endCell->getX() && currCell->getY() == endCell->getY())
        {
            direction = LEFT;
            Cell *nextCell = PathGenerator::getAdjacentCell(currCell, LEFT);
            if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                directionsSequence->addDirection(direction);
        }

        // complex diagonal
        if(currCell->getX() == endCell->getX() && currCell->getY() > endCell->getY())
        {
            if(isCellInLeftRow(currCell))
            {
                direction = RIGHT_UP;
                Cell *nextCell = PathGenerator::getAdjacentCell(currCell, RIGHT_UP);
                if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                    directionsSequence->addDirection(direction);
            }
            else
            {
                direction = LEFT_UP;
                Cell *nextCell = PathGenerator::getAdjacentCell(currCell, LEFT_UP);
                if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                    directionsSequence->addDirection(direction);
            }


        }

        if(currCell->getX() == endCell->getX() && currCell->getY() < endCell->getY())
        {
            if(isCellInLeftRow(currCell))
            {
                direction = RIGHT_DOWN;
                Cell *nextCell = PathGenerator::getAdjacentCell(currCell, RIGHT_DOWN);
                if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                    directionsSequence->addDirection(direction);
            }

            else
            {
                direction = LEFT_DOWN;
                Cell *nextCell = PathGenerator::getAdjacentCell(currCell, LEFT_DOWN);
                if(locationData->isFreeToGo(nextCell->getX(), nextCell->getY()))
                    directionsSequence->addDirection(direction);
            }
        }

        if(currCell->getX() == endCell->getX() && currCell->getY() == endCell->getY())
        {
            path->addCell(endCell);
            break;
        }

        Cell *nextCell = getAdjacentCell(currCell, direction);

        if(locationData->getCell(nextCell->getX(), nextCell->getY()) > 0 &&
                    locationData->getCell(nextCell->getX(), nextCell->getY()) < 100)
        {
            break;
        }

        path->addCell(nextCell);
        currCell = nextCell;

    } while(true);

    directionsSequence->addDirection(NONE);

    return path;
}

std::vector<Cell*>* PathGenerator::getAvaliableAdjacentCells(Cell *currCell, LocationData *locationData)
{
    std::vector<Cell*> *res = new std::vector<Cell*>();

    Cell *cell = getAdjacentCell(currCell, RIGHT_UP);
    if(cell->getX() >= 0 && cell->getX() < locationData->getWidth()
       && cell->getY() >= 0 && cell->getY() < locationData->getHeight()
       && locationData->isFreeToGo(cell->getX(), cell->getY()))
    {
        res->push_back(cell);
    }

    cell = getAdjacentCell(currCell, RIGHT);
    if(cell->getX() >= 0 && cell->getX() < locationData->getWidth()
       && cell->getY() >= 0 && cell->getY() < locationData->getHeight()
       && locationData->isFreeToGo(cell->getX(), cell->getY()))
    {
        res->push_back(cell);
    }

    cell = getAdjacentCell(currCell, RIGHT_DOWN);
    if(cell->getX() >= 0 && cell->getX() < locationData->getWidth()
       && cell->getY() >= 0 && cell->getY() < locationData->getHeight()
       && locationData->isFreeToGo(cell->getX(), cell->getY()))
    {
        res->push_back(cell);
    }

    cell = getAdjacentCell(currCell, LEFT_DOWN);
    if(cell->getX() >= 0 && cell->getX() < locationData->getWidth()
       && cell->getY() >= 0 && cell->getY() < locationData->getHeight()
       && locationData->isFreeToGo(cell->getX(), cell->getY()))
    {
        res->push_back(cell);
    }

    cell = getAdjacentCell(currCell, LEFT);
    if(cell->getX() >= 0 && cell->getX() < locationData->getWidth()
       && cell->getY() >= 0 && cell->getY() < locationData->getHeight()
       && locationData->isFreeToGo(cell->getX(), cell->getY()))
    {
        res->push_back(cell);
    }

    cell = getAdjacentCell(currCell, LEFT_UP);
    if(cell->getX() >= 0 && cell->getX() < locationData->getWidth()
       && cell->getY() >= 0 && cell->getY() < locationData->getHeight()
       && locationData->isFreeToGo(cell->getX(), cell->getY()))
    {
        res->push_back(cell);
    }

    return res;
}

Cell* PathGenerator::getAdjacentCell(Cell *currCell, Direction direction)
{
    Cell *result = new Cell();
    bool isCurrCellInLeftRow = false;

    if(currCell->getY() % 2 == 0)
    {
        isCurrCellInLeftRow = true;
    }

    switch (direction)
    {
        case RIGHT:
            result->setX(currCell->getX() + 1);
            result->setY(currCell->getY());
            break;
        case LEFT:
            result->setX(currCell->getX() - 1);
            result->setY(currCell->getY());
            break;
        case RIGHT_UP:
            if(isCurrCellInLeftRow)
                result->setX(currCell->getX());
            else
                result->setX(currCell->getX() + 1);

            result->setY(currCell->getY() - 1);
            break;
        case RIGHT_DOWN:
            if(isCurrCellInLeftRow)
                result->setX(currCell->getX());
            else
                result->setX(currCell->getX() + 1);

            result->setY(currCell->getY() + 1);
            break;
        case LEFT_UP:
            if(isCurrCellInLeftRow)
                result->setX(currCell->getX() - 1);
            else
                result->setX(currCell->getX());

            result->setY(currCell->getY() - 1);
            break;
        case LEFT_DOWN:
            if(isCurrCellInLeftRow)
                result->setX(currCell->getX() - 1);
            else
                result->setX(currCell->getX());

            result->setY(currCell->getY() + 1);
            break;
    }

    return result;
}

Direction PathGenerator::getDirection(Node *currCell, Node *nextCell)
{

    if(currCell->getX() < nextCell->getX() && currCell->getY() == nextCell->getY())
        return RIGHT;

    if(currCell->getX() > nextCell->getX() && currCell->getY() == nextCell->getY())
        return LEFT;

    Cell *cell = new Cell(currCell->getX(), currCell->getY());
    if(isCellInLeftRow(cell))
    {
        if(currCell->getX() > nextCell->getX() && currCell->getY() > nextCell->getY())
            return LEFT_UP;

        if(currCell->getX() > nextCell->getX() && currCell->getY() < nextCell->getY())
            return LEFT_DOWN;

        if(currCell->getX() == nextCell->getX() && currCell->getY() > nextCell->getY())
            return RIGHT_UP;

        if(currCell->getX() == nextCell->getX() && currCell->getY() < nextCell->getY())
            return RIGHT_DOWN;
    }
    else
    {
        if(currCell->getX() == nextCell->getX() && currCell->getY() > nextCell->getY())
            return LEFT_UP;

        if(currCell->getX() == nextCell->getX() && currCell->getY() < nextCell->getY())
            return LEFT_DOWN;

        if(currCell->getX() < nextCell->getX() && currCell->getY() > nextCell->getY())
            return RIGHT_UP;

        if(currCell->getX() < nextCell->getX() && currCell->getY() < nextCell->getY())
            return RIGHT_DOWN;
    }
    return RIGHT;
}

bool PathGenerator::isCellInLeftRow(Cell *cell)
{
    bool isCellInLeftRow = false;

    if(cell->getY() % 2 == 0)
    {
        isCellInLeftRow = true;
    }

    return isCellInLeftRow;
}

int PathGenerator::getDistance(Node *beginNode, Node *endNode)
{
    int x1 = beginNode->getX() - (beginNode->getY() - (beginNode->getY() & 1)) / 2;
    int z1 = beginNode->getY();
    int y1 = -x1 - z1;;

    int x2 = endNode->getX() - (endNode->getY() - (endNode->getY() & 1)) / 2;
    int z2 = endNode->getY();
    int y2 = -x2 - z2;

    return (abs(x1 - x2) + abs(y1 - y2) + abs(z1 - z2)) / 2;

}





