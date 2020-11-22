#ifndef MECI_H_INCLUDED
#define MECI_H_INCLUDED
#include <iostream>
#include "Echipa.h"
#include <cstdlib>

class Meci
{
    Echipa echipa_1;
    Echipa echipa_2;
public:
    void joaca(Echipa& echipa_1, Echipa& echipa_2);

    ~Meci();
};

#endif // MECI_H_INCLUDED
