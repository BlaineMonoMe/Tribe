#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>


class Logger
{
    public:
        static void log(char *filename, char *text);
        static void log(char *filename, const char *text);
        static void log(char *filename, int value);
};

#endif // LOGGER_H
