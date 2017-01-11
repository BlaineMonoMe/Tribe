#include "LocationData.h"

LocationData::LocationData(char* locationNumber)
{

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
    actualMatrix = new int*[cellsInColCount];
	for(int i = 0; i < cellsInColCount; i++)
	{
	    matrix[i] = new int[cellsInRowCount];
	    actualMatrix[i] = new int[cellsInRowCount];
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
            actualMatrix[j][i] = matrix[j][i];
        }
    }

}

LocationData::~LocationData()
{
    for(int i = 0; i < cellsInColCount; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	for(int i = 0; i < cellsInColCount; i++)
	{
		delete[] actualMatrix[i];
	}
	delete[] actualMatrix;
}

int LocationData::getWidth()
{
    return cellsInRowCount;
}

int LocationData::getHeight()
{
    return cellsInColCount;
}

int LocationData::getCell(int x, int y)
{
    return matrix[y][x];
}

bool LocationData::isFreeToGo(int x, int y)
{
    if(x < 0 || y < 0) return false;
    if(x >= cellsInRowCount - 1 || y > cellsInColCount - 1) return false;
    if(actualMatrix[y][x] == 1) return false;
    if(actualMatrix[y][x] == 2) return false;
    return true;
}

void LocationData::reinitActualData()
{
    for(int j = 0; j < cellsInColCount; j++)
    {
        for(int i = 0; i < cellsInRowCount; i++)
        {
            actualMatrix[j][i] = matrix[j][i];
        }
    }
}

void LocationData::setEnemyOnCell(int x, int y)
{
    actualMatrix[y][x] = 2;
}

bool LocationData::isWater(int x, int y)
{
    if(x < 0 || y < 0) return false;
    if(x >= cellsInRowCount - 1 || y > cellsInColCount - 1) return false;
    if(matrix[y][x] == 3) return true;
    return false;
}

bool LocationData::isOtherLocation(int x, int y)
{
    if(x < 0 || y < 0) return false;
    if(x >= cellsInRowCount - 1 || y > cellsInColCount - 1) return false;
    if(matrix[y][x] >= 100) return true;
    return false;
}






