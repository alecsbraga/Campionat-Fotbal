#ifndef CAMPIONAT_H_INCLUDED
#define CAMPIONAT_H_INCLUDED
#include <iostream>
#include <vector>
#include <algorithm>
#include "Echipa.h"
#include "Meci.h"

class Campionat:public Meci
{
protected:
    std::string nume_campionat;
    std::vector <Echipa> campionat_list;
    int echipe;

public:

    void joaca();

    void cine_a_castigat();

    void ordoneaza()
    {
        std::sort(campionat_list.begin(), campionat_list.end());
    }
    friend std::istream& operator>>(std::istream&, Campionat&);

    friend std::ostream& operator<<(std::ostream&, Campionat&);

    virtual ~Campionat();

};

#endif // CAMPIONAT_H_INCLUDED
