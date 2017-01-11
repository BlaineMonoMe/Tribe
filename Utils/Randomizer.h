#ifndef RANDOMIZER_H
#define RANDOMIZER_H

#include <cstdlib>
#include <ctime>


class Randomizer
{
    public:
        static int getRandom(int from, int to);
        static bool isEvent(int probability);
};

#endif // PROBABILITYEVENTVENDOR_H
