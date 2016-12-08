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

        virtual void draw() = 0;


    protected:
        int xCell;
        int yCell;
};

#endif // UNIT_H
