#ifndef SQUARE_H
#define SQUARE_H


class Square
{
    public:
        Square();
        void setside(float val);
        float getside();
        Square(float s);
        float perimeter();
        float diagonal();
        float area();
        Square operator ++ ();
        Square operator ++ (int);
        Square operator -- ();
        Square operator -- (int);
        Square operator + (Square) const;
        Square operator - (Square) const;
        bool operator == (Square sq) const;
        bool operator > (Square sq) const;
        bool operator < (Square sq) const;
        ~Square();

    protected:

    private:
        float side;
        //bool flag=true;
};

#endif // SQUARE_H
