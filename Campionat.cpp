#include <iostream>
#include "Campionat.h"

void Campionat::joaca()
{
    int i,j;
    for(i=0; i<8; ++i)
        for(j=0; j<8; ++j)
            if(i!=j)
            {
                Meci::joaca(campionat_list[i],campionat_list[j]);
                std::cout<<std::endl;
            }

}

void Campionat::cine_a_castigat()
{
    std::cout<<"Echipa castigatoare este ";
    campionat_list[0].echipa_nume();
}

std::istream& operator >> (std::istream& in, Campionat& campionat)
{
    in>>campionat.nume_campionat;
    Echipa echipa;
    for(int i=0; i<8; ++i)
    {
        in>>echipa;
        campionat.campionat_list.push_back(echipa);
    }
    return in;
}

std::ostream& operator <<(std::ostream& out, Campionat& campionat)
{
    out<<campionat.nume_campionat<<std::endl;
    for(unsigned int i=0; i<campionat.campionat_list.size(); ++i)
        out<<i+1<<". "<<campionat.campionat_list[i];
    return out;
}

Campionat::~Campionat()
{

}
