#include "Logger.h"

void Logger::log(char* filename, char *text)
{
    std::ofstream datafile;
	datafile.open(filename, std::ofstream::app);
	datafile << text << "\n";
	datafile.close();
}

void Logger::log(char* filename, const char *text)
{
    std::ofstream datafile;
	datafile.open(filename, std::ofstream::app);
	datafile << text << "\n";
	datafile.close();
}

void Logger::log(char* filename, int value)
{
    std::ofstream datafile;
	datafile.open(filename, std::ofstream::app);
	datafile << value << "\n";
	datafile.close();
}
