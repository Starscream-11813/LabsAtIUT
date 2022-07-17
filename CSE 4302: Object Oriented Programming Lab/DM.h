#ifndef DM_H
#define DM_H
//#include"DB.h"

class DM
{
    public:
        DM(float m, float cm);
        ~DM();
        float getmeters();
        float getcentimeters();

    protected:

    private:
        float meters;
        float centimeters;
};

#endif // DM_H
