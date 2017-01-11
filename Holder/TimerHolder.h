#ifndef TIMERHOLDER_H
#define TIMERHOLDER_H

#include <vector>
#include <algorithm>
#include <stdlib.h>

#include "Timer.h"


class TimerHolder
{
    public:
        static TimerHolder getInstance();

        void addTimer(Timer *timer);
        void removeTimer(Timer *timer);
        void updateTimers(int currTime);

    private:
        TimerHolder();

        static TimerHolder instance;

        std::vector<Timer*> *timers = NULL;
};

#endif // TIMERHOLDER_H
