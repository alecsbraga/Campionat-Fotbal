#include <iostream>
#include "Echipa.h"
#include "Patron.h"
#include "Stadion.h"
#include "Meci.h"
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

int compare(const void *a, const void *b)
{
    Echipa *A=(Echipa *) a;
    Echipa *B=(Echipa *) b;
    return B->Punctaj() - A->Punctaj();
}

class Campionat:public Meci
{
    string nume_campionat;
    vector <Echipa> campionat_list;

public:
    void meciuri()
    {
        int i,j;
        for(i=0;i<4;++i)
            for(j=0;j<4;++j)
                if(i!=j)
                joaca(campionat_list[i],campionat_list[j]);
       qsort(&campionat_list[0], campionat_list.size(), sizeof(Echipa), compare);
    }

    friend istream& operator>>(istream&, Campionat&);

    friend ostream& operator<<(ostream&, Campionat&);

};

istream& operator >> (istream& in, Campionat& campionat)
{
    in>>campionat.nume_campionat;
    Echipa echipa;
    for(int i=0; i<4; ++i)
    {
        in>>echipa;
        campionat.campionat_list.push_back(echipa);
    }
    return in;
}

ostream& operator <<(ostream& out, Campionat& campionat)
{
    out<<campionat.nume_campionat<<endl;
    for(int i=0; i<campionat.campionat_list.size(); ++i)
        out<<i+1<<". "<<campionat.campionat_list[i];
    return out;
}

int main()
{
    /*Echipa echipa_1("FCSB", 4, 1);
    Echipa echipa_2("FC Dinamo Bucuresti",2, 2, 1);
    Echipa echipa_3("CFR Cluj",3,1,1);
    cout<<echipa_1;
    cout<<echipa_2;
    cout<<echipa_3;
    Patron patron_1("Gigi Becali", echipa_1);
    Patron patron_2("Pablo Cortacero", echipa_2);
    Stadion stadion_1("Ghencea",echipa_1);
    Stadion stadion_2("Stefan Cel Mare",echipa_2);
    Meci meci_1(echipa_1,echipa_2);
    Meci meci_2(echipa_2,echipa_3);
    Meci meci_3(echipa_1,echipa_3);

*/
    Campionat campionat;
    ifstream f("Echipe.in");
    f>>campionat;
    campionat.meciuri();
    cout<<campionat;
    return 0;
}
