#include "Location.h"

Location::Location(char* locationNumber)
{
    strcpy(this->locationNumber, locationNumber);

    char dataFilePath[80] = {0};
    strcat(dataFilePath, GlobalValues::LOCATIONS_DIR);
    strcat(dataFilePath, locationNumber);
    strcat(dataFilePath, GlobalValues::LOCATION_TXT_FILENAME);

    std::string line;
    std::ifstream myfile(dataFilePath);

    std::getline(myfile, line);
    cellsInRowCount = atoi(line.c_str());

    std::getline(myfile, line);
    cellsInColCount = atoi(line.c_str());

    matrix = new int*[cellsInColCount];
	for(int i = 0; i < cellsInColCount; i++)
	{
	    matrix[i] = new int[cellsInRowCount];
	}


    for(int j = 0; j < cellsInColCount; j++)
    {
        std::getline(myfile, line);
        std::istringstream f(line);
        std::string subline;

        for(int i = 0; i < cellsInRowCount; i++)
        {
            std::getline(f, subline, ' ');
            matrix[j][i] = atoi(subline.c_str());
        }
    }

}

Location::~Location()
{
    for(int i = 0; i < cellsInColCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int Location::getWidth()
{
    return cellsInRowCount;
}

int Location::getHeight()
{
    return cellsInColCount;
}

int Location::getCell(int x, int y)
{
    return matrix[y][x];
}






