#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>


class Timer
{
    public:
        Timer(int interval);

        virtual void execute() = 0;

        bool getIsStarted();
        int getInterval();

        bool isTime(int gameTime);

        void start();
        void stop();

    private:
        int interval;
        bool isStarted;
        int startedTime;

};

#endif // TIMER_H
