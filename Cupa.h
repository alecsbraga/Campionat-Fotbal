#ifndef CUPA_H_INCLUDED
#define CUPA_H_INCLUDED
#include "Echipa.h"
#include "Campionat.h"
#include <iostream>
#include <vector>
#include "CupaRomaniei.h"

template <class T>
class Cupa
{

    std::vector <Echipa> cupa_lista;
    int nr_echipe ;
    std::string nume_campionat;
    T cupa;
public:

    void data_jucata()
    {
        std::cout<<"Meciurile au fost jucate pe data de ";
        cupa.data_afis();
    }

    void joaca();

    void afisare_nr_echipe()
    {
        std::cout<<nr_echipe;
    }

    void afisare_nume_campionat()
    {
        std::cout<<nume_campionat;
    }

    template<class U> friend std::istream& operator>>(std::istream& in, Cupa<U>& c);

    template<class U> friend std::ostream& operator<<(std::ostream& out, Cupa<U>& c);


};

template <class T>void afisare(T cupa)
{
    std::cout<<std::endl<<"Numarul total de echipe care au participat la ";
    cupa.afisare_nume_campionat();
    std::cout<<" a fost: ";
    cupa.afisare_nr_echipe();
    std::cout<<std::endl;
}

template<class T>
void Cupa<T>::joaca()
{
    int numar_echipe=nr_echipe;
    while(numar_echipe >1)
        for(unsigned int i=0; i<cupa_lista.size(); i=i+2)
        {
            int r=1 + (rand() % ( 2 - 1 + 1 ) );
            std::cout<<"Castigatorul dintre ";
            cupa_lista[i].echipa_nume();
            std::cout<<" si ";
            cupa_lista[i+1].echipa_nume();
            std::cout<<" este: "<<std::endl;
            if(r==1)
            {
                cupa_lista[i+1].echipa_nume();
                std::cout<<std::endl;
                cupa_lista.erase(cupa_lista.begin()+i);


            }
            else
            {
                cupa_lista[i].echipa_nume();
                std::cout<<std::endl;
                cupa_lista.erase(cupa_lista.begin()+i+1);


            }
            std::cout<<std::endl;
            --numar_echipe;

        }


}

template<class T>
std::istream& operator>>(std::istream& in, Cupa<T>&  c)
{

    in>>c.nr_echipe;
    in>>c.nume_campionat;
    Echipa echipa;
    for(int i=0; i<c.nr_echipe; ++i)
    {
        in>>echipa;
        c.cupa_lista.push_back(echipa);
    }
    return in;
}

template<class T>
std::ostream& operator<<(std::ostream& out,Cupa<T>& c)
{
    out<<"Castigatoarea "<<c.nume_campionat<<" este ";
    c.cupa_lista[0].echipa_nume();
    return out;
}

#endif // CUPA_H_INCLUDED
