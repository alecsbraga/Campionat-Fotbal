#include <iostream>
#include "Echipa.h"

Echipa& Echipa::operator=(const Echipa &echipa)
{
    nume_echipa=echipa.nume_echipa;
    nr_partide_castigate=echipa.nr_partide_castigate;
    nr_partide_egale=echipa.nr_partide_egale;
    nr_partide_pierdute=echipa.nr_partide_pierdute;
    return *this;
}

Echipa::~Echipa()
{
    //  cout<<'\n'<<"Gata cu echipa "<<nume_echipa<<'\n';
}

std::ostream& operator<<(std::ostream& out, Echipa& echipa)
{
    out<<echipa.nume_echipa<<" "<<echipa.nr_partide_castigate+echipa.nr_partide_egale+echipa.nr_partide_pierdute<<" "<<echipa.nr_partide_castigate<<" "<<echipa.nr_partide_egale<<" "<<echipa.nr_partide_pierdute<<" "<<echipa.nr_partide_castigate*3+echipa.nr_partide_egale<<'\n';
    return out;
}

std::istream& operator >>(std::istream& in, Echipa& echipa)
{
    in>>echipa.nume_echipa>>echipa.nr_partide_castigate>>echipa.nr_partide_egale>>echipa.nr_partide_pierdute;
    return in;
}

bool Echipa::operator<(Echipa& echipa)
{
    return this->Punctaj()  > echipa.Punctaj();
}
