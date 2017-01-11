#include "Creature.h"

Creature::Creature(char *creatureNumber, SDL_Renderer *renderer)
{
    init(creatureNumber, renderer);
}

Creature::Creature() {}

Creature::~Creature()
{

}

void Creature::init(char *creatureNumber, SDL_Renderer *renderer)
{
    strcpy(this->creatureNumber, creatureNumber);
    loadGraphics(creatureNumber, renderer);

    creatureMover = new CreatureMover(this, 90);

    setNewAnimationAndStart(STAY, RIGHT);

    TimerHolder::getInstance().addTimer(creatureMover);
}

void Creature::draw(int xPixellScreenOffset, int yPixellScreenOffset)
{

    SDL_Point absolutePixellCoords = CoordsTranformer::cellsToPixels(xCell, yCell);

    int screenPixellCoordX = absolutePixellCoords.x - xPixellScreenOffset;
    int screenPixellCoordY = absolutePixellCoords.y - yPixellScreenOffset;

    int staticPixellCoordX = screenPixellCoordX + staticOffsetX;
    int staticPixellCoordY = screenPixellCoordY + staticOffsetY;

    int intercellPixellCoordX = staticPixellCoordX + currPixellOffsetX;
    int intercellPixellCoordY = staticPixellCoordY + currPixellOffsetY;

    currAnimation->setScreenCoords(intercellPixellCoordX, intercellPixellCoordY);

    currAnimation->draw();

}

int Creature::getCurrPixellOffsetX() {return currPixellOffsetX;}
int Creature::getCurrPixellOffsetY() {return currPixellOffsetY;}
void Creature::setCurrPixellOffsetX(int x) {this->currPixellOffsetX = x;}
void Creature::setCurrPixellOffsetY(int y) {this->currPixellOffsetY = y;}

State Creature::getState() {return state;}
Direction Creature::getDirection() {return direction;}
void Creature::setState(State state) {this->state = state;}
void Creature::setDirection(Direction direction) {this->direction = direction;}


void Creature::setDetstinationAndGo(int destX, int destY, LocationData *locationData)
{
    if(locationData->isFreeToGo(destX, destY))
    {
        creatureMover->generatePath(new Cell(xCell, yCell), new Cell(destX, destY), locationData);
        creatureMover->initMove(new Cell(xCell, yCell));
        creatureMover->start();
        state = GO;
    }
}


void Creature::setNewAnimationAndStart(State state, Direction direction)
{
    this->state = state;
    this->direction = direction;

    currAnimation = new Animation(getAnimationData(state, direction), getAnimationInterval());
    currAnimation->start();
    TimerHolder::getInstance().addTimer(currAnimation);
}

void Creature::setNewAnimationAndStart(State state)
{
    setNewAnimationAndStart(state, direction);
}





