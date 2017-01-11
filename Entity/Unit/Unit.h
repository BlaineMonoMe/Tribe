#ifndef UNIT_H
#define UNIT_H


class Unit
{
    public:
        Unit();
        Unit(int xCell, int yCell);
        ~Unit();

        int getXCell();
        void setXCell(int val);
        int getYCell();
        void setYCell(int val);

        virtual void draw(int xPixellScreenOffset, int yPixelScreenOffset) = 0;


    protected:
        int xCell;
        int yCell;
};

bool unitComp(Unit *unit1, Unit *unit2);


#endif // UNIT_H
