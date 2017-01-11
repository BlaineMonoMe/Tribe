#include "Randomizer.h"

int Randomizer::getRandom(int from, int to)
{
    //srand(time(0));
    int diapason = to - from + 1;
    return rand() % diapason + from;
}

bool Randomizer::isEvent(int probabitity)
{
    int rand = getRandom(0, 100);
    return rand <= probabitity;
}
