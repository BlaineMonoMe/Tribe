#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>


class Logger
{
    public:
        static void log(char *filename, char *text);
};

#endif // LOGGER_H
