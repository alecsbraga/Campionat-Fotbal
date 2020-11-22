#include <iostream>
#include "Patron.h"

void Patron::afisare_date()
{

    std::cout<<"Patron: "<<nume_patron<<" "<<", club: ";
    std::cout<<echipa;

}
Patron::~Patron()
{
    // cout<<"Gata cu patronul "<<nume_patron<<endl;
}
