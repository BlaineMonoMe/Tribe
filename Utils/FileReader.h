#ifndef FILEREADER_H
#define FILEREADER_H

#include <string.h>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Logger.h"



class FileReader
{
    public:
        FileReader(char *filename);
        ~FileReader();
        int readInt();
        float readDouble();
        std::string readLine();

    private:
        std::ifstream myfile;
};

#endif // FILEREADER_H
