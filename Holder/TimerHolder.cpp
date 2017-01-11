#include "TimerHolder.h"

TimerHolder TimerHolder::instance;

TimerHolder TimerHolder::getInstance()
{
    return instance;
}

TimerHolder::TimerHolder()
{
    timers = new std::vector<Timer*>();
}

void TimerHolder::addTimer(Timer *timer)
{
    timers->push_back(timer);
}

void TimerHolder::removeTimer(Timer *timer)
{
    timers->erase(std::remove(timers->begin(), timers->end(), timer), timers->end());
}

void TimerHolder::updateTimers(int currTime)
{
    for(int i = 0; i < timers->size(); i++)
    {
        if(timers->at(i)->getIsStarted() == true)
        {
            if(timers->at(i)->isTime(currTime) == true)
            {
                timers->at(i)->execute();
            }
        }
    }
}
