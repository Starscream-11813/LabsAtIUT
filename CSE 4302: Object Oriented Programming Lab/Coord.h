#ifndef COORD_H
#define COORD_H


class Coord
{
    public:
        Coord();
        Coord(double i, double j);
        ~Coord();
        void setCoordInPolar(double distance, double angleInDegree);
        double getx();
        double gety();
        int getQuadrants();
        double distance(const Coord other);

    protected:

    private:
        double x;
        double y;
};

#endif // COORD_H
