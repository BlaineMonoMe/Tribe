#include "CoordsTranformer.h"

SDL_Point CoordsTranformer::pixelsToCells(int pixelX, int pixelY)
{

	bool isLeftRow = false;

	int colNumber = 0;
	int rowNumber = pixelY / (GlobalValues::CELL_HEIGHT / 2);
	if(rowNumber % 3 == 2){isLeftRow = false;}else{isLeftRow = true;}

	rowNumber = pixelY / (GlobalValues::CELL_HEIGHT * 1.5);
	rowNumber *= 2;
	if(!isLeftRow) ++rowNumber;

	if(isLeftRow)
	{
		colNumber = pixelX / GlobalValues::CELL_WIDTH;
	} else
	{
		colNumber = (pixelX + GlobalValues::CELL_WIDTH / 2) / GlobalValues::CELL_WIDTH - 1;
	}

	if(isLeftRow)
	{
		//---- getting coords of the center of the current cell ----
		int centerX = GlobalValues::CELL_WIDTH / 2 + GlobalValues::CELL_WIDTH * colNumber;
		int centerY = rowNumber / 2 * 1.5 * GlobalValues::CELL_HEIGHT + 0.5 * GlobalValues::CELL_HEIGHT;

		//---- calc if wrong cell is current ----
        //TODO: in future, try to move this all block to seperate functions

        if(pixelY < centerY - GlobalValues::CELL_HEIGHT / 4)
        {
            int topLeftCellXCenter = centerX - GlobalValues::CELL_WIDTH / 2;
            int topLeftCellYCenter = centerY - GlobalValues::CELL_HEIGHT / 1.5;
            double distToCurrCellCenter = getDistBetwPoints(pixelX, pixelY, centerX, centerY);
			double distToAnotherCellCenter = getDistBetwPoints(pixelX, pixelY, topLeftCellXCenter, topLeftCellYCenter);
			if(distToAnotherCellCenter < distToCurrCellCenter) {
				--rowNumber;
				--colNumber;
			}

            topLeftCellXCenter = centerX + GlobalValues::CELL_WIDTH / 2;
			topLeftCellYCenter = centerY - GlobalValues::CELL_HEIGHT / 1.5;
			distToCurrCellCenter = getDistBetwPoints(pixelX, pixelY, centerX, centerY);
			distToAnotherCellCenter = getDistBetwPoints(pixelX, pixelY, topLeftCellXCenter, topLeftCellYCenter);
			if(distToAnotherCellCenter < distToCurrCellCenter) {
				--rowNumber;
			}
        }

        if(pixelY > centerY + GlobalValues::CELL_HEIGHT / 4)
        {
			int topLeftCellXCenter = centerX - GlobalValues::CELL_WIDTH / 2;
			int topLeftCellYCenter = centerY + GlobalValues::CELL_HEIGHT / 1.5;
			double distToCurrCellCenter = getDistBetwPoints(pixelX, pixelY, centerX, centerY);
			double distToAnotherCellCenter = getDistBetwPoints(pixelX, pixelY, topLeftCellXCenter, topLeftCellYCenter);
			if(distToAnotherCellCenter < distToCurrCellCenter) {
				++rowNumber;
				--colNumber;
			}

			topLeftCellXCenter = centerX + GlobalValues::CELL_WIDTH / 2;
			topLeftCellYCenter = centerY + GlobalValues::CELL_HEIGHT / 1.5;
			distToCurrCellCenter = getDistBetwPoints(pixelX, pixelY, centerX, centerY);
			distToAnotherCellCenter = getDistBetwPoints(pixelX, pixelY, topLeftCellXCenter, topLeftCellYCenter);
			if(distToAnotherCellCenter < distToCurrCellCenter) {
				++rowNumber;
			}
        }
	}

	SDL_Point result;
	result.x = colNumber;
	result.y = rowNumber;

	return result;
}

SDL_Point CoordsTranformer::cellsToPixels(int cellX, int cellY)
{
    SDL_Point result;

    if(cellY % 2 == 0)
    {
        result.x = GlobalValues::CELL_WIDTH / 2 + GlobalValues::CELL_WIDTH * cellX;
        result.y = GlobalValues::CELL_HEIGHT / 2 + 1.5 * GlobalValues::CELL_HEIGHT / 2 * cellY;
    }
    else
    {
        result.x = GlobalValues::CELL_WIDTH + GlobalValues::CELL_WIDTH * cellX;
        result.y = GlobalValues::CELL_HEIGHT / 2 + 1.5 * GlobalValues::CELL_HEIGHT / 2 * cellY;
    }

    return result;
}

double CoordsTranformer::getDistBetwPoints(int x1, int y1, int x2, int y2)
{
	return sqrt(double((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
}
