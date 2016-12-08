#include "FileReader.h"

FileReader::FileReader(char *filename)
{
    myfile.open(filename);
}

FileReader::~FileReader()
{
    myfile.close();
    delete myfile;
}


int FileReader::readInt()
{
    return atoi(readLine().c_str());
}

float FileReader::readDouble()
{
    return atof(readLine().c_str());
}

std::string FileReader::readLine()
{
    std::string line;
    std::getline(myfile, line);

    //Logger::log("E:\\C++\\CodeBlocks\\Tribe\\logs\\1.txt", res);
    return line;
}
