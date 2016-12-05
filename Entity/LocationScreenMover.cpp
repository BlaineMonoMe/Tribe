#include "LocationScreenMover.h"

LocationScreenMover::LocationScreenMover(LocationScreen *locationScreen, int interval): Timer(interval)
{
    this->locationScreen = locationScreen;
}

LocationScreenMover::~LocationScreenMover() {}

void LocationScreenMover::setDirection(Direction direction)
{
    this->direction = direction;
}

void LocationScreenMover::checkNeedToMove(int cursorX, int cursorY)
{
    bool isNeedToMove = false;

    bool isDirectionUp = false;
    bool isDirectionRight = false;
    bool isDirectionDown = false;
    bool isDirectionLeft = false;

    if(cursorX < GlobalValues::SCREEN_EDGE_WIDTH)
    {
        isDirectionLeft = true;
        isNeedToMove = true;
    }
    if(cursorX > GlobalValues::SCREEN_WIDTH - GlobalValues::SCREEN_EDGE_WIDTH)
    {
        isDirectionRight = true;
        isNeedToMove = true;
    }
    if(cursorY < GlobalValues::SCREEN_EDGE_WIDTH)
    {
        isDirectionUp = true;
        isNeedToMove = true;
    }
    if(cursorY > GlobalValues::SCREEN_HEIGHT - GlobalValues::SCREEN_EDGE_WIDTH)
    {
        isDirectionDown = true;
        isNeedToMove = true;
    }

    if(isDirectionLeft)
    {
        direction = LEFT;
    }
    if(isDirectionRight)
    {
        direction = RIGHT;
    }
    if(isDirectionUp)
    {
        direction = UP;
        if(isDirectionLeft) direction = LEFT_UP;
        if(isDirectionRight) direction = RIGHT_UP;
    }
    if(isDirectionDown)
    {
        direction = DOWN;
        if(isDirectionLeft) direction = LEFT_DOWN;
        if(isDirectionRight) direction = RIGHT_DOWN;
    }

    if(isNeedToMove == true)
    {
        if(getIsStarted() == false)
        {
            start();
        }
    }
    else
    {
        stop();
    }

}

void LocationScreenMover::execute()
{
    locationScreen->move(direction, GlobalValues::SCREEN_MOVE_SPEED);
    locationScreen->draw();
}
