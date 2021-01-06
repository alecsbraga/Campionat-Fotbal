#ifndef LIGA2_H_INCLUDED
#define LIGA2_H_INCLUDED
#include "Campionat.h"

class Liga2:public Campionat
{
private:
    Liga2()= default;
    static Liga2* liga2;
public:
    Liga2(const Liga2&)= delete;
    Liga2& operator =(const Liga2&) = delete;
    static Liga2* get_liga2()
    {
        if(liga2 == nullptr)
            { liga2 = new Liga2; }
            return liga2;
    }
};

Liga2* Liga2::liga2 = nullptr;


#endif // LIGA2_H_INCLUDED
