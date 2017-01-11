#ifndef CELL_H
#define CELL_H


class Cell
{
    public:
        Cell();
        Cell(Cell *cell);
        Cell(int x, int y);

        int getX() const;
        int getY() const;

        void setX(int x);
        void setY(int y);

        bool operator==(const Cell &other);

    private:
        int x;
        int y;
};

#endif // CELL_H
