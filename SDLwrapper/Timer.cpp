#include "Timer.h"

Timer::Timer(int interval)
{
    this->interval = interval;
    this->isStarted = false;
    this->startedTime = 0;
}

bool Timer::getIsStarted()
{
    return isStarted;
}

int Timer::getInterval()
{
    return interval;
}

void Timer::start()
{
    startedTime = SDL_GetTicks();
    execute();
    isStarted = true;
}

void Timer::stop()
{
    isStarted = false;
}

bool Timer::isTime(int gameTime)
{
    if(startedTime + interval <= gameTime)
    {
        startedTime = gameTime;
        return true;
    }
    return false;
}
