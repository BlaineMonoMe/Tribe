#include "AbstractCreatureGraphics.h"

AbstractCreatureGraphics::AbstractCreatureGraphics()
{
    //ctor
}

AbstractCreatureGraphics::~AbstractCreatureGraphics()
{
    //dtor
}

int AbstractCreatureGraphics::getStaticOffsetX() {return staticOffsetX;}
int AbstractCreatureGraphics::getStaticOffsetY() {return staticOffsetY;}
int AbstractCreatureGraphics::getAnimationInterval() {return animationInterval;}

void AbstractCreatureGraphics::loadGraphics(char* creatureNumber, SDL_Renderer *renderer)
{
    char infoFile[80] = {0};

    strcat(infoFile, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(infoFile, creatureNumber);
    strcat(infoFile, GlobalValues::INFO_FILE_TXT);
    FileReader *fileReader = new FileReader(infoFile);

    animationInterval = fileReader->readInt();
    staticOffsetX = fileReader->readInt();
    staticOffsetY = fileReader->readInt();

    int standFramesCount = fileReader->readInt();
    int goFramesCount = fileReader->readInt();
    int attackFramesCount = fileReader->readInt();
    int getDamageFramesCount = fileReader->readInt();
    int dieFramesCount = fileReader->readInt();

    delete fileReader;

    // -----

    char imageFilePath[80] = {0};
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\STAND_rightup.png");
    standRightUp = new AnimationData(imageFilePath, standFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\STAND_right.png");
    standRight = new AnimationData(imageFilePath, standFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\STAND_rightdown.png");
    standRightDown = new AnimationData(imageFilePath, standFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\STAND_leftdown.png");
    standLeftDown = new AnimationData(imageFilePath, standFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\STAND_left.png");
    standLeft = new AnimationData(imageFilePath, standFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\STAND_leftup.png");
    standLeftUp = new AnimationData(imageFilePath, standFramesCount, renderer);

    // -----

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\WALK_rightup.png");
    goRightUp = new AnimationData(imageFilePath, goFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\WALK_right.png");
    goRight = new AnimationData(imageFilePath, goFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\WALK_rightdown.png");
    goRightDown = new AnimationData(imageFilePath, goFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\WALK_leftdown.png");
    goLeftDown = new AnimationData(imageFilePath, goFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\WALK_left.png");
    goLeft = new AnimationData(imageFilePath, goFramesCount, renderer);

    imageFilePath[0] = '\0';
    strcat(imageFilePath, GlobalValues::IMAGES_CREATURES_DIR);
    strcat(imageFilePath, creatureNumber);
    strcat(imageFilePath, "\\WALK_leftup.png");
    goLeftUp = new AnimationData(imageFilePath, goFramesCount, renderer);






}

AnimationData* AbstractCreatureGraphics::getAnimationData(State state, Direction direction)
{
    switch (state)
    {
        case STAY:
            switch (direction)
            {
                case RIGHT_UP: return standRightUp; break;
                case RIGHT: return standRight; break;
                case RIGHT_DOWN: return standRightDown; break;
                case LEFT_DOWN: return standLeftDown; break;
                case LEFT: return standLeft; break;
                case LEFT_UP: return standLeftUp; break;
            }
            break;

        case GO:
            switch (direction)
            {
                case RIGHT_UP: return goRightUp; break;
                case RIGHT: return goRight; break;
                case RIGHT_DOWN: return goRightDown; break;
                case LEFT_DOWN: return goLeftDown; break;
                case LEFT: return goLeft; break;
                case LEFT_UP: return goLeftUp; break;
            }
            break;
    }
}
