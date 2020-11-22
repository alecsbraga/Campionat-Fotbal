#ifndef STADION_H_INCLUDED
#define STADION_H_INCLUDED
#include "Echipa.h"
#include <iostream>

class Stadion
{
    const std::string nume_stadion;
    Echipa echipa;

public:
    void afisare_date();

    Stadion(const std::string &nume_stadion, Echipa &echipa)
        :nume_stadion{nume_stadion},
         echipa{echipa}
    {
        afisare_date();
    }

    ~Stadion();

};

#endif // STADION_H_INCLUDED
