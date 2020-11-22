#include <iostream>
#include "Stadion.h"


void Stadion::afisare_date()
{
    std::cout<<"Stadion: "<<nume_stadion<<" Gazda: "<<echipa<<std::endl;

}

Stadion::~Stadion()
{
    // cout<<"Gata cu stadionul " << nume_stadion;
}
