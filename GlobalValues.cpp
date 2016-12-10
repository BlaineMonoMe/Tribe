#include "GlobalValues.h"

int GlobalValues::SCREEN_WIDTH = 1366;
int GlobalValues::SCREEN_HEIGHT = 768;
char *GlobalValues::PROJECT_NAME = "Tribe";
char *GlobalValues::LOCATIONS_DIR = "resources\\locations\\";
char *GlobalValues::ITEMS_DIR_FILE = "\\items\\containers.txt";
char *GlobalValues::OBSTACLES_DIR_FILE = "\\obstacles\\obstacles.txt";
char *GlobalValues::ENEMIES_DIR_FILE = "\\enemies\\enemies.txt";
char *GlobalValues::LOCATION_IMG_FILENAME = "\\img.jpg";
char *GlobalValues::LOCATION_TXT_FILENAME = "\\data.txt";
char *GlobalValues::ABSTRACT_WEAPON_DIR_FILE = "resources\\abstractData\\weapons.txt";
char *GlobalValues::ABSTRACT_ENEMY_DIR_FILE = "resources\\abstractData\\enemies.txt";

float GlobalValues::CELL_HEIGHT = 25.0;
float GlobalValues::CELL_WIDTH = 42.0; // OR 43.3???
int GlobalValues::CELLS_PER_SCREEN_X = SCREEN_WIDTH / CELL_WIDTH;
int GlobalValues::CELLS_PER_SCREEN_Y = SCREEN_HEIGHT / CELL_HEIGHT;

int GlobalValues::SCREEN_EDGE_WIDTH = 20;
int GlobalValues::SCREEN_MOVE_SPEED = 30;
