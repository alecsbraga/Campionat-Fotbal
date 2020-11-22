#include <iostream>
#include "Campionat.h"

void Campionat::meciuri()
{
    int i,j;
    for(i=0; i<8; ++i)
        for(j=0; j<8; ++j)
            if(i!=j)
                joaca(campionat_list[i],campionat_list[j]);

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
    for(int i=0; i<campionat.campionat_list.size(); ++i)
        out<<i+1<<". "<<campionat.campionat_list[i];
    return out;
}
