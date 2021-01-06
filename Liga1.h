#ifndef LIGA1_H_INCLUDED
#define LIGA1_H_INCLUDED
#include "Campionat.h"
#include "Meci.h"

class Liga1:public Campionat
{
private:
    Liga1()= default;
    static Liga1* liga1;

public:
    Liga1(const Liga1&)= delete;
    Liga1& operator =(const Liga1&) = delete;
    void joaca()
    {

        Meci m;
        int i,j;
        for(i=0; i<echipe; ++i)
            for(j=0; j<echipe; ++j)
                if(i!=j)
                {
                    m.joaca(campionat_list[i],campionat_list[j]);
                    std::cout<<"Multa bafta!"<<std::endl;
                }
    }
    void cine_a_castigat()
    {
        std::cout<<"Echipa care a castigat acest sezon este ";
        campionat_list[0].echipa_nume();
        std::cout<<std::endl;
    }
    static Liga1* get_liga1()
    {
        if(liga1 == nullptr)
        {
            liga1 = new Liga1;
        }
        return liga1;
    }
};

Liga1* Liga1::liga1 = nullptr;


#endif // LIGA1_H_INCLUDED
