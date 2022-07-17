#ifndef DB_H
#define DB_H
#include "DM.h"
#include "DB.h"
class DB
{
    public:
        DB(float ft, float in);
        ~DB();

        float getfeet();
        float getinches();
        void add_dist(DM other);
        DB add_dist_ret(DM other);


    protected:

    private:
        float feet;
        float inches;
};

#endif // DB_H
