#include "GlobalValues.h"

int GlobalValues::SCREEN_WIDTH = 1366;
int GlobalValues::SCREEN_HEIGHT = 768;
char *GlobalValues::PROJECT_NAME = "Tribe";
char *GlobalValues::LOCATIONS_DIR = "resources\\locations\\";
char *GlobalValues::LOCATION_IMG_FILENAME = "\\img.jpg";
char *GlobalValues::LOCATION_TXT_FILENAME = "\\data.txt";

float GlobalValues::CELL_HEIGHT = 25.0;
float GlobalValues::CELL_WIDTH = 42.0; // OR 43.3???
int GlobalValues::CELLS_PER_SCREEN_X = SCREEN_WIDTH / CELL_WIDTH;
int GlobalValues::CELLS_PER_SCREEN_Y = SCREEN_HEIGHT / CELL_HEIGHT;
