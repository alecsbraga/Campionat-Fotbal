#include <iostream>
#include "Meci.h"

void cine_a_castigat(Echipa &castigatoare, Echipa &pierzatoare, bool remiza)
{
    std::cout<<"In urma meciului dintre " ;
    castigatoare.echipa_nume();
    std::cout<<" si ";
    pierzatoare.echipa_nume();
    if(remiza == false)
    {
        std::cout<<", a castigat ";
        castigatoare.echipa_nume();
    }
    else
    {

        std::cout<<", s-a terminat egal";
    }
    std::cout<<std::endl<<"Datele sunt urmatoarele:"<<std::endl;
    std::cout<<castigatoare;
    std::cout<<pierzatoare;

}

void Meci::joaca(Echipa& echipa_1, Echipa& echipa_2)
 {

        bool remiza;
        int castiga= 1 + (rand() % ( 3 - 1 + 1 ) );
        if(castiga == 1)
        {
            remiza= false;
            echipa_1.a_castigat_un_meci();
            echipa_2.a_pierdut_un_meci();
            cine_a_castigat(echipa_1, echipa_2, remiza);

        }
        else if(castiga == 2)
        {
            remiza= true;
            echipa_1.a_facut_egal();
            echipa_2.a_facut_egal();
            cine_a_castigat(echipa_1, echipa_2, remiza);

        }
        else
        {
            remiza= false;
            echipa_2.a_castigat_un_meci();
            echipa_1.a_pierdut_un_meci();
            cine_a_castigat(echipa_2, echipa_1, remiza);

        }

    }
    Meci::~Meci()
{

}
