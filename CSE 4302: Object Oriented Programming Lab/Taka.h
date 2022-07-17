#ifndef TAKA_H
#define TAKA_H


class Taka
{
    public:
        Taka();
        void setone(int o);
        void settwo(int t);
        void setfive(int f);
        void setten(int te);
        void settwenty(int tw);
        int getTaka();
        bool operator == (Taka tt) const;
        bool operator > (Taka tt) const;
        bool operator < (Taka tt) const;
        Taka operator + (Taka) ;
        Taka operator - (Taka) ;
        Taka operator | (Taka);
        //Taka operator - (Taka) const;
        ~Taka();

    protected:

    private:
        int one;
        int two;
        int five;
        int ten;
        int twenty;
};

#endif // TAKA_H
