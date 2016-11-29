#include "Logger.h"

void Logger::log(char* filename, char *text)
{
    std::ofstream datafile;
	datafile.open(filename, std::ofstream::app);
	datafile << text << "\n";
	datafile.close();
}
