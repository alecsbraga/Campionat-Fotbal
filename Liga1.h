#ifndef LIGA1_H_INCLUDED
#define LIGA1_H_INCLUDED
#include "Campionat.h"

class Liga1:public Campionat
{
private:
    Liga1()= default;
    static Liga1* liga1;
public:
    Liga1(const Liga1&)= delete;
    Liga1& operator =(const Liga1&) =delete;
    static Liga1* get_liga1()
    {
        if(liga1 == nullptr)
            { liga1 = new Liga1; }
            return liga1;
    }
};

Liga1* Liga1::liga1 = nullptr;


#endif // LIGA1_H_INCLUDED
