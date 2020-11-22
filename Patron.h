#ifndef PATRON_H_INCLUDED
#define PATRON_H_INCLUDED
#include "Echipa.h"
#include <iostream>

class Patron
{
    const std::string nume_patron;
    Echipa echipa;
public:

    void afisare_date();

    Patron(const std::string &nume_patron, Echipa &echipa)
        :nume_patron{nume_patron},
         echipa{echipa}
    {
        afisare_date();
    }

    ~Patron();

};

#endif // PATRON_H_INCLUDED
